#ifndef LAZY_PRIM_MST_H
#define LAZY_PRIM_MST_H

#include <vector>
#include <queue>
#include <functional>
#include "EdgeWeightedGraph/EdgeWeightedGraph.h"

/*
===============================================================================
4.3.4.3：最小生成树的Prim算法的延时实现
===============================================================================
*/
class LazyPrimMST
{
	template<typename T>
	using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T> >;

public:
	LazyPrimMST(EdgeWeightedGraph const &G);

private:
	void Visit(EdgeWeightedGraph const &G, size_t v);

private:
	std::vector<bool>	marked_;	// 最小生成树的顶点
	std::queue<Edge>	mst_;		// 最小生成树的边
	MinPQ<Edge>			pq_;		// 横切边（包括失效的边）
};


inline LazyPrimMST::LazyPrimMST(EdgeWeightedGraph const &G)
{
	marked_.resize(G.V(), false);
	Visit(G, 0);
	while (!pq_.empty()) {
		Edge const e = pq_.top();
		pq_.pop();
		size_t const v = e.Either();
		size_t const w = e.Other(v);
		if (marked_[v] && marked_[w]) { continue; }
		mst_.push(e);
		if (!marked_[v]) { Visit(G, v); }
		if (!marked_[w]) { Visit(G, w); }
	}
}


void LazyPrimMST::Visit(EdgeWeightedGraph const &G, size_t v)
{
	marked_[v] = true;
	for (Edge const &e : G.Adj(v)) {
		if (!marked_[e.Other(v)]) {
			pq_.push(e);
		}
	}
}

#endif // LAZY_PRIM_MST_H
