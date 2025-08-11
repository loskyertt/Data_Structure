#include "array/tree_array.hpp"
#include <climits>
#include <stack>
#include <stdexcept>

using std::out_of_range;
using std::stack;

// private:
/* dfs 遍历 */
void ArrayBinaryTree::dfs(vector<int> &res, string order, int index) {
  if (val(index) == INT_MAX) {
    return;
  }

  if (order == "pre") {
    res.push_back(val(index));
  }

  dfs(res, order, left(index));

  if (order == "in") {
    res.push_back(val(index));
  }

  dfs(res, order, right(index));

  if (order == "post") {
    res.push_back(val(index));
  }
}

ArrayBinaryTree::ArrayBinaryTree(vector<int> arr) {
  tree = arr;
}

/* 列表容量 */
int ArrayBinaryTree::size() {
  return tree.size();
}

/* 获取索引为 i 节点的值 */
int ArrayBinaryTree::val(int i) {
  if (i < 0 || i >= size()) {
    return INT_MAX;
  }
  return tree[i];
}

/* 获取索引为 i 节点的左子节点的索引 */
int ArrayBinaryTree::left(int i) {
  return 2 * i + 1;
}

/* 获取索引为 i 节点的右子节点的索引 */
int ArrayBinaryTree::right(int i) {
  return 2 * i + 2;
}

/* 获取索引为 i 节点的父节点的索引 */
int ArrayBinaryTree::parent(int i) {
  return (i - 1) / 2;
}

/* bfs */
vector<int> ArrayBinaryTree::levelOrder() {
  vector<int> res;
  for (int val : tree) {
    if (val != INT_MAX) {
      res.push_back(val);
    }
  }

  return res;
}

/* dfs */
/* 前序遍历 */
vector<int> ArrayBinaryTree::pre_order() {
  vector<int> res;

  dfs(res, "pre", 0);

  return res;
}

/* 中序遍历 */
vector<int> ArrayBinaryTree::in_order() {
  vector<int> res;

  dfs(res, "in", 0);

  return res;
}

/* 后序遍历 */
vector<int> ArrayBinaryTree::post_order() {
  vector<int> res;

  dfs(res, "post", 0);

  return res;
}

/* 前序遍历：迭代实现 */
vector<int> ArrayBinaryTree::pre_order_iteration() {
  if (tree.empty() || val(0) == INT_MAX) {
    throw out_of_range("ERROR!");
  }

  vector<int> res;
  stack<int> nodeStack;

  nodeStack.push(0);
  while (!nodeStack.empty()) {
    int index = nodeStack.top();
    nodeStack.pop();

    if (val(index) == INT_MAX) {
      continue;
    }

    res.push_back(val(index));

    nodeStack.push(right(index));
    nodeStack.push(left(index));
  }

  return res;
}