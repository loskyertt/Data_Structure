#include "undirectedGraph/graphAdjLinkedList.hpp"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::out_of_range;

// protected
/* 添加节点：把 n1 节点添加到 n0 链表后 */
template <typename VertexType>
void GraphAdjLinkedList<VertexType>::add_node(Vertex<VertexType> *n0, Vertex<VertexType> *n1) {
  if (n0->next == nullptr) {
    n0->next = n1;
  } else {
    Vertex<VertexType> *temp = n0->next;
    n0->next = n1;
    n1->next = temp;
  }
}

/* 删除节点：把值为 val 的节点从 n0 节点后删除*/
template <typename VertexType>
void GraphAdjLinkedList<VertexType>::remove_node(Vertex<VertexType> *n0, VertexType val) {
  Vertex<VertexType> *prev = n0;
  Vertex<VertexType> *curr = n0->next;

  // 在 curr 节点的值等于 val 时退出循环
  while (curr && curr->v != val) {
    prev = curr;
    curr = curr->next;
  }

  if (curr == nullptr) {
    return;
  }

  Vertex<VertexType> *temp = curr;
  curr = curr->next;
  prev->next = curr;
  delete temp;
}

/* 删除链表 */
template <typename VertexType>
void GraphAdjLinkedList<VertexType>::free_linked_node(Vertex<VertexType> *node) {
  while (node) {
    Vertex<VertexType> *temp = node;
    node = node->next;
    delete temp;
  }
}

/* 获取目标元素索引 */
template <typename VertexType>
int GraphAdjLinkedList<VertexType>::get_index(const VertexType &target) {

  int index = 0;
  // 后续学了“查找”可以用其它方法搜索
  for (const auto val : m_vertices) {
    if (val == target) {
      return index;
    } else {
      index += 1;
    }
  }

  return -1;
}

/* 检查边是否存在 */
template <typename VertexType>
bool GraphAdjLinkedList<VertexType>::is_existed_edge(const Vertex<VertexType> *vertex, const VertexType val) {
  while (vertex) {
    if (vertex->v == val) {
      return true;
    }

    vertex = vertex->next;
  }

  return false;
}

/* 打印链表 */
template <typename VertexType>
void GraphAdjLinkedList<VertexType>::print_linkedlist(const Vertex<VertexType> *node) const {
  cout << "[ ";
  while (node) {
    cout << node->v << " -> ";
    node = node->next;
  }

  cout << "nullptr ]\n";
}

// public
/* 构造方法 */
template <typename VertexType>
GraphAdjLinkedList<VertexType>::GraphAdjLinkedList(const vector<VertexType> &vertices, const vector<Edge<VertexType>> &edges) {
  // 添加顶点
  for (const auto vertex : vertices) {
    add_vertex(vertex);
  }

  // 添加边
  for (const auto [v1, v2, weight] : edges) {
    add_edge(v1, v2, weight);
  }
}

/* 析构函数，释放申请的内存 */
template <typename VertexType>
GraphAdjLinkedList<VertexType>::~GraphAdjLinkedList() {
  for (auto &vertex : m_adjList) {
    free_linked_node(vertex);
  }

  m_adjList.clear();
}

/* 获取顶点数量 */
template <typename VertexType>
int GraphAdjLinkedList<VertexType>::size() const {
  return m_vertices.size();
}

/* 添加边 */
template <typename VertexType>
void GraphAdjLinkedList<VertexType>::add_edge(VertexType v1, VertexType v2, int weight) {
  if (get_index(v1) == -1 || get_index(v2) == -1) {
    throw out_of_range("没有 v1 或 v2 节点！");
  }

  Vertex<VertexType> *v1_node = new Vertex(v1, weight);
  Vertex<VertexType> *v2_node = new Vertex(v2, weight);

  int v1_idx = get_index(v1);
  int v2_idx = get_index(v2);

  if (is_existed_edge(m_adjList[v1_idx], v2)) {
    throw out_of_range("禁止重复添加边！");
  }

  add_node(m_adjList[v1_idx], v2_node);
  add_node(m_adjList[v2_idx], v1_node);
}

/* 删除边 */
template <typename VertexType>
void GraphAdjLinkedList<VertexType>::remove_edge(VertexType v1, VertexType v2) {
  if (get_index(v1) == -1 || get_index(v2) == -1) {
    throw out_of_range("无效的边！");
  }

  int v1_idx = get_index(v1);
  int v2_idx = get_index(v2);

  remove_node(m_adjList[v1_idx], v2);
  remove_node(m_adjList[v2_idx], v1);
}

/* 添加顶点 */
template <typename VertexType>
void GraphAdjLinkedList<VertexType>::add_vertex(VertexType v) {
  if (get_index(v) != -1) {
    throw out_of_range("禁止添加重复节点！");
  }

  m_vertices.push_back(v);
  // 新添加的顶点权重默认设置为 0
  Vertex<VertexType> *node = new Vertex(v, 0);
  m_adjList.push_back(node);
}

/* 删除顶点 */
template <typename VertexType>
void GraphAdjLinkedList<VertexType>::remove_vertex(VertexType v) {
  int target = get_index(v);

  // 把和 val 相关的边都删除
  for (int vertex : m_vertices) {
    remove_edge(vertex, v);
  }

  // 把顶点从顶点列表中移除
  m_vertices.erase(m_vertices.begin() + target);

  // 删除当前链表所有节点
  Vertex<VertexType> *curr = m_adjList[target];
  free_linked_node(curr);
  m_adjList.erase(m_adjList.begin() + target);
}

/* 打印邻接表 */
template <typename VertexType>
void GraphAdjLinkedList<VertexType>::print() const {
  cout << "邻接表（链表实现）：\n";

  for (const auto vertex : m_adjList) {
    cout << vertex->v << " -> ";
    print_linkedlist(vertex->next);
  }

  cout << "\n";
}

/* 获取图 */
template <typename VertexType>
vector<Vertex<VertexType> *> GraphAdjLinkedList<VertexType>::get_graph() const {
  return m_adjList;
}

template class GraphAdjLinkedList<int>;
template class GraphAdjLinkedList<char>;