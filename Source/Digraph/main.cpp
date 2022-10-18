#include <iostream>
#include "Digraph.h"

int main()
{
	Digraph digraph(13);
	digraph.AddEdge(4, 2);
	digraph.AddEdge(2, 3);
	digraph.AddEdge(3, 2);
	digraph.AddEdge(6, 0);
	digraph.AddEdge(0, 1);
	digraph.AddEdge(2, 0);
	digraph.AddEdge(11, 12);
	digraph.AddEdge(12, 9);
	digraph.AddEdge(9, 10);
	digraph.AddEdge(9, 11);
	digraph.AddEdge(7, 9);
	digraph.AddEdge(10, 12);
	digraph.AddEdge(11, 4);
	digraph.AddEdge(4, 3);
	digraph.AddEdge(3, 5);
	digraph.AddEdge(6, 8);
	digraph.AddEdge(8, 6);
	digraph.AddEdge(5, 4);
	digraph.AddEdge(0, 5);
	digraph.AddEdge(6, 4);
	digraph.AddEdge(6, 9);
	digraph.AddEdge(7, 6);
	return 0;
}
