#include "array/tree_array.hpp"
#include <climits>
#include <stack>
#include <stdexcept>
#include <utility>

using std::out_of_range;
using std::pair;
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

/* 中序遍历：迭代实现 */
vector<int> ArrayBinaryTree::in_order_iteration() {
  if (tree.empty() || val(0) == INT_MAX) {
    throw out_of_range("ERROR!");
  }

  vector<int> res;
  stack<int> nodeStack;

  int index = 0;

  // 只有当栈为空和索引超出数组范围时，才会退出循环
  while (!nodeStack.empty() || index < size()) {

    // 先让所有左子树的节点依次进栈，最后进的（最左边的）节点会先弹出
    while (val(index) != INT_MAX) {
      nodeStack.push(index);

      index = left(index);
    }

    index = nodeStack.top();
    nodeStack.pop();

    res.push_back(val(index));

    index = right(index);
  }

  return res;
}

/* 后序遍历：迭代实现，方式一，双栈法 */
vector<int> ArrayBinaryTree::post_order_iteration_1() {
  if (tree.empty() || val(0) == INT_MAX) {
    throw out_of_range("ERROR!");
  }

  vector<int> res;
  stack<int> nodeStack1, nodeStack2;
  nodeStack1.push(0);

  // nodeStack2 是用来反转 nodeStack1 中的节点的
  while (!nodeStack1.empty()) {
    int index = nodeStack1.top();
    nodeStack1.pop();
    nodeStack2.push(index);

    if (val(left(index)) != INT_MAX) {
      nodeStack1.push(left(index));
    }

    if (val(right(index)) != INT_MAX) {
      nodeStack1.push(right(index));
    }
  }

  while (!nodeStack2.empty()) {
    int index = nodeStack2.top();
    nodeStack2.pop();

    res.push_back(val(index));
  }

  return res;
}

/* 后序遍历：迭代实现，方式二，标记法 */
vector<int> ArrayBinaryTree::post_order_iteration_2() {
  if (tree.empty() || val(0) == INT_MAX) {
    throw out_of_range("ERROR!");
  }

  vector<int> res;
  stack<pair<int, bool>> nodeStack;
  nodeStack.push({0, false});

  while (!nodeStack.empty()) {
    /*
    显示表示法：
    pair<int, bool> top = stk.top();
    int index = top.first;
    bool visited = top.second;
    */
    auto [index, visited] = nodeStack.top();
    nodeStack.pop();

    // 如果还没访问过，把该节点标记为访问过，并把该节点的左右子树压入栈
    if (!visited) {
      nodeStack.push({index, true});

      if (val(right(index)) != INT_MAX) {
        nodeStack.push({right(index), false});
      }

      if (val(left(index)) != INT_MAX) {
        nodeStack.push({left(index), false});
      }
    } else {
      res.push_back(val(index));
    }
  }

  return res;
}