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

void test1() {
  std::cout << "测试一：\n";

  // 情况一
  std::vector<int> nums = {1, 2, 4, 4, 4, 6, 8, 9, 10, 10, 14};

  Node *node = create_linked_list(nums);
  std::cout << "node 初始：";
  print_linked_list(node->next);

  std::cout << "node 去重后：";
  remove_duplicated_node(node);
  print_linked_list(node->next);
}

void test2() {
  std::cout << "测试二：\n";

  // 情况二（末尾元素重复）
  std::vector<int> nums = {1, 2, 4, 4, 4, 6, 8, 9, 14, 14, 14};

  Node *node = create_linked_list(nums);
  std::cout << "node2 初始：";
  print_linked_list(node->next);

  std::cout << "node2 去重后：";
  remove_duplicated_node(node);
  print_linked_list(node->next);
}

int main() {
  test1();

  std::cout << "\n";

  test2();
}