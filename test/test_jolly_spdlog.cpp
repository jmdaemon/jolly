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

//USE_JOLLY_SPDLOG_SETUP_LOGGER_FUNCTION
//std::shared_ptr<spdlog::logger> setup_logger(std::vector<spdlog::sink_ptr> sinks) {
  //auto logger = spdlog::get(logger_name);
  //if (!logger) {
    //if (sinks.size() > 0) {
        //logger = std::make_shared<spdlog::logger>(logger_name, std::begin(sinks), std::end(sinks));
        //spdlog::register_logger(logger);
    //} else {
        ////logger = spdlog::stdout_color_mt(logger_name);
        ////logger = spdlog::ostream_sink_mt::ostream_sink_mt(logger_name);
        ////logger = spdlog::ostream_sink(logger_name);
        ////logger = spdlog::sinks::ostream_sink_mt(logger_name);
    //} 
  //} 
  //return logger; 
//}

USE_JOLLY_SPDLOG_SETUP_LOGGER_FUNCTION
USE_JOLLY_SPDLOG_SETUP_LOGGING_FUNCTION

//void init_logger(int verbose) {

//std::shared_ptr<spdlog::logger> init_logger(int verbose) {
  //std::vector<spdlog::sink_ptr> sinks;
  ////sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
  ////sinks.push_back(std::make_shared<spdlog::sinks::ostream_sink_st>());
  //sinks.push_back(std::make_shared<spdlog::sinks::ringbuffer_sink_mt>());
  //auto logger = setup_logger(sinks);
  //setup_logging(verbose);
  //return logger;
//}

TEST_CASE("spdlog logging macros log to stdout") {
  // Setup
  //std::ios_base::fmtflags restore_cout_buffer( std::cout.flags() );

  //std::ios old_state(nullptr);
  //old_state.copyfmt(std::cout);

  std::ostringstream oss;
  //std::istringstream oss;
  //std::stringstream oss;
  //std::stringstream oss;
  //std::streambuf * old = std::cout.rdbuf(oss.rdbuf());

  //std::cin.rdbuf(oss.rdbuf());

  //std::cout.rdbuf(oss.rdbuf());
  const int VERBOSE = 1;
  //auto logger = init_logger(VERBOSE);

  std::vector<spdlog::sink_ptr> sinks;
  //sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
  //sinks.push_back(std::make_shared<spdlog::sinks::ostream_sink_st>());
  //auto rbuffer = std::make_shared<spdlog::sinks::ringbuffer_sink_mt>();
  //auto rbuffer = std::make_shared<spdlog::sinks::ringbuffer_sink_st>(5);

  //auto rbuffer = std::make_shared<spdlog::sinks::ringbuffer_sink_mt>(5);
  //sinks.push_back(rbuffer);

  //auto ostream_sink = std::make_shared<spdlog::sinks::ostream_sink_mt> (oss);
  auto ostream_sink = std::make_shared<spdlog::sinks::ostream_sink_st> (oss);
  sinks.push_back(ostream_sink);
  fmt::print("Sink Size: {}\n", sinks.size());

  auto logger = setup_logger(sinks);
  spdlog::set_default_logger(logger);
  setup_logging(VERBOSE);
  
  std::string expect = "This should log to the debug log level.";
  //const int LOGLEVEL_BEG = 27;
  //const int LOGLEVEL_END = 33;

  const int LOGLEVEL_BEG = 26;
  //const int LOGLEVEL_END = 32;
  const int LOGLEVEL_END = strlen("[debug]");

  //const int LOGLEVEL_BEG = 26;
  //const int LOGLEVEL_END = 27;
  //const int LOGLEVEL_END = 30;


  //const int LOGMSG_BEG = 47;

  fmt::print("Spdlog setup finished\n");

  // Test case
  SPDLOG_DEBUG(expect);
  fmt::print("Ran debug message test case\n");

  // Evaluation
  //std::cout.flags(restore_cout_buffer);
  //std::cout.copyfmt(old_state);
  //std::cout.rdbuf(old_state.rdbuf());
  logger->flush();

  std::string result = oss.str();
  fmt::print("Result: {}\n", result);

  //auto val = logger->sinks().front().get();
  //std::string result = logger->sinks().front().get();
  //std::vector<std::string> results = rbuffer->last_formatted();
  //std::vector<std::string> results = rbuffer->last_formatted();

  //std::vector<std::string> results = rbuffer->last_formatted();
  //fmt::print("Showing results: \n");
  //puts("Showing results: \n");
  //for (auto r: results) {
    //fmt::print("r: {}\n", r);
  //}

  //std::string result = results.front();
  //std::string result = results.at(0);

  //std::string result = results.begin()[0];
  //std::string result = nullptr;
  //std::cout.rdbuf(old);
  //std::string msg = result.substr(LOGMSG_BEG, result.length());
  if (result.empty()) {
    fmt::print(stderr, "Result is empty. Exiting...\n");
    exit(1);
  }
  std::string loglevel = result.substr(LOGLEVEL_BEG, LOGLEVEL_END);

  //auto lb = result.find("[debug]");
  //auto rb = result.rfind("[debug]");

  //std::string loglevel = result.substr(lb, rb);

  fmt::print("Finished evaluation\n");

  // Test
  fmt::print("Running tests\n");
  //printf("Result: %s\n", result.c_str());
  REQUIRE(result != "");
  CHECK(loglevel == "[debug]");

  //CHECK(msg == expect);

  //std::cout << 
  //auto result  oss.rdbuf();
  //auto result = ("Enter any integer: ");
  //CHECK(result == "5");
}
