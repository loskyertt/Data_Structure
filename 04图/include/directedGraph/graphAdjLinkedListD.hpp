#include "undirectedGraph/graphAdjLinkedList.hpp"

/* 邻接表（有向图） */
class GraphAdjLinkedListD : public GraphAdjLinkedList {

public:
  GraphAdjLinkedListD(const vector<int> &vertices, const vector<vector<int>> &edges);

  // 重写有向图下的边操作
  /* 添加边 */
  void add_edge(int v1, int v2, int weight = 0) override;

  /* 删除边 */
  void remove_edge(int v1, int v2) override;
};