#pragma once

#include "tree_node.hpp"

/* 释放节点 */
void free_tree_node(TreeNode *root);

/* 求二叉树最大深度 */
int max_depth(TreeNode *root);

/* 求二叉树叶子节点个数 */
int leaf_count(TreeNode *root);