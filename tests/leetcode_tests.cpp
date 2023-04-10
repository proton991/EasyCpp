#include "catch.hpp"
#include "one_away_lcci.hpp"
#include "sum_list_lcci.hpp"
#include "route_between_nodes_lcci.hpp"
#include "sorted_stack_lcci.hpp"
#include "kth_magic_number_lcci.hpp"
#include "find_closest_lcci.hpp"
#include "subsets.hpp"
#include <iostream>
#include <algorithm>

TEST_CASE("Test one way lcci") {
  OneEditAwaySolution solution;
  bool actual = solution.oneEditAway("teacher", "treacher");
  REQUIRE(actual == true);
}

TEST_CASE("Test sum list lcci") {
  SumListLCCISolution solution;
  auto l1 = new ListNode(5);

  auto l2 = new ListNode(5);

  auto res = solution.addTwoNumbers(l1, l2);
  std::cout << *res << std::endl;
}

TEST_CASE("Test route between nodes lcci") {
  int n = 3;
  vector<vector<int>> graph = {{0, 1}, {0, 2}, {1, 2}, {1, 2}};
  RbnSolution solution{};
  bool res = solution.findWhetherExistsPath(n, graph, 0, 2);
  REQUIRE(res == true);
}

TEST_CASE("Test sorted stack lcci") {
  SortedStack sortedStack;
  sortedStack.push(1);
  sortedStack.push(2);
  sortedStack.push(3);

  REQUIRE(sortedStack.peek() == 1);
}

TEST_CASE("Test find closest lcci") {
  FindClosestSolution soultion;
  vector<string> data1 = {"I","am","a","student","from","a","university","in","a","city"};
  int res1 = soultion.findClosest(data1, "a", "student");
  REQUIRE(res1 == 1);
}

TEST_CASE("Test kth magic number lcci") {
  kthMagicNumberSolution solution;
  REQUIRE(solution.getKthMagicNumber(8) == 25);
}

TEST_CASE("Test subsets") {
  vector<int> nums = {1, 2, 3};
  SubsetsSolution solution;
  auto res = solution.subsets(nums);
  vector<vector<int>> expected = {{},{1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}};
  std::sort(expected.begin(), expected.end());
  std::sort(res.begin(), res.end());
  REQUIRE(expected == res);
}
//
// Created by cxy on 2022/12/8.
//
