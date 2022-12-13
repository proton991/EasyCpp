#ifndef EASYCPP_ROUTE_BETWEEN_NODES_LCCI_HPP
#define EASYCPP_ROUTE_BETWEEN_NODES_LCCI_HPP

#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

namespace lc {
class RbnSolution {
public:
  bool findWhetherExistsPath(int n, vector<vector<int>> &graph, int start,
                             int target) {
    vector<unordered_set<int>> adjList;
    adjList.resize(n);
    for (const auto &pair: graph) {
      adjList[pair[0]].insert(pair[1]);
    }
    auto neighbours = adjList[start];
    queue<int> q;
    for (auto node: neighbours) {
      q.push(node);
    }
    vector<bool> visited;
    visited.resize(n, false);
    while (!q.empty()) {
      auto node = q.front();
      if (node == target) return true;
      q.pop();
      for (const auto &adj: adjList[node]) {
        if (!visited[adj]) {
          q.push(adj);
          visited[adj] = true;
        }

      }
    }
    return false;
  }
};
}

#endif //EASYCPP_ROUTE_BETWEEN_NODES_LCCI_HPP
