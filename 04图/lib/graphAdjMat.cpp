#include "matrix/graphAdjMat.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using std::cout;
using std::out_of_range;

/* 构造方法*/
GraphAdjMat::GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges) {
  // 添加顶点
  for (const int vertex : vertices) {
    add_vertex(vertex);
  }

  // 添加边
  for (const vector<int> &edge : edges) {
    add_edge(edge[0], edge[1]);
  }
}

/* 获取顶点数量 */
int GraphAdjMat::size() const {
  return vertices.size();
}

/* 添加顶点 */
void GraphAdjMat::add_vertex(int val) {
  int n = size();

  vertices.push_back(val);

  // 添加一个节点，就给邻接矩阵增加一行
  adjMat.emplace_back(vector<int>(n, 0));

  // 然后给每一行增加一个 0（表示增加一列）
  // 注意这里 row 前要加 &，因为 row 是一个拷贝，auto row : adjMat 不会修改原始的 adjMat
  for (auto &row : adjMat) {
    row.push_back(0);
  }
}

/* 删除顶点 */
void GraphAdjMat::remove_vertex(int index) {
  if (index < 0 || index >= size()) {
    throw out_of_range("索引不正确！");
  }

  // 擦除顶点列表中的对应顶点
  vertices.erase(vertices.begin() + index);

  // 擦除邻接矩阵中对应 index 的那一行
  adjMat.erase(adjMat.begin() + index);

  // 再擦除每一行对应 index 的元素（擦除 index 列）
  for (auto &row : adjMat) {
    row.erase(row.begin() + index);
  }
}

/* 添加边 */
void GraphAdjMat::add_edge(int i, int j) {
  if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
    // adjMat[i][i] （对角线）没有意义
    throw out_of_range("超出邻接矩阵范围！");
  }

  // 设置为 1，表示顶点 i 和顶点 j 相连
  adjMat[i][j] = 1;
  adjMat[j][i] = 1;
}

/* 删除边 */
void GraphAdjMat::remove_edge(int i, int j) {
  if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
    throw out_of_range("超出邻接矩阵范围！");
  }

  // 设置为 0，表示顶点 i 和顶点 j 断开连接
  adjMat[i][j] = 0;
  adjMat[j][i] = 0;
}

/* 打印邻接矩阵 */
void GraphAdjMat::print() {

  cout << "顶点列表：\n";
  for (const int vertex : vertices) {
    cout << vertex << " ";
  }

  cout << "\n\n";

  cout << "邻接矩阵：\n";
  for (const auto &row : adjMat) {
    for (const int val : row) {
      cout << val << " ";
    }

    cout << "\n";
  }

  cout << "\n";
}