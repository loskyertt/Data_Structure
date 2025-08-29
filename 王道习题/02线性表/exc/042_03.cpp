#include "node.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>

/* 逆置链表 */
void reverse_linked_list(Node *node) {
  Node *head = node;       // 记录头节点
  Node *curr = node->next; // 记录当前节点
  Node *prev = nullptr;

  while (curr) {
    Node *temp = curr;
    curr = curr->next; // 先移动到下一个节点
    temp->next = prev;
    prev = temp;
  }

  head->next = prev;
}

void test1() {
  std::cout << "测试一：\n";

  std::vector<int> nums = {1, 2, 3, 4, 5, 6};
  Node *node = create_linked_list(nums);

  std::cout << "初始链表：";
  print_linked_list(node->next);

  std::cout << "逆序后的链表：";
  reverse_linked_list(node);
  print_linked_list(node->next);
}

int main() {
  test1();
}