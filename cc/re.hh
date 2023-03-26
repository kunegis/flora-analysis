#ifndef RE_HH
#define RE_HH

#include <regex>

bool re_match(std::string s, const char *re)
{
	return std::regex_match(s.c_str(), std::regex(re, std::regex::extended));
}

#endif /* ! RE_HH */
