#include "graph_factory.hpp"
#include <iostream>
#include <queue>
#include <unordered_map>

using std::cout;
using std::queue;
using std::unordered_map;

/* bfs 遍历 */
template <typename VertexType>
void bfs(const vector<VertexType> &vertices, const vector<Vertex<VertexType> *> &adjList, const int start_index) {
  int size = vertices.size();
  vector<bool> visited(size, false);

  queue<int> q;
  q.push(start_index);
  visited[start_index] = true;

  // 用哈希表，将顶点值映射到索引，查找时 O(1)
  unordered_map<int, int> vertex2idx;
  for (int i = 0; i < size; ++i) {
    vertex2idx[vertices[i]] = i;
  }

  while (!q.empty()) {
    int index = q.front();
    q.pop();

    cout << vertices[index] << " ";

    Vertex<VertexType> *node = adjList[index]->next;
    while (node) {
      // 找到顶点列表中值为 node->val 的顶点的索引
      int next_idx = vertex2idx[node->v];

      if (visited[next_idx] == false) {
        q.push(next_idx);
        visited[next_idx] = true;
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

  // 创建邻接表图（无向图）
  auto listGraph = GraphFactory<int>::createGraph(GraphType::ADJACENCY_LIST_UNDIRECTED, vertices, edges);

  listGraph->print();

  // 获取图
  auto *listGraphRaw = dynamic_cast<GraphAdjLinkedList<int> *>(listGraph.get());
  vector<Vertex<int> *> adjList = listGraphRaw->get_graph();

  bfs(vertices, adjList, 0);

  return 0;
}