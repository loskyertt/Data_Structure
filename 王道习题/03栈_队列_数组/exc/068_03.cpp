#include <iostream>
#include <stack>
#include <vector>

/* 判定出入栈序列是否合法 */
bool is_legal(const std::vector<int> &nums) {
  std::stack<int> stk;

  for (const int &val : nums) {
    if (val == 1) {
      stk.push(1); // 放入元素
    } else {
      if (stk.empty()) {
        return false; // 说明不合法
      }
      stk.pop(); // 弹出元素
    }
  }

  return stk.empty(); // 如果栈最后为空，返回是 true，说明合法；否则不合法
}

void test1() {
  std::cout << "测试一：\n";

  // 1 表示入栈，0 表示出栈
  std::vector<int> nums = {1, 0, 1, 1, 0, 1, 0, 0}; // 合法

  if (is_legal(nums)) {
    std::cout << "是合法序列！\n";
  } else {
    std::cout << "不是合法序列！\n";
  }
}

void test2() {
  std::cout << "测试二：\n";

  // 1 表示入栈，0 表示出栈
  std::vector<int> nums = {1, 0, 0, 1, 0, 1, 1, 0}; // 合法

  if (is_legal(nums)) {
    std::cout << "是合法序列！\n";
  } else {
    std::cout << "不是合法序列！\n";
  }
}

void test3() {
  std::cout << "测试三：\n";

  // 1 表示入栈，0 表示出栈
  std::vector<int> nums = {1, 1, 1, 0, 1, 0, 1, 0}; // 合法

  if (is_legal(nums)) {
    std::cout << "是合法序列！\n";
  } else {
    std::cout << "不是合法序列！\n";
  }
}

void test4() {
  std::cout << "测试一：\n";

  // 1 表示入栈，0 表示出栈
  std::vector<int> nums = {1, 1, 1, 0, 0, 1, 0, 0}; // 合法

  if (is_legal(nums)) {
    std::cout << "是合法序列！\n";
  } else {
    std::cout << "不是合法序列！\n";
  }
}

int main() {
  test1();

  std::cout << "\n";

  test2();

  std::cout << "\n";

  test3();

  std::cout << "\n";

  test4();
}