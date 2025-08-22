#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void free_node(TreeNode *&node) {
  if (node == nullptr) {
    return;
  }

  free_node(node->left);
  free_node(node->right);

  delete node;
  node = nullptr;
}

void test01() {
  TreeNode *n0 = new TreeNode(1);
  TreeNode *n1 = new TreeNode(2);
  TreeNode *n2 = new TreeNode(3);

  n0->left = n1;
  n0->right = n2;

  free_node(n0);

  std::cout << "n0 指向的地址：" << n0 << "\n";
}

void test02() {
  TreeNode *n0 = new TreeNode(1);
  TreeNode *n1 = new TreeNode(2);
  TreeNode *n2 = new TreeNode(3);

  n0->left = n1;
  n0->right = n2;

  delete n1;

  std::cout << n0->left->val << "\n"; // 未定义行为
}

int main() {
  // test01();

  test02();
}