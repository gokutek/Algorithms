#ifndef PRIM_MST_H
#define PRIM_MST_H

#include <numeric>
#include <queue>
#include <vector>
#include "EdgeWeightedGraph/EdgeWeightedGraph.h"

class PrimMST
{
public:
	PrimMST(EdgeWeightedGraph const &G);

private:
	void Prim(EdgeWeightedGraph const &G, size_t s);

private:
	std::vector<Edge>	edgeTo_;
	std::vector<double> distTo_;
	std::vector<bool>	marked_;
};


inline PrimMST::PrimMST(EdgeWeightedGraph const &G)
{
	edgeTo_.resize(G.V());
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
}

#endif // PRIM_MST_H
