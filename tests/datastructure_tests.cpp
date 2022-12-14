#include "catch.hpp"
#include "graph.hpp"
#include "node.hpp"
#include "stack.hpp"
#include "deque.hpp"

TEST_CASE("node tests") {
  ListNode<int> node0{0};
  ListNode<int> node1{1};
  ListNode<int> node2{2};
  node0.SetNext(&node1);
  node1.SetNext(&node2);

  REQUIRE(node0.GetNext()->GetNext()->GetItem() == 2);
}

TEST_CASE("stack tests") {
  Stack<int> st;
  st.Push(1);
  st.Push(2);
  st.Push(3);
  REQUIRE(st.GetSize() == 3);
  REQUIRE(st.IsEmpty() == false);
  REQUIRE(st.Top() == 3);
  st.Pop();
  st.Pop();
  st.Pop();
  REQUIRE(st.Pop() == false);
  REQUIRE(st.IsEmpty() == true);
}

TEST_CASE("graph tests") {
  Graph<std::string, false> graph(9);
  graph.AddVertex(0, "v1");
  graph.AddVertex(1, "v2");
  graph.AddVertex(2, "v3");
  graph.AddVertex(3, "v4");
  graph.AddVertex(4, "v5");
  graph.AddVertex(5, "v6");
  graph.AddVertex(6, "v7");
  graph.AddVertex(7, "v8");
  graph.AddVertex(8, "v9");
  graph.AddEdge(0, 1, 4);
  graph.AddEdge(0, 7, 8);
  graph.AddEdge(1, 2, 8);
  graph.AddEdge(1, 7, 11);
  graph.AddEdge(2, 3, 7);
  graph.AddEdge(2, 8, 2);
  graph.AddEdge(2, 5, 4);
  graph.AddEdge(3, 4, 9);
  graph.AddEdge(3, 5, 14);
  graph.AddEdge(4, 5, 10);
  graph.AddEdge(5, 6, 2);
  graph.AddEdge(6, 7, 1);
  graph.AddEdge(6, 8, 6);
  graph.AddEdge(7, 8, 7);

  graph.Print();
  REQUIRE(graph.Dijkstra(0, 8) == 14);
  REQUIRE(graph.FloydWarshall(0, 8) == 14);
}

TEST_CASE("deque test") {
  Deque<int> deque;
  deque.PushBack(1);
  deque.PushBack(2);
  deque.PushBack(3);

  REQUIRE(deque.Front() == 1);
  deque.PopFront();
  REQUIRE(deque.Front() == 2);
  deque.PopFront();
  REQUIRE(deque.Front() == 3);
  deque.PopFront();

  REQUIRE(deque.IsEmpty() == true);
}