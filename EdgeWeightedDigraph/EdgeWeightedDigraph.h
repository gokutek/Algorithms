#ifndef EDGE_WEIGHTED_DIGRAPH_H
#define EDGE_WEIGHTED_DIGRAPH_H

#include <vector>
#include <list>
#include "DirectedEdge.h"

class EdgeWeightedDigraph
{
public:
	explicit EdgeWeightedDigraph(size_t V);

	void AddEdge(DirectedEdge const &e);

	size_t V() const;

	size_t E() const;

	std::list<DirectedEdge> const& Adj(size_t v) const;

	size_t OutDegree(size_t v) const;

	size_t InDegree(size_t v) const;

	std::list<DirectedEdge> Edges() const;

private:
	size_t									V_;
	size_t									E_;
	std::vector<std::list<DirectedEdge> >	adj_;
	std::vector<size_t>						inDegree_;
};


inline EdgeWeightedDigraph::EdgeWeightedDigraph(size_t V)
{
	V_ = V;
	E_ = 0;
	adj_.resize	(V);
	inDegree_.resize(V, 0);
}


inline void EdgeWeightedDigraph::AddEdge(DirectedEdge const &e)
{
	adj_[e.From()].push_back(e);
	++inDegree_[e.To()];
	++E_;
}


inline size_t EdgeWeightedDigraph::V() const
{
	return V_;
}


inline size_t EdgeWeightedDigraph::E() const
{
	return E_;
}


inline std::list<DirectedEdge> const& EdgeWeightedDigraph::Adj(size_t v) const
{
	return adj_[v];
}


inline size_t EdgeWeightedDigraph::OutDegree(size_t v) const
{
	return adj_[v].size();
}


inline size_t EdgeWeightedDigraph::InDegree(size_t v) const
{
	return inDegree_[v];
}


inline std::list<DirectedEdge> EdgeWeightedDigraph::Edges() const
{
	std::list<DirectedEdge> res;
	for (std::list<DirectedEdge> const &adj : adj_) {
		res.insert(res.end(), adj.begin(), adj.end());
	}
	return res;
}

#endif // EDGE_WEIGHTED_DIGRAPH_H
