#include "graph_factory.hpp"

int main() {
  vector<char> vertices = {'a', 'b', 'c', 'd', 'e', 'f'};
  vector<Edge<char>> edges = {
      // {v1(index), v2(index), weight}
      {'a', 'b', 2},
      {'a', 'c', 5},
      {'b', 'c', 1},
      {'b', 'd', 3},
      {'c', 'd', 3},
      {'c', 'e', 4},
      {'c', 'f', 1},
      {'d', 'e', 1},
      {'d', 'f', 4},
      {'e', 'f', 1}};

  // 创建邻接矩阵图（有向带权图）
  auto matGraphD = GraphFactory<char>::createGraph(GraphType::ADJACENCY_MATRIX_DIRECTED, vertices, edges);

  matGraphD->print();

  // 获取图
  auto *matGraphRaw = dynamic_cast<GraphAdjMat<char> *>(matGraphD.get());
  vector<vector<int>> adjMat = matGraphRaw->get_graph();

  return 0;
}