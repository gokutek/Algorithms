#include <iostream>
#include "DepthFirstOrder.h"

int main()
{
	Digraph DG("../data/tinyDG.txt");
	DepthFirstOrder dfs(DG);
	return 0;
}
