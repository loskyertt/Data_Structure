#include "node.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>

/* 去除链表中重复元素，链表中的元素是递增有序的 */
void remove_duplicated_node(Node *node) {
  Node *prev = node;
  Node *curr = node->next;

  while (curr->next) {
    // 删除重复元素，直到该重复元素的最后一个
    if (curr->val == curr->next->val) {
      Node *temp = curr;
      curr = temp->next;
      prev->next = curr;
      delete temp;
    } else {
      prev = curr;
      curr = curr->next;
    }
  }
}

int main() {

  // 情况一
  std::vector<int> nums1 = {1, 2, 4, 4, 4, 6, 8, 9, 10, 10, 14};

  Node *node1 = create_linked_list(nums1);
  std::cout << "node1 初始：";
  print_linked_list(node1->next);

  std::cout << "node1 去重后：";
  remove_duplicated_node(node1);
  print_linked_list(node1->next);

  // 情况二
  std::vector<int> nums2 = {1, 2, 4, 4, 4, 6, 8, 9, 14, 14, 14};

  Node *node2 = create_linked_list(nums2);
  std::cout << "node2 初始：";
  print_linked_list(node2->next);

  std::cout << "node2 去重后：";
  remove_duplicated_node(node2);
  print_linked_list(node2->next);
}