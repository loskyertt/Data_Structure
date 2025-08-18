#pragma once

#include <vector>

using std::vector;

/* 边 */
template <typename VertexType>
struct Edge {
  VertexType v1;
  VertexType v2;
  int weight = 1;
};

/* 图的抽象接口 */
template <typename VertexType>
class IGraph {
public:
  virtual ~IGraph() = default;

  /* 获取顶点数量 */
  virtual int size() const = 0;

  /* 添加顶点 */
  virtual void add_vertex(VertexType v) = 0;

  /* 删除顶点 */
  virtual void remove_vertex(VertexType v) = 0;

  /* 添加边 */
  virtual void add_edge(VertexType v1, VertexType v2, int weight) = 0;

  /* 删除边 */
  virtual void remove_edge(VertexType v1, VertexType v2) = 0;

  /* 打印图 */
  virtual void print() const = 0;
};