#include <climits>
#include <iostream>
#include <vector>

/* 获取顺序存储二叉树的最近祖先节点 */
int get_nearest_ancestor_node(const std::vector<int> &tree, int i, int j) {
  while (i != j && i != 0 && j != 0) {
    if (i > j) {
      i = (i - 1) / 2;
    } else {
      j = (j - 1) / 2;
    }
  }

  return i == 0 ? i : j; // 返回节点索引
}

void test1() {
  std::cout << "测试一：\n";

  std::vector<int> tree = {
      1, 2, 3, 4, 5,
      INT_MAX, 7, INT_MAX, INT_MAX, 6,
      INT_MAX, INT_MAX, INT_MAX, 8};

  int index = get_nearest_ancestor_node(tree, 9, 3);

  std::cout << "节点 6 和节点 4 的最近祖先节点为：" << tree[index] << "\n";
}

void test2() {
  std::cout << "测试二：\n";

  std::vector<int> tree = {
      1, 2, 3, 4, 5,
      INT_MAX, 7, INT_MAX, INT_MAX, 6,
      INT_MAX, INT_MAX, INT_MAX, 8};

  int index = get_nearest_ancestor_node(tree, 9, 13);

  std::cout << "节点 6 和节点 8 的最近祖先节点为：" << tree[index] << "\n";
}

int main() {
  test1();

  std::cout << "\n";

  test2();
}