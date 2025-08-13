#include "linkedlist/graphAdjLinkedList.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  // 初始化顶点和边
  vector<int> vertices = {1, 2, 3, 4};
  vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}};
  GraphAdjLinkedList g(vertices, edges);

  cout << "初始邻接表：" << endl;
  g.print();

  // 测试添加顶点
  cout << "添加顶点5：" << endl;
  g.add_vertex(5);
  g.print();

  // 测试添加边
  cout << "添加边(4,5)：" << endl;
  g.add_edge(4, 5);
  g.print();

  // 测试删除边
  cout << "删除边(2,3)：" << endl;
  g.remove_edge(2, 3);
  g.print();

  // 测试删除顶点
  cout << "删除顶点3：" << endl;
  g.remove_vertex(3);
  g.print();

  // 测试异常：添加重复顶点
  try {
    g.add_vertex(2);
  } catch (const std::exception &e) {
    cout << "异常捕获（重复顶点）：" << e.what() << endl;
  }

  // 测试异常：添加不存在的边
  try {
    g.add_edge(10, 2);
  } catch (const std::exception &e) {
    cout << "异常捕获（不存在的顶点）：" << e.what() << endl;
  }

  // 测试异常：删除不存在的顶点
  try {
    g.remove_vertex(100);
  } catch (const std::exception &e) {
    cout << "异常捕获（删除不存在顶点）：" << e.what() << endl;
  }

  return 0;
}