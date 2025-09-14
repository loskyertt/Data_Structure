#include <climits>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace EXC {
struct Node {
  int data;
  int freq; // 访问频度
  Node *prev;
  Node *next;
  Node(int x, int y = 0) : data(x), freq(y), prev(nullptr), next(nullptr) {}
};

/* 打印双链表 */
void print_linked_listD(Node *head) {
  std::cout << "head -> ";

  head = head->next;
  while (head) {
    std::cout << "[" << head->data << ", " << head->freq << "]" << " -> ";
    head = head->next;
  }

  std::cout << "nullptr\n";
}

/* 创建双链表 */
Node *create_linked_listD(std::vector<int> &nums) {
  Node *head = new Node(INT_MAX, INT_MAX); // 头节点是无效节点，保持频度最大即可
  Node *current = head;

  for (int val : nums) {
    Node *new_node = new Node(val);
    current->next = new_node;
    new_node->prev = current;
    current = current->next;
  }

  return head;
}
} // namespace EXC

/* 每访问值为 x 的元素，就让其对应的节点的 freq 加 1 */
void locate(EXC::Node *L, int x) {
  EXC::Node *current = L->next; // 从第一个有效节点开始
  // 找到 x 元素节点
  while (current && current->data != x) {
    current = current->next;
  }
  if (!current) {
    throw std::out_of_range("没有目标节点！");
  }
  current->freq += 1;

  // 找到应该插入的位置（第一个 freq < current->freq 的节点前）
  EXC::Node *pos = current->prev;
  while (pos != L && current->freq >= pos->freq) {
    pos = pos->prev;
  }

  // 如果需要移动
  if (current->prev != pos) {
    // 1. 断开 current
    current->prev->next = current->next;
    if (current->next)
      current->next->prev = current->prev;
    // 2. 插入到 pos 后面
    current->next = pos->next;
    if (pos->next)
      pos->next->prev = current;
    pos->next = current;
    current->prev = pos;
  }
}

void test1() {
  std::cout << "测试一：\n";

  std::vector<int> nums = {11, 12, 13, 14, 15, 16, 17, 18};
  EXC::Node *head = EXC::create_linked_listD(nums);

  std::cout << "初始链表：";
  EXC::print_linked_listD(head);

  std::cout << "\n";

  std::cout << "第一次访问：\n";
  locate(head, 14);
  EXC::print_linked_listD(head);

  std::cout << "\n";

  std::cout << "第二次访问：\n";
  locate(head, 12);
  EXC::print_linked_listD(head);

  std::cout << "\n";

  std::cout << "第三次访问：\n";
  locate(head, 17);
  EXC::print_linked_listD(head);

  std::cout << "\n";

  std::cout << "第四次访问：\n";
  locate(head, 12);
  EXC::print_linked_listD(head);

  std::cout << "\n";

  std::cout << "第五次访问：\n";
  locate(head, 12);
  EXC::print_linked_listD(head);
}

int main() {
  test1();
}