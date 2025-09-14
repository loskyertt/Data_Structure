#include "utils.hpp"
#include <iostream>
#include <stack>
#include <vector>

/* 判断字符链表是否对称 */
bool is_symmetry(node1::Node<char> *node) {
  node = node->next; // 从第一个有效字符开始
  node1::Node<char> *curr = node;

  std::stack<char> stk;

  int count = 0; // 用于统计字符数量
  while (curr) {
    stk.push(curr->val);
    ++count;
    curr = curr->next;
  }

  count = count / 2; // （除 2）取一半。如果 count 是奇数，中间元素会忽略，但是不影响

  while (count) {
    if (stk.top() == node->val) {
      stk.pop();
      node = node->next;
      --count;
    } else {
      return false;
    }
  }

  return true; // 循环成功结束，则说明字符链表是对称的
}

void test1() {
  std::cout << "测试一（偶数元素）：\n";

  std::vector<char> nums = {'x', 'y', 'y', 'x'};

  node1::Node<char> *head = node1::create_linked_list(nums);

  std::cout << "初始链表：";
  node1::print_linked_list(head->next);

  if (is_symmetry(head)) {
    std::cout << "序列是中心对称！\n";
  } else {
    std::cout << "序列不是中心对称！\n";
  }
}

void test2() {
  std::cout << "测试二（奇数元素）：\n";

  std::vector<char> nums = {'x', 'y', 'a', 'y', 'x'};

  node1::Node<char> *head = node1::create_linked_list(nums);

  std::cout << "初始链表：";
  node1::print_linked_list(head->next);

  if (is_symmetry(head)) {
    std::cout << "序列是中心对称！\n";
  } else {
    std::cout << "序列不是中心对称！\n";
  }
}

void test3() {
  std::cout << "测试三（一个元素）：\n";

  std::vector<char> nums = {'x'};

  node1::Node<char> *head = node1::create_linked_list(nums);

  std::cout << "初始链表：";
  node1::print_linked_list(head->next);

  if (is_symmetry(head)) {
    std::cout << "序列是中心对称！\n";
  } else {
    std::cout << "序列不是中心对称！\n";
  }
}

void test4() {
  std::cout << "测试四：\n";

  std::vector<char> nums = {'x', 'a', 'y', 'x'};

  node1::Node<char> *head = node1::create_linked_list(nums);

  std::cout << "初始链表：";
  node1::print_linked_list(head->next);

  if (is_symmetry(head)) {
    std::cout << "序列是中心对称！\n";
  } else {
    std::cout << "序列不是中心对称！\n";
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