#include "node.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>

/* 检查带头节点的循环双链表是否对称 */
bool is_symmetry(DNode *node) {
  DNode *left = node->next;  // 第一个有效节点（跳过头节点）
  DNode *right = node->prev; // 尾节点

  while (left != right && left->next != right) {
    if (left->val == right->val) {
      left = left->next;
      right = right->prev;
    } else {
      return false; // 表示不对称
    }
  }

  // 循环完整结束，表示链表对称
  return true;
}

void test1() {
  std::cout << "测试一（偶数个元素）：\n";

  std::vector<int> nums = {1, 3, 5, 5, 3, 1};

  DNode *head = create_linked_listD_looped(nums);

  std::cout << "初始链表：";
  print_linked_listD_looped(head);

  if (is_symmetry(head)) {
    std::cout << "该链表对称！\n";
  } else {
    std::cout << "链表不对称！\n";
  }
}

void test2() {
  std::cout << "测试二（奇数个元素）：\n";

  std::vector<int> nums = {1, 3, 5, 7, 5, 3, 1};

  DNode *head = create_linked_listD_looped(nums);

  std::cout << "初始链表：";
  print_linked_listD_looped(head);

  if (is_symmetry(head)) {
    std::cout << "该链表对称！\n";
  } else {
    std::cout << "链表不对称！\n";
  }
}

void test3() {
  std::cout << "测试二（不对称链表）：\n";

  std::vector<int> nums = {1, 3, 2, 7, 5, 3, 1};

  DNode *head = create_linked_listD_looped(nums);

  std::cout << "初始链表：";
  print_linked_listD_looped(head);

  if (is_symmetry(head)) {
    std::cout << "该链表对称！\n";
  } else {
    std::cout << "链表不对称！\n";
  }
}

int main() {

  test1();

  std::cout << "\n";

  test2();

  std::cout << "\n";

  test3();
}