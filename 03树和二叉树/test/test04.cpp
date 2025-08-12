#include "node/tree_node.hpp"
#include "node/utils.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(8);

  cout << "二叉树深度：" << max_depth(root) << endl;

  cout << "二叉树的叶节点数：" << leaf_count(root) << endl;

  free_tree_node(root);

  return 0;
}