#include <iostream>
#include <assert.h>
#include <fstream>
#include "DepthFirstPaths.h"


int main()
{
	std::ifstream ifs("../data/tinyCG.txt");
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

	DepthFirstPaths search(G, 0);
	for (size_t i = 0; i < G.V(); ++i) {
		if (!search.HasPathTo(i)) { continue; }
		auto vec = search.PathTo(i);
		std::cout << "0 to " << i << ": ";
		for (auto v : vec) {
			std::cout << v << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
