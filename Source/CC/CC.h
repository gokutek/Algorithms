#ifndef CC_H
#define CC_H

#include <vector>
#include "Graphs/Graphs.h"

/*
===============================================================================
CC是connected components的缩写，表示连通分量
===============================================================================
*/
class CC
{
public:
	// 构造函数，预处理找出所有的连通分量
	CC(const Graphs& G);
	
	// v和w是否连通
	bool Connected(size_t v, size_t w) const;
	
	// 连通分量数
	size_t Count() const;

	// v所在的连通分量标识符（0 ~ count()-1）
	size_t Id(size_t v) const;

private:
	void DFS(const Graphs& G, size_t v);

private:
	std::vector<size_t>	marked_;	///< 访问标识
	size_t				count_;		///< 连通分量数
};



inline CC::CC(const Graphs& G)
{
	marked_.resize(G.V(), 0);
	count_ = 0;
	for (size_t i = 0; i < marked_.size(); ++i) {
		if (!marked_[i]) {
			++count_;
			DFS(G, i);
		}
	}
}


inline bool CC::Connected(size_t v, size_t w) const
{
	return marked_[v] == marked_[w];
}


inline size_t CC::Count() const
{
	return count_;
}


inline size_t CC::Id(size_t v) const
{
	return marked_[v] - 1;
}


inline void CC::DFS(const Graphs& G, size_t v)
{
	marked_[v] = count_;
	for (auto w : G.Adj(v)) {
		if (!marked_[w]) {
			DFS(G, w);
		}
	}
}

#endif // CC_H
