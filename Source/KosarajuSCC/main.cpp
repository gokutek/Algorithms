﻿#include <iostream>
#include "KosarajuSCC.h"
#include "data_file.h"

int main()
{
	Digraph digraph(get_data_file_path("tinyDG.txt"));
	KosarajuSCC cc(digraph);

	std::vector<std::vector<size_t> > components(cc.Count());
	for (size_t v = 0; v < digraph.V(); ++v) {
		components[cc.Id(v)].push_back(v);
	}

	for (auto &vec : components) {
		for (auto v : vec) {
			std::cout << v << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
