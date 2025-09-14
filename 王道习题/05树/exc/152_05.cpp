#include "tree.hpp"
#include <iostream>
#include <queue>

// 迭代实现
namespace way1 {
/* 计算一颗给定二叉树的所有双分支节点数（度为 2 的节点数） */
int count_double_branch_nodes(tree1::Node<int> *root) {

  int count = 0;

  std::queue<tree1::Node<int> *> q;
  q.push(root);

  while (!q.empty()) {
    tree1::Node<int> *node = q.front();
    q.pop();

    if (node) {
      // 如果有左右孩子节点
      if (node->left && node->right) {
        ++count;
      }

      q.push(node->left);
      q.push(node->right);
    }
  }

  return count;
}
} // namespace way1

// 递归实现
namespace way2 {
/* 计算一颗给定二叉树的所有双分支节点数（度为 2 的节点数） */
int count_double_branch_nodes(tree1::Node<int> *root) {
  if (!root) {
    return 0;
  } else if (root->left && root->right) {
    return count_double_branch_nodes(root->left) + count_double_branch_nodes(root->right) + 1;
  } else {
    return count_double_branch_nodes(root->left) + count_double_branch_nodes(root->right);
  }
}
} // namespace way2

void test1() {
  std::cout << "测试一（迭代实现）：\n";

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

  std::cout << "度为 2 的节点数为：" << way1::count_double_branch_nodes(n0) << "\n";
}

void test2() {
  std::cout << "测试二（迭代实现）：\n";

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

  std::cout << "度为 2 的节点数为：" << way1::count_double_branch_nodes(n0) << "\n";
}

void test3() {
  std::cout << "测试三（递归实现）：\n";

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

  std::cout << "度为 2 的节点数为：" << way2::count_double_branch_nodes(n0) << "\n";
}

void test4() {
  std::cout << "测试四（递归实现）：\n";

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

  std::cout << "度为 2 的节点数为：" << way2::count_double_branch_nodes(n0) << "\n";
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