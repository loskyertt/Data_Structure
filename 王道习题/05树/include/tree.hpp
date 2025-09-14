#pragma once

#include <iostream>
#include <queue>

namespace tree1 {
template <typename T>
struct Node {
  T val;
  Node<T> *left;
  Node<T> *right;
  Node<T>(T x) : val(x), left(nullptr), right(nullptr) {}
};

/* 先序遍历 */
template <typename T>
void pre_order(Node<T> *root) {
  if (!root) {
    return;
  }

  std::cout << root->val << " ";
  pre_order(root->left);
  pre_order(root->right);
}

/* 中序遍历 */
template <typename T>
void in_order(Node<T> *root) {
  if (!root) {
    return;
  }

  in_order(root->left);
  std::cout << root->val << " ";
  in_order(root->right);
}

/* 后序遍历 */
template <typename T>
void post_order(Node<T> *root) {
  if (!root) {
    return;
  }

  post_order(root->left);
  post_order(root->right);
  std::cout << root->val << " ";
}

/* bfs 遍历 */
template <typename T>
void bfs(Node<T> *root) {
  if (!root) {
    return;
  }

  std::queue<Node<T> *> q;
  q.push(root);

  while (!q.empty()) {
    Node<T> *node = q.front();
    q.pop();

    if (node) {
      std::cout << node->val << " ";
      q.push(node->left);
      q.push(node->right);
    }
  }

  std::cout << "\n";
}
} // namespace tree1