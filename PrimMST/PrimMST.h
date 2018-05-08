#ifndef PRIM_MST_H
#define PRIM_MST_H

#include <numeric>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include "EdgeWeightedGraph/EdgeWeightedGraph.h"
#include "IndexMinPQ/IndexMinPQ.h"

class PrimMST
{
public:
	PrimMST(EdgeWeightedGraph const &G);

	// 最小生成树的所有边
	std::vector<Edge> Edges() const;

	// 最小生成树的权重
	double Weight() const;

private:
	void Prim(EdgeWeightedGraph const &G, size_t s);
	
	void Scan(EdgeWeightedGraph const &G, size_t v);

private:
	std::map<size_t, Edge>	edgeTo_;
	std::vector<double>		distTo_;
	std::vector<bool>		marked_;
	IndexMinPQ<double>		pq_;
};


inline PrimMST::PrimMST(EdgeWeightedGraph const &G)
	: pq_(G.V())
{
	distTo_.resize(G.V(), std::numeric_limits<double>::max());
	marked_.resize(G.V(), false);
	for (size_t v = 0; v < G.V(); ++v) {
		if (!marked_[v]) {
			Prim(G, v);
		}
	}
}


inline void PrimMST::Prim(EdgeWeightedGraph const &G, size_t s)
{
	distTo_[s] = 0.0;
	pq_.Insert(s, distTo_[s]);
	while (!pq_.IsEmpty()) {
		size_t const v = pq_.DelMin();
		Scan(G, v);
	}
}


inline void PrimMST::Scan(EdgeWeightedGraph const &G, size_t v)
{
	marked_[v] = true;
	for (Edge const &e : G.Adj(v)) {
		size_t const w = e.Other(v);
		if (marked_[w]) { continue; }
		if (e.Weight() < distTo_[w]) {
			distTo_[w] = e.Weight();
			edgeTo_[w] = e;
			if (pq_.Contains(w)) {
				pq_.ChangeKey(w, distTo_[w]);
			} else {
				pq_.Insert(w, distTo_[w]);
			}
		}
	}
}


inline std::vector<Edge> PrimMST::Edges() const
{
	std::vector<Edge> edges;
	for (auto &iter : edgeTo_) {
		edges.push_back(iter.second);
	}
	return edges;
}


inline double PrimMST::Weight() const
{
	std::vector<Edge> edges = Edges();
	double weight = 0;
	std::for_each(edges.begin(), edges.end(), [&](Edge const &e) {
		weight += e.Weight();
	});
	return weight;
}

#endif // PRIM_MST_H
