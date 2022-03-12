#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <string.h>
#include "test/catch.hpp"

TEST_CASE("find range in 1 block of continuous range array") {
  int arr[2] = {4,5};
  findRanges(arr,2);
  REQUIRE(ranges[0].lowerLim,4);
  REQUIRE(ranges[0].upperLim,5);
  REQUIRE(ranges[0].samplesNumber,2);
}

TEST_CASE("find range in 1 block of continuous range array") {
  int arr[4] = {4,5,6,7};
  findRanges(arr,4);
  REQUIRE(ranges[0].lowerLim,4);
  REQUIRE(ranges[0].upperLim,7);
  REQUIRE(ranges[0].samplesNumber,4);
}

TEST_CASE("find ranges in 2 blocks continuous range array") {
  int arr[7] = {3,3,5,4,10,11,12};
  findRanges(arr,7);
  REQUIRE(ranges[0].lowerLim,3);
  REQUIRE(ranges[0].upperLim,5);
  REQUIRE(ranges[0].samplesNumber,4);
  
  REQUIRE(ranges[1].lowerLim,10);
  REQUIRE(ranges[1].upperLim,12);
  REQUIRE(ranges[1].samplesNumber,3);
}
