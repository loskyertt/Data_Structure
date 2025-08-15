#include "graph_factory.hpp"
#include <iostream>

using std::cout;

/* dfs 遍历 */
void dfs(const vector<int> &vertices, const vector<vector<int>> &adjMat, const int start_index) {
}

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

  // 获取图
  auto *matGraphRaw = dynamic_cast<GraphAdjMat *>(matGraph.get());
  vector<vector<int>> adjMat = matGraphRaw->get_graph();

  cout << "邻接矩阵的 dfs 遍历：\n";

  dfs(vertices, adjMat, 0);

  return 0;
}