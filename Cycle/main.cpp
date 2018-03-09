#include <assert.h>
#include <fstream>
#include <iostream>
#include "Cycle.h"


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

	Cycle cycle(G);
	if (cycle.HasCycle()) {
		auto& vec = cycle.GetCircle();
		for (auto v : vec) {
			std::cout << v << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
