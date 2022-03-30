#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <string.h>
#include "test/catch.hpp"
#include "ranges.h"
#include "sort.h"
#include "converters.h"

TEST_CASE("find range in 1 block of continuous range array") {
  int arr[2] = {4,5};
  struct ranges* ranges;
  
  ranges = findRanges(arr,2);
  
  printRanges(ranges);
  
  REQUIRE((ranges[0].lowerLim) == 4);
  REQUIRE((ranges[0].upperLim) == 5);
  REQUIRE((ranges[0].numberOfElements) == 2);
}

TEST_CASE("find range in 1 block of continuous range array with different input") {
  int arr[4] = {4,5,6,7};
  struct ranges* ranges;
  
  ranges = findRanges(arr,4);
  
  printRanges(ranges);
  
  REQUIRE((ranges[0].lowerLim) == 4);
  REQUIRE((ranges[0].upperLim) == 7);
  REQUIRE((ranges[0].numberOfElements) == 4);
}

TEST_CASE("find ranges in 2 blocks continuous range array") {
  int arr[7] = {3,3,5,4,10,11,12};
  struct ranges* ranges;
  
  ranges = findRanges(arr,7);
  
  printRanges(ranges);
  
  REQUIRE((ranges[0].lowerLim) == 3);
  REQUIRE((ranges[0].upperLim) == 5);
  REQUIRE((ranges[0].numberOfElements) == 4);
  
  REQUIRE((ranges[1].lowerLim) == 10);
  REQUIRE((ranges[1].upperLim) == 12);
  REQUIRE((ranges[1].numberOfElements) == 3);
}

TEST_CASE("check if convert function works") {
  int analogValue = 1146, digitalValue;
  
  digitalValue = currentConvereterD2A(analogValue);
  REQUIRE(digitalValue == 3);
  
  analogValue = 3400;
  digitalValue = currentConvereterD2A(analogValue);
  REQUIRE(digitalValue == 8);
}

TEST_CASE("check if convert array function works") {
  int arr[7] = {3400,0,1146,4095,500,249,1238};
  
  currentArrayConvertersD2A(arr,7);
  REQUIRE(arr[0] == 8);
  REQUIRE(arr[1] == 0);
  REQUIRE(arr[2] == 3);
  REQUIRE(arr[3] == 4095);
  REQUIRE(arr[4] == 1);
  REQUIRE(arr[5] == 1);
  REQUIRE(arr[6] == 3);
}

TEST_CASE("end to end test case, convert analog to amp value then find ranges") {
  int arr[7] = {1146,1238,2047,1638,4094,4503,4913};//{3,3,5,4,10,11,12}
  struct ranges* ranges;
  
  currentArrayConvertersD2A(arr,7);
  REQUIRE(arr[0] == 3);
  REQUIRE(arr[1] == 3);
  REQUIRE(arr[2] == 5);
  REQUIRE(arr[3] == 4);
  REQUIRE(arr[4] == 10);
  REQUIRE(arr[5] != 11);//for a 12 bit number 4503 will cause an overflow ideally and hence this should be !=11
  REQUIRE(arr[5] == 1);
  REQUIRE(arr[6] != 12);//for a 12 bit number 4913 will cause an overflow ideally and hence this should be !=12
  REQUIRE(arr[6] == 2);
  
  for(int i=0; i<7 ; i++)
    printf("\n%d",arr[i]);
  
  ranges = findRanges(arr,7);
  
  printRanges(ranges);
  
  REQUIRE((ranges[0].lowerLim) == 1);
  REQUIRE((ranges[0].upperLim) == 5);
  REQUIRE((ranges[0].numberOfElements) == 6);
  
  REQUIRE((ranges[1].lowerLim) == 10);
  REQUIRE((ranges[1].upperLim) == 0);
  REQUIRE((ranges[1].numberOfElements) == 1);
  
}
