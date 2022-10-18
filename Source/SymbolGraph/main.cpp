#include <iostream>
#include "SymbolGraph.h"
#include "data_file.h"

int main()
{
	SymbolGraph sg(get_data_file_path("routes.txt"), ' ');
	return 0;
}
