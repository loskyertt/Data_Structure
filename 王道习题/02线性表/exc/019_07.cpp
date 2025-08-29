#include "utils.hpp"
#include <iostream>
#include <utility>
#include <vector>

/* [a1, a2, b1, b2, b3] -> [b1, b2, b3, a1, a2]*/
void swap_ele(std::vector<int> &nums, int m, int n) {
  // 先把整个数组元素逆序
  int i = 0, j = nums.size() - 1;
  while (i < j) {
    std::swap(nums[i], nums[j]);
    ++i;
    --j;
  }

  // 把 bi 逆序
  int i_b = 0, j_b = n - 1;
  while (i_b < j_b) {
    std::swap(nums[i_b], nums[j_b]);
    ++i_b;
    --j_b;
  }

  // 把 ai 逆序
  int i_a = n, j_a = nums.size() - 1;
  while (i_a < j_a) {
    std::swap(nums[i_a], nums[j_a]);
    ++i_a;
    --j_a;
  }
}

void test1() {
  std::cout << "测试一：\n";

  // m = 3, n = 2
  std::vector<int> nums = {1, 2, 3, 6, 7};

  swap_ele(nums, 3, 2);
  print_vector(nums);
}

void test2() {
  std::cout << "测试二：";

  // m = 3, n = 3
  std::vector<int> nums = {1, 2, 3, 6, 7, 8};

  swap_ele(nums, 3, 3);
  print_vector(nums);
}

void test3() {
  std::cout << "测试三：";

  // m = 2, n = 3
  std::vector<int> nums = {1, 2, 6, 7, 8};

  swap_ele(nums, 2, 3);
  print_vector(nums);
}

int main() {
  test1();

  std::cout << "\n";

  test2();

  std::cout << "\n";

  test3();
}