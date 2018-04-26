#include <iostream>
#include <algorithm>
#include "DirectedCycle.h"

int main()
{
	Digraph DG(6);
	DG.AddEdge(0, 5);
	DG.AddEdge(3, 5);
	DG.AddEdge(5, 4);
	DG.AddEdge(4, 3);
	size_t const source = 9;
	DirectedCycle cycle(DG);
	if (cycle.HasCycle()) {
		auto &vec = cycle.Cycle();
		std::for_each(vec.begin(), vec.end(), [](size_t v) {
			std::cout << v << " ";
		});
		std::cout << std::endl;
	} else {
		std::cout << "No Cycle" << std::endl;
	}
	return 0;
}
