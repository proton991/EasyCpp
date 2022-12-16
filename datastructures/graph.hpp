#ifndef EASYCPP_GRAPH_HPP
#define EASYCPP_GRAPH_HPP

#include <iostream>
#include <vector>

class Edge;
template <class T>
class Graph;

template <class T>
class Vertex {
public:
  Vertex() = default;
  explicit Vertex(const T& data_) : data(data_), id(GLOBAL_ID++) {}

  Vertex& operator=(const Vertex& v) {
    id      = std::move(v.id);
    data    = std::move(v.data);
    adj     = std::move(v.adj);
    visited = v.visited;
    return *this;
  }

  void AddNeighbour(uint32_t nodeId) { adj.emplace_back(nodeId); }

  [[nodiscard]] uint32_t GetId() const { return id; }

  const T& GetData() const { return data; }

  [[nodiscard]] const std::vector<uint32_t>& GetNeighbours() const { return adj; }

private:
  uint32_t id;
  T data;
  std::vector<uint32_t> adj;
  bool visited{false};

private:
  inline static uint32_t GLOBAL_ID = 0;
};

struct Edge {
  Edge(uint32_t srcId_, uint32_t dstId_) : srcId(srcId_), dstId(dstId_) {}
  uint32_t srcId{};
  uint32_t dstId{};
  int weight{0};
};

template <class T>
class Graph {
public:
  explicit Graph(uint32_t capacity) : m_capacity(capacity) { m_vertices.reserve(capacity); }

  void AddVertex(const T& data) {
    if (m_vertexCount >= m_capacity)
      return;
    Vertex<T> v(data);
    m_vertices[v.GetId()] = v;
  }

  void AddEdge(uint32_t srcId, uint32_t dstId) {
    Edge edge{srcId, dstId};
    m_edges.emplace_back(edge);
    m_vertices[srcId].AddNeighbour(dstId);
    m_vertices[dstId].AddNeighbour(srcId);
  }

  void Print() const {
    for (const auto& it : m_vertices) {
      std::cout << "id: " << it.first << "; data: " << it.second.GetData() << "\n";
      for (const auto& id : it.second.GetNeighbours()) {
        std::cout << "neighbour id: " << id << "\n";
      }
    }
    for (const auto& edge : m_edges) {
      std::cout << "src: " << edge.srcId << "; dst: " << edge.dstId << "\n";
    }
  }

private:
  uint32_t m_capacity;
  uint32_t m_vertexCount{0};
  std::unordered_map<uint32_t, Vertex<T>> m_vertices;
  std::vector<Edge> m_edges;
};

#endif  //EASYCPP_GRAPH_HPP
