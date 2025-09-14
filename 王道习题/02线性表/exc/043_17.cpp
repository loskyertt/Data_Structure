#include "node.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>

/* 查找链表倒数第 k 个节点 */
int get_reciprocal_k(Node *node, int k) {

  int count = k;

  Node *fast = node->next, *slow = node->next; // 从第一个有效节点开始

  while (fast && count > 0) {
    fast = fast->next;
    --count;
  }

  if (k < 0 || count > 0) {
    std::cout << "k 不符！\n";
    return 0; // 说明 k 不符合
  }

  while (fast) {
    fast = fast->next;
    slow = slow->next;
  }

  std::cout << "倒数第 " << k << " 个节点的值为：" << slow->val << "\n";

  return 1; // 成功找到
}

void test1() {
  std::cout << "测试一：\n";

  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
  Node *head = create_linked_list(nums);

  get_reciprocal_k(head, 2); // 输出：7
}

void test2() {
  std::cout << "测试二：\n";

  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
  Node *head = create_linked_list(nums);

  get_reciprocal_k(head, 1); // 输出：8
}

void test3() {
  std::cout << "测试三：\n";

  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
  Node *head = create_linked_list(nums);

  get_reciprocal_k(head, 8); // 输出：1
}

void test4() {
  std::cout << "测试四：\n";

  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
  Node *head = create_linked_list(nums);

  get_reciprocal_k(head, 9); // 无效 k
}

int main() {
  test1();

  std::cout << "\n";

  test2();

  std::cout << "\n";

  test3();

  std::cout << "\n";

  test4();
}