#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {10, 20, 30, 40, 50};
  int target = 30;

  auto it = std::find(v.begin(), v.end(), target);

  if (it != v.end()) {
    unsigned short index = it - v.begin();
    std::cout << "元素 " << target << " 的索引是: " << index << std::endl;
  } else {
    std::cout << "元素 " << target << " 未找到" << std::endl;
  }

  int index = 0;
  for (const int val : v) {
    if (val == 30) {
      std::cout << index << std::endl;
    } else {
      index += 1;
    }
  }

  return 0;
}