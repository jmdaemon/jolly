#pragma once
#ifndef JOLLY_SPDLOG_H
#define JOLLY_SPDLOG_H

/** Macros for using spdlog library logging in both a library and binary target
  * For more information see: 
  * https://stackoverflow.com/questions/30400286/logging-from-library-with-spdlog
  * https://github.com/gabime/spdlog/issues/1224 */

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

//#define JOLLY_DISABLE_SPDLOG_LOGGING(log_level) \
  //log_level SPDLOG_LEVEL_NONE

/** Enables or disables macro logging with spdlog library
  * Note that if spdlog is not installed this turns into a no-op */
//void toggle_spdlog_macro_logging(bool enable) {
  ////if (!enable) {
//#define SPDLOG_ENABLE enable
//#if !enable
  //#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_NONE 
  ////} else {
//#else 
  //#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
  //}
//}

void disable_spdlog_macro_logging() {
  #define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_NONE 
}

#define USE_JOLLY_SPDLOG_SETUP_LOGGING_FUNCTION \
/* Enable/disable logging */ \
void setup_logging(bool verbose) { \
  if (verbose == 1) \
    spdlog::set_level(spdlog::level::level_enum::trace); \
  else { \
    /* Default to no logging */ \
    spdlog::set_level(spdlog::level::level_enum::off); \
    /* toggle_spdlog_macro_logging(false); \ */ \
    disable_spdlog_macro_logging(); \
  } \
  spdlog::cfg::load_env_levels(); \
  spdlog::set_pattern(logger_format); \
}

#endif // JOLLY_SPDLOG_H
