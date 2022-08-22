#pragma once
#ifndef JOLLY_H
#define JOLLY_H

#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

// Strings
std::string slurp (const std::string& path);
void ltrim(std::string &s);
void rtrim(std::string &s);
void trim(std::string &s);

#endif // JOLLY_H
