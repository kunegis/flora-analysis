#ifndef FLAG_HH
#define FLAG_HH

#include <stdexcept>

std::string color_by_flag_b(char flag_b)
{
	switch (flag_b) {
	case ' ':
		return "#000000";
	case 'D':  case 'G':  case 'E':  case 'L':
		return "#666666";
	case 'S':
		return "#000066";
	case 'W':
		return "#884400";
	default:
		throw std::runtime_error(std::string("Invalid flag_b «")+flag_b+"»");
	}
}

#endif /* ! FLAG_HH */
