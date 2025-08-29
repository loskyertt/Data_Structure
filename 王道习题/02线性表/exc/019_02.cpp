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

// 测试一
void test1() {
  std::cout << "测试一：\n";

  // 奇数个元素
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

  std::cout << "nums 逆序后（奇数个元素）：";
  reverse(nums);
  print_vector(nums);
}

// 测试二
void test2() {
  std::cout << "测试二：\n";

  // 偶数个元素
  std::vector<int> nums = {1, 2, 3, 4, 5, 6};

  std::cout << "nums 逆序后（偶数个元素）：";
  reverse(nums);
  print_vector(nums);
}

int main() {
  test1();

  std::cout << "\n";

  test2();
}