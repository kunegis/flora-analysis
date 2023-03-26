#ifndef HTML_HH
#define HTML_HH

/* 
 * Output things as HTML. 
 */

#include "log.hh"
#include "flag.hh"

namespace html
{
	void write_all(std::ofstream &o,
		       const Log &log)
	{
		o << "<TABLE>\n";

		for (auto &i:  log.plants) {
			std::string id_text= i.first.to_string(); 
			try {
				std::string color= color_by_flag_b(i.second.flag_b);
			
				o << "<TR><TD style=\"color: "+color+"\">" << id_text
				  << "</TD><TD style=\"color: "+color+"\">" << i.second.name << "</TD></TR>\n";
			} catch (std::runtime_error &e) {
				fprintf(stderr, "*** In plant %s:\n", id_text.c_str());
				throw e;
			}
		}

		o << "</TABLE>\n";
	}
};

#endif /* ! HTML_HH */
