#pragma once

#include "undirectedGraph/graphAdjMat.hpp"

/* 邻接矩阵（有向图） */
class GraphAdjMatD : public GraphAdjMat {

public:
  GraphAdjMatD(const std::vector<int> &vertices, const std::vector<std::vector<int>> &edges);

  // 重写有向图下的边操作
  /* 添加边 */
  void add_edge(int v1, int v2) override;

  /* 删除边 */
  void remove_edge(int v1, int v2) override;
};