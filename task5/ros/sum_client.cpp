#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "action_tutorials/action/sum.hpp"
// 引入Action类型的头文件（确保已包含）
#include "action_tutorials/action/sum.hpp"
// 引入rclcpp_action相关头文件
#include "rclcpp_action/rclcpp_action.hpp"

// 定义GoalHandleSum类型（对应Sum这个Action）
using GoalHandleSum = rclcpp_action::ClientGoalHandle<action_tutorials::action::Sum>;

using Sum = action_tutorials::action::Sum;
using Client = rclcpp_action::Client<Sum>;

class SumClient : public rclcpp::Node {
public:
  SumClient() : Node("sum_client") {
    // 创建动作客户端（需与服务器动作名称一致）
    client_ = rclcpp_action::create_client<Sum>(this, "sum_action");
  }

  // 发送目标请求
  void send_goal(int64_t n) {
    if (!client_->wait_for_action_server(std::chrono::seconds(5))) {
      RCLCPP_ERROR(this->get_logger(), "未连接到动作服务器");
      return;
    }

    // 构建目标消息
    auto goal_msg = Sum::Goal();
    goal_msg.n = n;

    // 设置目标发送选项（含反馈和结果回调）
    auto send_goal_options = rclcpp_action::Client<action_tutorials::action::Sum>::SendGoalOptions();
    send_goal_options.feedback_callback =
      std::bind(&SumClient::feedback_callback, this, std::placeholders::_1, std::placeholders::_2);
    send_goal_options.result_callback =
      std::bind(&SumClient::result_callback, this, std::placeholders::_1);

    // 发送目标
    client_->async_send_goal(goal_msg, send_goal_options);
    RCLCPP_INFO(this->get_logger(), "已发送目标：累加到 %ld", n);
  }

private:
  Client::SharedPtr client_;

  // 反馈回调（接收实时反馈）
  void feedback_callback(
    GoalHandleSum::SharedPtr,
    const std::shared_ptr<const Sum::Feedback> feedback
  ) {
    RCLCPP_INFO(
      this->get_logger(),
      "客户端反馈：当前累加数字 %ld，当前和 %ld",
      feedback->current_num,
      feedback->current_sum
    );
  }

  // 结果回调（接收最终结果）
  void result_callback(const GoalHandleSum::WrappedResult & result) {
    switch (result.code) {
      case rclcpp_action::ResultCode::SUCCEEDED:
        RCLCPP_INFO(this->get_logger(), "任务成功！最终累加和：%ld", result.result->sum);
        break;
      case rclcpp_action::ResultCode::ABORTED:
        RCLCPP_ERROR(this->get_logger(), "任务被中止");
        return;
      case rclcpp_action::ResultCode::CANCELED:
        RCLCPP_INFO(this->get_logger(), "任务被取消，当前和：%ld", result.result->sum);
        return;
      default:
        RCLCPP_ERROR(this->get_logger(), "未知结果状态");
        return;
    }
  }
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  auto client_node = std::make_shared<SumClient>();
  
  // 发送目标（例如累加到10）
  int64_t target = 10;
  if (argc > 1) {
    target = std::stoll(argv[1]);  // 支持命令行参数指定目标
  }
  client_node->send_goal(target);

  rclcpp::spin(client_node);
  rclcpp::shutdown();
  return 0;
}
