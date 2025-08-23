#include "utils.hpp"
#include "node.hpp"
#include <climits>
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::out_of_range;

/* 打印链表 */
void print_linked_list(Node *head) {
  cout << "head -> ";

  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }

  cout << "nullptr" << endl;
}

/* 数组转链表 */
Node *create_linked_list(vector<int> &nums) {
  // 带头节点
  Node *head = new Node(INT_MAX);
  Node *current = head;

  for (int num : nums) {
    Node *new_node = new Node(num);
    current->next = new_node;
    current = current->next;
  }

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
    throw out_of_range("没有节点可删除！");
  }

  Node *temp = n0->next;
  n0->next = temp->next;

  delete temp;
}

/* 打印数组 */
void print_vector(const vector<int> &nums) {
  if (nums.empty()) {
    throw out_of_range("数组为空！");
  }

  for (int val : nums) {
    cout << val << " ";
  }
  cout << "\n";
}