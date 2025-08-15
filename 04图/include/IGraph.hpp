#pragma once

#include <vector>

using std::vector;

/* 图的抽象接口 */
class IGraph {
public:
  virtual ~IGraph() = default;

  /* 获取顶点数量 */
  virtual int size() const = 0;

  /* 添加顶点 */
  virtual void add_vertex(int val) = 0;

  /* 删除顶点 */
  virtual void remove_vertex(int val) = 0;

  /* 添加边 */
  virtual void add_edge(int v1, int v2, int weight) = 0;

  /* 删除边 */
  virtual void remove_edge(int v1, int v2) = 0;

  /* 打印图 */
  virtual void print() const = 0;
};