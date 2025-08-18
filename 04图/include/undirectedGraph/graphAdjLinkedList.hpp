#pragma once

#include "IGraph.hpp"
#include <vector>

using std::vector;

/* 顶点 */
template <typename VertexType>
struct Vertex {
  VertexType v;
  int weight;
  Vertex *next;
  Vertex(VertexType x, int y) : v(x), weight(y), next(nullptr) {}
};

/* 邻接表（链表实现） */
template <typename VertexType>
class GraphAdjLinkedList : public IGraph<VertexType> {

protected:
  // adjList[i] -> vertex1 -> vertex2 -> ...
  vector<Vertex<VertexType> *> m_adjList;

  // 顶点列表
  vector<VertexType> m_vertices;

  /* 添加节点：把 n1 节点添加到 n0 链表后 */
  void add_node(Vertex<VertexType> *n0, Vertex<VertexType> *n1);

  /* 删除节点：把值为 val 的节点从 n0 节点后删除*/
  void remove_node(Vertex<VertexType> *n0, VertexType val);

  /* 删除链表 */
  void free_linked_node(Vertex<VertexType> *node);

  /* 获取目标元素索引 */
  int get_index(const VertexType &target);

  /* 检查边是否存在 */
  bool is_existed_edge(const Vertex<VertexType> *vertex, const VertexType val);

  /* 打印链表 */
  void print_linkedlist(const Vertex<VertexType> *node) const;

public:
  /* 构造方法 */
  GraphAdjLinkedList(const vector<VertexType> &vertices, const vector<Edge<VertexType>> &edges);

  /* 析构函数，释放申请的内存 */
  ~GraphAdjLinkedList();

  /* 获取顶点数量 */
  int size() const override;

  /* 添加边 */
  virtual void add_edge(VertexType v1, VertexType v2, int weight = 0) override;

  /* 删除边 */
  virtual void remove_edge(VertexType v1, VertexType v2) override;

  /* 添加顶点 */
  void add_vertex(VertexType v) override;

  /* 删除顶点 */
  void remove_vertex(VertexType v) override;

  /* 打印邻接表 */
  void print() const override;

  /* 获取图 */
  vector<Vertex<VertexType> *> get_graph() const;
};

extern template class GraphAdjLinkedList<int>;
extern template class GraphAdjLinkedList<char>;