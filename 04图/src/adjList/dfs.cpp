#include "graph_factory.hpp"
#include <functional>
#include <iostream>
#include <unordered_map>

using std::cout;
using std::function;
using std::unordered_map;

/* dfs 遍历 */
template <typename VertexType>
void dfs(const vector<VertexType> &vertices, const vector<Vertex<VertexType> *> &adjList, const int start_index) {
  int size = vertices.size();
  vector<bool> visited(size, false);

  unordered_map<int, int> vertex2idx;
  for (int i = 0; i < size; ++i) {
    vertex2idx[vertices[i]] = i;
  }

  function<void(int)> lambda = [&](int index) {
    cout << vertices[index] << " ";
    visited[index] = true;

    Vertex<VertexType> *node = adjList[index]->next;
    while (node) {
      int next_idx = vertex2idx[node->v];
      if (visited[next_idx] == false) {
        lambda(next_idx);
      }

      node = node->next;
    }
  };

  lambda(start_index);

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

  // 创建邻接表图（无向图）
  auto listGraph = GraphFactory<int>::createGraph(GraphType::ADJACENCY_LIST_UNDIRECTED, vertices, edges);

  listGraph->print();

  // 获取图
  auto *listGraphRaw = dynamic_cast<GraphAdjLinkedList<int> *>(listGraph.get());
  vector<Vertex<int> *> adjList = listGraphRaw->get_graph();

  dfs(vertices, adjList, 0);

  return 0;
}