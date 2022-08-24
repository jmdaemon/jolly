#include "jolly.h"
#include <iostream>

/** Read file into string */
std::string slurp (const std::string& path) {
  std::ostringstream buf; 
  std::ifstream input (path.c_str()); 
  buf << input.rdbuf(); 
  return buf.str();
}

/** Trim from start */
std::string ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    return s;
}

/** Trim from end */
std::string rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
    return s;
}

/** Trim from both ends */
std::string trim(std::string &s) {
  auto stripped = ltrim(s);
  return(rtrim(stripped));
}

/** Removes quotes in a string */
std::string unquote(std::string &s) {
  s.erase(remove( s.begin(), s.end(), '\"' ),s.end());
  return s;
}

/** Replace parts of strings */
std::string substitute(std::string str, const std::string& from, const std::string& to) {
  size_t start_pos = 0;
  while((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
  }
  return str;
}

/** Prompts a user for input from the command line */
std::string prompt(std::string prompt) {
  std::string input = "";
  std::cout << prompt;
  while (std::getline(std::cin, input))
    return input;
  return input;
}

/** Parse a datetime string according to any arbitrary datetime format */
std::tm parse_datetime(std::string datetime, std::string format) {
  std::tm tm = {};
  std::stringstream ss(datetime);
  ss >> std::get_time(&tm, format.c_str());
  return tm;
}
