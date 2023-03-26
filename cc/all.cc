#include "html.hh"
#include "log.hh"

#include <stdexcept>

int main()
{
	Log log;

	const char *filename_out= "html/all.html";
	
	std::ofstream o(filename_out);
	html::write_all(o, log); 
	o.close();
	if (o.fail())
		throw std::runtime_error(filename_out); 
	
	return 0;
}
