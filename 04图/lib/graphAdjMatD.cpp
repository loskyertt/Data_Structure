#include "directedGraph/graphAdjMatD.hpp"
#include <stdexcept>

using std::out_of_range;

// 先初始化顶点，边稍后添加
GraphAdjMatD::GraphAdjMatD(const vector<int> &vertices, const vector<vector<int>> &edges) : GraphAdjMat(vertices, {}) {
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

/* 添加边 */
void GraphAdjMatD::add_edge(int v1, int v2, int weight) {
  int i = get_index(v1);
  int j = get_index(v2);

  if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
    // adjMat[i][i] （对角线）没有意义
    throw out_of_range("超出邻接矩阵范围！");
  }

  // 设置权重
  m_adjMat[i][j] = weight;
}

/* 删除边 */
void GraphAdjMatD::remove_edge(int v1, int v2) {
  int i = get_index(v1);
  int j = get_index(v2);

  if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
    // adjMat[i][i] （对角线）没有意义
    throw out_of_range("超出邻接矩阵范围！");
  }

  m_adjMat[i][j] = 0;
}