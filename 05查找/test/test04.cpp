#include "heap/maxHeap.hpp"
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

// 测试堆
int main() {
  // 手动实现的大顶堆
  MaxHeap max_heap;
  max_heap.push(1);
  max_heap.push(3);
  max_heap.push(10);
  max_heap.push(2);
  max_heap.push(5);
  max_heap.push(4);
  max_heap.push(6);

  std::cout << "大顶堆（手动实现的）：";
  while (!max_heap.is_empty()) {
    std::cout << max_heap.top() << " ";
    max_heap.pop();
  }
  std::cout << "\n\n";

  // 标准库中的优先队列
  std::priority_queue<int, std::vector<int>, std::less<int>> std_max_heap; // 初始化大顶堆

  std_max_heap.push(1);
  std_max_heap.push(3);
  std_max_heap.push(10);
  std_max_heap.push(2);
  std_max_heap.push(5);
  std_max_heap.push(4);
  std_max_heap.push(6);

  std::cout << "大顶堆（标准库）：";
  while (!std_max_heap.empty()) {
    std::cout << std_max_heap.top() << " ";
    std_max_heap.pop();
  }
  std::cout << "\n\n";

  std::priority_queue<int, std::vector<int>, std::greater<int>> std_min_heap; // 初始化小顶堆

  std_min_heap.push(1);
  std_min_heap.push(3);
  std_min_heap.push(10);
  std_min_heap.push(2);
  std_min_heap.push(5);
  std_min_heap.push(4);
  std_min_heap.push(6);

  std::cout << "小顶堆（标准库）：";
  while (!std_min_heap.empty()) {
    std::cout << std_min_heap.top() << " ";
    std_min_heap.pop();
  }
  std::cout << "\n\n";

  return 0;
}