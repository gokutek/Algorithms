#include <iostream>
#include "Topological.h"
#include "SymbolDigraph/SymbolDigraph.h"
#include "data_file.h"

int main()
{
	SymbolDigraph sg(get_data_file_path("jobs.txt"), '/');
	Topological top(sg.GetGraph());
	auto &order = top.GetOrder();
	for (auto v : order) {
		std::cout << v << ": " << sg.NameOf(v) << std::endl;
	}
	return 0;
}
