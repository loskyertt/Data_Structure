#include "stack/stack.hpp"
#include <iostream>

using namespace std;

/* 测试链表实现的栈 */
int main() {
  LinkedListStack stack;

  /* 元素入栈 */
  stack.push(1);
  stack.push(2);
  stack.push(4);

  /* 访问栈顶元素 */
  int top = stack.top();
  cout << "top = " << top << endl;

  /* 元素出栈 */
  stack.pop();
  cout << "top = " << stack.top() << endl;

  /* 获取栈长度 */
  int size = stack.size();
  cout << "Stack size: " << size << endl;

  /* 判断是否为空 */
  if (stack.empty()) {
    cout << "栈为空！" << endl;
  } else {
    cout << "栈中还有元素" << endl;
  }

  return 0;
}