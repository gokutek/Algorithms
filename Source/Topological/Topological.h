#ifndef TOPOLOGICAL_H
#define TOPOLOGICAL_H

#include <vector>
#include "DirectedCycle/DirectedCycle.h"
#include "DepthFirstOrder/DepthFirstOrder.h"

/*
===============================================================================
4.2.4.2：有向图拓扑排序
1. 有向图中没有环时才可以进行拓扑排序
===============================================================================
*/
class Topological
{
public:
	Topological(Digraph const &G);

	// G是有向无环图吗
	bool IsDAG() const;

	// 拓扑有序的所有顶点
	std::vector<size_t> const & GetOrder() const;

private:
	std::vector<size_t>	order_;
};



inline Topological::Topological(Digraph const &G)
{
	DirectedCycle cycleFinder(G);
	if (!cycleFinder.HasCycle()) {
		DepthFirstOrder dfs(G);
	 	order_ = dfs.ReversePostOrder();
	}
}


bool Topological::IsDAG() const
{
	return !order_.empty();
}


std::vector<size_t> const & Topological::GetOrder() const
{
	return order_;
}

#endif // TOPOLOGICAL_H
