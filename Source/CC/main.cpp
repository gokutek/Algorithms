#include <fstream>
#include <iostream>
#include <assert.h>
#include "CC.h"
#include "data_file.h"

int main()
{
	std::ifstream ifs(get_data_file_path("tinyG.txt"));
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

	CC cc(G);

	std::vector<std::vector<size_t>> components;
	components.resize(cc.Count());
	for (size_t i = 0; i < G.V(); ++i) {
		components[cc.Id(i)].push_back(i);
	}

	for (size_t i = 0; i < components.size(); ++i) {
		for (auto v : components[i]) {
			std::cout << v << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
