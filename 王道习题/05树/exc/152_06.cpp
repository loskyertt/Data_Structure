#include "tree.hpp"
#include <iostream>

/* 交换二叉树的左右孩子节点 */
void swap(tree1::Node<int> *node) {
  tree1::Node<int> *temp = node->left;
  node->left = node->right;
  node->right = temp;
}

/* 交换二叉树中的所有左右子树 */
void swap_tree_node(tree1::Node<int> *root) {
  if (!root) {
    return;
  }

  swap_tree_node(root->left);  // 先交换左子树
  swap_tree_node(root->right); // 再交换右子树

  swap(root); // 交换左右孩子节点
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

  std::cout << "初始二叉树：\n";

  std::cout << "中序：";
  tree1::in_order(n0);

  std::cout << "\n";

  std::cout << "后序：";
  tree1::post_order(n0);

  std::cout << "\n";

  std::cout << "交换节点后的二叉树：\n";
  swap_tree_node(n0);

  std::cout << "中序：";
  tree1::in_order(n0);

  std::cout << "\n";

  std::cout << "后序：";
  tree1::post_order(n0);
}

int main() {
  test1();
}