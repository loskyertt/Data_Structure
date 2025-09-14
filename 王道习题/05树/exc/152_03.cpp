#include "tree.hpp"
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

/* 非递归求解链式二叉树高度 */
int get_height(tree1::Node<int> *root) {
  if (root == nullptr) {
    return 0;
  }

  int max_height = 0;
  std::queue<std::pair<tree1::Node<int> *, int>> q;
  q.push({root, 1});

  while (!q.empty()) {
    auto [node, height] = q.front();
    q.pop();
    max_height = std::max(max_height, height);

    if (node->left) {
      q.push({node->left, height + 1});
    }

    if (node->right) {
      q.push({node->right, height + 1});
    }
  }

  return max_height;
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

  std::cout << "该二叉树的高度为：" << get_height(n0) << "\n";
}

int main() {
  test1();
}