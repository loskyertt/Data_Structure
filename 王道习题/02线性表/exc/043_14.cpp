#include "node.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>

/* 将 L（不带头节点） 中保存的序列循环右移 k（0<k<n，n 为链表长度） 个位置 */
Node *move_node(Node *L, int k) {
  Node *slow = L, *fast = L;
  Node *prev = nullptr; // 记录 slow 的前驱节点

  // 先让 fast 指针走 k 步
  while (k > 0) {
    fast = fast->next;
    --k;
  }

  // 最后 slow 指向倒数第 k 个节点
  while (fast) {
    fast = fast->next;
    prev = slow;
    slow = slow->next;
  }

  prev->next = nullptr;
  Node *curr = slow;

  // 让 slow 链表的尾节点连接 L 的第一个节点
  while (curr->next) {
    curr = curr->next;
  }

  curr->next = L;

  return slow;
}

void test1() {
  std::cout << "测试一（奇数个节点）：";

  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

  Node *head = create_linked_list(nums);
  std::cout << "初始链表：";
  print_linked_list(head->next);

  // 传参时跳过头节点
  Node *node = move_node(head->next, 3);
  std::cout << "循环移动后的链表：";
  print_linked_list(node);
}

void test2() {
  std::cout << "测试二（偶数个节点）：";

  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};

  Node *head = create_linked_list(nums);
  std::cout << "初始链表：";
  print_linked_list(head->next);

  // 传参时跳过头节点
  Node *node = move_node(head->next, 7);
  std::cout << "循环移动后的链表：";
  print_linked_list(node);
}

int main() {
  test1();

  std::cout << "\n";

  test2();
}