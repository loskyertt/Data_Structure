#pragma once

#include "IGraph.hpp"
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

/* 邻接矩阵（无向图） */
template <typename VertexType>
class GraphAdjMat : public IGraph<VertexType> {

protected:
  vector<VertexType> m_vertices;               // 顶点列表
  vector<vector<int>> m_adjMat;                // 邻接矩阵，行列索引对应“顶点索引”
  unordered_map<VertexType, int> m_vertex2idx; // 记录顶点的索引
  int m_size = 0;                              // 记录顶点数量

  /* 获取目标顶点元素索引 */
  int get_index(const VertexType &target);

public:
  /* 构造方法*/
  GraphAdjMat(const vector<VertexType> &vertices, const vector<Edge<VertexType>> &edges);

  /* 获取顶点数量 */
  int size() const override;

  /* 添加顶点 */
  void add_vertex(VertexType v) override;

  /* 删除顶点 */
  void remove_vertex(VertexType v) override;

  /* 添加边 */
  virtual void add_edge(VertexType v1, VertexType v2, int weight = 1) override;

  /* 删除边 */
  virtual void remove_edge(VertexType v1, VertexType v2) override;

  /* 打印邻接矩阵 */
  void print() const override;

  /* 获取图 */
  vector<vector<int>> get_graph() const;
};

// 显示实例化配置
extern template class GraphAdjMat<int>;
extern template class GraphAdjMat<char>;
