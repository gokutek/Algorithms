#ifndef GRAPHS_H
#define GRAPHS_H

#include <vector>
#include <string>
#include <sstream>
#include <cassert>

/*
===============================================================================
使用邻接表来实现的图
===============================================================================
*/
class Graphs
{
public:
	// 初始化一个顶点数为V的无向图
	Graphs(size_t V);
	
	// 获取顶点数
	size_t V() const;
	
	// 获取边数
	size_t E() const;

	// 添加一条边
	void AddEdge(size_t v, size_t w);

	// 获取该顶点的邻接点
	std::vector<size_t> const& Adj(size_t v) const;

	// 获取该顶点的度
	size_t Degree(size_t v) const;

	// 转成文本，用于输出调试
	std::string ToString() const;

private:
	size_t const						V_;		///< 顶点个数
	size_t								E_;		///< 边数
	std::vector<std::vector<size_t>>	adj_;	///< 记录每个顶点相邻的顶点
};


inline Graphs::Graphs(size_t V)
	: V_(V)
{
	assert(V >= 0);
	E_ = 0;
	adj_.resize(V);
}


inline size_t Graphs::V() const
{
	return V_;
}


inline size_t Graphs::E() const
{
	return E_;
}


inline void Graphs::AddEdge(size_t v, size_t w)
{
	assert(v < V_ && w < V_);
	++E_;
	adj_[v].push_back(w);
	adj_[w].push_back(v);
}


inline std::vector<size_t> const& Graphs::Adj(size_t v) const
{
	assert(v < V_);
	return adj_[v];
}


inline size_t Graphs::Degree(size_t v) const
{
	return adj_[v].size();
}


inline std::string Graphs::ToString() const
{
	std::ostringstream oss;
	oss << V_ << " vertices, " << E_ << " edges" << std::endl;
	for (size_t i = 0; i < V_; ++i) {
		oss << i << ": ";
		for (auto w : Adj(i)) {
			oss << w << " ";
		}
		oss << std::endl;
	}
	return oss.str();
}

#endif // GRAPHS_H
