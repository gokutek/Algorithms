#ifndef KRUSKAL_MST_H
#define KRUSKAL_MST_H

#include <queue>
#include <vector>
#include <functional>
#include "EdgeWeightedGraph/EdgeWeightedGraph.h"
#include "UF/UF.h"

/*
===============================================================================
4.3.6：最小生成树Kruskal算法
1. 依赖于前面实现的UF算法；
2. 代码看起来比Prim算法更简单；
===============================================================================
*/
class KruskalMST
{
	template<typename T>
	using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T> >;

public:
	explicit KruskalMST(EdgeWeightedGraph const &G);

	// 最小生成树的所有边
	std::vector<Edge> const& Edges() const;

	// 最小生成树的权重
	double Weight() const;

private:
	std::vector<Edge> mst_;
	double			weight_;
};



inline KruskalMST::KruskalMST(EdgeWeightedGraph const &G)
	: weight_(0)
{
	MinPQ<Edge> pq;
	for (Edge const &e : G.Edges()) {
		pq.push(e);
	}

	UF uf(G.V());
	while (!pq.empty() && mst_.size() < G.V() - 1) {
		Edge const e = pq.top();
		pq.pop();
		size_t const v = e.Either();
		size_t const w = e.Other(v);
		if (!uf.Connected(v, w)) {
			uf.Union(v, w);
			mst_.push_back(e);
			weight_ += e.Weight();
		}
	}
}


inline std::vector<Edge> const& KruskalMST::Edges() const
{
	return mst_;
}


inline double KruskalMST::Weight() const
{
	return weight_;
}

#endif // KRUSKAL_MST_H
