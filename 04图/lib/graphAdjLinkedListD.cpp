#include "directedGraph/graphAdjLinkedListD.hpp"
#include <stdexcept>

using std::out_of_range;

// 先初始化顶点，边稍后添加
GraphAdjLinkedListD::GraphAdjLinkedListD(const vector<int> &vertices, const vector<vector<int>> &edges) : GraphAdjLinkedList(vertices, {}) {
  if (edges[0].size() == 2) {
    for (const vector<int> &edge : edges) {
      add_edge(edge[0], edge[1]);
    }
  } else {
    // edges 数组的第三列表示权重
    for (const vector<int> &edge : edges) {
      add_edge(edge[0], edge[1], edge[2]);
    }
  }
}

// 重写有向图下的边操作
/* 添加边 */
void GraphAdjLinkedListD::add_edge(int v1, int v2, int weight) {
  if (get_index(v1) == -1 || get_index(v2) == -1) {
    throw out_of_range("没有 v1 或 v2 节点！");
  }

  Vertex *v2_node = new Vertex(v2, weight);

  int v1_idx = get_index(v1);

  if (is_existed_edge(m_adjList[v1_idx], v2)) {
    throw out_of_range("禁止重复添加边！");
  }

  // v1 -> v2
  add_node(m_adjList[v1_idx], v2_node);
}

/* 删除边 */
void GraphAdjLinkedListD::remove_edge(int v1, int v2) {
  if (get_index(v1) == -1 || get_index(v2) == -1) {
    throw out_of_range("无效的边！");
  }

  int v1_idx = get_index(v1);

  remove_node(m_adjList[v1_idx], v2);
}