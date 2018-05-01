﻿#ifndef KOSARAJU_CC_H
#define KOSARAJU_CC_H

#include <vector>
#include <limits>
#include "Digraph/Digraph.h"
#include "DepthFirstOrder/DepthFirstOrder.h"


/*
===============================================================================
4.2.5.3：Kosaraju算法
计算有向图中，所有的强连通分量。
===============================================================================
*/
class KosarajuSCC
{
public:
	explicit KosarajuSCC(Digraph const &G);
	
	// v和w是强连通的吗？
	bool StronglyConnected(size_t v, size_t w) const;
		
	// 图中的强连通分量的总数
	size_t Count() const;

	// v所在的强连通分量的标识符（在0至Count()-1之间）
	size_t Id(size_t v) const;

private:
	void DFS(Digraph const &G, size_t v);

private:
	std::vector<bool>	marked_;	///< 顶点访问标识
	std::vector<size_t>	id_;		///< 每个顶点所在的连通分量标识符
	int					count_;		///< 连通分量总数
};



inline KosarajuSCC::KosarajuSCC(Digraph const &G)
{
	marked_.resize(G.V(), false);
	id_.resize(G.V(), std::numeric_limits<size_t>::max());
	count_ = 0;

	DepthFirstOrder order(G.Reverse());
	for (size_t v : order.ReversePostOrder()) {
		if (!marked_[v]) {
			DFS(G, v);
			++count_;
		}
	}
}


inline void KosarajuSCC::DFS(Digraph const &G, size_t v)
{
	marked_[v] = true;
	id_[v] = count_;

	for (size_t w : G.Adj(v)) {
		if (!marked_[w]) {
			DFS(G, w);
		}
	}
}


inline bool KosarajuSCC::StronglyConnected(size_t v, size_t w) const
{
	return id_[v] == id_[w];
}


inline size_t KosarajuSCC::Count() const
{
	return count_;
}


inline size_t KosarajuSCC::Id(size_t v) const
{
	return id_[v];
}

#endif // KOSARAJU_CC_H
