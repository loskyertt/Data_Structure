#include "graph_factory.hpp"
#include "undirectedGraph/graphAdjMat.hpp"

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

  // 创建邻接矩阵图（无向图）
  auto matGraph = GraphFactory::createGraph(GraphType::ADJACENCY_MATRIX_UNDIRECTED, vertices, edges);

  matGraph->print();

  // 获取图
  auto *matGraphRaw = dynamic_cast<GraphAdjMat *>(matGraph.get());
  auto adjMat = matGraphRaw->get_graph();

  // 创建邻接矩阵图（有向图）
  auto matGraphD = GraphFactory::createGraph(GraphType::ADJACENCY_MATRIX_DIRECTED, vertices, edges);

  matGraphD->print();

  // 创建邻接表图（无向图）
  auto listGraph = GraphFactory::createGraph(GraphType::ADJACENCY_LIST_UNDIRECTED, vertices, edges);

  listGraph->print();

  // 创建邻接表图（有向图）
  auto listGraphD = GraphFactory::createGraph(GraphType::ADJACENCY_LIST_DIRECTED, vertices, edges);

  listGraphD->print();

  return 0;
}