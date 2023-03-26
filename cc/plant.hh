#ifndef PLANT_HH
#define PLANT_HH

#include <string>

class Plant
{
public:

	Id id;
	std::string name;
	char flag_a, flag_b;

	Plant(Id _id, std::string_view _name, char _flag_a, char _flag_b)
		:  id(_id), name(_name), flag_a(_flag_a), flag_b(_flag_b)
	{
	}
};

#endif /* ! PLANT_HH */
