#include "tree.hpp"
#include <iostream>
#include <queue>

/* 判断二叉树是否是完全二叉树 */
bool is_completed_bt(tree1::Node<int> *root) {
  if (root == nullptr)
    return true; // 空树是完全二叉树

  std::queue<tree1::Node<int> *> q;
  q.push(root);

  bool has_null = false; // 标记是否已经遇到空节点

  while (!q.empty()) {
    tree1::Node<int> *node = q.front();
    q.pop();

    if (node == nullptr) {
      has_null = true; // 标记已遇到空
    } else {
      // 当前节点非空
      if (has_null) {
        // 已经遇到过 null，现在又出现非空节点 → 不是完全二叉树
        return false;
      }
      // 正常入队左右子（即使是 null 也入）
      q.push(node->left);
      q.push(node->right);
    }
  }

  return true;
}

void test1() {
  std::cout << "测试一：\n";

  tree1::Node<int> *n0 = new tree1::Node<int>(0);
  tree1::Node<int> *n1 = new tree1::Node<int>(1);
  tree1::Node<int> *n2 = new tree1::Node<int>(2);
  tree1::Node<int> *n3 = new tree1::Node<int>(3);
  tree1::Node<int> *n4 = new tree1::Node<int>(4);
  tree1::Node<int> *n5 = new tree1::Node<int>(5);
  tree1::Node<int> *n6 = new tree1::Node<int>(6);

  n0->left = n1;
  n0->right = n2;
  n1->left = n3;
  n2->left = n4;
  n2->right = n5;
  n4->left = n6;

  if (is_completed_bt(n0)) {
    std::cout << "是完全二叉树！\n";
  } else {
    std::cout << "不是完全二叉树！\n";
  }
}

void test2() {
  std::cout << "测试二：\n";

  tree1::Node<int> *n0 = new tree1::Node<int>(0);
  tree1::Node<int> *n1 = new tree1::Node<int>(1);
  tree1::Node<int> *n2 = new tree1::Node<int>(2);
  tree1::Node<int> *n3 = new tree1::Node<int>(3);
  tree1::Node<int> *n4 = new tree1::Node<int>(4);
  tree1::Node<int> *n5 = new tree1::Node<int>(5);
  tree1::Node<int> *n6 = new tree1::Node<int>(6);

  n0->left = n1;
  n0->right = n2;
  n1->left = n3;
  n1->right = n4;
  n2->left = n5;
  n2->right = n6;

  if (is_completed_bt(n0)) {
    std::cout << "是完全二叉树！\n";
  } else {
    std::cout << "不是完全二叉树！\n";
  }
}

int main() {
  test1();

  std::cout << "\n";

  test2();
}