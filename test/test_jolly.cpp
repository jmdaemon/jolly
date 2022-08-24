#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "jolly.h"
#include <fmt/core.h>

void show_tm(std::tm tm) {
    fmt::print("Time Struct:");
    fmt::print("tm.tm_year : {}\n", tm.tm_year); // Date
    fmt::print("tm.tm_mon  : {}\n", tm.tm_mon);
    fmt::print("tm.tm_mday : {}\n", tm.tm_mday);

    fmt::print("tm.tm_hour : {}\n", tm.tm_hour); // Time
    fmt::print("tm.tm_min  : {}\n", tm.tm_min);
    fmt::print("tm.tm_sec  : {}\n", tm.tm_sec);
}

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

TEST_CASE("prompt() substrings in string") { 
  //prompt("Enter any integer: ");
  //std::cout << 5 << std::endl;

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
    show_tm(tm);

    // Checks
    CHECK(tm.tm_year == 2001);
    CHECK(tm.tm_yday == 07);
    CHECK(tm.tm_yday == 07);
  }
}
