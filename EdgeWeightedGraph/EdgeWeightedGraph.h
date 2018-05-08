#ifndef EDGE_WEIGHTED_GRAPH_H
#define EDGE_WEIGHTED_GRAPH_H

#include <list>
#include <vector>
#include <assert.h>
#include <fstream>
#include "Edge.h"

/*
===============================================================================
4.3.2：加权无向图
===============================================================================
*/
class EdgeWeightedGraph
{
public:
	// 含有V个顶点的图
	explicit EdgeWeightedGraph(size_t V);

	// 从文件中加载图
	explicit EdgeWeightedGraph(std::string const &file);

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

	// 图中的所有边
	std::list<Edge> Edges() const;

private:
	size_t							V_;		// 顶点数
	size_t							E_;		// 边数
	std::vector<std::list<Edge> >	adj_;	// 邻接表
};


inline EdgeWeightedGraph::EdgeWeightedGraph(size_t V)
	: V_(V)
	, E_(0)
{
	adj_.resize(V);
}


inline EdgeWeightedGraph::EdgeWeightedGraph(std::string const &file)
{
	std::ifstream ifs(file.c_str());
	assert(ifs.is_open());
	size_t E = 0;
	ifs >> V_ >> E;
	adj_.resize(V_);
	for (size_t i = 0; i < E; ++i)
	{
		size_t v, w;
		double weight;
		ifs >> v >> w >> weight;
		AddEdge(Edge(v, w, weight));
	}
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


inline std::list<Edge> const& EdgeWeightedGraph::Adj(size_t v) const
{
	return adj_[v];
}


inline size_t EdgeWeightedGraph::Degree(size_t v) const
{
	return adj_[v].size();
}


inline std::list<Edge> EdgeWeightedGraph::Edges() const
{
	std::list<Edge> edges;
	for (size_t v = 0; v < V_; ++v) {
		int selfLoops = 0;
		for (Edge const &e : Adj(v)) {
			if (e.Other(v) > v) {
				edges.push_back(e);
			} else if (e.Other(v) == v) {
				if (selfLoops % 2 == 0) { edges.push_back(e); }
				++selfLoops;
			}
		}
	}
	return edges;
}

#endif // EDGE_WEIGHTED_GRAPH_H
