#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "jolly.h"
#include <fmt/core.h>

// Standard Library
#include <iostream>
#include <sstream>

TEST_CASE("trim() removes whitespace from strings") { 
  std::string s1 = " left";
  std::string s2 = "right ";
  std::string s3 = " both ";

  CHECK(ltrim(s1) == "left");
  CHECK(rtrim(s2) == "right");
  CHECK(trim(s3) == "both");
}

TEST_CASE("unquote() removes embedded quotes in strings") { 
  std::string s = "\"Test\"";
  CHECK(unquote(s) == "Test");
}

TEST_CASE("substitute() replaces substrings in string") { 
  std::string s = "[replace]";
  CHECK(substitute(s, "replace", "new") == "[new]");
}

TEST_CASE("prompt() can reads lines from stdin") {
  std::istringstream iss("5");
  std::cin.rdbuf(iss.rdbuf());
  
  auto result = prompt("Enter any integer: ");
  CHECK(result == "5");
}

TEST_CASE("parse_datetime() parses datetimes") {
  std::string datetime = "2021-07-14T02:10:41Z";
  std::string format;
  SUBCASE("Can parse ISO 8601 Format") {
    datetime = "2022-08-23T21:37:26Z";
    format = "%FT%T%z";
    fmt::print("datetime  : {}\n", datetime);
    fmt::print("format    : {}\n", format);
    auto tm = parse_datetime(datetime, format);

    // Checks
    CHECK(mktime(&tm) != 0);
    CHECK(asctime(&tm) != NULL);
  }
}

// Macro tests
JOLLY_HASH_FUNCTION
TEST_CASE("JOLLY_HASH_FUNCTION expands to hash() function") {
  SUBCASE("hash() create compile time unsigned integers") {
    const char* key = "value";
    unsigned int val = 0;
    switch(hash(key)) {
      case hash("value"):
        val = 1;
        CHECK(val == 1);
    }
  }
}
