#pragma once
#include <iostream>
#include <vector>

namespace node1 {

template <typename T>
struct Node {
  T val;
  Node *next;
  Node(T x) : val(x), next(nullptr) {}
};

/* 数组转单链表 */
template <typename T>
Node<T> *create_linked_list(std::vector<T> &nums) {
  {
    Node<T> *head = new Node<T>(T{}); // 头节点，并不存储有效值，只是作为标识
    Node<T> *current = head;

    for (const auto &num : nums) {
      Node<T> *new_node = new Node<T>(num);
      current->next = new_node;
      current = current->next;
    }

    return head;
  }
}

/* 打印单链表 */
template <typename T>
void print_linked_list(Node<T> *head) {
  {
    std::cout << "head -> ";

    while (head) {
      std::cout << head->val << " -> ";
      head = head->next;
    }

    std::cout << "nullptr\n";
  }
}
} // namespace node1