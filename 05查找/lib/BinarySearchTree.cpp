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

  // target 小于当前节点值，向左寻找
  if (target < root->val) {
    return is_existed_recur(root->left, target);
  }
  // target 大于当前节点值，向右寻找
  else if (target > root->val) {
    return is_existed_recur(root->right, target);
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
    throw std::out_of_range("禁止插入重复节点！");
  }
}

/* 删除操作：递归实现 */
// 注意这里传入的是“指针的引用”，相当于是参数的“别名”
void bst::remove_recur(TreeNode *&root, int target) {
  if (root == nullptr) {
    throw std::out_of_range("没有目标节点！");
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
      // 找到右子树里最小的节点
      while (temp->left) {
        temp = temp->left;
      }
      root->val = temp->val;                // 替换节点
      remove_recur(root->right, temp->val); // 再删除 temp 节点
    }
    // 情况三：target 节点度为 1，把该节点替换为该节点的子节点即可
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
bool bst::is_existed_iter(TreeNode *root, int target) {
  if (root == nullptr) {
    return false;
  }

  while (root) {
    // 值小了，往左找
    if (target < root->val) {
      root = root->left;
    }
    // 值大了，往右找
    else if (target > root->val) {
      root = root->right;
    }
    // 相等，找到了
    else {
      return true;
    }
  }

  return false;
}

/* 插入操作：迭代插入 */
void bst::insert_iter(TreeNode *root, int target) {
  if (root == nullptr) {
    root = new TreeNode(target);
    return;
  }

  TreeNode *prev = nullptr; // 记录 root 的前一个节点
  // 循环完毕后，root 指向 nullptr
  while (root) {
    prev = root;
    if (target < root->val) {
      root = root->left;
    } else if (target > root->val) {
      root = root->right;
    } else {
      throw std::out_of_range("禁止插入重复节点！");
    }
  }

  root = new TreeNode(target);
  if (target < prev->val) {
    prev->left = root;
  } else {
    prev->right = root;
  }
}

/* 删除节点：迭代实现 */
// 这里只能出入 root 的引用，因为会涉及到删除根节点的情况
void bst::remove_iter(TreeNode *&root, int target) {
  TreeNode *prev = nullptr;
  TreeNode *curr = root;

  // 1. 找到目标节点
  while (curr && curr->val != target) {
    prev = curr;
    if (target < curr->val) {
      curr = curr->left;
    } else {
      curr = curr->right;
    }
  }

  if (curr == nullptr) {
    throw std::out_of_range("没有目标节点！");
  }

  // 2. 删除节点
  // 情况一：度为 0
  if (!curr->left && !curr->right) {
    if (prev == nullptr) {
      // 删除的是根节点
      delete curr;
      root = nullptr;
    } else {
      if (prev->left == curr)
        prev->left = nullptr;
      else
        prev->right = nullptr;
      delete curr;
    }
  }
  // 情况二：度为 2
  else if (curr->left && curr->right) {
    // 找右子树的最小节点
    TreeNode *p = curr;
    TreeNode *succ = curr->right;
    while (succ->left) {
      p = succ;
      succ = succ->left;
    }
    // 用后继节点值替换
    curr->val = succ->val;
    // 删除后继节点（succ 度一定是 0 或 1）
    if (p->left == succ) {
      p->left = succ->right;
    } else {
      p->right = succ->right;
    }
    delete succ;
  }
  // 情况三：度为 1
  else {
    TreeNode *child = (curr->left ? curr->left : curr->right);
    if (prev == nullptr) {
      // 删除的是根节点
      delete curr;
      root = child;
    } else {
      if (prev->left == curr)
        prev->left = child;
      else
        prev->right = child;
      delete curr;
    }
  }
}
