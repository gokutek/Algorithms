#include <iostream>
#include "KosarajuCC.h"

int main()
{
	Digraph digraph("../data/tinyDG.txt");
	KosarajuCC cc(digraph);

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
