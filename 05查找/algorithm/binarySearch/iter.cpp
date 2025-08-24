#include <iostream>
#include <vector>

/* 二分查找：迭代实现 */
int binary_search(const std::vector<int> &nums, const int &target) {
  int i = 0, j = nums.size() - 1; // 双闭区间写法：[i, j]

  while (i <= j) {
    int mid = i + (j - i) / 2; // 计算中点索引 m，这样计算是为了避免大数越界

    // 说明 target 在 [i, mid-1] 中
    if (target < nums[mid]) {
      j = mid - 1;
    }
    // 说明 target 在 [mid+1, j] 中
    else if (target > nums[mid]) {
      i = mid + 1;
    }
    // 找到 target
    else {
      // 若找到，i j mid 索引
      std::cout << "找到 target, i = " << i << ", j = " << j << ", mid = " << mid << "\n";
      return mid;
    }
  }

  std::cout << "没找到 target, i = " << i << ", j = " << j << "\n";
  return -1; // 表示没找到
}

int main() {
  std::cout << "二分查找（迭代实现）：\n";

  // 奇数个元素
  std::vector<int> nums1 = {2, 5, 7, 10, 12, 13, 17, 19, 25, 26, 30};

  // 偶数个元素
  std::vector<int> nums2 = {2, 5, 7, 10, 12, 13, 17, 19, 25, 26};

  std::cout << "nums1 中的元素查找：\n";
  std::cout << "元素 10 的索引：" << binary_search(nums1, 10) << "\n";
  std::cout << "元素 2 的索引：" << binary_search(nums1, 2) << "\n";
  std::cout << "元素 19 的索引：" << binary_search(nums1, 19) << "\n";
  std::cout << "元素 11 的索引（不存在）：" << binary_search(nums1, 11) << "\n";
  std::cout << "元素 1 的索引（不存在）：" << binary_search(nums1, 1) << "\n";

  std::cout << "\n";

  std::cout << "nums2 中的元素查找：\n";
  std::cout << "元素 10 的索引：" << binary_search(nums2, 10) << "\n";
  std::cout << "元素 2 的索引：" << binary_search(nums2, 2) << "\n";
  std::cout << "元素 19 的索引：" << binary_search(nums2, 19) << "\n";
  std::cout << "元素 1 的索引（不存在）：" << binary_search(nums2, 1) << "\n";
}