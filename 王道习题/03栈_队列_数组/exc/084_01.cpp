#include <climits>
#include <iostream>
#include <vector>

#define MAX_SIZE 8

/* 队列结构体 */
template <typename T>
class Queue {
private:
  std::vector<T> queue;
  int front = 0;
  int rear = 0;

public:
  Queue() : queue(MAX_SIZE, INT_MAX) {}

  // 判空
  bool is_empty() {
    return front == rear;
  }

  // 判满
  bool is_full() {
    return (rear + 1) % MAX_SIZE == front;
  }

  // 入队
  void push(T val) {
    if (is_full()) {
      std::cout << "队列已满！\n";
      return;
    }
    queue[rear] = val;
    rear = (rear + 1) % MAX_SIZE;
  }

  // 出队
  void pop() {
    if (is_empty()) {
      std::cout << "队列是空的！\n";
      return;
    }
    queue[front] = INT_MAX;
    front = (front + 1) % MAX_SIZE;
  }

  // 返回队首元素
  int get_front() {
    if (is_empty()) {
      std::cout << "队列是空的！\n";
      return INT_MAX;
    }
    return queue[front];
  }
};

void test1() {
  std::cout << "测试一：\n";

  Queue<int> q;

  // 把队列中的元素填满
  for (int i = 0; i < 8; ++i) {
    q.push(i);
  }

  // 尝试往已满的队列中添加元素
  q.push(10);

  // 出队
  std::cout << "队首元素：" << q.get_front() << "\n";

  q.pop();
  std::cout << "队首元素：" << q.get_front() << "\n"; // 此时队列：1, 2, 3, 4, 5, 6, 7

  q.pop();
  q.pop();
  std::cout << "队首元素：" << q.get_front() << "\n"; // 此时队列：3, 4, 5, 6

  for (int i = 0; i < 4; ++i) {
    q.push(i + 10);
  } // 此时队列元素应为：3, 4, 5, 6, 10, 11, 12, 13

  // 依次出队
  std::cout << "依次出队：";
  while (!q.is_empty()) {
    std::cout << q.get_front() << " ";
    q.pop();
  }

  std::cout << "\n";

  if (q.is_empty()) {
    std::cout << "队列为空！\n";
  }
}

int main() {
  test1();
}