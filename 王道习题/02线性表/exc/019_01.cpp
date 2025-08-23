#include "utils.hpp"
#include <climits>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>

/* 删除顺序表中最小值元素 */
void remove_min(std::vector<int> &nums) {
  // 如果线性表为空，显示出错信息并退出
  int n = nums.size();

  if (n == 0) {
    throw std::out_of_range("线性表为空！");
  }

  int min_num = INT_MAX;
  int idx = -1;

  for (int i = 0; i < n; ++i) {
    if (nums[i] < min_num) {
      min_num = nums[i];
      idx = i;
    }
  }

  // 空出的位置由最后一个元素填补
  nums[idx] = nums[n - 1];
}

int main() {
  // 最小值为 2
  std::vector<int> nums = {3, 5, 7, 2, 9, 10, 6, 4};

  remove_min(nums);

  std::cout << "删除最小值后：";
  print_vector(nums);

  std::vector<int> empty_nums = {};
  try {
    remove_min(empty_nums);
  } catch (const std::exception &e) {
    std::cout << "异常捕获：" << e.what() << "\n";
  }
}