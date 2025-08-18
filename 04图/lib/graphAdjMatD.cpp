#include "directedGraph/graphAdjMatD.hpp"
#include <climits>
#include <stdexcept>

using std::out_of_range;

// 先初始化顶点，边稍后添加
template <typename VertexType>
GraphAdjMatD<VertexType>::GraphAdjMatD(const vector<VertexType> &vertices, const vector<Edge<VertexType>> &edges) : GraphAdjMat<VertexType>(vertices, {}) {
  for (const auto &[v1, v2, weight] : edges) {
    add_edge(v1, v2, weight);
  }
}

/* 添加边 */
template <typename VertexType>
void GraphAdjMatD<VertexType>::add_edge(VertexType v1, VertexType v2, int weight) {
  int i = this->get_index(v1);
  int j = this->get_index(v2);

  if (i == -1 || j == -1) {
    throw out_of_range("顶点不存在，删除边失败！");
  }

  // 设置权重
  this->m_adjMat[i][j] = weight;
}

/* 删除边 */
template <typename VertexType>
void GraphAdjMatD<VertexType>::remove_edge(VertexType v1, VertexType v2) {
  int i = this->get_index(v1);
  int j = this->get_index(v2);

  if (i == -1 || j == -1) {
    throw out_of_range("顶点不存在，删除边失败！");
  }

  this->m_adjMat[i][j] = INT_MAX;
}

template class GraphAdjMatD<int>;
template class GraphAdjMatD<char>;