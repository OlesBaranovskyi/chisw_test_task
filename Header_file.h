#pragma once
#include <experimental\filesystem>
#include <regex>
#include <map>
namespace fs = std::experimental::filesystem;
using namespace std;
struct Header_file
{
	string name_file;
	fs::path path_to_file;
	map<string, list<string>> order;
	
};
ostream& operator << (ostream& os, Header_file h_f);





