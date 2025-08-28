#include "node.hpp"
#include "utils.hpp"
#include <climits>
#include <iostream>
#include <vector>

/* 将 a 链表和 b 链表中的公共节点构成新的链表，a b 链表中的元素递增有序 */
Node *get_public_nodes(Node *node_a, Node *node_b) {
  Node *head = new Node(INT_MAX);
  Node *curr = head;

  // 跳过头节点
  node_a = node_a->next;
  node_b = node_b->next;

  while (node_a && node_b) {
    // a 小，移 a
    if (node_a->val < node_b->val) {
      node_a = node_a->next;
    }
    // b 小，移 b
    else if (node_a->val > node_b->val) {
      node_b = node_b->next;
    } else {
      // 因为不能破坏原链表，只能重新创建节点
      curr->next = new Node(node_a->val);
      curr = curr->next;
      node_a = node_a->next;
      node_b = node_b->next;
    }
  }

  return head;
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

  Node *node_c = get_public_nodes(node_a, node_b);
  std::cout << "公共节点构成的链表：";
  print_linked_list(node_c->next);
}