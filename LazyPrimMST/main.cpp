#include <iostream>
#include "LazyPrimMST.h"

int main()
{
	EdgeWeightedGraph g("../data/tinyEWG.txt");
	LazyPrimMST mst(g);
	return 0;
}
