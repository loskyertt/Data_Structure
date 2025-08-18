#pragma once

#include "undirectedGraph/graphAdjLinkedList.hpp"

/* 邻接表（有向图） */
template <typename VertexType>
class GraphAdjLinkedListD : public GraphAdjLinkedList<VertexType> {

public:
  GraphAdjLinkedListD(const vector<VertexType> &vertices, const vector<Edge<VertexType>> &edges);

  // 重写有向图下的边操作
  /* 添加边 */
  void add_edge(VertexType v1, VertexType v2, int weight = 0) override;

  /* 删除边 */
  void remove_edge(VertexType v1, VertexType v2) override;
};

extern template class GraphAdjLinkedListD<int>;
extern template class GraphAdjLinkedListD<char>;