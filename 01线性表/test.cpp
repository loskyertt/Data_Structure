#include "utils.hpp"
#include <iostream>

using std::cout;
// using std::endl;

void test01() {
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  Node *head = create_linked_list(nums);

  // 打印链表
  print_linked_list(head->next);
}

void test02() {
  Node *n0 = new Node(1);
  Node *n1 = new Node(3);
  Node *n2 = new Node(2);
  Node *n3 = new Node(5);
  Node *n4 = new Node(4);

  n0->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;

  // 初始链表
  cout << "初始链表：";
  print_linked_list(n0);

  // 在 n2 后插入新节点 new_node
  Node *new_node = new Node(10);

  insert(n3, new_node);

  cout << "插入节点后的：";
  print_linked_list(n0);

  // 删除 n1 的下一个节点（n2）
  remove(n1);

  cout << "删除后的：";
  print_linked_list(n0);

  // 无效操作
  remove(n4);
}

int main() {
  // test01();
  test02();

  return 0;
}