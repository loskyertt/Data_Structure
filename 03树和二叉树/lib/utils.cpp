#include "node/utils.hpp"
#include <algorithm>

using std::max;

/* 释放节点：后序遍历（前序和中序不行！） */
void free_tree_node(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  free_tree_node(root->left);
  free_tree_node(root->right);

  delete root;
}

/* 求二叉树最大深度 */
int max_depth(TreeNode *root) {
  if (!root) {
    return 0;
  }

  // 二叉树深度 = max{左子树深度, 右子树深度} + 1，这个 1 是根节点
  return max(max_depth(root->left), max_depth(root->right)) + 1;
}

/* 求二叉树叶子节点个数 */
int leaf_count(TreeNode *root) {
  if (!root) {
    return 0;
  }

  // 左子节点和右子节点同时为空，说明该节点就是叶子节点
  if (!root->left && !root->right) {
    return 1;
  }

  // 全部叶节点 = 左子树的叶节点 + 右子树的叶节点
  return leaf_count(root->left) + leaf_count(root->right);
}