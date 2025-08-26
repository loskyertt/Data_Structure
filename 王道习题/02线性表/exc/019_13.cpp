#include <algorithm>
#include <iostream>
#include <vector>

/* 找出数组中从未出现的最小正整数 */
int find_num(const std::vector<int> &nums) {
  if (nums.empty()) {
    return 1;
  }

  int max_val = *std::max_element(nums.begin(), nums.end());

  // 如果最大正数都小于1，说明没有正数
  if (max_val < 1) {
    return 1;
  }

  // 创建大小为 max_val + 1 的数组，用于标记 1 ~ max_val 是否出现
  std::vector<bool> present(max_val + 1, false); // 更语义化：用 bool

  for (int num : nums) {
    if (num > 0) {
      present[num] = true; // 标记 num 出现
    }
  }

  // 找第一个未出现的正整数
  for (int i = 1; i <= max_val; ++i) {
    if (!present[i]) {
      return i;
    }
  }

  // 1 到 max_val 都出现了，返回 max_val + 1
  return max_val + 1;
}

int main() {
  std::vector<int> nums1 = {-5, 3, 2, 3};
  std::vector<int> nums2 = {1, 2, 3};

  std::cout << "nums1 中从未出现的最小正数是：" << find_num(nums1) << "\n"; // 1
  std::cout << "nums2 中从未出现的最小正数是：" << find_num(nums2) << "\n"; // 4

  return 0;
}