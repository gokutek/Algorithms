#include <assert.h>
#include <fstream>
#include <iostream>
#include "Cycle.h"
#include "data_file.h"

int main()
{
	// 从文件中反序列化创建图
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

		Cycle cycle(G);
		if (cycle.HasCycle()) {
			auto& vec = cycle.GetCircle();
			for (auto v : vec) {
				std::cout << v << " ";
			}
			std::cout << std::endl;
		}
	}

	// 含有自环的图
	{
		Graphs G(5);
		G.AddEdge(1, 1);

		Cycle cycle(G);
		if (cycle.HasCycle()) {
			auto& vec = cycle.GetCircle();
			for (auto v : vec) {
				std::cout << v << " ";
			}
			std::cout << std::endl;
		}
	}

	// 含有平行边的图
	{
		Graphs G(5);
		G.AddEdge(1, 2);
		G.AddEdge(1, 2);

		Cycle cycle(G);
		if (cycle.HasCycle()) {
			auto& vec = cycle.GetCircle();
			for (auto v : vec) {
				std::cout << v << " ";
			}
			std::cout << std::endl;
		}
	}


	
	return 0;
}
