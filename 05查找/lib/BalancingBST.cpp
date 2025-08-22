#include "BST/BalancingBST.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>

/* 中序遍历 */
void avl::in_order(avl::TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  in_order(root->left);
  std::cout << root->val << " ";
  in_order(root->right);
}

/* 释放内存 */
void avl::free_node(avl::TreeNode *&root) {
  if (root == nullptr) {
    return;
  }

  free_node(root->left);
  free_node(root->right);
  delete root;

  root = nullptr;
}

// --------------------------------------------------------------------------

/* 获取当前节点高度 */
int avl::get_height(avl::TreeNode *node) {

  // 空节点高度为 -1，叶节点高度为 0
  return node == nullptr ? -1 : node->height;
}

/* 更新节点高度 */
void avl::update_height(avl::TreeNode *node) {
  // 当前节点高度 = max(左子树高度, 右子树高度) + 1
  node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
}

/* 计算平衡因子 */
// 设平衡因子为 f，则一颗 AVL 树的任意节点的平衡因子均满足 -1 <= f <= 1
int avl::get_balanced_factor(avl::TreeNode *node) {
  // 空节点平衡因子为 0
  if (node == nullptr) {
    return 0;
  }

  // 节点的平衡因子定义为节点左子树的高度减去右子树的高度
  return get_height(node->left) - get_height(node->right);
}

// 旋转的一定是首个失衡节点（即 |f| > 1）
/* LL：右旋 */
avl::TreeNode *avl::rotate_right(avl::TreeNode *node) {
  avl::TreeNode *child = node->left;
  avl::TreeNode *grand_child = child->right;

  // 以 child 为原点，将 node 向右旋转
  child->right = node; // 这就是叫“右旋”的原因
  node->left = grand_child;

  // 更新节点高度
  update_height(node);
  update_height(child);

  // 返回旋转后的根节点
  return child;
}

/* RR：左旋 */
avl::TreeNode *avl::rotate_left(avl::TreeNode *node) {
  avl::TreeNode *child = node->right;
  avl::TreeNode *grand_child = child->left;

  // 以 child 为原点，将 node 向左旋转
  child->left = node; // 这就是叫“左旋”的原因
  node->right = grand_child;

  // 更新节点高度
  update_height(node);
  update_height(child);

  // 返回旋转后的根节点
  return child;
}

/* 旋转 */
avl::TreeNode *avl::rotate(avl::TreeNode *node) {

  // 获取节点 node 的平衡因子
  int balanced_factor = get_balanced_factor(node);

  // 左偏树（左高）
  if (balanced_factor > 1) {
    // 只右旋
    if (get_balanced_factor(node->left) >= 0) {
      return rotate_right(node);
    }
    // 先左旋，后右旋
    else {
      node->left = rotate_left(node->left);
      return rotate_right(node);
    }
  }

  // 右偏树（右高）
  if (balanced_factor < -1) {
    // 只左旋
    if (get_balanced_factor(node->right) <= 0) {
      return rotate_left(node);
    }
    // 先右旋，后左旋
    else {
      node->right = rotate_right(node->right);
      return rotate_left(node);
    }
  }

  // 平衡树，无需旋转
  return node;
}

/* 插入节点 */
void avl::insert(avl::TreeNode *&root, int target) {
  if (root == nullptr) {
    root = new avl::TreeNode(target);
    return;
  }

  // target 小于当前节点值，插入 root 的左子树
  if (target < root->val) {
    insert(root->left, target);
  }
  // target 大于当前节点值，插入 root 的右子树
  else if (target > root->val) {
    insert(root->right, target);
  } else {
    throw std::out_of_range("禁止插入重复节点！");
  }

  // 更新节点高度
  update_height(root);

  // 执行旋转操作
  root = rotate(root);
}

/* 删除节点 */
void avl::remove(avl::TreeNode *&root, int target) {
  if (root == nullptr) {
    throw std::out_of_range("没有目标节点！");
  }

  if (target < root->val) {
    remove(root->left, target);
  } else if (target > root->val) {
    remove(root->right, target);
  }
  // 找到目标节点时
  else {
    // 情况一：target 节点度为 0，直接删除即可
    if (root->left == nullptr && root->right == nullptr) {
      delete root;
      root = nullptr; // 置空
    }
    // 情况二：target 节点度为 2，无法直接删除它，而需要使用一个节点替换该节点
    else if (root->left && root->right) {
      avl::TreeNode *temp = root->right; // 往当前节点的右子树找（确保替换后仍是 BST）
      // 找到右子树里最小的节点
      while (temp->left) {
        temp = temp->left;
      }
      root->val = temp->val;          // 替换节点值
      remove(root->right, temp->val); // 再删除 temp 节点
    }
    // 情况三：target 节点度为 1，把该节点替换为该节点的子节点即可
    else {
      avl::TreeNode *child = root->left != nullptr ? root->left : root->right;
      delete root;
      root = child; // 更新父节点指向子节点
    }
  }

  if (root != nullptr) { // 确保 root 不是空指针
    // 更新节点高度
    update_height(root);

    // 执行旋转操作
    root = rotate(root);
  }
}
