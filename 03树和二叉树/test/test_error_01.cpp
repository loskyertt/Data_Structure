#include "array/tree_array.hpp"
#include <climits>
#include <iostream>

// 测试 in_order_iteration
int main() {
  vector<int> arr = {
      1,
      INT_MAX, // left child empty
      2,
      INT_MAX, INT_MAX, // children of index 1 (ignored)
      3                 // left child of index 2
  };

  ArrayBinaryTree tree = ArrayBinaryTree(arr);

  vector<int> res = tree.in_order_iteration();

  for (int val : res) {
    std::cout << val << " ";
  }

  return 0;
}