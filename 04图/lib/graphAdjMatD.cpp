#include "directedGraph/graphAdjMatD.hpp"
#include <stdexcept>

using std::out_of_range;

GraphAdjMatD::GraphAdjMatD(const std::vector<int> &vertices, const std::vector<std::vector<int>> &edges)
    : GraphAdjMat(vertices, {}) // 先初始化顶点，边稍后添加
{
  for (const auto &edge : edges) {
    add_edge(edge[0], edge[1]);
  }
}

/* 添加边 */
void GraphAdjMatD::add_edge(int v1, int v2) {
  int i = get_index(v1);
  int j = get_index(v2);

  if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
    // adjMat[i][i] （对角线）没有意义
    throw out_of_range("超出邻接矩阵范围！");
  }

  adjMat[i][j] = 1;
}

/* 删除边 */
void GraphAdjMatD::remove_edge(int v1, int v2) {
  int i = get_index(v1);
  int j = get_index(v2);

  if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
    // adjMat[i][i] （对角线）没有意义
    throw out_of_range("超出邻接矩阵范围！");
  }

  adjMat[i][j] = 0;
}