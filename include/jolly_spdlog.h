#pragma once
#ifndef JOLLY_SPDLOG_H
#define JOLLY_SPDLOG_H

/** Macros for using spdlog library logging in both a library and binary target
  * For more information see: 
  * https://stackoverflow.com/questions/30400286/logging-from-library-with-spdlog
  * https://github.com/gabime/spdlog/issues/1224 */

/** Disables spdlog macro logging statements
  * Note that this function is used internally and you should not really be using this. */
void disable_spdlog_macro_logging() {
  #define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_NONE 
}

// Macros

/** Registers new loggers and creates them if a logger hasn't been made */
#define USE_JOLLY_SPDLOG_SETUP_LOGGER_FUNCTION \
std::shared_ptr<spdlog::logger> setup_logger(std::vector<spdlog::sink_ptr> sinks) { \
  auto logger = spdlog::get(logger_name); \
  if (!logger) { \
    if (sinks.size() > 0) { \
        logger = std::make_shared<spdlog::logger>(logger_name, std::begin(sinks), std::end(sinks)); \
        spdlog::register_logger(logger); \
    } else { \
        logger = spdlog::stdout_color_mt(logger_name); \
    } \
  } \
  return logger; \
}

/* Enable/disable logging */
#define USE_JOLLY_SPDLOG_SETUP_LOGGING_FUNCTION \
void setup_logging(bool verbose) { \
  if (verbose == 1) \
    spdlog::set_level(spdlog::level::level_enum::trace); \
  else { \
    /* Default to no logging */ \
    spdlog::set_level(spdlog::level::level_enum::off); \
    disable_spdlog_macro_logging(); \
  } \
  spdlog::cfg::load_env_levels(); \
  spdlog::set_pattern(logger_format); \
}

/* Initializes the spdlog logger with a dynamic toggle */

#define USE_JOLLY_SPDLOG_INIT_SPDLOG_DYNAMIC_LOGGING_FUNCTION \
void init_spdlog_dynamic_logging(int verbose) { \
  std::vector<spdlog::sink_ptr> sinks; \
  sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>()); \
  auto logger = setup_logger(sinks); \
  /*spdlog::set_default_logger(logger); */ \
  setup_logging(verbose); \
}

#endif // JOLLY_SPDLOG_H
