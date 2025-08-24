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

int main() {
  // m = 3, n = 2
  std::vector<int> nums1 = {1, 2, 3, 6, 7};

  // m = 3, n = 3
  std::vector<int> nums2 = {1, 2, 3, 6, 7, 8};

  // m = 2, n = 3
  std::vector<int> nums3 = {1, 2, 6, 7, 8};

  std::cout << "情况一：";
  swap_ele(nums1, 3, 2);
  print_vector(nums1);

  std::cout << "情况二：";
  swap_ele(nums2, 3, 3);
  print_vector(nums2);

  std::cout << "情况三：";
  swap_ele(nums3, 2, 3);
  print_vector(nums3);
}