#ifndef DEPTH_FIRST_ORDER_H
#define DEPTH_FIRST_ORDER_H

#include <queue>
#include <stack>
#include <vector>
#include "Digraph/Digraph.h"

/*
===============================================================================
有向图的深度优先搜索，增加了pre_、post_、reversePost_三个数据结构来记录DFS的轨迹。
拓扑排序时，依赖本算法。
===============================================================================
*/
class DepthFirstOrder
{
public:
	DepthFirstOrder(Digraph &G);

	std::queue<size_t> const & PreOrder() const;
	std::queue<size_t> const & PostOrder() const;
	std::stack<size_t> const & ReversePostOrder() const;

private:
	void DFS(Digraph &G, size_t v);

private:
	std::vector<size_t>	marked_;
	std::queue<size_t>	pre_;
	std::queue<size_t>	post_;
	std::stack<size_t>	reversePost_;
};



inline DepthFirstOrder::DepthFirstOrder(Digraph &G)
{
	marked_.resize(G.V(), false);
	for (size_t v = 0; v < G.V(); ++v) {
		if (!marked_[v]) {
			DFS(G, v);
		}
	}
}


inline void DepthFirstOrder::DFS(Digraph &G, size_t v)
{
	marked_[v] = true;
	pre_.push(v);
	for (size_t w : G.Adj(v)) {
		if (!marked_[w]) {
			DFS(G, w);
		}
	}
	post_.push(v);
	reversePost_.push(v);
}


inline std::queue<size_t> const & DepthFirstOrder::PreOrder() const
{
	return pre_;
}


inline std::queue<size_t> const & DepthFirstOrder::PostOrder() const
{
	return post_;
}


inline std::stack<size_t> const & DepthFirstOrder::ReversePostOrder() const
{
	return reversePost_;
}

#endif // DEPTH_FIRST_ORDER_H
