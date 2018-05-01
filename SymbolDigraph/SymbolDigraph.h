#ifndef SYMBOL_DIGRAPH_H
#define SYMBOL_DIGRAPH_H

#include <string>
#include <memory>
#include <vector>
#include <map>
#include "Digraph/Digraph.h"
#include "Common/string_utils.h"

/*
===============================================================================
同SymbolGraph类似，唯一的区别就是Digraph代替了Graph
===============================================================================
*/
class SymbolDigraph
{
public:
	SymbolDigraph(const std::string& filename, char delimiter);
	bool Contains(const std::string& s);
	size_t IndexOf(const std::string& s);
	std::string NameOf(size_t v);
	Digraph const & GetGraph();

private:
	std::unique_ptr<Digraph>		digraph_;
	std::map<std::string, size_t>	st_;
	std::vector<std::string>		keys_;
};

#include "SymbolDigraph.inl"

#endif // SYMBOL_DIGRAPH_H
