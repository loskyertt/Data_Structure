#include "graph_factory.hpp"
#include <climits>
#include <iostream>
#include <queue>

using std::cout;
using std::queue;

/* 获取图的入度 */
template <typename VertexType>
vector<int> get_indegree(const vector<VertexType> &vertices, const vector<vector<int>> &adjMat) {
  int size = vertices.size();

  // indegree 索引对应 vertices 中顶点的索引，indegree 中的元素表示入度数
  vector<int> indegree(size, 0);

  for (const auto row : adjMat) {
    for (int i = 0; i < size; ++i) {
      if (row[i] != 0 && row[i] != INT_MAX) {
        ++indegree[i];
      }
    }
  }

  return indegree;
}

/* 拓扑排序（bfs 实现） */
template <typename VertexType>
void topology_sort(const vector<VertexType> &vertices, const vector<vector<int>> &adjMat) {

  int size = vertices.size();

  // 获取入度列表
  vector<int> indegree = get_indegree(vertices, adjMat);

  // 存放顶点索引的队列
  queue<int> q;
  for (int i = 0; i < size; ++i) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int index = q.front();
    q.pop();

    cout << vertices[index] << " ";

    for (int i = 0; i < size; i++) {
      if (adjMat[index][i] != 0 && adjMat[index][i] != INT_MAX) {
        // 去除一个顶点后，被该顶点连接的顶点的入度减一
        --indegree[i];

        // 再把入度为 0 的顶点放入队列
        if (indegree[i] == 0) {
          q.push(i);
        }
      }
    }
  }

  cout << "\n";
}

int main() {
  // 初始化顶点和边
  vector<int> vertices = {1, 2, 3, 4, 5};
  vector<Edge<int>> edges = {
      {1, 3},
      {1, 5},
      {3, 2},
      {2, 5},
      {2, 4},
      {5, 4}};

  // 创建邻接矩阵图（有向图）
  auto matGraphD = GraphFactory<int>::createGraph(GraphType::ADJACENCY_MATRIX_DIRECTED, vertices, edges);

  matGraphD->print();

  // 获取图
  auto *matGraphDRaw = dynamic_cast<GraphAdjMat<int> *>(matGraphD.get());
  vector<vector<int>> adjMat = matGraphDRaw->get_graph();

  cout << "BFS 遍历：\n";
  // 拓扑排序可以用来检查图有没有环
  topology_sort(vertices, adjMat);

  return 0;
}