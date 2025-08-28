#include "node.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>

/* 寻找两个递增有序链表的交集，并存放于 node_a 中 */
void find_intersections(Node *node_a, Node *node_b) {
  Node *prev_a = node_a; // 记录 node_a 的前驱节点
  node_a = node_a->next;
  node_b = node_b->next;

  while (node_a && node_b) {
    // 此时 node_a 会移动节点，这个节点可以删除了
    if (node_a->val < node_b->val) {
      Node *temp = node_a;
      node_a = node_a->next;
      prev_a->next = node_a;
      delete temp;
    }
    // 这里只移动 node_b，不影响 node_a
    else if (node_a->val > node_b->val) {
      node_b = node_b->next;
    } else {
      prev_a = node_a;
      node_a = node_a->next;
      node_b = node_b->next;
    }
  }

  // 如果 node_a 还没有走到头，把剩余节点都删了
  while (node_a) {
    Node *temp = node_a;
    node_a = node_a->next;
    prev_a->next = node_a;
    delete temp;
  }
}

int main() {
  std::vector<int> nums_a = {1, 2, 4, 6, 8, 9, 10, 13, 15, 16};
  std::vector<int> nums_b = {2, 3, 4, 5, 8, 10, 12, 13, 14, 16};

  Node *node_a = create_linked_list(nums_a);
  Node *node_b = create_linked_list(nums_b);

  std::cout << "node_a 初始：";
  print_linked_list(node_a->next);
  std::cout << "node_b 初始：";
  print_linked_list(node_b->next);

  std::cout << "构成交集的 node_a: ";
  find_intersections(node_a, node_b);
  print_linked_list(node_a->next);
}