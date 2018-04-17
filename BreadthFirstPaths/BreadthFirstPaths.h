#ifndef BREADTH_FIRST_PATHS_H
#define BREADTH_FIRST_PATHS_H

#include <vector>
#include <queue>
#include "Graphs/Graphs.h"

/*
===============================================================================
广度优先搜索：
可以用于查找最短路径
===============================================================================
*/
class BreadthFirstPaths
{
public:
	BreadthFirstPaths(Graphs const &G, size_t s);

	// 是否存在到s到v的路径
	bool HasPathTo(size_t v) const;

	// 获取s到v的最短路径
	std::vector<size_t> PathTo(size_t v) const;

private:
	void BFS(Graphs const &G, size_t v);

private:
	std::vector<bool>	marked_;	///< 顶点的访问标志
	std::vector<size_t>	edge_;		///< edge_[v]表示通过哪个顶点到达v的
	const size_t		start_;		///< 起点
};



inline BreadthFirstPaths::BreadthFirstPaths(Graphs const &G, size_t s)
	: start_(s)
{
	marked_.resize(G.V(), false);
	edge_.resize(G.V());
	BFS(G, s);
}


inline bool BreadthFirstPaths::HasPathTo(size_t v) const
{
	return marked_[v];
}


inline std::vector<size_t> BreadthFirstPaths::PathTo(size_t v) const
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


inline void BreadthFirstPaths::BFS(Graphs const &G, size_t v)
{
	std::queue<size_t> vertices;
	vertices.push(v);
	marked_[v] = true;
	while (!vertices.empty()) {
		v = vertices.front();
		vertices.pop();
		for (auto w : G.Adj(v)) {
			if (!marked_[w]) {
				marked_[w] = true;
				edge_[w] = v;
				vertices.push(w);
			}
		}
	}
}

#endif // BREADTH_FIRST_PATHS_H
