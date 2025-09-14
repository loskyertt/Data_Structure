#include "node.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <iostream>
#include <unordered_set>
#include <vector>

/* 去重节点 */
void remove_duplicated_node(Node *node) {
  std::unordered_set<int> set;

  Node *prev = node; // 前驱节点
  node = node->next; // 从第一个有效节点开始

  while (node) {
    int num = std::abs(node->val);
    // 找到了
    if (set.find(num) != set.end()) {
      Node *temp = node;
      node = node->next;
      prev->next = node;
      delete temp;
    } else {
      // 把该数字加入集合中
      set.insert(num);
      prev = node;
      node = node->next;
    }
  }
}

void test1() {
  std::cout << "测试一：\n";

  std::vector<int> nums = {21, -15, 15, -7, 15};

  Node *head = create_linked_list(nums);

  std::cout << "初始链表：";
  print_linked_list(head->next);

  std::cout << "去重后的链表：";
  remove_duplicated_node(head);
  print_linked_list(head->next);
}

int main() {
  test1();
}