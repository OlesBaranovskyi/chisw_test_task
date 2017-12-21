#include "Header_file.h"
ostream& operator << (ostream& os, Header_file h_f)
{
	h_f.name_file=="file not found  " ? os<< h_f.name_file : os << h_f.name_file << "    have  next absolute path  " << h_f.path_to_file << endl;
	
	
	if (h_f.order.count("includes")) {
		os << "and have dependencies on next files" << endl;

		copy(h_f.order["includes"].begin(), h_f.order["includes"].end(), std::ostream_iterator<string>(os, " \n"));
	}
	else if(h_f.order.count("errors"))
	{
		os << "and have next errors" << endl;

		copy(h_f.order["errors"].begin(), h_f.order["errors"].end(), std::ostream_iterator<string>(os, " \n"));
	}
	
	os << "---------------------------------------------------------------------------------------------" << endl;
	return os;
}