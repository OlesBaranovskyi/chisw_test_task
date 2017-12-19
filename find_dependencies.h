#pragma once
#include <experimental\filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;
pair<string,list<string>> find_dependencies(string name_file);
