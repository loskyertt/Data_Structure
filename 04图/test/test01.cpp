#include "matrix/graphAdjMat.hpp"
#include <iostream>

using std::cout;

// 测试邻接矩阵
int main() {
  vector<int> vertices = {1, 3, 2, 5, 4};
  vector<vector<int>> edges = {
      {0, 1},
      {0, 3},
      {1, 2},
      {2, 3},
      {2, 4},
      {3, 4}};

  GraphAdjMat graph(vertices, edges);

  // 初始邻接矩阵
  cout << "初始邻接矩阵：\n";
  graph.print();

  // 删除顶点“3”（index = 1）
  graph.remove_vertex(1);
  cout << "删除顶点“3”后的邻接矩阵：\n";
  graph.print();

  // 添加顶点“6”，默认添加到矩阵最后一行/列
  graph.add_vertex(6);
  cout << "添加顶点“6”后的邻接矩阵：\n";
  graph.print();

  // 连接顶点“4”和“6”（对应索引为 3 和 4）
  graph.add_edge(3, 4);
  cout << "连接顶点“4”和“6”后的邻接矩阵：\n";
  graph.print();

  // 断开顶点“1”和“5”（对应索引为 0 和 2）
  graph.remove_edge(0, 2);
  cout << "断开顶点“1”和“5”后的邻接矩阵：\n";
  graph.print();

  return 0;
}
