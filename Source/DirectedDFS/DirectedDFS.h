#ifndef DIRECTED_DFS_H
#define DIRECTED_DFS_H

#include <vector>
#include "Digraph/Digraph.h"

/*
===============================================================================
4.2.3：有向图中的可达性
===============================================================================
*/
class DirectedDFS
{
public:
	// 在G中找到从source可达的所有顶点
	DirectedDFS(Digraph const &G, size_t source);

	// 在G中找到从sources中的所有顶点可达的所有顶点
	DirectedDFS(Digraph const &G, std::vector<size_t> const &sources);

	// v是可达的吗
	bool Marked(size_t v) const;

private:
	void DFS(Digraph const &G, size_t v);

private:
	std::vector<bool>	marked_;
};


inline DirectedDFS::DirectedDFS(Digraph const &G, size_t source)
	: DirectedDFS(G, std::vector<size_t>{ source })
{
}


inline DirectedDFS::DirectedDFS(Digraph const &G, std::vector<size_t> const &sources)
{
	marked_.resize(G.V(), false);
	for (auto v : sources) {
		if (!marked_[v]) {
			DFS(G, v);			
		}
	}
}


inline void DirectedDFS::DFS(Digraph const &G, size_t v)
{
	marked_[v] = true;
	auto &adj = G.Adj(v);
	for (size_t w : adj) {
		if (!marked_[w]) {
			DFS(G, w);
		}
	}
}


inline bool DirectedDFS::Marked(size_t v) const
{
	return marked_[v];
}

#endif // DIRECTED_DFS_H
