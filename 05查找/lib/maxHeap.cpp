#include "heap/maxHeap.hpp"
#include <stdexcept>
#include <utility>

// private:
/* 获得当前节点的左孩子 */
int MaxHeap::left(int i) {
  return 2 * i + 1;
}

/* 获得当前节点的右孩子 */
int MaxHeap::right(int i) {
  return 2 * i + 2;
}

/* 获得父亲节点 */
int MaxHeap::parent(int i) {
  return (i - 1) / 2;
}

/* 从节点 i 开始，自底至顶堆化 */
void MaxHeap::sift_up(int i) {
  int p = parent(i);

  // 如果子节点比父节点大，交换这两个节点
  while (i >= 0 && max_heap[i] > max_heap[p]) {
    std::swap(max_heap[i], max_heap[p]);
    // 更新节点索引
    i = p;
    p = parent(i);
  }
}

/* 从节点 i 开始，自顶至底堆化 */
void MaxHeap::sift_down(int i = 0) {
  while (true) {
    // 判断节点 i, l, r 中值最大的节点，记为 max_i
    int l = left(i), r = right(i), max_i = i;

    if (l < size() && max_heap[l] > max_heap[max_i]) {
      max_i = l;
    }
    if (r < size() && max_heap[r] > max_heap[max_i]) {
      max_i = r;
    }

    // 若节点 i 最大或索引 l, r 越界，则无须继续堆化，跳出
    if (max_i == i) {
      break;
    }

    std::swap(max_heap[max_i], max_heap[i]);

    // 循环向下堆化
    i = max_i;
  }
}

// public:
/* 获取堆大小 */
int MaxHeap::size() {
  return max_heap.size();
}

/* 访问堆顶元素 */
int MaxHeap::top() {
  if (is_empty()) {
    throw std::out_of_range("堆为空！");
  }

  return max_heap[0];
}

/* 元素入堆 */
void MaxHeap::push(int val) {
  max_heap.push_back(val);

  sift_up(size() - 1);
}

/* 元素出堆 */
void MaxHeap::pop() {
  if (is_empty()) {
    throw std::out_of_range("堆为空！");
  }

  std::swap(max_heap[0], max_heap[size() - 1]);

  // 弹出最后一个元素
  max_heap.pop_back();

  if (!is_empty()) {
    sift_down(0);
  }
}

/* 判断堆是否为空 */
bool MaxHeap::is_empty() {
  return max_heap.empty();
}