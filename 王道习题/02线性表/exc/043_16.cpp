#include "node.hpp"
#include "utils.hpp"
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

namespace way1 {
/* 求节点最大孪生和 */
int get_twins_sum(Node *L, int n) {
  int max_val = INT_MIN;
  Node *curr = L;

  int i = 0;
  while (i < n / 2) {
    Node *twin_node = L;
    int step = n - i - 1;
    // 移动到 i 节点的孪生节点
    while (step > 0) {
      twin_node = twin_node->next;
      --step;
    }

    max_val = std::max(max_val, curr->val + twin_node->val);
    curr = curr->next;
    ++i;
  }

  return max_val;
}
} // namespace way1

// 使用快慢指针
namespace way2 {

/* 反转链表 */
Node *reverse_l(Node *node) {
  Node *prev = nullptr, *curr = node;
  while (curr) {
    Node *temp = curr;
    curr = curr->next;
    temp->next = prev;
    prev = temp;
  }

  return prev;
}

/* 求节点最大孪生和 */
int get_twins_sum(Node *L) {
  Node *slow = L, *fast = L, *prev = nullptr;

  while (fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prev->next = nullptr;
  Node *last_half_node = reverse_l(slow);

  int max_val = INT_MIN;
  while (last_half_node) {
    max_val = std::max(max_val, last_half_node->val + L->val);
    last_half_node = last_half_node->next;
    L = L->next;
  }

  return max_val;
}
} // namespace way2

void test1() {
  std::cout << "测试一：\n";

  std::vector<int> nums = {2, 5, 8, 4, 6, 8};

  Node *head = create_linked_list(nums);

  std::cout << "最大孪生和为：" << way1::get_twins_sum(head->next, 6) << "\n";
}

void test2() {
  std::cout << "测试二：\n";

  std::vector<int> nums = {2, 5, 8, 4, 6, 8};

  Node *head = create_linked_list(nums);

  std::cout << "最大孪生和为：" << way2::get_twins_sum(head->next) << "\n";
}

void test3() {
  std::cout << "测试三：\n";

  std::vector<int> nums = {2, 8};

  Node *head = create_linked_list(nums);

  std::cout << "最大孪生和为：" << way1::get_twins_sum(head->next, 2) << "\n";
}

void test4() {
  std::cout << "测试四：\n";

  std::vector<int> nums = {2, 8};

  Node *head = create_linked_list(nums);

  std::cout << "最大孪生和为：" << way2::get_twins_sum(head->next) << "\n";
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