#include <iostream>
#include <vector>

/* 求两个等长升序序列的中位数 */
// 还是这种方式简单些，虽然时间复杂度和空间复杂度有点大
int get_mid_num(std::vector<int> &A, std::vector<int> &B) {

  std::vector<int> res;
  int i = 0, j = 0, n = A.size();

  while (i < n && j < n) {
    if (A[i] < B[j]) {
      res.push_back(A[i]);
      ++i;
    } else {
      res.push_back(B[j]);
      ++j;
    }
  }

  while (i < n) {
    res.push_back(A[i]);
    ++i;
  }

  while (j < n) {
    res.push_back(B[j]);
    ++j;
  }

  int mid = n - 1;

  return res[mid];
}

int main() {
  // A1 和 B1 均为奇数个元素
  std::vector<int> A1 = {11, 13, 15, 17, 19};
  std::vector<int> B1 = {2, 4, 6, 8, 20};

  std::cout << "A1 和 B1 的中位数：" << get_mid_num(A1, B1) << "\n";

  std::cout << "\n";

  // A2 和 B2 均为偶数个元素
  std::vector<int> A2 = {13, 15, 17, 19};
  std::vector<int> B2 = {4, 6, 8, 20};

  std::cout << "A1 和 B1 的中位数：" << get_mid_num(A2, B2) << "\n";
}