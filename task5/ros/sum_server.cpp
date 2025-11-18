#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "action_tutorials/action/sum.hpp"  // 自定义动作接口头文件

using Sum = action_tutorials::action::Sum;  // 简化类型名
using GoalHandleSum = rclcpp_action::ServerGoalHandle<Sum>;

class SumServer : public rclcpp::Node {
public:
  SumServer() : Node("sum_server") {
    // 创建动作服务器
    action_server_ = rclcpp_action::create_server<Sum>(
      this,
      "sum_action",  // 动作名称（客户端需匹配）
      std::bind(&SumServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
      std::bind(&SumServer::handle_cancel, this, std::placeholders::_1),
      std::bind(&SumServer::handle_accepted, this, std::placeholders::_1)
    );
    RCLCPP_INFO(this->get_logger(), "动作服务器已启动，等待目标...");
  }

private:
  rclcpp_action::Server<Sum>::SharedPtr action_server_;

  // 处理目标请求（是否接受目标）
  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const Sum::Goal> goal
  ) {
    RCLCPP_INFO(this->get_logger(), "收到目标：累加到 %ld", goal->n);
    (void)uuid;  // 未使用参数
    if (goal->n < 1) {  // 拒绝无效目标（N必须≥1）
      return rclcpp_action::GoalResponse::REJECT;
    }
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  // 处理取消请求
  rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHandleSum> goal_handle
  ) {
    RCLCPP_INFO(this->get_logger(), "收到取消请求");
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  // 接受目标后执行累加逻辑
  void handle_accepted(const std::shared_ptr<GoalHandleSum> goal_handle) {
    // 异步执行（避免阻塞节点）
    std::thread{std::bind(&SumServer::execute, this, std::placeholders::_1), goal_handle}.detach();
  }

  // 执行累加任务
  void execute(const std::shared_ptr<GoalHandleSum> goal_handle) {
    RCLCPP_INFO(this->get_logger(), "开始累加...");
    const auto goal = goal_handle->get_goal();
    int64_t n = goal->n;
    int64_t current_sum = 0;

    // 设置循环频率（1Hz，每1秒累加一次，方便观察反馈）
    rclcpp::Rate loop_rate(1);

    for (int64_t i = 1; i <= n; ++i) {
      // 检查是否需要取消
      if (goal_handle->is_canceling()) {
        auto result = std::make_shared<Sum::Result>();
        result->sum = current_sum;
        goal_handle->canceled(result);
        RCLCPP_INFO(this->get_logger(), "任务已取消，当前和：%ld", current_sum);
        return;
      }

      // 累加并发布反馈
      current_sum += i;
      auto feedback = std::make_shared<Sum::Feedback>();
      feedback->current_num = i;
      feedback->current_sum = current_sum;
      goal_handle->publish_feedback(feedback);
      RCLCPP_INFO(this->get_logger(), "服务器反馈：已累加至 %ld，当前和：%ld", i, current_sum);

      loop_rate.sleep();  // 等待1秒
    }

    // 完成任务，返回结果
    if (rclcpp::ok()) {
      auto result = std::make_shared<Sum::Result>();
      result->sum = current_sum;
      goal_handle->succeed(result);
      RCLCPP_INFO(this->get_logger(), "累加完成，最终和：%ld", current_sum);
    }
  }
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SumServer>());
  rclcpp::shutdown();
  return 0;
}