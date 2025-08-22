#include <iostream>
#include <vector>

/* 二分查找：递归实现 */
int binary_search(const std::vector<int> &nums, const int &target, int i, int j) {

  if (i > j) {
    return -1;
  }

  int mid = i + (j - i) / 2;

  // // 说明 target 在 [i, mid-1] 中
  if (target < nums[mid]) {
    return binary_search(nums, target, i, mid - 1);
  }
  // 说明 target 在 [mid+1, j] 中
  else if (target > nums[mid]) {
    return binary_search(nums, target, mid + 1, j);
  }
  // 找到了
  else {
    return mid;
  }
}

int main() {
  std::cout << "二分查找（递归实现）：\n";

  // 奇数个元素
  std::vector<int> nums1 = {2, 5, 7, 10, 12, 13, 17, 19, 25, 26, 30};

  // 偶数个元素
  std::vector<int> nums2 = {2, 5, 7, 10, 12, 13, 17, 19, 25, 26};

  std::cout << "nums1 中的元素查找：\n";
  std::cout << "元素 10 的索引：" << binary_search(nums1, 10, 0, 10) << "\n";
  std::cout << "元素 2 的索引：" << binary_search(nums1, 2, 0, 10) << "\n";
  std::cout << "元素 19 的索引：" << binary_search(nums1, 19, 0, 10) << "\n";

  std::cout << "\n";

  std::cout << "nums2 中的元素查找：\n";
  std::cout << "元素 10 的索引：" << binary_search(nums2, 10, 0, 9) << "\n";
  std::cout << "元素 2 的索引：" << binary_search(nums2, 2, 0, 9) << "\n";
  std::cout << "元素 19 的索引：" << binary_search(nums2, 19, 0, 9) << "\n";
}