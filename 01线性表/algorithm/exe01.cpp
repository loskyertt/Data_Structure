#include "node.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <iostream>
#include <unordered_set>

// 去除链表中的重复元素
void remove_duplicates(Node *node) {
  std::unordered_set<int> nums;

  Node *prev = nullptr;
  while (node) {
    // 如果当前节点值不在 nums 中
    if (nums.find(std::abs(node->val)) == nums.end()) {
      // 把该节点值放入集合中
      nums.insert(std::abs(node->val));
      prev = node;
      node = node->next;
    }
    // 在 nums 中
    else {
      Node *nxt = node->next;
      delete node;
      node = nxt;
      prev->next = node;
    }
  }
}

int main() {
  Node *n0 = new Node(1);
  Node *n1 = new Node(3);
  Node *n2 = new Node(2);
  Node *n3 = new Node(5);
  Node *n4 = new Node(-2);
  Node *n5 = new Node(1);
  Node *n6 = new Node(2);
  Node *n7 = new Node(-3);

  n0->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;
  n6->next = n7;

  std::cout << "初始链表：";
  print_linked_list(n0);

  std::cout << "去重后的链表：";
  remove_duplicates(n0);
  print_linked_list(n0);
}