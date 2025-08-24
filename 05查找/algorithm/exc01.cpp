#include <iostream>
#include <unordered_map>
#include <vector>

/* 删除顺序表中的重复元素 */
void remove_duplicated_ele(std::vector<int> &nums) {
  int n = nums.size();

  std::unordered_map<int, std::vector<int>> num2idx;

  for (int i = 0; i < n; ++i) {
    num2idx[nums[i]].push_back(i);
  }

  for (auto [k, v] : num2idx) {
    // 标记重复元素为-1（保留第一个出现的元素）
    if (v.size() > 1) {
      for (int j = 1; j < v.size(); ++j) {
        nums[v[j]] = -1;
      }
    }
  }

  // 移除标记为-1的元素
  int i = 0;
  for (int j = 0; j < n; ++j) {
    if (nums[j] != -1) {
      nums[i] = nums[j];
      ++i;
    }
  }

  nums.resize(i);
}

int main() {
  std::vector<int> nums = {1, 3, 1, 2, 6, 5, 7, 2, 2, 10};
  remove_duplicated_ele(nums);

  std::cout << "去重后的元素：";
  for (int val : nums) {
    std::cout << val << " ";
  }

  std::cout << "\n";
}