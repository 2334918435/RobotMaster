#include "rclcpp/rclcpp.hpp"
#include "fibonacci_service/srv/fibonacci.hpp"

using Fibonacci = fibonacci_service::srv::Fibonacci;

// 处理客户端请求的回调函数
void handle_request(
  const std::shared_ptr<Fibonacci::Request> request,
  std::shared_ptr<Fibonacci::Response> response)
{
  // 计算下一个斐波那契数（a + b）
  response->next = request->a + request->b;
  // 服务端输出结果
  RCLCPP_INFO(rclcpp::get_logger("server"), "Server: Next Fibonacci number is %ld", response->next);
}

int main(int argc, char **argv)
{
  // 初始化ROS 2
  rclcpp::init(argc, argv);
  // 创建服务端节点
  auto node = rclcpp::Node::make_shared("fibonacci_server");
  // 创建服务，绑定回调函数
  auto service = node->create_service<Fibonacci>("fibonacci_service", &handle_request);
  
  RCLCPP_INFO(node->get_logger(), "Fibonacci server ready. Waiting for client...");
  // 循环处理请求
  rclcpp::spin(node);
  // 关闭ROS 2
  rclcpp::shutdown();
  return 0;
}