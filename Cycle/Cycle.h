#ifndef CYCLE_H
#define CYCLE_H

#include <vector>
#include <limits>
#include <set>
#include "Graphs/Graphs.h"


/*
===============================================================================
检测图中是否含有环，使用深度优先搜索，找到一个环之后，就停止查找。
DFS函数加了一个参数，表示从哪个邻接点访问到顶点v的。
在遍历v的邻接点时，如果顶点w已被访问过，并且w不是from，则必存在环。
===============================================================================
*/
class Cycle
{
public:
	// 假设G不含有自环、平行边
	Cycle(const Graphs& G);

	// 图中是否含有环
	bool HasCycle() const;

	// 获取找到的一个环
	const std::vector<size_t>& GetCircle() const;

private:
	// 检查是否含有自环
	bool HasSelfLoop(const Graphs& G);

	// 检查是否含有平行边
	bool HasParallelEdges(const Graphs& G);

	// 深度优先搜索
	void DFS(const Graphs& G, size_t v, size_t from);

private:
	std::vector<bool>	marked_;
	std::vector<size_t>	edgeTo_;
	std::vector<size_t> cycle_;
};



inline Cycle::Cycle(const Graphs& G)
{
	if (HasSelfLoop(G) || HasParallelEdges(G)) { return; }

	marked_.resize(G.V(), false);
	edgeTo_.resize(G.V(), std::numeric_limits<size_t>::max());
	for (size_t i = 0; i < G.V() && cycle_.empty(); ++i) {
		if (!marked_[i]) {
			DFS(G, i, std::numeric_limits<size_t>::max());
		}
	}
}


inline bool Cycle::HasCycle() const
{
	return !cycle_.empty();
}


inline const std::vector<size_t>& Cycle::GetCircle() const
{
	return cycle_;
}


inline bool Cycle::HasSelfLoop(const Graphs& G)
{
	for (size_t v = 0; v < G.V(); ++v) {
		for (auto w : G.Adj(v)) {
			if (w == v) {
				cycle_.push_back(v);
				cycle_.push_back(v);
				return true;
			}
		}
	}
	return false;
}


inline bool Cycle::HasParallelEdges(const Graphs& G)
{
	for (size_t v = 0; v < G.V(); ++v) {
		std::set<size_t> edges;
		for (auto w : G.Adj(v)) {
			if (edges.count(w)) {
				cycle_.push_back(v);
				cycle_.push_back(w);
				cycle_.push_back(v);
				return true; 
			}
			edges.insert(w);
		}
	}
	return false;
}


inline void Cycle::DFS(const Graphs& G, size_t v, size_t from)
{
	marked_[v] = true;
	for (auto w : G.Adj(v)) {
		if (!cycle_.empty()) { return; }

		if (!marked_[w]) {
			edgeTo_[w] = v;
			DFS(G, w, v);
		} else if (w != from) {
			for (size_t x = v; x != w; x = edgeTo_[x]) {
				cycle_.push_back(x);
			}
			cycle_.push_back(w);
			cycle_.push_back(v);
		}
	}
}

#endif // CYCLE_H
