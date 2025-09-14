#include "tree.hpp"
#include <functional>
#include <iostream>

/* 求二叉树先序遍历序列中第 k 个节点的值 */
int get_k_node(tree1::Node<int> *root, int k) {

  int count = 0;
  int val = -1;

  std::function<void(tree1::Node<int> *)> pre_order = [&](tree1::Node<int> *root) {
    if (!root) {
      return;
    }

    ++count;
    if (count == k) {
      val = root->val;
      return;
    }

    pre_order(root->left);
    pre_order(root->right);
  };

  pre_order(root);

  return val; // 返回值
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

  std::cout << "先序遍历的第 4 个值是：" << get_k_node(n0, 4) << "\n";
}

int main() {
  test1();
}