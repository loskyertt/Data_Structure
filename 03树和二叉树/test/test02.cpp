#include "array/tree_array.hpp"
#include <climits>
#include <iostream>

using std::cout;

// 数组实现的二叉树：遍历测试
int main() {
  vector<int> arr = {40, 25, 60, INT_MAX, 30, INT_MAX, 80, INT_MAX, INT_MAX, 27};

  ArrayBinaryTree tree(arr);

  // bfs 遍历
  cout << "bfs 遍历：";

  vector<int> bfs_res = tree.levelOrder();

  for (int val : bfs_res) {
    cout << val << " ";
  }

  cout << "\n";

  // dfs 遍历
  // 前序遍历
  cout << "前序遍历：";

  vector<int> pre_res = tree.pre_order();

  for (int val : pre_res) {
    cout << val << " ";
  }

  cout << "\n";

  // 中1序遍历
  cout << "中序遍历：";

  vector<int> in_res = tree.in_order();

  for (int val : in_res) {
    cout << val << " ";
  }

  cout << "\n";

  // 后序遍历
  cout << "后序遍历：";

  vector<int> post_res = tree.post_order();

  for (int val : post_res) {
    cout << val << " ";
  }

  cout << "\n";

  // 前序遍历（迭代实现）
  cout << "前序遍历（迭代实现）：";

  vector<int> pre_iter_res = tree.pre_order_iteration();

  for (int val : pre_iter_res) {
    cout << val << " ";
  }

  cout << "\n";

  // 中序遍历（迭代实现）
  cout << "中序遍历（迭代实现）：";

  vector<int> in_iter_res = tree.in_order_iteration();

  for (int val : in_iter_res) {
    cout << val << " ";
  }

  cout << "\n";

  // 后序遍历（迭代实现，方式一）
  cout << "后序遍历（迭代实现，方式一）：";

  vector<int> post_iter_res1 = tree.post_order_iteration_1();

  for (int val : post_iter_res1) {
    cout << val << " ";
  }

  cout << "\n";

  // 后序遍历（迭代实现，方式二）
  cout << "后序遍历（迭代实现，方式二）：";

  vector<int> post_iter_res2 = tree.post_order_iteration_2();

  for (int val : post_iter_res2) {
    cout << val << " ";
  }

  cout << "\n";

  return 0;
}
