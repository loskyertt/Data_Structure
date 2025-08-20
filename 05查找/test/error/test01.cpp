#include <iostream>

int main() {
  int a = 10;
  void *ptr = &a;
  std::cout << "a 的地址：" << ptr << "\n";
}