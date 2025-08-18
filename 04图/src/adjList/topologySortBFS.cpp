#include "graph_factory.hpp"
#include <iostream>
#include <queue>

using std::cout;
using std::queue;
using std::unordered_map;

template <typename VertexType>
vector<int> get_indegree(const vector<VertexType> &vertices, const vector<Vertex<VertexType> *> &adjList) {
  int size = vertices.size();

  // 建立“顶点：索引”映射
  unordered_map<int, int> vertex2idx;

  for (int i = 0; i < size; ++i) {
    vertex2idx[vertices[i]] = i;
  }

  // 入度列表
  vector<int> indegree(size, 0);

  for (auto node : adjList) {
    node = node->next;

    while (node) {
      int index = vertex2idx[node->v];
      ++indegree[index];
      node = node->next;
    }
  }

  return indegree;
}

template <typename VertexType>
void topology_sort(const vector<VertexType> &vertices, const vector<Vertex<VertexType> *> &adjList) {

  int size = vertices.size();

  // 建立“顶点：索引”映射
  unordered_map<int, int> vertex2idx;

  for (int i = 0; i < size; ++i) {
    vertex2idx[vertices[i]] = i;
  }

  vector<int> indegree = get_indegree(vertices, adjList);

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

    Vertex<VertexType> *node = adjList[index]->next;
    while (node) {
      int in_index = vertex2idx[node->v];
      --indegree[in_index];

      if (indegree[in_index] == 0) {
        q.push(in_index);
      }

      node = node->next;
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

  // 创建邻接表图（有向图）
  auto listGraphD = GraphFactory<int>::createGraph(GraphType::ADJACENCY_LIST_DIRECTED, vertices, edges);

  listGraphD->print();

  // 获取图
  auto *listGraphRaw = dynamic_cast<GraphAdjLinkedListD<int> *>(listGraphD.get());
  vector<Vertex<int> *> adjList = listGraphRaw->get_graph();

  cout << "BFS 遍历：\n";
  topology_sort(vertices, adjList);

  return 0;
}