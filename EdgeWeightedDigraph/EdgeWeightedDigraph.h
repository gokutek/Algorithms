#ifndef EDGE_WEIGHTED_DIGRAPH_H
#define EDGE_WEIGHTED_DIGRAPH_H

#include <assert.h>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include "DirectedEdge.h"

/*
===============================================================================
4.4.2：加权有向图的数据结构
===============================================================================
*/
class EdgeWeightedDigraph
{
public:
	// 构造一个含有V个顶点的图
	explicit EdgeWeightedDigraph(size_t V);

	// 从文件中加载图
	explicit EdgeWeightedDigraph(std::string const &file);

	// 添加一条边
	void AddEdge(DirectedEdge const &e);

	// 顶点数
	size_t V() const;

	// 边数
	size_t E() const;

	// 从顶点v指出的边
	std::list<DirectedEdge> const& Adj(size_t v) const;

	// 顶点v的出度
	size_t OutDegree(size_t v) const;

	// 顶点v的入度
	size_t InDegree(size_t v) const;

	// 所有边
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
	adj_.resize(V);
	inDegree_.resize(V, 0);
}


inline EdgeWeightedDigraph::EdgeWeightedDigraph(std::string const &file)
{
	std::ifstream ifs(file.c_str());
	assert(ifs.is_open());
	size_t E = 0;
	ifs >> V_ >> E;
	adj_.resize(V_);
	inDegree_.resize(V_, 0);
	for (size_t i = 0; i < E; ++i)
	{
		size_t v, w;
		double weight;
		ifs >> v >> w >> weight;
		AddEdge(DirectedEdge(v, w, weight));
	}
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
