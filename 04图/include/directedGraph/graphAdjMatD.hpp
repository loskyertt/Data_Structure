#pragma once

#include "undirectedGraph/graphAdjMat.hpp"

/* 邻接矩阵（有向图） */
template <typename VertexType>
class GraphAdjMatD : public GraphAdjMat<VertexType> {

public:
  GraphAdjMatD(const vector<VertexType> &vertices, const vector<Edge<VertexType>> &edges);

  // 重写有向图下的边操作
  /* 添加边 */
  void add_edge(VertexType v1, VertexType v2, int weight = 1) override;

  /* 删除边 */
  void remove_edge(VertexType v1, VertexType v2) override;
};

extern template class GraphAdjMatD<int>;
extern template class GraphAdjMatD<char>;