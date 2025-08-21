#include <iostream>

void test01(int *&p) {
  delete p;
  p = nullptr; // 这里相当于把 main 函数中的 ptr1 置空
}

void test02(int *p) {
  delete p;
  p = nullptr; // 这里只是把 main 函数中的 ptr2 的副本（即 p）置空
}

/* 经典指针问题 */
int main() {
  int *ptr1 = new int(10);

  std::cout << "ptr1 = " << *ptr1 << "\n";
  std::cout << "ptr1 指向的地址：" << ptr1 << "\n";

  test01(ptr1);

  if (ptr1 == nullptr) {
    std::cout << "ptr1 指针指向为空！\n";
  }
  std::cout << "ptr1 指向的地址：" << ptr1 << "\n";

  std::cout << "\n";

  int *ptr2 = new int(2);

  std::cout << "ptr2 = " << *ptr2 << "\n";
  std::cout << "ptr2 指向的地址：" << ptr2 << "\n";

  test02(ptr2);

  if (ptr2 == nullptr) {
    std::cout << "ptr2 指针指向为空！\n";
  } else {
    std::cout << "ptr2 指针指向未知内存地址！\n";
    std::cout << "ptr2（野指针） = " << *ptr2 << "\n";
  }
  std::cout << "ptr2 指向的地址：" << ptr2 << "\n";
}