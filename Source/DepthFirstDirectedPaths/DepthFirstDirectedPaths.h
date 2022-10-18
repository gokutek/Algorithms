#ifndef DEPTH_FIRST_DIRECTED_PATHS_H
#define DEPTH_FIRST_DIRECTED_PATHS_H

#include <vector>
#include <limits>
#include <assert.h>
#include "Digraph/Digraph.h"

/*
===============================================================================
4.2.3：有向图中，一点到另一点的路径
===============================================================================
*/
class DepthFirstDirectedPaths
{
public:
	DepthFirstDirectedPaths(Digraph const &G, size_t source);

	// 是否存在到s到v的路径
	bool HasPathTo(size_t v) const;

	// 获取s到v的路径（非最短）
	std::vector<size_t> PathTo(size_t v) const;

private:
	void DFS(Digraph const &G, size_t v);

private:
	size_t const		source_;
	std::vector<bool>	marked_;
	std::vector<size_t> edgeTo_;
};


inline DepthFirstDirectedPaths::DepthFirstDirectedPaths(Digraph const &G, size_t source)
	: source_(source)
{
	marked_.resize(G.V(), false);
	edgeTo_.resize(G.V(), std::numeric_limits<size_t>::max());
	DFS(G, source);
}


void DepthFirstDirectedPaths::DFS(Digraph const &G, size_t v)
{
	marked_[v] = true;
	for (auto w : G.Adj(v)) {
		if (!marked_[w]) {
			edgeTo_[w] = v;
			DFS(G, w);
		}
	}
}


inline bool DepthFirstDirectedPaths::HasPathTo(size_t v) const
{
	return marked_[v];
}


inline std::vector<size_t> DepthFirstDirectedPaths::PathTo(size_t v) const
{
	std::vector<size_t> res;
	assert(HasPathTo(v));
	while (v != source_) {
		res.push_back(v);
		v = edgeTo_[v];
	}
	res.push_back(source_);
	std::reverse(res.begin(), res.end());
	return res;
}

#endif // DEPTH_FIRST_DIRECTED_PATHS_H
