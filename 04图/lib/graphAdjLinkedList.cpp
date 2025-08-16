#include "undirectedGraph/graphAdjLinkedList.hpp"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::out_of_range;

// private
/* 添加节点：把 n1 节点添加到 n0 链表后 */
void GraphAdjLinkedList::add_node(Vertex *n0, Vertex *n1) {
  if (n0->next == nullptr) {
    n0->next = n1;
  } else {
    Vertex *temp = n0->next;
    n0->next = n1;
    n1->next = temp;
  }
}

/* 删除节点：把值为 val 的节点从 n0 节点后删除*/
void GraphAdjLinkedList::remove_node(Vertex *n0, int val) {
  Vertex *prev = n0;
  Vertex *curr = n0->next;

  // 在 curr 节点的值等于 val 时退出循环
  while (curr && curr->val != val) {
    prev = curr;
    curr = curr->next;
  }

  if (curr == nullptr) {
    return;
  }

  Vertex *temp = curr;
  curr = curr->next;
  prev->next = curr;
  delete temp;
}

/* 删除链表 */
void GraphAdjLinkedList::free_linked_node(Vertex *node) {
  while (node) {
    Vertex *temp = node;
    node = node->next;
    delete temp;
  }
}

/* 获取目标元素索引 */
int GraphAdjLinkedList::get_index(const int target) {

  int index = 0;
  // 后续学了“查找”可以用其它方法搜索
  for (const int val : m_vertices) {
    if (val == target) {
      return index;
    } else {
      index += 1;
    }
  }

  return -1;
}

/* 检查边是否存在 */
bool GraphAdjLinkedList::is_existed_edge(const Vertex *vertex, const int val) {
  while (vertex) {
    if (vertex->val == val) {
      return true;
    }

    vertex = vertex->next;
  }

  return false;
}

/* 打印链表 */
void GraphAdjLinkedList::print_linkedlist(const Vertex *node) const {
  cout << "[ ";
  while (node) {
    cout << node->val << " -> ";
    node = node->next;
  }

  cout << "nullptr ]\n";
}

// public
/* 构造方法 */
GraphAdjLinkedList::GraphAdjLinkedList(const vector<int> &vertices, const vector<vector<int>> &edges) {
  // 添加顶点
  for (const int vertex : vertices) {
    add_vertex(vertex);
  }

  // 添加边
  // 先判断边矩阵是否为空（因为子类 GraphAdjLinkedListD 调用父类构造函数时会传入空的边矩阵）
  if (!edges.empty()) {
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
}

/* 析构函数，释放申请的内存 */
GraphAdjLinkedList::~GraphAdjLinkedList() {
  for (auto &vertex : m_adjList) {
    free_linked_node(vertex);
  }

  m_adjList.clear();
}

/* 获取顶点数量 */
int GraphAdjLinkedList::size() const {
  return m_vertices.size();
}

/* 添加边 */
void GraphAdjLinkedList::add_edge(int v1, int v2, int weight) {
  if (get_index(v1) == -1 || get_index(v2) == -1) {
    throw out_of_range("没有 v1 或 v2 节点！");
  }

  Vertex *v1_node = new Vertex(v1, weight);
  Vertex *v2_node = new Vertex(v2, weight);

  int v1_idx = get_index(v1);
  int v2_idx = get_index(v2);

  if (is_existed_edge(m_adjList[v1_idx], v2)) {
    throw out_of_range("禁止重复添加边！");
  }

  add_node(m_adjList[v1_idx], v2_node);
  add_node(m_adjList[v2_idx], v1_node);
}

/* 删除边 */
void GraphAdjLinkedList::remove_edge(int v1, int v2) {
  if (get_index(v1) == -1 || get_index(v2) == -1) {
    throw out_of_range("无效的边！");
  }

  int v1_idx = get_index(v1);
  int v2_idx = get_index(v2);

  remove_node(m_adjList[v1_idx], v2);
  remove_node(m_adjList[v2_idx], v1);
}

/* 添加顶点 */
void GraphAdjLinkedList::add_vertex(int val) {
  if (get_index(val) != -1) {
    throw out_of_range("禁止添加重复节点！");
  }

  m_vertices.push_back(val);
  // 新添加的顶点权重默认设置为 0
  Vertex *node = new Vertex(val, 0);
  m_adjList.push_back(node);
}

/* 删除顶点 */
void GraphAdjLinkedList::remove_vertex(int val) {
  int target = get_index(val);

  // 把和 val 相关的边都删除
  for (int vertex : m_vertices) {
    remove_edge(vertex, val);
  }

  // 把顶点从顶点列表中移除
  m_vertices.erase(m_vertices.begin() + target);

  // 删除当前链表所有节点
  Vertex *curr = m_adjList[target];
  free_linked_node(curr);
  m_adjList.erase(m_adjList.begin() + target);
}

/* 打印邻接表 */
void GraphAdjLinkedList::print() const {
  cout << "邻接表（链表实现）：\n";

  for (const auto vertex : m_adjList) {
    cout << vertex->val << " -> ";
    print_linkedlist(vertex->next);
  }

  cout << "\n";
}

/* 获取图 */
vector<Vertex *> GraphAdjLinkedList::get_graph() const {
  return m_adjList;
}