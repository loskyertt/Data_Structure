#include "node.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>

/* 检查链表 b 是否是 链表 a 的子序列 */
bool is_subsequence(Node *node_a, Node *node_b) {
  node_a = node_a->next;
  node_b = node_b->next;

  Node *curr_b = node_b;

  while (node_a) {
    if (node_a->val != node_b->val) {
      node_a = node_a->next;
    } else {
      while (curr_b && node_a && curr_b->val == node_a->val) {
        node_a = node_a->next;
        curr_b = curr_b->next;
      }
      if (curr_b == nullptr) {
        return true;
      } else {
        curr_b = node_b;
      }
    }
  }

  return false;
}

// 测试一
void test1() {
  std::cout << "测试一：\n";

  std::vector<int> nums_a = {1, 6, 8, 4, 2, 5, 6, 8, 3, 2, 4, 6};
  std::vector<int> nums_b = {6, 8, 3, 2};

  Node *node_a = create_linked_list(nums_a);
  Node *node_b = create_linked_list(nums_b);

  if (is_subsequence(node_a, node_b)) {
    std::cout << "b 是 a 的子序列！\n";
  } else {
    std::cout << "b 不是 a 的子序列！\n";
  }
}

// 测试二
void test2() {
  std::cout << "测试二：\n";

  std::vector<int> nums_a = {1, 6, 8, 4, 2, 5, 6, 8, 3, 2, 4, 6};
  std::vector<int> nums_b = {6, 7, 3, 2};

  Node *node_a = create_linked_list(nums_a);
  Node *node_b = create_linked_list(nums_b);

  if (is_subsequence(node_a, node_b)) {
    std::cout << "b 是 a 的子序列！\n";
  } else {
    std::cout << "b 不是 a 的子序列！\n";
  }
}

int main() {
  test1();

  std::cout << "\n";

  test2();
}