#include "undirectedGraph/graphAdjLinkedList.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::exception;

int main() {
  // 初始化顶点和边
  vector<int> vertices = {1, 2, 3, 4, 5};
  vector<vector<int>> edges = {
      // 这里是按照顶点元素值来进行连接
      {1, 3},
      {1, 5},
      {3, 2},
      {2, 5},
      {2, 4},
      {4, 5}};
  GraphAdjLinkedList graph(vertices, edges);

  cout << "初始邻接表：\n";
  graph.print();

  // 测试添加顶点
  cout << "添加顶点 6 ：\n";
  graph.add_vertex(6);
  graph.print();

  // 测试添加边
  cout << "添加边 (1, 6) ：\n";
  graph.add_edge(1, 6);
  graph.print();

  // 测试删除边
  cout << "删除边 (2, 4) ：\n";
  graph.remove_edge(2, 4);
  graph.print();

  // 测试删除顶点
  cout << "删除顶点 3 ：\n";
  graph.remove_vertex(3);
  graph.print();

  // 测试异常：添加重复顶点
  try {
    graph.add_vertex(2);
  } catch (const exception &e) {
    cout << "异常捕获（重复顶点）：" << e.what() << endl;
  }

  // 测试异常：添加重复边
  try {
    graph.add_edge(4, 5);
  } catch (const exception &e) {
    cout << "异常捕获（重复边）：" << e.what() << endl;
  }

  // 测试异常：添加不存在的边
  try {
    graph.add_edge(10, 2);
  } catch (const exception &e) {
    cout << "异常捕获（不存在的顶点）：" << e.what() << endl;
  }

  // 测试异常：删除不存在的顶点
  try {
    graph.remove_vertex(100);
  } catch (const exception &e) {
    cout << "异常捕获（删除不存在顶点）：" << e.what() << endl;
  }

  return 0;
}