#ifndef ID_HH
#define ID_HH

#include <stdexcept>
#include <string>
#include <string_view>

#include <cassert>
#include <climits>
#include <cstring>

/* 
 * The ID of a plant.  Stored as a right-aligned char array.  Unused chars are
 * '\0'.  
 */
class Id
{
public:
	static constexpr int len= 4;

	char c[len]= {};

	Id(std::string_view s)
	{
		assert(s.size() <= len);

		memcpy(c + len - s.size(), s.data(), s.size());
	}

	std::string to_string() const
	{
		int i= 0;
		while (i < len && c[i] == ' ')
			++i;
		return std::string(c+i, len-i);
	}
	
	bool operator<(const Id &id) const
	{
		assert(CHAR_BIT * sizeof(c) == 32);
		using c_t= uint32_t;
		return *(const c_t *)this->c < *(const c_t *)id.c;
	}
};

constexpr Id id_with{"W"};

#endif /* ! ID_HH */
