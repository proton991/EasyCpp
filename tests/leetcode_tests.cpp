#include "catch.hpp"
#include "one_away_lcci.hpp"
#include <iostream>

TEST_CASE("Test one way lcci") {
  OneEditAwaySolution solution;
  bool actual = solution.oneEditAway("teacher", "treacher");
  REQUIRE(actual == true);
}

//
// Created by cxy on 2022/12/8.
//
