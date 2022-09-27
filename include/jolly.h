#pragma once
#ifndef JOLLY_H
#define JOLLY_H

#include <algorithm>
#include <fstream>
#include <iosfwd>
#include <sstream>
#include <string>

#include <iomanip>
#include <chrono>

// Strings
std::string slurp (const std::string& path);
std::string ltrim(std::string &s);
std::string rtrim(std::string &s);
std::string trim(std::string &s);
std::string unquote(std::string &s);
std::string substitute(std::string str, const std::string& from, const std::string& to);

// Misc
std::string prompt(std::string prompt);
std::tm parse_datetime(std::string datetime, std::string format);

// Macros
#define JOLLY_HASH_FUNCTION constexpr unsigned int hash(const char *s, int off = 0) { \
    return !s[off] ? 5381 : (hash(s, off+1)*33) ^ s[off]; \
  }

#endif // JOLLY_H
