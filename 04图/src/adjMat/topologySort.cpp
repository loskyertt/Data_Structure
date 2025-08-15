#include "graph_factory.hpp"
#include <iostream>

using std::cout;

int main() {
  // 初始化顶点和边
  vector<int> vertices = {1, 2, 3, 4, 5};
  vector<vector<int>> edges = {
      {1, 3},
      {1, 5},
      {3, 2},
      {2, 5},
      {2, 4},
      {5, 4}};

  // 创建邻接矩阵图（有向图）
  auto matGraphD = GraphFactory::createGraph(GraphType::ADJACENCY_MATRIX_DIRECTED, vertices, edges);

  matGraphD->print();

  // 获取图
  auto *matGraphDRaw = dynamic_cast<GraphAdjMat *>(matGraphD.get());
  vector<vector<int>> adjMat = matGraphDRaw->get_graph();

  return 0;
}