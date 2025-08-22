#include "BST/BinarySearchTree.hpp"
#include <iostream>

/* 测试二叉搜索树的操作（迭代实现） */
int main() {
  bst::TreeNode *root = new bst::TreeNode(8);
  root->left = new bst::TreeNode(4);
  root->right = new bst::TreeNode(12);
  root->left->left = new bst::TreeNode(2);
  root->left->right = new bst::TreeNode(6);
  root->right->left = new bst::TreeNode(10);

  std::cout << "初始二叉树：";
  bst::in_order(root);
  std::cout << "\n\n";

  // 查找节点
  if (bst::is_existed_iter(root, 4)) {
    std::cout << "节点 4 存在！\n\n";
  } else {
    std::cout << "节点 4 不存在！\n\n";
  }

  // 插入节点 7
  bst::insert_iter(root, 7);
  std::cout << "插入节点 7：";
  bst::in_order(root);
  std::cout << "\n\n";

  // 插入节点 13
  bst::insert_iter(root, 13);
  std::cout << "插入节点 13：";
  bst::in_order(root);
  std::cout << "\n\n";

  // 删除节点 2（度为 0）
  bst::remove_iter(root, 2);
  std::cout << "删除节点 2：";
  bst::in_order(root);
  std::cout << "\n\n";

  // 删除节点 6（度为 1，右子节点是 7）
  bst::remove_iter(root, 6);
  std::cout << "删除节点 6：";
  bst::in_order(root);
  std::cout << "\n\n";

  // 删除节点 12（度为 2，左子节点是 10，右子节点是 13）
  bst::remove_iter(root, 12);
  std::cout << "删除节点 12：";
  bst::in_order(root);
  std::cout << "\n\n";

  // 删除根节点 8（度为 2，左子节点是 4，右子节点是12）
  bst::remove_iter(root, 8);
  std::cout << "删除节点 8：";
  bst::in_order(root);
  std::cout << "\n\n";

  // 释放内存
  bst::free_node(root);

  return 0;
}