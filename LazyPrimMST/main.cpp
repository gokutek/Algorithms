#include <iostream>
#include "LazyPrimMST.h"

int main()
{
	EdgeWeightedGraph g("../data/tinyEWG.txt");
	LazyPrimMST mst(g);
	std::cout << "weight: " << mst.Weight() << std::endl;
	return 0;
}
