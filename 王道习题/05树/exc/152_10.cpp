#include "tree.hpp"
#include <iostream>

// 递归实现
namespace way1 {
/* 查找二叉树中任意两个节点的最近公共祖先节点 */
tree1::Node<int> *get_nearest_ancestor(tree1::Node<int> *root, int p, int q) {
  if (!root) {
    return nullptr; // 表示没找到
  }

  // 如果根节点等于 p 节点或者 q 节点，那么说明根节点就是最近的公共祖先节点
  if (root->val == p || root->val == q) {
    return root;
  }

  tree1::Node<int> *left = get_nearest_ancestor(root->left, p, q);   // 往左子树找
  tree1::Node<int> *right = get_nearest_ancestor(root->right, p, q); // 往右子树找

  // 如果 p 节点和 q 节点分别在左右两边子树当中，那么最近祖先节点就是根节点
  if (left && right) {
    return root;
  }

  // 如果均在左子树或者右子树中，则返回对应子树的结果即可
  return left != nullptr ? left : right;
}
} // namespace way1

void test1() {
  std::cout << "测试一（递归实现）：\n";

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

  tree1::Node<int> *node = way1::get_nearest_ancestor(n0, 6, 5);
  std::cout << "6 和 5 的最近祖先节点为：" << node->val << "\n";
}

int main() {
  test1();

  std::cout << "\n";
}