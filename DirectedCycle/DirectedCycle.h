#ifndef DIRECTED_CYCLE_H
#define DIRECTED_CYCLE_H

#include <vector>
#include <numeric>
#include "Digraph/Digraph.h"

/*
===============================================================================
4.2.4.2：检测有向图中是否含有环（不会找出所有的环）
===============================================================================
*/
class DirectedCycle
{
public:
	DirectedCycle(Digraph const &G);

	// G是否含有有向环
	bool HasCycle() const;

	// 有向环中的所有顶点（如果存在的话）
	std::vector<size_t> const & Cycle() const;

private:
	void DFS(Digraph const &G, size_t v);

private:
	std::vector<bool>	marked_;
	std::vector<size_t>	edgeTo_;
	std::vector<bool>	onStack_;
	std::vector<size_t>	cycle_;
};



inline DirectedCycle::DirectedCycle(Digraph const &G)
{
	marked_.resize(G.V(), false);
	edgeTo_.resize(G.V(), std::numeric_limits<size_t>::max());
	onStack_.resize(G.V(), false);

	for (size_t v = 0; v < G.V(); ++v) {
		if (!marked_[v]) {
			DFS(G, v);
		}
	}
}


inline bool DirectedCycle::HasCycle() const
{
	return !cycle_.empty();
}


inline std::vector<size_t> const & DirectedCycle::Cycle() const
{
	return cycle_;
}


void DirectedCycle::DFS(Digraph const &G, size_t v)
{
	onStack_[v] = true;
	marked_[v] = true;
	for (size_t w : G.Adj(v)) {
		if (HasCycle()) {
			return;
		} else if (!marked_[w]) {
			edgeTo_[w] = v;
			DFS(G, w);
		} else if (onStack_[w]) {
			while (v != w) {
				cycle_.push_back(v);
				v = edgeTo_[v];
			}
		}
	}
	onStack_[v] = false;
}

#endif // DIRECTED_CYCLE_H
