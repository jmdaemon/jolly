// Enable spdlog macros
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

// Build doctest with default main runner
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

// Spdlog
#include <spdlog/logger.h>
#include <spdlog/spdlog.h>
#include <spdlog/cfg/env.h>
#include <spdlog/fmt/fmt.h>
#include <spdlog/fmt/bundled/core.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/ostream_sink.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/sinks/ringbuffer_sink.h>

#include "doctest.h"
#include "jolly_spdlog.h"

// Standard Library
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>

static const std::string logger_name = "jolly";
static const std::string logger_format = "[%Y-%m-%d %H.%M.%S.%e] [%^%l%$] [%s:%#] %v"; /* [2022-08-20 23:16:43.347] [debug] [app.cpp:3] Message! */
//[2022-08-20 23:16:43.347] [debug] [app.cpp:3] Message!
//[2022-09-27 00.23.48.788] [debug] [test_jolly_spdlog.cpp:119] This should log to the debug log level.

USE_JOLLY_SPDLOG_SETUP_LOGGER_FUNCTION
USE_JOLLY_SPDLOG_SETUP_LOGGING_FUNCTION

TEST_CASE("spdlog logging macros log to stdout") {
  // Setup
  std::ostringstream oss;
  const int VERBOSE = 1;
  std::string expect = "This should log to the debug log level.";
  const int LOGLEVEL_BEG = 26; // Offset
  const int LOGLEVEL_END = strlen("[debug]");
  const int LOGMSG_BEG = 61; // Offset

  // Initialize test logger 
  std::vector<spdlog::sink_ptr> sinks;
  auto ostream_sink = std::make_shared<spdlog::sinks::ostream_sink_st>(oss);
  sinks.push_back(ostream_sink);
  fmt::print("Sink Size: {}\n", sinks.size());
  auto logger = setup_logger(sinks);
  spdlog::set_default_logger(logger);
  setup_logging(VERBOSE);
  fmt::print("Spdlog setup finished\n");

  // Test case
  SPDLOG_DEBUG(expect);
  fmt::print("Ran debug message test case\n");

  // Evaluation
  std::string result = oss.str();
  fmt::print("Result: {}\n", result);

  if (result.empty()) {
    fmt::print(stderr, "Result is empty. Exiting...\n");
    exit(1);
  }

  std::string loglevel = result.substr(LOGLEVEL_BEG, LOGLEVEL_END);
  std::string msg = result.substr(LOGMSG_BEG, expect.length());
  fmt::print("Finished evaluation\n");

  // Test
  fmt::print("Running tests\n");
  REQUIRE(result != "");
  CHECK(loglevel == "[debug]");
  CHECK(msg == expect);
}
