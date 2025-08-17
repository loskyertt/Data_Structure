#include "graph_factory.hpp"

int main() {
  vector<int> vertices = {0, 1, 2, 3, 4, 5};
  vector<vector<int>> edges = {
      // {v1(index), v2(index), weight}
      {0, 1, 2},
      {0, 2, 5},
      {1, 2, 1},
      {1, 3, 3},
      {2, 3, 3},
      {2, 4, 4},
      {2, 5, 1},
      {3, 4, 1},
      {3, 5, 4},
      {4, 5, 1}};

  // 创建邻接矩阵图（有向带权图）
  auto matGraphD = GraphFactory::createGraph(GraphType::ADJACENCY_MATRIX_DIRECTED, vertices, edges);

  matGraphD->print();

  // 获取图
  auto *matGraphRaw = dynamic_cast<GraphAdjMat *>(matGraphD.get());
  vector<vector<int>> adjMat = matGraphRaw->get_graph();

  return 0;
}