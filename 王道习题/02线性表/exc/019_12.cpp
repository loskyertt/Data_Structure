#include <iostream>
#include <vector>

/* 查找数组中的主元素（数量超过数组一半的1元素） */
int boyerMoore(const std::vector<int> &nums) {
  int count = 0; // 用于计数

  int candidate_num = 0; // 记录候选数字

  // 投票阶段
  for (int val : nums) {
    if (count == 0) {
      candidate_num = val;
      count = 1;
    } else if (val == candidate_num) {
      count++;
    } else {
      count--;
    }
  }

  // 检验候选元素
  count = 0;
  for (int val : nums) {
    if (val == candidate_num) {
      count++;
    }
  }

  if (count > nums.size() / 2) {
    return candidate_num;
  }

  return -1; // 表示没有
}

int main() {
  std::vector<int> nums1 = {1, 4, 3, 4, 7, 4, 4, 2, 1, 4, 4, 4};
  std::vector<int> nums2 = {1, 2, 3, 4, 7, 4, 4, 2, 1, 4, 4, 4};

  std::cout << "nums1 中的主元素：" << boyerMoore(nums1) << "\n";
  std::cout << "nums2 中的主元素：" << boyerMoore(nums2) << "\n";
}