#ifndef STRING_UTILS_HH
#define STRING_UTILS_HH

#include <string>
#include <string_view>

#include <cassert>

/*
 * Replace tabs by spaces, assuming 8-char tab stops, and each byte taking one
 * position.  
 */ 
std::string replace_tabs(std::string_view line)
{
	std::string ret;

	for (char c:  line) {
		if (c == '\t') {
			int count= (-ret.size()-1) % 8 + 1;
			assert(count > 0 && count <= 8);
			ret += std::string(count, ' '); 
		} else {
			ret += c;
		}
	}

	return ret;
}

/* 
 * Extract a substring, allowing POS to be past the end of LINE.  END may be
 * 'npos'.  
 */
std::string substr_cut(const std::string &line, std::string::size_type pos, std::string::size_type end)
{
	if (line.size() < pos)
		return {};
	if (end == std::string::npos)
		return line.substr(pos, std::string::npos);
	return line.substr(pos, end-pos); 
}

#endif /* ! STRING_UTILS_HH */
