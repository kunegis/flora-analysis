#ifndef LOG_HH
#define LOG_HH

#include "id.hh"
#include "plant.hh"
#include "re.hh"
#include "string_utils.hh"

#include <format>
#include <fstream>

/*
 * The content of the file 'Flora'.
 */
class Log
{
public:

	std::map <Id, Plant> plants; 
	
	Log();
};

Log::Log()
{
	std::ifstream i("../Flora");

	unsigned id_next_wish= 1;
	
	for (std::string line; std::getline(i, line); ) {
		line= replace_tabs(line);
		if (re_match(line, "[[:space:]]*"))  continue;
		if (line.size() && line[0] == '_')  continue;
		if (re_match(line, "[[:space:]]*[A-Za-z ]+:[[:space:]]*")) continue;

		std::string id_text   = substr_cut(line,   0,   4);
		std::string date_text = substr_cut(line,   5,  15);
		std::string flags_text= substr_cut(line,  16,  18);
		std::string name_text = substr_cut(line,  19,  63);
		std::string desc_text = substr_cut(line,  64,  95);
		std::string src_text  = substr_cut(line,  96, 127);
		std::string log_text  = substr_cut(line, 128, std::string::npos);

		if (flags_text.size() < 2)
			throw std::runtime_error("Missing flags in "+line);
		char flag_a= flags_text[0];
		char flag_b= flags_text[1];
		
		Id id(id_text);
		if (id_text == "W") {
			/* Use auto-increment to give wish plants unique IDs. */
			id_text= std::format("W%u", id_next_wish++);
			xxx change %u to whatever format() uses.;
			id= Id(id_text); 
		}

		Plant plant(id, name_text, flag_a, flag_b);

		plants.insert({id, plant});
	}
}

#endif /* ! LOG_HH */
