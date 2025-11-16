#include "rclcpp/rclcpp.hpp"
#include "item_info_pkg/msg/item_info.hpp"  // 自定义消息头文件

class ItemPublisher : public rclcpp::Node
{
public:
  ItemPublisher() : Node("item_publisher"), count_(0)
  {
    // 创建发布者（话题名：/item_info，队列大小10）
    publisher_ = this->create_publisher<item_info_pkg::msg::ItemInfo>("/item_info", 10);
    // 定时器：1秒发布一次消息
    timer_ = this->create_wall_timer(
      std::chrono::seconds(1),
      std::bind(&ItemPublisher::publish_item, this)
    );
  }

private:
  void publish_item()
  {
    // 构建消息内容
    auto msg = item_info_pkg::msg::ItemInfo();
    msg.id = count_;
    msg.name = "物品" + std::to_string(count_);
    msg.description = "这是第" + std::to_string(count_) + "个测试物品";
    msg.price = 10.5 + count_ * 2.3;  // 价格递增

    // 发布消息并打印
    publisher_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "发布物品：ID=%d, 名称=%s, 价格=%.2f",
                msg.id, msg.name.c_str(), msg.price);
    count_++;
  }

  rclcpp::TimerBase::SharedPtr timer_;         // 定时器
  rclcpp::Publisher<item_info_pkg::msg::ItemInfo>::SharedPtr publisher_;  // 发布者
  size_t count_;  // 计数器（用于生成ID）
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);                  // 初始化ROS 2
  rclcpp::spin(std::make_shared<ItemPublisher>());  // 运行节点
  rclcpp::shutdown();                        // 关闭节点
  return 0;
}