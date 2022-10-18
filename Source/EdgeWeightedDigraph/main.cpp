#include <iostream>
#include "EdgeWeightedDigraph.h"
#include "data_file.h"

int main()
{
	EdgeWeightedDigraph g(get_data_file_path("tinyEWD.txt"));
	return 0;
}
