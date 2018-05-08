﻿#ifndef UF_H
#define UF_H

#include <vector>

/*
===============================================================================
===============================================================================
*/
class UF
{
public:
	explicit UF(size_t n);

	size_t Find(size_t p);

	size_t Count() const;

	bool Connected(size_t p, size_t q);

	void Union(size_t p, size_t q);

private:
	std::vector<size_t>	parent_;
	std::vector<size_t>	rank_;
	size_t				count_;
};


inline UF::UF(size_t n)
{
	count_ = n;
	parent_.resize(n);
	rank_.resize(n, 0);
	for (size_t i = 0; i < n; ++i) {
		parent_[i] = i;
	}
}


inline size_t UF::Find(size_t p)
{
	while (p != parent_[p]) {
		parent_[p] = parent_[parent_[p]];
		p = parent_[p];
	}
	return p;
}


inline size_t UF::Count() const
{
	return count_;
}


inline bool UF::Connected(size_t p, size_t q)
{
	return Find(p) == Find(q);
}


inline void UF::Union(size_t p, size_t q)
{
	size_t const rootP = Find(p);
	size_t const rootQ = Find(q);
	if (rootP == rootQ) { return; }
	if (rank_[rootP] < rank_[rootQ]) {
		parent_[rootP] = rootQ;
	} else if (rank_[rootP] > rank_[rootQ]) {
		parent_[rootQ] = rootP;
	} else {
		parent_[rootQ] = rootP;
		++rank_[rootP];
	}
	--count_;
}

#endif // UF_H
