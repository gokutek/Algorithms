﻿#include <iostream>
#include "Topological.h"
#include "SymbolDigraph/SymbolDigraph.h"


int main()
{
	SymbolDigraph sg("../data/jobs.txt", '/');
	Topological top(sg.GetGraph());
	auto &order = top.GetOrder();
	for (auto v : order) {
		std::cout << v << ": " << sg.NameOf(v) << std::endl;
	}
	return 0;
}