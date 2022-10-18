#include "SymbolDigraph.h"
#include "data_file.h"

int main()
{
	SymbolDigraph sg(get_data_file_path("jobs.txt"), '/');
	return 0;
}
