#ifndef SYMBOL_GRAPH_H
#define SYMBOL_GRAPH_H

#include <assert.h>
#include <string>
#include <fstream>
#include <map>
#include <memory>
#include <vector>
#include "Graphs/Graphs.h"
#include "Common/string_utils.h"

/*
===============================================================================
之前已实现的图算法，内部采用size_t类型来标识顶点。
本算法中，顶点是字符串名称，所以需要一个字符串到size_t的映射以及反向映射。
===============================================================================
*/
class SymbolGraph
{
public:
	SymbolGraph(const std::string& filename, char delimiter);
	bool Contains(const std::string& s);
	int IndexOf(const std::string& s);
	std::string NameOf(size_t v);
	Graphs& GetGraph();

private:
	std::unique_ptr<Graphs>			graph_;
	std::map<std::string, size_t>	st_;
	std::vector<std::string>		keys_;
};

#include "SymbolGraph.inl"

#endif // SYMBOL_GRAPH_H
