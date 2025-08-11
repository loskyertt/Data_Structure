#include <iostream>
#include <queue>

using namespace std;

/* 测试标准库里的队列 */
int main() {
  queue<int> queue;

  queue.push(1);
  queue.push(2);
  queue.push(3);
  queue.push(4);

  // 获取队首值
  cout << "front = " << queue.front() << endl;

  // 删除队首值
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