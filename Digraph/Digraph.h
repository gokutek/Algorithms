#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <stdint.h>
#include <vector>
#include <string>
#include <sstream>

/*
===============================================================================
有向图
===============================================================================
*/
class Digraph
{
public:
	// 创建一幅含有V个顶点但没有边的有向图
	explicit Digraph(size_t V);

	// 顶点总数
	size_t V() const;

	// 边的总数
	size_t E() const;

	// 向有向图中添加一条边v->w
	void AddEdge(size_t v, size_t w);

	// 由v指出的边所连接的所有顶点
	std::vector<size_t> const& Adj(size_t v) const;

	// 该图的反向图
	Digraph Reverse() const;

	// 对象的字符串表示
	std::string ToString() const;

private:
	const size_t						V_;
	size_t								E_;
	std::vector<std::vector<size_t>>	adj_;
};


inline Digraph::Digraph(size_t V)
	: V_(V)
{
	E_ = 0;
	adj_.resize(V);
}


inline size_t Digraph::V() const
{
	return V_;
}


inline size_t Digraph::E() const
{
	return E_;
}


inline void Digraph::AddEdge(size_t v, size_t w)
{
	++E_;
	adj_[v].push_back(w);
}


inline std::vector<size_t> const& Digraph::Adj(size_t v) const
{
	return adj_[v];
}


inline Digraph Digraph::Reverse() const
{
	Digraph digraph(V_);
	for (size_t v = 0; v < V_; ++v) {
		std::vector<size_t> const &adj = Adj(v);
		for (auto w : adj) {
			digraph.AddEdge(w, v);
		}
	}
	return digraph;
}


inline std::string Digraph::ToString() const
{
	std::ostringstream oss;
	oss << V_ << std::endl;
	oss << E_ << std::endl;
	for (size_t v = 0; v < V_; ++v)
	{
		std::vector<size_t> const &adj = Adj(v);
		for (auto w : adj)
		{
			oss << v << " " << w << std::endl;
		}
	}
	return oss.str();
}

#endif // DIGRAPH_H
