#include "node.hpp"
#include <iostream>

/* 检查单链表是否有环 */
bool is_circle(Node *L) {
  Node *slow = L, *fast = L;

  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;

    if (fast == slow) {
      return true; // 如果 fast 指针和 slow 指针相遇，说明有环
    }
  }

  return false;
}

void test1() {
  std::cout << "测试一（无环）：";

  // 构造无环链表 1->2->3->nullptr
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);

  std::cout << (is_circle(head) ? "有环" : "无环") << std::endl;
}

void test2() {
  std::cout << "测试二（有环）：";

  // 构造有环链表
  Node *n0 = new Node(0);
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);

  n0->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n3; // 构成环

  std::cout << (is_circle(n0) ? "有环" : "无环") << std::endl;
}

int main() {
  test1();

  std::cout << "\n";

  test2();
}