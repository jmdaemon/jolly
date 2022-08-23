#include "jolly.h"

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
