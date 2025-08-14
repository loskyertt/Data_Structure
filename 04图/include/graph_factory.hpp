#include "undirectedGraph/graphAdjLinkedList.hpp"
#include "undirectedGraph/graphAdjMat.hpp"
#include <memory>

/* 图的类型枚举 */
enum class GraphType {
  ADJACENCY_MATRIX,
  ADJACENCY_LIST
};

/* 图的工厂类 */
class GraphFactory {
public:
  static std::unique_ptr<IGraph> createGraph(
      GraphType type,
      const vector<int> &vertices,
      const vector<vector<int>> &edges) {
    switch (type) {
    case GraphType::ADJACENCY_MATRIX:
      return std::make_unique<GraphAdjMat>(vertices, edges);
    case GraphType::ADJACENCY_LIST:
      return std::make_unique<GraphAdjLinkedList>(vertices, edges);
    default:
      throw std::invalid_argument("Unknown graph type");
    }
  }
};