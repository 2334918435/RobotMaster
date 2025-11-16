#include "rclcpp/rclcpp.hpp"
#include "fibonacci_service/srv/fibonacci.hpp"
#include <chrono>
using namespace std::chrono_literals;

using Fibonacci = fibonacci_service::srv::Fibonacci;

int main(int argc, char **argv)
{
  // 初始化ROS 2
  rclcpp::init(argc, argv);
  // 创建客户端节点
  auto node = rclcpp::Node::make_shared("fibonacci_client");
  // 创建客户端，指定服务名
  auto client = node->create_client<Fibonacci>("fibonacci_service");

  // 等待服务端启动
  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(node->get_logger(), "Client stopped waiting.");
      return 1;
    }
    RCLCPP_INFO(node->get_logger(), "Waiting for server...");
  }

  // 斐波那契初始值（0, 1）
  int64_t a = 0;
  int64_t b = 1;

  // 循环发送请求
  while (rclcpp::ok()) {
    // 创建请求
    auto request = std::make_shared<Fibonacci::Request>();
    request->a = a;
    request->b = b;

    // 发送异步请求
    auto result_future = client->async_send_request(request);
    // 等待服务端响应
    if (rclcpp::spin_until_future_complete(node, result_future) ==
        rclcpp::FutureReturnCode::SUCCESS)
    {
      // 接收服务端返回的结果
      auto response = result_future.get();
      // 客户端计算下一个数（b + 服务端返回的next）并输出
      int64_t client_next = b + response->next;
      RCLCPP_INFO(node->get_logger(), "Client: Next Fibonacci number is %ld", client_next);
      // 更新下一次请求的参数
      a = response->next;
      b = client_next;
    } else {
      RCLCPP_ERROR(node->get_logger(), "Failed to call service.");
    }

    // 延迟1秒，避免输出过快
    std::this_thread::sleep_for(1s);
  }

  // 关闭ROS 2
  rclcpp::shutdown();
  return 0;
}