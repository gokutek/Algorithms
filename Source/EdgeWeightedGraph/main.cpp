#include <iostream>
#include "EdgeWeightedGraph.h"
#include "data_file.h"

int main()
{
	EdgeWeightedGraph g(get_data_file_path("tinyEWG.txt"));
	return 0;
}
