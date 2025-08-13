#include "linkedlist/graphAdjLinkedList.hpp"
#include <iostream>

using std::cout;

int main() {
  vector<int> vertices = {1, 3, 2, 5, 4};
  vector<vector<int>> edges = {
      {1, 3},
      {1, 5},
      {3, 2},
      {2, 5},
      {2, 4},
      {4, 5}};

  GraphAdjLinkedList graph(vertices, edges);

  cout << "初始图：\n";
  graph.print();

  // cout << "删除了边后的图：\n";
  // graph.remove_edge(1, 5);
  // graph.print();

  // cout << "删除了顶点后的图：" << endl;
  // graph.remove_vertex(3);
  // graph.print();

  // cout << "添加了边后的图：" << endl;
  // graph.add_edge(1, 4);
  // graph.print();

  // cout << "添加了点后的图：" << endl;
  // graph.add_vertex(7);
  // graph.print();

  return 0;
}