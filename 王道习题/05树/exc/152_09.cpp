#include "tree.hpp"
#include <cstddef>
#include <iostream>
#include <stack>
#include <vector>

// 回溯法实现
namespace way1 {
/* 打印值为 x 的节点的所有祖先节点 */
bool get_x_path(tree1::Node<int> *root, int x, std::vector<int> &path) {
  if (!root) {
    return false;
  }

  path.push_back(root->val);
  if (root->val == x) {
    return true;
  }

  if (get_x_path(root->left, x, path) || get_x_path(root->right, x, path)) {
    return true;
  }

  path.pop_back(); // 如果左右子树都没找到，说明当前节点不在路径上，进行回溯，弹出节点

  return false;
}
} // namespace way1

// 递归后序遍历实现
namespace way2 {
/* 打印值为 x 的节点的所有祖先节点 */
void get_x_path(tree1::Node<int> *root, int x) {
  if (!root) {
    return;
  }

  std::stack<tree1::Node<int> *> stk;
  std::stack<std::vector<int>> stk_path; // 记录路径
  stk.push(root);
  stk_path.push({root->val});

  while (!stk.empty()) {
    tree1::Node<int> *node = stk.top();
    stk.pop();
    std::vector<int> path = stk_path.top();
    stk_path.pop();

    // 找到目标节点
    if (node->val == x) {
      // 输出该节点路径（path 中的最后一个元素是值为 x 的节点，可以不输出）
      for (size_t i = 0; i < path.size() - 1; ++i) {
        std::cout << path[i] << " ";
      }
      break;
    }

    // 添加右子树的路径
    if (node->right) {
      stk.push(node->right);
      std::vector<int> right_path = path;
      right_path.push_back(node->right->val);
      stk_path.push(right_path);
    }

    // 添加左子树路径
    if (node->left) {
      stk.push(node->left);
      std::vector<int> left_path = path;
      left_path.push_back(node->left->val);
      stk_path.push(left_path);
    }
  }

  std::cout << "\n";
}
} // namespace way2

void test1() {
  std::cout << "测试一（回溯实现）：\n";

  tree1::Node<int> *n0 = new tree1::Node<int>(0);
  tree1::Node<int> *n1 = new tree1::Node<int>(1);
  tree1::Node<int> *n2 = new tree1::Node<int>(2);
  tree1::Node<int> *n3 = new tree1::Node<int>(3);
  tree1::Node<int> *n4 = new tree1::Node<int>(4);
  tree1::Node<int> *n5 = new tree1::Node<int>(5);
  tree1::Node<int> *n6 = new tree1::Node<int>(6);

  n0->left = n1;
  n0->right = n2;
  n1->left = n3;
  n2->left = n4;
  n2->right = n5;
  n4->left = n6;

  std::vector<int> path;
  way1::get_x_path(n0, 6, path);

  std::cout << "节点 6 的祖先节点为：";
  // 输出该节点路径（path 中的最后一个元素是值为 x 的节点，可以不输出）
  for (size_t i = 0; i < path.size() - 1; ++i) {
    std::cout << path[i] << " ";
  }

  std::cout << "\n";
}

void test2() {
  std::cout << "测试二（迭代实现）：\n";
  tree1::Node<int> *n0 = new tree1::Node<int>(0);
  tree1::Node<int> *n1 = new tree1::Node<int>(1);
  tree1::Node<int> *n2 = new tree1::Node<int>(2);
  tree1::Node<int> *n3 = new tree1::Node<int>(3);
  tree1::Node<int> *n4 = new tree1::Node<int>(4);
  tree1::Node<int> *n5 = new tree1::Node<int>(5);
  tree1::Node<int> *n6 = new tree1::Node<int>(6);

  n0->left = n1;
  n0->right = n2;
  n1->left = n3;
  n2->left = n4;
  n2->right = n5;
  n4->left = n6;

  std::cout << "节点 6 的祖先节点为：";
  way2::get_x_path(n0, 6);
}

int main() {
  test1();

  std::cout << "\n";

  test2();
}