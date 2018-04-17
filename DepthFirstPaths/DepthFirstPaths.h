#ifndef DEPTH_FIRST_PATHS_H
#define DEPTH_FIRST_PATHS_H

#include <vector>
#include <limits>
#include "Graphs/Graphs.h"


/*
===============================================================================
简单修改DepthFirstSearch，使得可以获取到某个点的一条路径（非最短路径）
===============================================================================
*/
class DepthFirstPaths
{
public:
	DepthFirstPaths(Graphs const &G, size_t s);

	// 是否存在到s到v的路径
	bool HasPathTo(size_t v) const;

	// 获取s到v的路径（非最短）
	std::vector<size_t> PathTo(size_t v) const;

private:
	void DFS(Graphs const &G, size_t v);

private:
	std::vector<bool>	marked_;	///< 顶点的访问标志
	std::vector<size_t>	edge_;		///< edge_[v]表示通过哪个顶点到达v的
	const size_t		start_;		///< 起点
};



inline DepthFirstPaths::DepthFirstPaths(Graphs const &G, size_t s)
	: start_(s)
{
	marked_.resize(G.V());
	edge_.resize(G.V(), std::numeric_limits<size_t>::max());
	DFS(G, s);
}


inline bool DepthFirstPaths::HasPathTo(size_t v) const
{
	return marked_[v];
}


inline std::vector<size_t> DepthFirstPaths::PathTo(size_t v) const
{
	std::vector<size_t> res;
	while (v != start_) {
		res.push_back(v);
		v = edge_[v];
	}
	res.push_back(start_);
	std::reverse(res.begin(), res.end());
	return res;
}


inline void DepthFirstPaths::DFS(Graphs const &G, size_t v)
{
	marked_[v] = true;
	for (auto w : G.Adj(v)) {
		if (!marked_[w]) {
			edge_[w] = v;
			DFS(G, w);
		}
	}
}

#endif // DEPTH_FIRST_PATHS_H
