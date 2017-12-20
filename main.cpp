#include "Header_file.h"
#include "find_dependencies.h"
#include "find_file.h"
void main(int argc, char* argv[] ) {

	Header_file hf = find_file(fs::current_path(),argv[1]);
	
	hf.order.insert( find_dependencies(hf.name_file));
	cout << hf;
		

}