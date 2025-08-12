#include "node/traverse.hpp"
#include "node/tree_node.hpp"
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <utility>

using std::cout;
using std::out_of_range;
using std::pair;
using std::queue;
using std::stack;

/* bfs 遍历 */
void level_order(TreeNode *root) {
  if (root == nullptr) {
    throw out_of_range("ERROR!");
  }

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    cout << node->val << " ";

    if (node->left) {
      q.push(node->left);
    }
    if (node->right) {
      q.push(node->right);
    }
  }

  cout << "\n";
}

// dfs
/* 前序遍历 */
void pre_order(TreeNode *root) {
  if (!root) {
    return;
  }

  cout << root->val << " ";
  pre_order(root->left);
  pre_order(root->right);
}

/* 中序遍历 */
void in_order(TreeNode *root) {
  if (!root) {
    return;
  }

  in_order(root->left);
  cout << root->val << " ";
  in_order(root->right);
}

/* 后序遍历 */
void post_order(TreeNode *root) {
  if (!root) {
    return;
  }

  post_order(root->left);
  post_order(root->right);
  cout << root->val << " ";
}

/* ----------------------------------- */

// dfs
/* 前序遍历：非递归实现 */
void pre_order_iter(TreeNode *root) {
  if (!root) {
    throw out_of_range("ERROR!");
  }

  stack<TreeNode *> stk;
  stk.push(root);

  while (!stk.empty()) {
    TreeNode *node = stk.top();
    stk.pop();

    cout << node->val << " ";

    // 根 -> 左 -> 右
    // 先放右子树，再放左子树（因为栈是后进先出，保证左子树先处理）
    if (node->right) {
      stk.push(node->right);
    }

    if (node->left) {
      stk.push(node->left);
    }
  }

  cout << "\n";
}

/* 中序遍历：非递归实现 */
void in_order_iter(TreeNode *root) {
  if (!root) {
    throw out_of_range("ERROR!");
  }

  stack<TreeNode *> stk;
  TreeNode *node = root;

  // 左 -> 根 -> 右
  while (!stk.empty() || node) {
    // 先把所有左子节点入栈
    while (node) {
      stk.push(node);
      node = node->left;
    }

    node = stk.top();
    stk.pop();
    cout << node->val << " ";

    // 再往右找
    node = node->right;
  }

  cout << "\n";
}

/* 后序遍历：非递归实现，方式一 */
void post_order_iter_01(TreeNode *root) {
  if (!root) {
    throw out_of_range("ERROR!");
  }

  stack<TreeNode *> stk1, stk2;
  stk1.push(root);

  while (!stk1.empty()) {
    TreeNode *node = stk1.top();
    stk1.pop();
    stk2.push(node); // 逆序存入 stk2（根 → 右 → 左）

    // 先把左子树压入 s1，因为一会儿要把左子树先从 s1 弹出，然后压入 s2
    if (node->left) {
      stk1.push(node->left);
    }
    if (node->right) {
      stk1.push(node->right);
    }
  }

  // 现在 s2 栈中存储的是 (根 → 右 → 左) 的逆序，即 (左 → 右 → 根)
  while (!stk2.empty()) {
    TreeNode *node = stk2.top();
    stk2.pop();

    cout << node->val << " ";
  }

  cout << "\n";
}

/* 后序遍历：非递归实现，方式二 */
void post_order_iter_02(TreeNode *root) {
  if (!root) {
    throw out_of_range("ERROR!");
  }

  stack<pair<TreeNode *, bool>> stk;
  stk.push({root, false});

  while (!stk.empty()) {
    auto [node, visited] = stk.top();
    stk.pop();

    // 如果没有处理过，把当前节点标记为处理过并重新压入栈，然后先压右子树，再压左子树
    if (!visited) {
      stk.push({node, true});

      if (node->right) {
        stk.push({node->right, false});
      }
      if (node->left) {
        stk.push({node->left, false});
      }
    } else {
      // 处理过就可以直接输出
      cout << node->val << " ";
    }
  }

  cout << "\n";
}