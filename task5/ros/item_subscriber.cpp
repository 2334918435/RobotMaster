#include "rclcpp/rclcpp.hpp"
#include "item_info_pkg/msg/item_info.hpp"  // 自定义消息头文件

class ItemSubscriber : public rclcpp::Node
{
public:
  ItemSubscriber() : Node("item_subscriber")
  {
    // 创建订阅者（订阅话题：/item_info，队列大小10）
    subscriber_ = this->create_subscription<item_info_pkg::msg::ItemInfo>(
      "/item_info", 10,
      std::bind(&ItemSubscriber::receive_item, this, std::placeholders::_1)
    );
  }

private:
  // 接收消息的回调函数
  void receive_item(const item_info_pkg::msg::ItemInfo & msg) const
  {
    RCLCPP_INFO(this->get_logger(), "接收物品：ID=%d, 名称=%s, 描述=%s, 价格=%.2f",
                msg.id, msg.name.c_str(), msg.description.c_str(), msg.price);
  }

  rclcpp::Subscription<item_info_pkg::msg::ItemInfo>::SharedPtr subscriber_;  // 订阅者
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);                  // 初始化ROS 2
  rclcpp::spin(std::make_shared<ItemSubscriber>());  // 运行节点
  rclcpp::shutdown();                        // 关闭节点
  return 0;
}