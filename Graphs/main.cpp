#include "Graphs.h"
#include <fstream>
#include <iostream>
#include <assert.h>


/*
===============================================================================
演示：
1. 使用邻接表来表示图；
2. Graphs的实现没有检查自环、平行边；
===============================================================================
*/
int main()
{
	std::ifstream ifs("../data/tinyG.txt");
	assert(ifs.is_open());
	size_t V;
	ifs >> V;
	Graphs G(V);
	size_t E;
	ifs >> E;
	for (size_t i = 0; i < E; ++i) {
		size_t v, w;
		ifs >> v >> w;
		G.AddEdge(v, w);
	}
	std::cout << G.ToString() << std::endl;
	return 0;
}
