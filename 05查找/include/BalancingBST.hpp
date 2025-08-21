#pragma once

namespace bbst {

struct TreeNode {
  int val;
  int height = 0;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // explicit 防止隐式转换
};

/* 中序遍历 */
void in_order(TreeNode *root);

/* 释放内存 */
void free_node(TreeNode *root);

/* 获取当前节点高度 */
int get_height(TreeNode *node);

/* 更新节点高度 */
void update_height(TreeNode *node);

/* 计算平衡因子 */
int get_balanced_factor(TreeNode *node);

/* LL：右旋-旋转最右边的 */
TreeNode *rotate_right(TreeNode *node);

/* RR：左旋-旋转最左边的 */
TreeNode *rotate_left(TreeNode *node);

/* 旋转 */
TreeNode *rotate(TreeNode *node);

/* 插入节点 */
void insert(TreeNode *&root, int target);

/* 删除节点 */
void remove(TreeNode *&root, int target);

} // namespace bbst