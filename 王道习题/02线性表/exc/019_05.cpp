#include "utils.hpp"
#include <iostream>
#include <vector>

// 方式一
namespace way1 {
/* 删除有序顺序表中所有值重复的元素 */
void remove_duplicated_val(std::vector<int> &nums) {
  int target = 0, i = 0; // 这里 target 设置为 0 表示无效值的意思，也可以用 INT_MAX 替代
  int n = nums.size() - 1;

  for (int j = 0; j < n; ++j) {
    if (nums[j] != target) {
      nums[i] = nums[j];
      ++i;
    }
    // 如果这个数连续出现两次，从下次起就开始删除
    if (nums[j] == nums[j + 1]) {
      target = nums[j];
    }
  }

  // 单独处理最后一个元素
  if (nums[n] != target) {
    nums[i] = nums[n];
    ++i;
  }

  nums.resize(i);
}
} // namespace way1

// 方式二：双指针法
namespace way2 {
/* 删除有序顺序表中所有值重复的元素 */
void remove_duplicated_val(std::vector<int> &nums) {
  int i = 0; // 慢指针，指向当前已去重部分的最后一个位置

  for (int j = 1; j < nums.size(); ++j) {
    if (nums[i] != nums[j]) {
      ++i;
      nums[i] = nums[j];
    }
  }

  // i 指向的是最后一个有效元素的位置，而不是元素个数
  nums.resize(i + 1);
}
} // namespace way2

/* 03，04，05 基本上是同一种思路 */
void test01() {
  std::vector<int> nums1 = {1, 2, 4, 4, 4, 5, 6, 6, 7, 10, 10};

  std::vector<int> nums2 = {1, 3, 3, 4, 4, 6, 6, 6, 10, 11, 13};

  std::cout << "去重后的元素：\n";

  std::cout << "nums1（方式一）: ";
  way1::remove_duplicated_val(nums1);
  print_vector(nums1);

  std::cout << "nums2（方式一）: ";
  way1::remove_duplicated_val(nums2);
  print_vector(nums2);
}

void test02() {
  std::vector<int> nums1 = {1, 2, 4, 4, 4, 5, 6, 6, 7, 10, 10};

  std::vector<int> nums2 = {1, 3, 3, 4, 4, 6, 6, 6, 10, 11, 13};

  std::cout << "去重后的元素：\n";

  std::cout << "nums1（方式二）: ";
  way2::remove_duplicated_val(nums1);
  print_vector(nums1);

  std::cout << "nums2（方式二）: ";
  way2::remove_duplicated_val(nums2);
  print_vector(nums2);
}

int main() {
  test01();

  std::cout << "\n";

  test02();
}