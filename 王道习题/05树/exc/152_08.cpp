#include "tree.hpp"
#include <functional>
#include <iostream>
#include <queue>

/* 删除以元素值 x 为根的子树，及 x 节点 */
void delete_target_node(tree1::Node<int> *root, int x) {

  if (!root) {
    return;
  }

  std::function<void(tree1::Node<int> *)> free_node = [&](tree1::Node<int> *node) {
    if (!node) {
      return;
    }

    // 后序遍历删除
    free_node(node->left);
    free_node(node->right);
    delete node;
  };

  // 如果删除的是根节点，直接删除整棵树，然后退出
  if (root->val == x) {
    free_node(root);
    return;
  }

  std::queue<tree1::Node<int> *> q;
  q.push(root);

  while (!q.empty()) {
    tree1::Node<int> *node = q.front();
    q.pop();

    // 这种判断可以避免值为 x 的节点的父节点指向不合法的内存区域
    if (node->left) {
      if (node->left->val == x) {
        tree1::Node<int> *temp = node->left;
        node->left = nullptr; // 让父节点指向 nullptr
        free_node(temp);
      } else {
        q.push(node->left);
      }
    }

    if (node->right) {
      if (node->right->val == x) {
        tree1::Node<int> *temp = node->right;
        node->right = nullptr;
        free_node(temp);
      } else {
        q.push(node->right);
      }
    }
  }
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

  std::cout << "初始二叉树：";
  tree1::bfs(n0);

  std::cout << "删除目标节点及子树的二叉树：";
  delete_target_node(n0, 2);
  tree1::bfs(n0);
}

int main() {
  test1();
}