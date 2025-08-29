#include "node.hpp"
#include "utils.hpp"
#include <climits>
#include <iostream>
#include <tuple>
#include <vector>

/* 拆分链表 */
std::tuple<Node *, Node *> split_linked_list(Node *node) {
  Node *head1 = new Node(INT_MAX);
  Node *head2 = new Node(INT_MAX);

  Node *curr = node->next;

  Node *a = curr, *b = curr->next;

  head1->next = a;
  head2->next = b;

  while (a && a->next && b && b->next) {
    Node *temp_a = a;
    Node *temp_b = b;

    a = a->next->next;
    temp_a->next = a;

    b = b->next->next;
    temp_b->next = b;
  }

  return {head1, head2};
}

void test1() {
  std::cout << "测试一（奇数个元素）：\n";

  // 奇数数组
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Node *node = create_linked_list(nums);
  std::cout << "node1 初始：";
  print_linked_list(node->next);

  auto [node_a, node_b] = split_linked_list(node);
  std::cout << "node_a: ";
  print_linked_list(node_a->next);
  std::cout << "node_b: ";
  print_linked_list(node_b->next);
}

int main() {
  test1();
}