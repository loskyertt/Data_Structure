#include "undirectedGraph/graphAdjMat.hpp"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::out_of_range;

// protected
/* 获取目标元素索引 */
int GraphAdjMat::get_index(const int target) {

  // 用哈希表来降低查找的时间复杂度
  auto it = m_vertex2idx.find(target);

  return (it != m_vertex2idx.end()) ? it->second : -1;
}

// public
/* 构造方法*/
GraphAdjMat::GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges) {

  // 添加顶点
  for (const int vertex : vertices) {
    add_vertex(vertex);
  }

  // 添加边
  // 先判断边矩阵是否为空（因为子类 GraphAdjMatD 调用父类构造函数时会传入空的边矩阵）
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

/* 获取顶点数量 */
int GraphAdjMat::size() const {
  return m_size;
}

/* 添加顶点 */
void GraphAdjMat::add_vertex(int val) {
  int n = size();

  m_vertices.push_back(val);

  // 记录顶点到索引的映射
  m_vertex2idx[val] = m_size;

  // 添加一个节点，就给邻接矩阵增加一行
  m_adjMat.emplace_back(vector<int>(n, 0));

  // 然后给每一行增加一个 0（表示增加一列）
  // 注意这里 row 前要加 &，因为 row 是一个拷贝，auto row : adjMat 不会修改原始的 adjMat
  for (auto &row : m_adjMat) {
    row.push_back(0);
  }

  // 每添加一个顶点，m_size 加 1
  m_size++;
}

/* 删除顶点 */
void GraphAdjMat::remove_vertex(int val) {
  int index = get_index(val);

  if (index == -1) {
    throw out_of_range("顶点不存在，删除顶点失败！");
  }

  // 注意：这会使得 m_vertices 中位于 index 之后的所有顶点向前移动一位（索引减 1），所以要更新 m_vertex2idx
  m_vertices.erase(m_vertices.begin() + index);

  // 删除 m_vertex2idx 中对应的“顶点：索引”
  m_vertex2idx.erase(val);

  // 更新后续顶点的索引，为了与顶点列表相对应
  for (int k = index; k < m_vertices.size(); ++k) {
    m_vertex2idx[m_vertices[k]] = k;
  }

  // 擦除邻接矩阵中对应 index 的那一行
  m_adjMat.erase(m_adjMat.begin() + index);

  // 再擦除每一行对应 index 的元素（擦除 index 列）
  for (auto &row : m_adjMat) {
    row.erase(row.begin() + index);
  }

  // 每移除一个顶点，m_size 减 1
  m_size--;
}

/* 添加边 */
void GraphAdjMat::add_edge(int v1, int v2, int weight) {
  int i = get_index(v1);
  int j = get_index(v2);

  if (i == -1 || j == -1) {
    // adjMat[i][i] （对角线）没有意义
    throw out_of_range("顶点不存在，增加边失败！");
  }

  // 设置为权重，表示顶点 i 和顶点 j 相连
  m_adjMat[i][j] = weight;
  m_adjMat[j][i] = weight;
}

/* 删除边 */
void GraphAdjMat::remove_edge(int v1, int v2) {
  int i = get_index(v1);
  int j = get_index(v2);

  if (i == -1 || j == -1) {
    throw out_of_range("顶点不存在，删除边失败！");
  }

  // 设置为 0，表示顶点 i 和顶点 j 断开连接
  m_adjMat[i][j] = 0;
  m_adjMat[j][i] = 0;
}

/* 打印邻接矩阵 */
void GraphAdjMat::print() const {

  cout << "顶点列表：\n";
  for (const int vertex : m_vertices) {
    cout << vertex << " ";
  }

  cout << "\n\n";

  cout << "邻接矩阵：\n";
  for (const auto &row : m_adjMat) {
    for (const int val : row) {
      cout << val << " ";
    }

    cout << "\n";
  }

  cout << "\n";
}

/* 获取图 */
vector<vector<int>> GraphAdjMat::get_graph() const {
  return m_adjMat;
}