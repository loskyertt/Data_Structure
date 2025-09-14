#include "utils.hpp"
#include "node.hpp"
#include <climits>
#include <iostream>
#include <stdexcept>

// 完蛋（；´д｀）ゞ 代码真成 shi 了ㄟ( ▔, ▔ )ㄏ

/* 打印单链表 */
void print_linked_list(Node *head) {
  std::cout << "head -> ";

  while (head) {
    std::cout << head->val << " -> ";
    head = head->next;
  }

  std::cout << "nullptr\n";
}

/* 打印循环单链表 */
void print_linked_list_looped(Node *head) {
  std::cout << "head -> ";

  Node *current = head->next;

  while (current != head) {
    std::cout << current->val << " -> ";
    current = current->next;
  }

  std::cout << "head\n";
}

/* 打印循环双链表 */
void print_linked_listD_looped(DNode *head) {
  std::cout << "head <-> ";

  DNode *current = head->next;
  while (current != head) {
    std::cout << current->val << " <-> ";
    current = current->next;
  }

  std::cout << "head\n";
}

/* 数组转链表：带头节点 */
Node *create_linked_list(std::vector<int> &nums) {
  Node *head = new Node(INT_MAX);
  Node *current = head;

  for (int num : nums) {
    Node *new_node = new Node(num);
    current->next = new_node;
    current = current->next;
  }

  return head;
}

/* 数组转循环单链表：带头节点 */
Node *create_linked_list_looped(std::vector<int> &nums) {
  Node *head = new Node(INT_MAX);
  Node *current = head;

  for (int num : nums) {
    Node *new_node = new Node(num);
    current->next = new_node;
    current = current->next;
  }

  // 尾节点连接头节点
  current->next = head;

  return head;
}

/* 数组转循环双链表：带头节点 */
DNode *create_linked_listD_looped(std::vector<int> &nums) {
  DNode *head = new DNode(INT_MAX);
  DNode *current = head;

  for (int val : nums) {
    DNode *new_node = new DNode(val);
    current->next = new_node;
    new_node->prev = current;
    current = current->next;
  }

  // 尾节点连接头节点
  current->next = head;
  head->prev = current;

  return head;
}

/* 插入节点，在 n0 后插入 n1 */
void insert(Node *n0, Node *n1) {
  Node *temp = n0->next;
  n0->next = n1;
  n1->next = temp;
}

/* 删除节点 n0 之后的首个节点 */
void remove(Node *n0) {
  if (n0 == nullptr || n0->next == nullptr) {
    throw std::out_of_range("没有节点可删除！");
  }

  Node *temp = n0->next;
  n0->next = temp->next;

  delete temp;
}

/* 打印数组 */
void print_vector(const std::vector<int> &nums) {
  if (nums.empty()) {
    throw std::out_of_range("数组为空！");
  }

  for (int val : nums) {
    std::cout << val << " ";
  }
  std::cout << "\n";
}