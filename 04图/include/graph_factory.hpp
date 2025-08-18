#include "directedGraph/graphAdjLinkedListD.hpp"
#include "directedGraph/graphAdjMatD.hpp"
#include "undirectedGraph/graphAdjLinkedList.hpp"
#include "undirectedGraph/graphAdjMat.hpp"
#include <memory>

/* 图的类型枚举 */
enum class GraphType {
  ADJACENCY_MATRIX_UNDIRECTED,
  ADJACENCY_LIST_UNDIRECTED,
  ADJACENCY_MATRIX_DIRECTED,
  ADJACENCY_LIST_DIRECTED
};

/* 图的工厂类 */
template <typename VertexType>
class GraphFactory {
public:
  static std::unique_ptr<IGraph<VertexType>> createGraph(GraphType type, const vector<VertexType> &vertices, const vector<Edge<VertexType>> &edges) {
    // 选择
    switch (type) {
    // 邻接矩阵（无向图）
    case GraphType::ADJACENCY_MATRIX_UNDIRECTED:
      return std::make_unique<GraphAdjMat<VertexType>>(vertices, edges);

    // 邻接链表（无向图）
    case GraphType::ADJACENCY_LIST_UNDIRECTED:
      return std::make_unique<GraphAdjLinkedList<VertexType>>(vertices, edges);

    // 邻接矩阵（有向图）
    case GraphType::ADJACENCY_MATRIX_DIRECTED:
      return std::make_unique<GraphAdjMatD<VertexType>>(vertices, edges);

    // 邻接链表（无向图）
    case GraphType::ADJACENCY_LIST_DIRECTED:
      return std::make_unique<GraphAdjLinkedListD<VertexType>>(vertices, edges);

    default:
      throw std::invalid_argument("Unknown graph type!");
    }
  }
};