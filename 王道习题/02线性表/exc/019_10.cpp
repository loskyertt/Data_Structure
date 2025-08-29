#include "utils.hpp"
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

/* [1, 2, 3, 4, 5, 6] => [3, 4, 5, 6, 1,2] （p = 2 时） */
void move_num(std::vector<int> &nums, int p) {
  // 逆置数组中元素
  std::function<void(int, int)> reverse = [&](int i, int j) {
    while (i < j) {
      std::swap(nums[i], nums[j]);
      ++i;
      --j;
    }
  };

  int n = nums.size();

  // 先逆置 [0, p-1] 的元素
  reverse(0, p - 1);
  // 再逆置 [p, n-1] 的元素
  reverse(p, n - 1);
  // 最后逆置整个数组
  reverse(0, n - 1);
}

void test1() {
  std::cout << "测试一：\n";

  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::cout << "p = 1 时：";
  move_num(nums, 1);
  print_vector(nums);
}

void test2() {
  std::cout << "测试二：\n";

  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::cout << "p = 2 时：";
  move_num(nums, 2);
  print_vector(nums);
}

void test3() {
  std::cout << "测试三：\n";

  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::cout << "p = 3 时：";
  move_num(nums, 3);
  print_vector(nums);
}

void test4() {
  std::cout << "测试四：\n";

  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::cout << "p = 5 时：";
  move_num(nums, 5);
  print_vector(nums);
}

int main() {
  test1();

  std::cout << "\n";

  test2();

  std::cout << "\n";

  test3();

  std::cout << "\n";

  test4();
}