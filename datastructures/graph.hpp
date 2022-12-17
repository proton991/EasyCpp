#ifndef EASYCPP_GRAPH_HPP
#define EASYCPP_GRAPH_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <list>

struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const std::pair<T1, T2>& p) const
  {
    auto hash1 = std::hash<T1>{}(p.first);
    auto hash2 = std::hash<T2>{}(p.second);

    if (hash1 != hash2) {
      return hash1 ^ hash2;
    }

    // If hash1 == hash2, their XOR is zero.
    return hash1;
  }
};

#define INF 0x3f3f3f3f
// iPair ==> Integer Pair
typedef std::pair<int, uint32_t> iPair;
typedef std::pair<uint32_t, uint32_t> EdgeId;

class Edge;

template <class T>
class Vertex {
public:
  Vertex() = default;
  explicit Vertex(uint32_t id_, const T& data_) : id(id_), data(data_) {}

  Vertex& operator=(const Vertex& v) {
    id      = std::move(v.id);
    data    = std::move(v.data);
    visited = v.visited;
    adjList = std::move(v.adjList);
    return *this;
  }

  void AddNeighbour(uint32_t nodeId) { adjList.emplace_back(nodeId); }

  [[nodiscard]] uint32_t GetId() const { return id; }

  const T& GetData() const { return data; }

  [[nodiscard]] const std::list<uint32_t>& GetNeighbours() const { return adjList; }

private:
  uint32_t id;
  T data;
  std::list<uint32_t> adjList;
  bool visited{false};
};

struct Edge {
  Edge() = default;
  Edge(uint32_t srcId_, uint32_t dstId_) : srcId(srcId_), dstId(dstId_) {}
  Edge(uint32_t srcId_, uint32_t dstId_, int w) : srcId(srcId_), dstId(dstId_), weight(w) {}
  uint32_t srcId{};
  uint32_t dstId{};
  int weight{0};
};

template <class T, bool DIRECTED>
class Graph {
public:
  explicit Graph(uint32_t capacity) : m_capacity(capacity) { m_adjList.reserve(capacity); }

  void AddVertex(uint32_t vertexId, const T& data) {
    if (m_vertexCount >= m_capacity)
      return;
    Vertex<T> v(vertexId, data);
    m_vertices[vertexId] = v;
    m_vertexCount++;
  }

  void AddEdge(uint32_t srcId, uint32_t dstId, int weight) {
    if (!DIRECTED) {
      Edge edge1{srcId, dstId, weight};
      Edge edge2{dstId, srcId, weight};
      m_edges[std::make_pair(srcId, dstId)] = edge1;
      m_edges[std::make_pair(dstId, srcId)] = edge2;
      m_vertices[srcId].AddNeighbour(dstId);
      m_vertices[dstId].AddNeighbour(srcId);
      m_adjList[srcId].emplace_back(dstId);
      m_adjList[dstId].emplace_back(srcId);
    } else {
      Edge edge{srcId, dstId, weight};
      m_edges[std::make_pair(srcId, dstId)] = edge;
      m_vertices[srcId].AddNeighbour(dstId);
      m_adjList[srcId].emplace_back(dstId);
    }
  }

  void Print() {
    std::cout << "graph vertices: \n";
    for (const auto& entry : m_vertices) {
      std::cout << "id: " << entry.first << "; data: " << entry.second.GetData() << "\n";
      std::cout << "neighbours: \n";
      for (const auto& v : m_adjList[entry.first]) {
        std::cout << v << " ";
      }
      std::cout << std::endl;
    }
    std::cout << "graph edges: \n";
    for (const auto& it : m_edges) {
      std::cout << "src: " << it.second.srcId << "; dst: " << it.second.dstId << "; weight: " << it.second.weight << "\n";
    }
  }

  int Dijkstra(uint32_t srcId, uint32_t dstId) {
    std::priority_queue<iPair, std::vector<iPair>, std::greater<>> pq;
    std::unordered_map<uint32_t, int> dist;
    for (const auto& it : m_vertices) {
      dist[it.first] = INF;
    }
    pq.push(std::make_pair(0, srcId));
    dist[srcId] = 0;

    while (!pq.empty()) {
      uint32_t v = pq.top().second;
      pq.pop();
      for (const auto& u : m_adjList[v]) {
        EdgeId edgeId = std::make_pair(v, u);
        Edge edge = m_edges[edgeId];
        if (dist[u] > dist[v] + edge.weight) {
          dist[u] = dist[v] + edge.weight;
          pq.push(std::make_pair(dist[u], u));
        }
      }
    }

    std::cout << "Vertex\tDistance\n";
    for (const auto& it : dist) {
      std::cout.width(5);
      std::cout << it.first << "\t" << it.second << "\n";
    }
    return dist[dstId];
  }

  int FloydWarshall(int srcId, int dstId) {
    std::vector<std::vector<int>> dist(m_vertexCount, std::vector<int>(m_vertexCount, INF));
    for (const auto& entry : m_edges) {
      auto i = entry.first.first, j = entry.first.second;
      dist[i][j] = entry.second.weight;
      dist[j][i] = entry.second.weight;
    }
    for (int k = 0; k < m_vertexCount; k++) {
      for (int i = 0; i < m_vertexCount; i++) {
        for (int j = 0; j < m_vertexCount; j++) {
          if (dist[i][k] == INF || dist[k][j] == INF)
            continue;
          if (dist[i][j] > dist[i][k] + dist[k][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
    }
    return dist[srcId][dstId];
  }
private:
  uint32_t m_capacity;
  uint32_t m_vertexCount{0};
  std::unordered_map<uint32_t, Vertex<T>> m_vertices;
  std::unordered_map<uint32_t, std::vector<uint32_t>> m_adjList;
  std::unordered_map<EdgeId, Edge, hash_pair> m_edges;
};

#endif  //EASYCPP_GRAPH_HPP
