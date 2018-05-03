#ifndef EDGE_WEIGHTED_GRAPH_H
#define EDGE_WEIGHTED_GRAPH_H

#include <list>
#include <vector>
#include <assert.h>
#include "Edge.h"

/*
===============================================================================
4.3.2：加权无向图
===============================================================================
*/
class EdgeWeightedGraph
{
public:
	explicit EdgeWeightedGraph(size_t V);

	// 顶点总数
	size_t V() const;

	// 边数
	size_t E() const;

	// 添加一条边
	void AddEdge(Edge const &e);

	// 获取顶点v的领接表
	std::list<Edge> const& Adj(size_t v) const;

	// 顶点v的度
	size_t Degree(size_t v) const;

private:
	const size_t					V_;		// 顶点数
	size_t							E_;		// 边数
	std::vector<std::list<Edge> >	adj_;	// 领接表
};


inline EdgeWeightedGraph::EdgeWeightedGraph(size_t V)
	: V_(V)
	, E_(0)
{
	adj_.resize(V);
}


inline size_t EdgeWeightedGraph::V() const
{
	return V_;
}


inline size_t EdgeWeightedGraph::E() const
{
	return E_;
}


inline void EdgeWeightedGraph::AddEdge(Edge const &e)
{
	adj_[e.Either()].push_front(e);
	adj_[e.Other(e.Either())].push_front(e);
	++E_;
}


std::list<Edge> const& EdgeWeightedGraph::Adj(size_t v) const
{
	return adj_[v];
}


size_t EdgeWeightedGraph::Degree(size_t v) const
{
	return adj_[v].size();
}

#endif // EDGE_WEIGHTED_GRAPH_H
