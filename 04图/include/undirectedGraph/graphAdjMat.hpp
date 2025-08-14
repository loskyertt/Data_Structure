#pragma once

#include "IGraph.hpp"
#include <vector>

using std::vector;

/* 邻接矩阵（无向图） */
class GraphAdjMat : public IGraph {

protected:
  vector<int> vertices;       // 顶点列表
  vector<vector<int>> adjMat; // 邻接矩阵，行列索引对应“顶点索引”

  /* 获取目标元素索引 */
  int get_index(const int target);

public:
  /* 构造方法*/
  GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges);

  /* 获取顶点数量 */
  int size() const override;

  /* 添加顶点 */
  void add_vertex(int val) override;

  /* 删除顶点 */
  void remove_vertex(int val) override;

  /* 添加边 */
  virtual void add_edge(int v1, int v2) override;

  /* 删除边 */
  virtual void remove_edge(int v1, int v2) override;

  /* 打印邻接矩阵 */
  void print() const override;

  /* 获取图 */
  vector<vector<int>> get_graph() const;
};
