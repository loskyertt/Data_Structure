#include "array/tree_array.hpp"
#include <climits>
#include <iostream>

using std::cout;
using std::endl;

// 基本功能测试
int main() {
  vector<int> arr = {40, 25, 60, INT_MAX, 30, INT_MAX, 80, INT_MAX, INT_MAX, 27};

  ArrayBinaryTree tree(arr);

  cout << "实际占用数组大小：" << tree.size() << endl;

  // 节点 60 的左右子节点
  cout << "节点 60 的左右子节点：" << endl;

  int left = tree.left(2);

  cout << "左子节点：" << tree.val(left) << endl;

  int right = tree.right(2);

  cout << "右子节点：" << tree.val(right) << endl;

  // 节点 27 的父节点
  int parent = tree.parent(9);

  cout << "节点 27 的父节点：" << tree.val(parent) << endl;

  return 0;
}