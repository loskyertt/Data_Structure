#include "directedGraph/graphAdjLinkedListD.hpp"
#include <stdexcept>

using std::out_of_range;

// 先初始化顶点，边稍后添加
template <typename VertexType>
GraphAdjLinkedListD<VertexType>::GraphAdjLinkedListD(const vector<VertexType> &vertices, const vector<Edge<VertexType>> &edges) : GraphAdjLinkedList<VertexType>(vertices, {}) {
  for (const auto &[v1, v2, weight] : edges) {
    this->add_edge(v1, v2, weight);
  }
}

// 重写有向图下的边操作
/* 添加边 */
template <typename VertexType>
void GraphAdjLinkedListD<VertexType>::add_edge(VertexType v1, VertexType v2, int weight) {
  int v1_idx = this->get_index(v1);
  int v2_idx = this->get_index(v2);

  if (v1_idx == -1 || v2_idx == -1) {
    throw out_of_range("没有 v1 或 v2 节点！");
  }

  Vertex<VertexType> *v2_node = new Vertex(v2, weight);

  if (this->is_existed_edge(this->m_adjList[v1_idx], v2)) {
    throw out_of_range("禁止重复添加边！");
  }

  // v1 -> v2
  this->add_node(this->m_adjList[v1_idx], v2_node);
}

/* 删除边 */
template <typename VertexType>
void GraphAdjLinkedListD<VertexType>::remove_edge(VertexType v1, VertexType v2) {
  int v1_idx = this->get_index(v1);
  int v2_idx = this->get_index(v2);

  if (v1_idx == -1 || v2_idx == -1) {
    throw out_of_range("无效的边！");
  }

  this->remove_node(this->m_adjList[v1_idx], v2);
}

template class GraphAdjLinkedListD<int>;
template class GraphAdjLinkedListD<char>;