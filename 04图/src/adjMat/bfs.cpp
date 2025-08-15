#include "graph_factory.hpp"
#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::queue;

/* bfs 遍历 */
void bfs(const vector<int> &vertices, const vector<vector<int>> &adjMat, const int start_index) {
  int size = vertices.size();

  // 访问标记，visited 的索引与 vertices 的索引相对应，表示是否访问过顶点
  vector<bool> visited(size, false);

  queue<int> q;
  q.push(start_index);
  visited[start_index] = true;

  while (!q.empty()) {
    int index = q.front();
    q.pop();

    cout << vertices[index] << " ";

    for (int i = 0; i < size; i++) {
      if (adjMat[index][i] == 1 && visited[i] == false) {
        q.push(i);
        visited[i] = true;
      }
    }
  }

  cout << "\n";
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

  cout << "邻接矩阵的 bfs 遍历：\n";

  bfs(vertices, adjMat, 0);

  return 0;
}