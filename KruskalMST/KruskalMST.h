#ifndef KRUSKAL_MST_H
#define KRUSKAL_MST_H

#include <queue>
#include <list>
#include <functional>
#include "EdgeWeightedGraph/EdgeWeightedGraph.h"

class KruskalMST
{
	template<typename T>
	using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T> >;

public:
	explicit KruskalMST(EdgeWeightedGraph const &G);

private:
	std::list<Edge> mst_;
};



inline KruskalMST::KruskalMST(EdgeWeightedGraph const &G)
{
	MinPQ<Edge> pq;
	for (Edge const &e : G.Edges()) {
		pq.push(e);
	}

	while (!pq.empty() && mst_.size() < G.V() - 1) {
		Edge const e = pq.top();
		pq.pop();
		size_t const v = e.Either();
		size_t const w = e.Other(v);
	}
}

#endif // KRUSKAL_MST_H
