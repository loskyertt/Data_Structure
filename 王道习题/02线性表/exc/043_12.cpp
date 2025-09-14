#include "node.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>

/* 连接两个循环单链表 */
void link_linked_list_looped(Node *h1, Node *h2) {
  Node *h1_rear = h1->next; // 从 h1 的第一个有效节点开始

  // 找到 h1 的尾节点
  while (h1_rear->next != h1) {
    h1_rear = h1_rear->next;
  }

  Node *h2_rear = h2->next;

  // 找到 h2 的尾节点
  while (h2_rear->next != h2) {
    h2_rear = h2_rear->next;
  }
  h2_rear->next = nullptr; // 先让 h2_rear 断开与头节点的连接

  Node *temp = h2;
  h2 = temp->next;
  delete temp; // 删除 h2 的头节点

  // 让 h1 的尾节点连接 h2 的第一个有效头节点
  h1_rear->next = h2;

  // 让 h2 的尾节点连接到 h1 的头结点
  h2_rear->next = h1;
}

void test1() {
  std::cout << "测试一：\n";

  std::vector<int> nums1 = {1, 2, 3, 4, 5};
  std::vector<int> nums2 = {7, 8, 9, 10};

  Node *node1 = create_linked_list_looped(nums1);
  Node *node2 = create_linked_list_looped(nums2);

  std::cout << "h1 初始：";
  print_linked_list_looped(node1);

  std::cout << "h2 初始：";
  print_linked_list_looped(node2);

  std::cout << "连接后的：";
  link_linked_list_looped(node1, node2);
  print_linked_list_looped(node1);
}

int main() {
  test1();
}