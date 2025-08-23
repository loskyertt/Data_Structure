#include "utils.hpp"
#include <iostream>
#include <vector>

/* 合并两个有序数组（归并排序会用到） */
std::vector<int> merge_nums(const std::vector<int> &nums1, const std::vector<int> nums2) {
  std::vector<int> res;
  // i 是 nums1 中元素指针，j 是 nums2 中元素指针
  int i = 0, j = 0;
  while (i < nums1.size() && j < nums2.size()) {
    if (nums1[i] <= nums2[j]) {
      res.push_back(nums1[i]);
      ++i;
    } else {
      res.push_back(nums2[j]);
      ++j;
    }
  }

  // 找出没遍历完的数组，把元素加到 res 末尾
  while (i < nums1.size()) {
    res.push_back(nums1[i]);
    ++i;
  }

  while (j < nums2.size()) {
    res.push_back(nums2[j]);
    ++j;
  }

  return res;
}

int main() {
  std::vector<int> nums1 = {1, 3, 4, 5, 7, 9, 10, 12, 14};
  std::vector<int> nums2 = {1, 2, 3, 4, 8, 11, 15};

  std::cout << "合并后的数组：";
  vector<int> res = merge_nums(nums1, nums2);
  print_vector(res);
}