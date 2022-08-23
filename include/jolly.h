#pragma once
#ifndef JOLLY_H
#define JOLLY_H

#include <algorithm>
#include <fstream>
#include <iosfwd>
#include <sstream>
#include <string>

// Strings
std::string slurp (const std::string& path);
std::string ltrim(std::string &s);
std::string rtrim(std::string &s);
std::string trim(std::string &s);
std::string unquote(std::string &s);
std::string substitute(std::string str, const std::string& from, const std::string& to);

// Misc
constexpr unsigned int shash(const char *s, int off = 0);
std::string prompt(std::string prompt);
#endif // JOLLY_H
