#pragma once

#include "undirectedGraph/graphAdjMat.hpp"

/* 邻接矩阵（有向图） */
class GraphAdjMatD : public GraphAdjMat {

public:
  GraphAdjMatD(const vector<int> &vertices, const vector<vector<int>> &edges);

  // 重写有向图下的边操作
  /* 添加边 */
  void add_edge(int v1, int v2, int weight = 1) override;

  /* 删除边 */
  void remove_edge(int v1, int v2) override;
};