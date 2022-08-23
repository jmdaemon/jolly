#pragma once
#ifndef JOLLY_H
#define JOLLY_H

#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

// Strings
std::string slurp (const std::string& path);
std::string ltrim(std::string &s);
std::string rtrim(std::string &s);
std::string trim(std::string &s);
std::string unquote(std::string &s);
std::string substitute(std::string str, const std::string& from, const std::string& to);

constexpr unsigned int shash(const char *s, int off);
#endif // JOLLY_H
