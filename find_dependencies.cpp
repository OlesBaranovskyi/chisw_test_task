#include "find_dependencies.h"
pair<string,list<string>> find_dependencies(string name_file)
{
	list<string> includes_files;
	try {
		ostringstream strfile();
		ifstream myfile(name_file, ios::in); // open file for reading
		if (!myfile.is_open()) { throw ifstream::failure::exception("error open file"); }
		stringstream buffer;   // stringstream for convert content file to string
		buffer << myfile.rdbuf();
		string flstr = buffer.str();
		regex words_regex("^#include.*");

		auto words_begin = std::sregex_iterator(flstr.begin(), flstr.end(), words_regex);
		auto words_end = std::sregex_iterator();
		
		for (std::sregex_iterator i = words_begin; i != words_end; ++i)
		{
			std::smatch match = *i;
			std::string match_str = match.str();
			includes_files.push_back(match_str);
		}



	}
	catch (const ifstream::failure::exception &ostr) {
		list<string> tmp_errors{ ostr.what() };
		return{ "errors",tmp_errors };
	}
	

	return  { "includes", includes_files };
}