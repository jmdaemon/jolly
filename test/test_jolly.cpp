#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "jolly.h"

TEST_CASE("Trim removes whitespace from strings") { 
  std::string s1 = " left";
  std::string s2 = "right ";
  std::string s3 = " both ";

  REQUIRE(ltrim(s1) == "left");
  REQUIRE(rtrim(s2) == "right");
  REQUIRE(trim(s3) == "both");
}
