#include "BinarySearchTree.hpp"
#include <iostream>
#include <stdexcept>

using bst::TreeNode;

/* 中序遍历打印，正好是从小到大的顺序  */
void bst::in_order(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  in_order(root->left);
  std::cout << root->val << " ";
  in_order(root->right);
}

/* 释放内存 */
void bst::free_node(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  free_node(root->left);
  free_node(root->right);
  delete root;
}

// --------------------------------------------------------------------------

/* 查找操作：递归实现 */
bool bst::is_existed_recur(TreeNode *root, int target) {
  if (root == nullptr) {
    return false;
  }

  // target 小于当前节点值，向右寻找
  if (target < root->val) {
    return is_existed_recur(root->right, target);
  }
  // target 大于当前节点值，向左寻找
  else if (target > root->val) {
    return is_existed_recur(root->left, target);
  }
  // 等于就直接返回
  else {
    return true;
  }
}

/* 插入节点：递归实现 */
void bst::insert_recur(TreeNode *&root, int target) {
  if (root == nullptr) {
    root = new TreeNode(target);
    return;
  }

  // target 小于当前节点值，插入 root 的左子树
  if (target < root->val) {
    insert_recur(root->left, target);
  }
  // target 大于当前节点值，插入 root 的右子树
  else if (target > root->val) {
    insert_recur(root->right, target);
  } else {
    return;
  }
}

/* 删除操作：递归实现 */
// 注意这里传入的是“指针的引用”，相当于是参数的“别名”
void bst::remove_recur(TreeNode *&root, int target) {
  if (root == nullptr) {
    throw std::out_of_range("树为空！");
  }

  if (target < root->val) {
    remove_recur(root->left, target);
  } else if (target > root->val) {
    remove_recur(root->right, target);
  }
  // 找到目标节点时
  else {
    // 情况一：target 节点度为 0，直接删除即可
    if (root->left == nullptr && root->right == nullptr) {
      delete root;
      // 要把 root 指针置空，否则就成了悬空指针（root 的父节点没有指向）
      root = nullptr;
    }
    // 情况二：target 节点度为 2，无法直接删除它，而需要使用一个节点替换该节点
    else if (root->left && root->right) {
      TreeNode *temp = root->right; // 往当前节点的右子树找（确保替换后仍是 BST）
      // 再一直往左子树找，当左子树为空时，退出循环，此时该节点 temp 就是要用来替换 curr 的节点
      while (temp->left) {
        temp = temp->left;
      }
      root->val = temp->val;                // 替换节点
      remove_recur(root->right, temp->val); // 再删除 temp 节点
    }
    // 情况三：target 节点度为 1，把该节点替换为该节点的子节点即可1
    else {
      TreeNode *child = root->left != nullptr ? root->left : root->right;
      delete root;
      // 让 root 指向 child 的地址
      root = child;
    }
  }
}

// --------------------------------------------------------------------------

/* 查找操作：迭代实现 */
bool bst::is_existed_iter(TreeNode *root, int val);

/* 插入操作：迭代插入 */
void bst::insert_iter(TreeNode *&root, int val);

/* 删除节点：迭代实现 */
void bst::remove_iter(TreeNode *root, int num);
