#include "utils.hpp"
#include <iostream>
#include <vector>

/* 删除 [s, t] 这个大小区间的数 */
void remove_ele(std::vector<int> &nums, int s, int t) {
  int i = 0;
  int n = nums.size();

  for (int j = 0; j < n; ++j) {
    if (nums[j] < s || nums[j] > t) {
      nums[i] = nums[j];
      ++i;
    }
  }

  nums.resize(i);
}

int main() {
  std::vector<int> nums = {3, 5, 3, 2, 9, 10, 3, 4};

  // 删除元素 3
  std::cout << "删除 [2, 4] 之间的顺序表：";
  remove_ele(nums, 2, 4);

  print_vector(nums);

  std::cout << "\n";
}