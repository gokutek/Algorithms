#include <iostream>
#include "DepthFirstOrder.h"
#include "data_file.h"

int main()
{
	Digraph DG(get_data_file_path("tinyDG.txt"));
	DepthFirstOrder dfs(DG);
	return 0;
}
