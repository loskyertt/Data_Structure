#include "utils.hpp"
#include <iostream>
#include <utility>
#include <vector>

/* 二分查找，并插入元素 */
void find_x(std::vector<int> &nums, int x) {
  int i = 0, j = nums.size() - 1;

  while (i <= j) {
    int mid = i + (j - i) / 2;
    if (x < nums[mid]) {
      j = mid - 1;
    } else if (x > nums[mid]) {
      i = mid + 1;
    } else {
      // 如果找到 x，则与它的后继元素交换
      std::swap(nums[mid], nums[mid + 1]);
      return;
    }
  }

  // 如果没找到，把元素插入进去（仍然要保持有序）
  nums.push_back(x);
  int n = nums.size();

  // 二分查找完毕，i 指向的是第一个大于 x 元素的位置
  while (i < n - 1) {
    std::swap(nums[i], nums[n - 1]);
    ++i;
  }
}

int main() {
  // 奇数个元素
  std::vector<int> nums1 = {1, 3, 4, 5, 6};

  // 偶数个元素
  std::vector<int> nums2 = {1, 3, 4, 5, 6, 7};

  std::cout << "找 3: ";
  find_x(nums1, 3);
  print_vector(nums1);

  std::cout << "找 6: ";
  find_x(nums2, 6);
  print_vector(nums2);

  // 元素不存在的情况
  // 奇数个元素
  std::vector<int> nums3 = {1, 3, 4, 5, 6};

  // 偶数个元素
  std::vector<int> nums4 = {1, 3, 4, 5, 7, 8};

  std::cout << "找 2（不存在）: ";
  find_x(nums3, 2);
  print_vector(nums3);

  std::cout << "找 6（不存在）: ";
  find_x(nums4, 6);
  print_vector(nums4);
}