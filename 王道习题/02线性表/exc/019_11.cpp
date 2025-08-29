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

void test1() {
  std::cout << "测试一（A B 均为奇数个元素）：\n";

  // A 和 B 均为奇数个元素
  std::vector<int> A = {11, 13, 15, 17, 19};
  std::vector<int> B = {2, 4, 6, 8, 20};

  std::cout << "A 和 B 的中位数：" << get_mid_num(A, B) << "\n";

  std::cout << "\n";
}

void test2() {
  std::cout << "测试二（A B 均为偶数个元素）：\n";

  // A2 和 B2 均为偶数个元素
  std::vector<int> A = {13, 15, 17, 19};
  std::vector<int> B = {4, 6, 8, 20};

  std::cout << "A 和 B 的中位数：" << get_mid_num(A, B) << "\n";
}

int main() {
  test1();

  std::cout << "\n";

  test2();
}