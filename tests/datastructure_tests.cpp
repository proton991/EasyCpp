#include "catch.hpp"
#include "graph.hpp"
#include "node.hpp"

TEST_CASE("node tests") {
  ListNode<int> node0{0};
  ListNode<int> node1{1};
  ListNode<int> node2{2};
  node0.SetNext(&node1);
  node1.SetNext(&node2);

  REQUIRE(node0.GetNext()->GetNext()->GetValue() == 2);
}

TEST_CASE("graph tests") {
  Graph<int> graph(4);
  graph.AddVertex(1);
  graph.AddVertex(2);
  graph.AddVertex(3);
  graph.AddVertex(4);
  graph.AddEdge(0, 1);

  graph.Print();
}