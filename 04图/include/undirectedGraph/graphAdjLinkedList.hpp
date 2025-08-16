#pragma once

#include "IGraph.hpp"
#include <vector>

using std::vector;

/* 顶点 */
struct Vertex {
  int val;
  int weight;
  Vertex *next;
  Vertex(int x, int y) : val(x), weight(y), next(nullptr) {}
};

/* 邻接表（链表实现） */
class GraphAdjLinkedList : public IGraph {

protected:
  // adjList[i] -> vertex1 -> vertex2 -> ...
  vector<Vertex *> m_adjList;

  // 顶点列表
  vector<int> m_vertices;

  /* 添加节点：把 n1 节点添加到 n0 链表后 */
  void add_node(Vertex *n0, Vertex *n1);

  /* 删除节点：把值为 val 的节点从 n0 节点后删除*/
  void remove_node(Vertex *n0, int val);

  /* 删除链表 */
  void free_linked_node(Vertex *node);

  /* 获取目标元素索引 */
  int get_index(const int target);

  /* 检查边是否存在 */
  bool is_existed_edge(const Vertex *vertex, const int val);

  /* 打印链表 */
  void print_linkedlist(const Vertex *node) const;

public:
  /* 构造方法 */
  GraphAdjLinkedList(const vector<int> &vertices, const vector<vector<int>> &edges);

  /* 析构函数，释放申请的内存 */
  ~GraphAdjLinkedList();

  /* 获取顶点数量 */
  int size() const override;

  /* 添加边 */
  virtual void add_edge(int v1, int v2, int weight = 0) override;

  /* 删除边 */
  virtual void remove_edge(int v1, int v2) override;

  /* 添加顶点 */
  void add_vertex(int val) override;

  /* 删除顶点 */
  void remove_vertex(int val) override;

  /* 打印邻接表 */
  void print() const override;

  /* 获取图 */
  vector<Vertex *> get_graph() const;
};