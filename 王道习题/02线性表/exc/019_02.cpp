#include "utils.hpp"
#include <iostream>
#include <utility>
#include <vector>

/* 逆置顺序表中的元素 */
void reverse(std::vector<int> &nums) {
  int i = 0, j = nums.size() - 1;

  while (i < j) {
    std::swap(nums[i], nums[j]);
    ++i;
    --j;
  }
}

int main() {
  // 奇数个元素
  std::vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};

  // 偶数个元素
  std::vector<int> nums2 = {1, 2, 3, 4, 5, 6};

  std::cout << "nums1 逆序后：";
  reverse(nums1);
  print_vector(nums1);

  std::cout << "\n";

  std::cout << "nums2 逆序后：";
  reverse(nums2);
  print_vector(nums2);
}