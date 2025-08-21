#include "BalancingBST.hpp"
#include <iostream>
#include <vector>

/* 测试 AVL 树的操作 */
int main() {
  std::vector<int> nums = {
      2,
      4,
      1,
      5,
      7,
      10,
      11,
      14,
      8,
      6,
      3,
  };

  bbst::TreeNode *root = nullptr;
  // 构造 AVL 树
  for (int num : nums) {
    bbst::insert(root, num);
  }

  std::cout << "AVL 树：";
  bbst::in_order(root);
  std::cout << "\n\n";

  // 删除节点 7
  bbst::remove(root, 7);
  std::cout << "删除节点 7：";
  bbst::in_order(root);
  std::cout << "\n\n";

  // 删除节点 1
  bbst::remove(root, 1);
  std::cout << "删除节点 1：";
  bbst::in_order(root);
  std::cout << "\n\n";

  // 删除节点 5
  bbst::remove(root, 5);
  std::cout << "删除节点 5：";
  bbst::in_order(root);
  std::cout << "\n\n";

  // 删除节点 11
  bbst::remove(root, 11);
  std::cout << "删除节点 11：";
  bbst::in_order(root);
  std::cout << "\n\n";

  // 释放内存
  bbst::free_node(root);

  return 0;
}