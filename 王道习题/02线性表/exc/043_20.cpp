#include "node.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>

namespace way1 {

/* 反转链表 */
Node *reverse(Node *node) {
  Node *prev = nullptr; // 记录前驱节点

  while (node) {
    Node *temp = node;
    node = temp->next;
    temp->next = prev;
    prev = temp;
  }

  return prev; // 循环结束后，prev 正好指向反转后的链表的第一个节点
}

/* 重排列节点 */
void rearrange_node(Node *node) {

  node = node->next; // 从第一个有效节点开始

  // 将链表折半拆分（从有效节点开始）
  Node *slow = node;
  Node *fast = node->next; // 确保快指针走到底后，slow 指针能指向中间的前一个节点

  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }

  Node *last_half = reverse(slow->next);
  slow->next = nullptr; // 让 slow 指向的节点断开与后一半节点的连接

  // std::cout << "\n\n";
  // print_linked_list(node);      // 前一半
  // print_linked_list(last_half); // 后一半
  // std::cout << "\n";

  while (last_half) {
    Node *temp1 = node->next;
    Node *temp2 = last_half;
    last_half = last_half->next;

    node->next = temp2;
    temp2->next = temp1;

    node = temp1;
  }
}
} // namespace way1

void test1() {
  std::cout << "测试一：（偶数个节点）\n";

  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};

  Node *head = create_linked_list(nums);
  std::cout << "初始链表：";
  print_linked_list(head->next);

  std::cout << "重排列后的节点：";
  way1::rearrange_node(head);
  print_linked_list(head->next);
}

void test2() {
  std::cout << "测试二：（奇数个节点）\n";

  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  Node *head = create_linked_list(nums);
  std::cout << "初始链表：";
  print_linked_list(head->next);

  std::cout << "重排列后的节点：";
  way1::rearrange_node(head);
  print_linked_list(head->next);
}

int main() {
  test1();

  std::cout << "\n";

  test2();
}