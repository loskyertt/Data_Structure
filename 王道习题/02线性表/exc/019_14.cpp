#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

/* 方式一：暴力求解，时间复杂度直接炸了 */
namespace way1 {
/* 求三元组最短距离 */
int get_min_dist(const std::vector<int> &A, const std::vector<int> &B, const std::vector<int> &C) {

  int dist = INT_MAX;

  // 三个数组中的元素都是递增的
  for (int val_a : A) {
    for (int val_b : B) {
      for (int val_c : C) {
        dist = std::min(dist, abs(val_a - val_b) + abs(val_b - val_c) + abs(val_c - val_a));
      }
    }
  }

  return dist;
}
} // namespace way1

/* 方式二：三指针法 */
namespace way2 {
/* 求三元组最短距离 */
int get_min_dist(const std::vector<int> &A, const std::vector<int> &B, const std::vector<int> &C) {

  int min_dist = INT_MAX;

  // 三个指针分别指向 A B C 中的元素
  int i = 0, j = 0, k = 0;
  while (i < A.size() && j < B.size() && k < C.size()) {
    int a = A[i], b = B[j], c = C[k];

    int min_val = std::min({a, b, c});
    int max_val = std::max({a, b, c});
    int dist = 2 * (max_val - min_val);

    min_dist = std::min(dist, min_dist);

    // 移动指向最小值的指针
    if (a == min_val) {
      ++i;
    } else if (b == min_val) {
      ++j;
    } else {
      ++k;
    }
  }

  return min_dist;
}
} // namespace way2

int main() {
  std::vector<int> A1 = {-1, 0, 9};
  std::vector<int> B1 = {-25, -10, 10, 11};
  std::vector<int> C1 = {2, 9, 17, 30, 41};

  std::cout << "A1 B1 C1 最小距离（方式一）：" << way1::get_min_dist(A1, B1, C1) << "\n";
  std::cout << "A1 B1 C1 最小距离（方式二）：" << way2::get_min_dist(A1, B1, C1) << "\n";
}