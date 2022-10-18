#include <iostream>
#include "PrimMST.h"
#include "data_file.h"

int main()
{
	EdgeWeightedGraph g(get_data_file_path("tinyEWG.txt"));
	PrimMST mst(g);
	std::cout << "weight: " << mst.Weight() << std::endl;
	auto &edges = mst.Edges();
	for (auto e : edges) {
		std::cout << e.Either() << ":" << e.Other(e.Either()) << " " << e.Weight() << std::endl;
	}
	return 0;
}
