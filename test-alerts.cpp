#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <string.h>
#include "test/catch.hpp"
#include "ranges.h"
#include "sort.h"

TEST_CASE("find range in 1 block of continuous range array") {
  int arr[2] = {4,5};
  struct ranges* ranges;
  
  ranges = findRanges(arr,2);
  
  printRanges(ranges);
  
  REQUIRE(ranges[0].lowerLim,4);
  REQUIRE(ranges[0].upperLim,5);
  REQUIRE(ranges[0].numberOfElements,2);
}

TEST_CASE("find range in 1 block of continuous range array") {
  int arr[4] = {4,5,6,7};
  struct ranges* ranges;
  
  ranges = findRanges(arr,4);
  
  printRanges(ranges);
  
  REQUIRE(ranges[0].lowerLim,4);
  REQUIRE(ranges[0].upperLim,7);
  REQUIRE(ranges[0].numberOfElements,4);
}

TEST_CASE("find ranges in 2 blocks continuous range array") {
  int arr[7] = {3,3,5,4,10,11,12};
  struct ranges* ranges;
  
  ranges = findRanges(arr,7);
  
  printRanges(ranges);
  
  REQUIRE(ranges[0].lowerLim,3);
  REQUIRE(ranges[0].upperLim,5);
  REQUIRE(ranges[0].numberOfElements,4);
  
  REQUIRE(ranges[1].lowerLim,10);
  REQUIRE(ranges[1].upperLim,12);
  REQUIRE(ranges[1].numberOfElements,3);
}
