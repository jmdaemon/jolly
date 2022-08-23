#include "jolly.h"

/** Read file into string */
std::string slurp (const std::string& path) {
  std::ostringstream buf; 
  std::ifstream input (path.c_str()); 
  buf << input.rdbuf(); 
  return buf.str();
}

/** Trim from start (in place) */
void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

/** Trim from end (in place) */
void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

/** Trim from both ends (in place) */
void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

/** Removes quotes in a string */
std::string unquote(std::string s) {
  s.erase(remove( s.begin(), s.end(), '\"' ),s.end());
  return s;
}
