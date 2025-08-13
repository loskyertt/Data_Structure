#include "linkedlist/graphAdjLinkedList.hpp"
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
int GraphAdjLinkedList::get_index(int target) {

  int index = 0;
  // 后续学了“查找”可以用其它方法搜索
  for (const int val : vertices) {
    if (val == target) {
      return index;
    } else {
      index += 1;
    }
  }

  return -1;
}

/* 打印链表 */
void GraphAdjLinkedList::print_linkedlist(Vertex *node) {
  cout << "[ ";
  while (node) {
    cout << node->val << " -> ";
    node = node->next;
  }

  cout << "nullptr ]\n";
}

// public
/* 构造方法 */
GraphAdjLinkedList::GraphAdjLinkedList(const vector<int> vertices, const vector<vector<int>> &edges) {
  for (int vertex : vertices) {
    add_vertex(vertex);
  }

  for (auto edge : edges) {
    add_edge(edge[0], edge[1]);
  }
}

/* 析构函数，释放申请的内存 */
GraphAdjLinkedList::~GraphAdjLinkedList() {
  for (auto &vertex : adjList) {
    free_linked_node(vertex);
  }

  adjList.clear();
}

/* 获取顶点数量 */
int GraphAdjLinkedList::size() {
  return vertices.size();
}

/* 添加边 */
void GraphAdjLinkedList::add_edge(int src, int dist) {
  if (get_index(src) == -1 || get_index(dist) == -1) {
    throw out_of_range("没有 src 或 dist 节点！");
  }

  Vertex *src_node = new Vertex(src);
  Vertex *dist_node = new Vertex(dist);

  for (auto &vertex : adjList) {
    if (vertex->val == src) {
      add_node(vertex, dist_node);
    }
    if (vertex->val == dist) {
      add_node(vertex, src_node);
    }
  }
}

/* 删除边 */
void GraphAdjLinkedList::remove_edge(int src, int dist) {
  if (get_index(src) == -1 || get_index(dist) == -1) {
    throw out_of_range("无效的边！");
  }

  for (auto &vertex : adjList) {
    if (vertex->val == src) {
      remove_node(vertex, dist);
    }
    if (vertex->val == dist) {
      remove_node(vertex, src);
    }
  }
}

/* 添加顶点 */
void GraphAdjLinkedList::add_vertex(int vertex) {
  if (get_index(vertex) != -1) {
    throw out_of_range("禁止添加重复节点！");
  }

  vertices.push_back(vertex);
  Vertex *node = new Vertex(vertex);
  adjList.push_back(node);
}

/* 删除顶点 */
void GraphAdjLinkedList::remove_vertex(int vertex) {
  int target = get_index(vertex);

  // 把和 vertex 相关的边都删除
  for (int val : vertices) {
    remove_edge(val, vertex);
  }

  // 把顶点从顶点列表中移除
  vertices.erase(vertices.begin() + target);

  // 删除当前链表所有节点
  Vertex *curr = adjList[target];
  free_linked_node(curr);
  adjList.erase(adjList.begin() + target);
}

/* 打印邻接表 */
void GraphAdjLinkedList::print() {
  cout << "邻接表（链表实现）：\n";

  for (const auto vertex : adjList) {
    cout << vertex->val << " -> ";
    print_linkedlist(vertex->next);
  }

  cout << "\n";
}