#pragma once

namespace bst {
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 中序遍历打印，正好是从小到大的顺序  */
void in_order(bst::TreeNode *root);

/* 释放内存 */
void free_node(bst::TreeNode *root);

/* 查找操作：递归实现 */
bool is_existed_recur(TreeNode *root, int target);

/* 插入节点：递归实现 */
void insert_recur(TreeNode *&root, int target);

/* 删除操作：递归实现 */
void remove_recur(TreeNode *&root, int target);

/* 查找操作：迭代实现 */
bool is_existed_iter(TreeNode *root, int target);

/* 插入操作：迭代插入 */
void insert_iter(TreeNode *root, int target);

/* 删除节点：迭代实现 */
void remove_iter(TreeNode *&root, int target);

} // namespace bst
