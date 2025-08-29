#include <algorithm>
#include <iostream>
#include <vector>

/* 寻找交集 */
void find_intersection(const std::vector<int> &A, const std::vector<int> &B, const std::vector<int> &C) {

  int n = A.size(); // A, B, C 数组的容量都一样

  // A, B, C 数组元素递增
  int i = 0, j = 0, k = 0; // i, j, k 分别指向 A, B, C 中的元素
  while (i < n && j < n && k < n) {
    if (A[i] == B[j] && B[j] == C[k]) {
      std::cout << A[i] << " ";
      ++i;
      ++j;
      ++k;
    } else {
      // 记录最大的元素
      int max_num = std::max({A[i], B[j], C[k]});
      // 只移动小的元素的指针（因为数组中的元素是递增的）
      if (A[i] < max_num) {
        ++i;
      }
      if (B[j] < max_num) {
        ++j;
      }
      if (C[k] < max_num) {
        ++k;
      }
    }
  }

  std::cout << "\n";
}

void test1() {
  std::cout << "测试一：\n";

  std::vector<int> A = {1, 2, 4, 6, 8};
  std::vector<int> B = {-1, 2, 4, 7, 8};
  std::vector<int> C = {2, 3, 4, 6, 8};

  std::cout << "A, B, C 的交集：";
  find_intersection(A, B, C);
}

int main() {
  test1();
}
