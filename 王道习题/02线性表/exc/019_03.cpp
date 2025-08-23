#include "utils.hpp"
#include <iostream>
#include <vector>

/* 删除顺序表中所有为 x 的元素 */
void remove_ele(std::vector<int> &nums, int x) {
  int i = 0;
  int n = nums.size();

  for (int j = 0; j < n; ++j) {
    // 把要删除的元素用后面的元素覆盖掉
    if (nums[j] != x) {
      nums[i] = nums[j];
      ++i;
    }
  }

  nums.resize(i);
}

int main() {
  std::vector<int> nums = {3, 5, 3, 2, 9, 10, 3, 4};

  // 删除元素 3
  std::cout << "删除 3 后的顺序表：";
  remove_ele(nums, 3);

  print_vector(nums);
}