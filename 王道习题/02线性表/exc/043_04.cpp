#include "node.hpp"
#include "utils.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

/* 删除链表中给定两个值之间的元素，给定区间 (a, b) */
void remove_target(Node *node, int a, int b) {
  if (a >= b) {
    throw std::out_of_range("区间不符！");
  }
  Node *prev = node, *curr = node->next;

  while (node) {
    // 如果节点的值在 (a, b) 之间，则删除
    if (node->val > a && node->val < b) {
      Node *temp = node;
      node = node->next;
      prev->next = node;
      delete temp;
    } else {
      prev = node;
      node = node->next;
    }
  }
}

int main() {
  std::vector<int> nums1 = {1, 3, 2, 6, 4, 9, 6, 7};

  Node *node1 = create_linked_list(nums1);

  std::cout << "初始链表：";
  print_linked_list(node1->next);

  std::cout << "删除节点后的链表：";
  remove_target(node1, 3, 7);
  print_linked_list(node1->next);

  std::vector<int> nums2 = {1, 3, 2, 6, 4, 9, 6, 7};

  Node *node2 = create_linked_list(nums2);

  std::cout << "删除全部节点：";
  remove_target(node2, 0, 16);
  print_linked_list(node2->next);
}