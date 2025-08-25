#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

/* 直接插入排序 */
void insert_sort_directly(std::vector<int> &nums) {

  for (size_t i = 1; i < nums.size(); ++i) {
    // i 前面的都是排好顺序的元素
    for (size_t j = i; j > 0; --j) {
      if (nums[j] < nums[j - 1]) {
        std::swap(nums[j], nums[j - 1]);
      }
      // 如果 nums[j] > nums[j-1]，就可以直接退出循环，因为 j 前面的元素已经排好序了
      else {
        break;
      }
    }
  }
}

void test01() {
  std::vector<int> nums = {13, 6, 3, 31, 9, 27, 5, 11, 2};

  insert_sort_directly(nums);

  std::cout << "直接插入排序后的数组（方式一）：";
  for (int val : nums) {
    std::cout << val << " ";
  }

  std::cout << "\n";
}

int main() {
  test01();
}