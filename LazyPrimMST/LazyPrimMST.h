#ifndef LAZY_PRIM_MST_H
#define LAZY_PRIM_MST_H

#include <vector>
#include <queue>
#include <functional>
#include "EdgeWeightedGraph/EdgeWeightedGraph.h"

/*
===============================================================================
4.3.4.3：最小生成树的Prim算法的延时实现
名词解释：
失效的边：这条边的两个顶点都已经在树中；
===============================================================================
*/
class LazyPrimMST
{
	template<typename T>
	using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T> >;

public:
	LazyPrimMST(EdgeWeightedGraph const &G);

	// 最小生成树的权重
	double Weight() const;

private:
	void Visit(EdgeWeightedGraph const &G, size_t v);

private:
	std::vector<bool>	marked_;	// 顶点是否在树中
	std::queue<Edge>	mst_;		// 最小生成树的边
	MinPQ<Edge>			pq_;		// 横切边（包括失效的边），按照权重从小到大排序
	double				weight_;	// 权重
};


inline LazyPrimMST::LazyPrimMST(EdgeWeightedGraph const &G)
	: weight_(0)
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
		weight_ += e.Weight();
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


inline double LazyPrimMST::Weight() const
{
	return weight_;
}

#endif // LAZY_PRIM_MST_H
