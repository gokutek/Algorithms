#include <iostream>
#include "TransitiveClosure.h"
#include "data_file.h"

int main()
{
	Digraph DG(get_data_file_path("tinyDG.txt"));
	TransitiveClosure dfs(DG);
	return 0;
}
