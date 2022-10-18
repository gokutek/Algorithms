#include <iostream>
#include <assert.h>
#include <fstream>
#include "DepthFirstSearch.h"


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

	size_t s;
	std::cout << "Input source: ";
	std::cin >> s;

	DepthFirstSearch DFS(G, s);

	size_t v;
	while (std::cin >> v) {
		std::cout << (DFS.Marked(v) ? "connected" : "NOT connected") << std::endl;
	}
	return 0;
}
