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
  std::vector<bool> present(max_val + 1, false);

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

void test1() {
  std::cout << "测试一（偶数个元素）：\n";

  std::vector<int> nums = {-5, 3, 2, 3};

  std::cout << "nums 中从未出现的最小正数是：" << find_num(nums) << "\n"; // 1
}

void test2() {
  std::cout << "测试二（奇数个元素）：\n";

  std::vector<int> nums = {1, 2, 3};

  std::cout << "nums 中从未出现的最小正数是：" << find_num(nums) << "\n"; // 4
}

int main() {
  test1();

  std::cout << "\n";

  test2();
}