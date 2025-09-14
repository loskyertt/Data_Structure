#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>

namespace EXC {
struct Node {
  char val;
  Node *next;
  Node(char x) : val(x), next(nullptr) {}
};

/* 数组转链表：带头节点 */
Node *create_linked_list(std::vector<char> &nums) {
  Node *head = new Node(0);
  Node *current = head;

  for (char num : nums) {
    Node *new_node = new Node(num);
    current->next = new_node;
    current = current->next;
  }

  return head;
}

/* 打印单链表 */
void print_linked_list(Node *head) {
  std::cout << "head -> ";

  while (head) {
    std::cout << head->val << " -> ";
    head = head->next;
  }

  std::cout << "nullptr\n";
}
} // namespace EXC

/* 找两个单链表的共同后缀 */
EXC::Node *get_same_suffix(EXC::Node *str1, EXC::Node *str2) {

  // 获取节点的长度
  std::function<int(EXC::Node *)> get_len = [](EXC::Node *node) -> int {
    int len = 0;
    while (node) {
      node = node->next;
      ++len;
    }

    return len;
  };

  // 从第一个有效节点开始
  str1 = str1->next;
  str2 = str2->next;

  // 分别获取 str1 和 str2 的长度
  int len1 = get_len(str1), len2 = get_len(str2);

  int step = std::abs(len1 - len2); // 让长的链表先走 k 步

  if (len1 > len2) {
    while (step > 0) {
      str1 = str1->next;
      --step;
    }
  } else {
    while (step > 0) {
      str2 = str2->next;
      --step;
    }
  }

  EXC::Node *record = nullptr;

  // 这时候两个链表一样长了
  while (str1) {
    if (str1->val == str2->val) {
      record = str1;
      while (str1 && str2 && str1->val == str2->val) {
        str1 = str1->next;
        str2 = str2->next;
      }

      // 如果链表走到头了，说明找到了共同后缀
      if (!str1) {
        return record;
      }

    } else {
      str1 = str1->next;
      str2 = str2->next;
    }
  }

  return nullptr;
}

void test1() {
  std::cout << "测试一：\n";

  // 这里以整形数据为例
  std::vector<char> letter1 = {'l', 'o', 'a', 'd', 'i', 'n', 'g'};
  std::vector<char> letter2 = {'b', 'e', 'i', 'n', 'g'};

  EXC::Node *head1 = EXC::create_linked_list(letter1);
  EXC::Node *head2 = EXC::create_linked_list(letter2);

  std::cout << "初始链表：\n";
  std::cout << "str1: ";
  EXC::print_linked_list(head1->next);
  std::cout << "str2: ";
  EXC::print_linked_list(head2->next);

  EXC::Node *suffix = get_same_suffix(head1, head2);
  if (suffix) {
    std::cout << "共同后缀为：";
    EXC::print_linked_list(suffix);
  } else {
    std::cout << "没有共同后缀！\n";
  }
}

void test2() {
  std::cout << "测试二：\n";

  // 这里以整形数据为例
  std::vector<char> letter1 = {'l', 'i', 'a', 'd', 'i', 'n', 'g'};
  std::vector<char> letter2 = {'b', 'e', 'o', 'n', 'g'};

  EXC::Node *head1 = EXC::create_linked_list(letter1);
  EXC::Node *head2 = EXC::create_linked_list(letter2);

  std::cout << "初始链表：\n";
  std::cout << "str1: ";
  EXC::print_linked_list(head1->next);
  std::cout << "str2: ";
  EXC::print_linked_list(head2->next);

  EXC::Node *suffix = get_same_suffix(head1, head2);
  if (suffix) {
    std::cout << "共同后缀为：";
    EXC::print_linked_list(suffix);
  } else {
    std::cout << "没有共同后缀！\n";
  }
}

void test3() {
  std::cout << "测试一：\n";

  // 这里以整形数据为例
  std::vector<char> letter1 = {'l', 'o', 'a', 'd', 'i', 'k', 'g'};
  std::vector<char> letter2 = {'b', 'e', 'i', 'n', 'i'};

  EXC::Node *head1 = EXC::create_linked_list(letter1);
  EXC::Node *head2 = EXC::create_linked_list(letter2);

  std::cout << "初始链表：\n";
  std::cout << "str1: ";
  EXC::print_linked_list(head1->next);
  std::cout << "str2: ";
  EXC::print_linked_list(head2->next);

  EXC::Node *suffix = get_same_suffix(head1, head2);
  if (suffix) {
    std::cout << "共同后缀为：";
    EXC::print_linked_list(suffix);
  } else {
    std::cout << "没有共同后缀！\n";
  }
}

int main() {
  test1();

  std::cout << "\n";

  test2();

  std::cout << "\n";

  test3();
}