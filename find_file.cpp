#include "find_file.h"
#include "find_dependencies.h"
Header_file find_file(fs::path _path,string file_name)
{
	Header_file tmp_hf;
	try {
		for (auto const &entry : fs::recursive_directory_iterator(fs::current_path(), fs::directory_options::follow_directory_symlink))
		{
			auto temp_file_name = entry.path().string();
			if (fs::is_regular_file(entry) && temp_file_name.find(file_name) != std::wstring::npos)
			{
				fs::path tmp_f_name = entry.path().filename();
				tmp_hf.path_to_file = entry.path();
				tmp_hf.name_file = tmp_f_name.string();
				tmp_hf.order.insert( find_dependencies(tmp_hf.name_file));
				return tmp_hf;
			}
		}
	}
	catch (const out_of_range &e)
	{
		tmp_hf.order["errors"].push_front( e.what());
		return tmp_hf;

	}
	tmp_hf.name_file = "file not found";

	return tmp_hf;
}