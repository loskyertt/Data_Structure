#include "graph_factory.hpp"
#include <climits>
#include <functional>
#include <iostream>
#include <stack>
#include <tuple>

using std::cout;
using std::function;
using std::stack;
using std::tuple;

/* dijkstra 单源最短路径算法 */
tuple<vector<int>, vector<int>> dijkstra(const vector<vector<int>> &adjMat, const int &start_idx) {
  int size = adjMat.size();

  vector<bool> visited(size, false);       // 访问控制数组，与 vertices 中的索引相对应
  vector<int> distance(adjMat[start_idx]); // 存放起点 start_idx 到其它各顶点的最短距离
  vector<int> path(size, -1);              // 存放当前顶点的前一个顶点

  visited[start_idx] = true; // 起点设置为访问过

  int next_idx;

  // 用于选出下个顶点
  function<int()> choose_idx = [&distance, &visited, &size]() {
    int min_distance = INT_MAX;
    int min_position;

    for (int i = 0; i < size; ++i) {
      // 找出距离最短的那条路径
      if (distance[i] < min_distance && visited[i] == false) {
        min_distance = distance[i];
        min_position = i;
      }
    }

    return min_position;
  };

  for (int i = 1; i < size; ++i) {
    next_idx = choose_idx();
    visited[next_idx] = true;

    for (int j = 0; j < size; ++j) {
      // 比如：若 c 没被访问过，且 distance(a->b->c) < distance(a->c)，则更新距离
      if (visited[j] == false && adjMat[next_idx][j] != INT_MAX && distance[next_idx] + adjMat[next_idx][j] < distance[j]) {
        distance[j] = distance[next_idx] + adjMat[next_idx][j];
        path[j] = next_idx; //
      }
    }
  }

  // 优化 path 的输出
  for (int k = 0; k < size; ++k) {
    if (k != start_idx && path[k] == -1) {
      path[k] = start_idx;
    }
  }

  return {distance, path};
}

int main() {
  vector<char> vertices = {'a', 'b', 'c', 'd', 'e', 'f'};
  vector<Edge<char>> edges = {
      // {v1(index), v2(index), weight}
      {'a', 'b', 2},
      {'a', 'c', 5},
      {'b', 'c', 1},
      {'b', 'd', 3},
      {'c', 'd', 3},
      {'c', 'e', 4},
      {'c', 'f', 1},
      {'d', 'e', 1},
      {'d', 'f', 4},
      {'e', 'f', 1}};

  // 创建邻接矩阵图（有向带权图）
  auto matGraphD = GraphFactory<char>::createGraph(GraphType::ADJACENCY_MATRIX_DIRECTED, vertices, edges);

  matGraphD->print();

  // 获取图
  auto *matGraphRaw = dynamic_cast<GraphAdjMat<char> *>(matGraphD.get());
  vector<vector<int>> adjMat = matGraphRaw->get_graph();

  auto [distance, path] = dijkstra(adjMat, 0);

  for (int i = 0; i < vertices.size(); i++) {

    stack<int> stk; // 因为是倒着往回推的，为了保证顺序，需要用栈来反转下
    int cur = i;    // 不能修改 i，使用 cur 代替
    while (path[cur] != -1) {
      stk.push(path[cur]);
      cur = path[cur]; // 这里用 cur 记录当前顶点的前驱顶点
    }

    cout << vertices[i] << "(distance = " << distance[i] << ")" << "：";
    while (!stk.empty()) {
      cout << vertices[stk.top()] << " -> ";
      stk.pop();
    }
    cout << vertices[i] << "\n"; // 最后输出终点
  }

  return 0;
}