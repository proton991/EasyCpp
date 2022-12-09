#include "catch.hpp"
#include "one_away_lcci.hpp"
#include "sum_list_lcci.hpp"
#include <iostream>

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

//
// Created by cxy on 2022/12/8.
//
