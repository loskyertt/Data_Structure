#include "queue/queue.hpp"
#include <iostream>

using namespace std;

/* 测试链表实现的队列 */
int main() {
  LinkedListQueue queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);
  queue.push(4);

  // 获取队首值
  cout << "front = " << queue.peek() << endl;

  // 删除队首值
  queue.pop();

  cout << "front = " << queue.peek() << endl;

  queue.pop();

  cout << "front = " << queue.peek() << endl;

  queue.pop();

  cout << "front = " << queue.peek() << endl;

  queue.pop();

  // 获取队列长度
  int size = queue.size();
  cout << "size = " << size << endl;

  /* 判断是否为空 */
  if (queue.empty()) {
    cout << "队列为空！" << endl;
  } else {
    cout << "队列中还有元素" << endl;
  }

  return 0;
}