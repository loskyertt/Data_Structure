#include "graph_factory.hpp"

int main() {
  vector<int> vertices = {1, 2, 3, 4};

  vector<vector<int>> edges = {
      {1, 2},
      {1, 3},
      {2, 3},
      {3, 4}};

  // 创建邻接矩阵图
  auto matGraph = GraphFactory::createGraph(
      GraphType::ADJACENCY_MATRIX,
      vertices,
      edges);
  matGraph->print();

  // 创建邻接表图
  auto listGraph = GraphFactory::createGraph(
      GraphType::ADJACENCY_LIST,
      vertices,
      edges);
  listGraph->print();

  return 0;
}