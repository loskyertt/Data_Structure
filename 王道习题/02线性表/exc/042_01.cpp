#include "node.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>

/* 删除带头节点的单链表中数值域为 x 的节点 */
void remove_x(Node *node, int x) {

  Node *prev = node; // 前驱节点（头节点）
  node = node->next;

  while (node) {
    if (node->val == x) {
      Node *temp = node;
      node = temp->next;
      prev->next = node;
      delete temp;
    } else {
      prev = node;
      node = node->next;
    }
  }
}

void test1() {
  std::cout << "测试一：\n";

  std::vector<int> nums = {1, 1, 4, 3, 1, 6, 7, 5, 1, 2, 1};

  // 数组转链表（带头节点：INT_MAX 作为头节点标识）
  Node *head = create_linked_list(nums);

  // 当前链表
  std::cout << "初始链表：";
  print_linked_list(head->next);

  std::cout << "删除 1 后链表：";
  remove_x(head, 1);
  print_linked_list(head->next);
}

int main() {
  test1();
}