#include <iostream>
#include "TransitiveClosure.h"

int main()
{
	Digraph DG("../data/tinyDG.txt");
	TransitiveClosure dfs(DG);
	return 0;
}
