#pragma once

#include <assert.h>
#include <string>
#include <windows.h>

inline std::string get_data_file_path(std::string const& file_name)
{
	char exe_path[256];
	GetModuleFileNameA(NULL, exe_path, sizeof(exe_path));

	while (true)
	{
		*strrchr(exe_path, '\\') = 0;
		char tmp[256];
		strcpy_s(tmp, exe_path);
		strcat(tmp, "\\Datas\\");
		strcat(tmp, file_name.c_str());
		FILE* fp = fopen(tmp, "r");
		if (fp)
		{
			fclose(fp);
			return tmp;
		}
	}

	assert(false);
	return "";
}
