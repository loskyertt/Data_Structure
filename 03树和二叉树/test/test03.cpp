#include "node/traverse.hpp"
#include "node/tree_node.hpp"
#include "node/utils.hpp"
#include <iostream>

using std::cout;

// 链表实现的二叉树：遍历测试
int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->right->left = new TreeNode(7);

  cout << "bfs 遍历：";
  level_order(root);

  cout << "\n";

  cout << "前序遍历：";
  pre_order(root);

  cout << "\n";

  cout << "中序遍历：";
  in_order(root);

  cout << "\n";

  cout << "后序遍历：";
  post_order(root);

  cout << "\n\n";

  cout << "前序遍历（迭代实现）：";
  pre_order_iter(root);

  cout << "中序遍历（迭代实现）：";
  in_order_iter(root);

  cout << "后序遍历（迭代实现，双栈法）：";
  post_order_iter_01(root);

  cout << "后序遍历（迭代实现，标记法）：";
  post_order_iter_02(root);

  cout << "\n";

  // 释放节点（养成好习惯 \O/ ）
  free_tree_node(root);

  return 0;
}