#include "node.hpp"
#include "utils.hpp"
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

/* 方式一：暴力求解 */
namespace way1 {
/* 删除链表中最小值的节点（该节点唯一） */
void remove_min_node(Node *node) {
  int min_val = INT_MAX;

  // 找出最小值
  Node *curr = node->next;
  while (curr) {
    min_val = std::min(min_val, curr->val);
    curr = curr->next;
  }

  Node *prev = node;
  while (node) {
    if (node->val == min_val) {
      Node *temp = node;
      node = temp->next;
      prev->next = node;
      delete temp;
    } else {
      prev = node;
      node = node->next;
    }
  }
}
} // namespace way1

/* 方式二：双重指针 */
namespace way2 {
/* 删除链表中最小值的节点（该节点唯一） */
void remove_min_node(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return; // 空链表或只有头节点
  }

  Node *prev_min = head;       // 最小值节点的前驱
  Node *curr_min = head->next; // 最小值节点
  Node *prev = head;
  Node *curr = head->next;

  // 遍历找到最小值节点及其前驱
  while (curr) {
    if (curr->val < curr_min->val) {
      prev_min = prev;
      curr_min = curr;
    }
    prev = curr;
    curr = curr->next;
  }

  // 删除最小值节点
  prev_min->next = curr_min->next;
  delete curr_min;
}
} // namespace way2

void test1() {
  std::cout << "测试一：\n";

  // 方式一
  std::vector<int> nums = {1, 4, 3, 6, 7, 5, 2};

  // 数组转链表（带头节点：INT_MAX 作为头节点标识）
  Node *head = create_linked_list(nums);

  // 当前链表
  std::cout << "初始链表：";
  print_linked_list(head->next);

  std::cout << "删除最小值后链表（方式一）：";
  way1::remove_min_node(head);
  print_linked_list(head->next);
}

void test2() {
  std::cout << "测试二：\n";

  // 方式二
  std::vector<int> nums = {1, 4, 3, 6, 7, 5, 2};

  // 数组转链表（带头节点：INT_MAX 作为头节点标识）
  Node *head = create_linked_list(nums);

  // 当前链表
  std::cout << "初始链表：";
  print_linked_list(head->next);

  std::cout << "删除最小值后链表（方式二）：";
  way2::remove_min_node(head);
  print_linked_list(head->next);
}

int main() {
  std::cout << "\n";
}