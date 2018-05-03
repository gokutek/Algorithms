#ifndef EDGE_H
#define EDGE_H

#include <assert.h>
#include <limits>
#include <string>

/*
===============================================================================
带权重的边
===============================================================================
*/
class Edge
{
public:
	Edge(size_t v, size_t w, double weight);

	double Weight() const;

	size_t Either() const;
	
	size_t Other(size_t v) const;

	std::string ToString() const;

	bool operator<(Edge const &other) const;
	
	bool operator>(Edge const &other) const;

private:
	size_t	v_;			// 顶点之一
	size_t	w_;			// 另一个顶点
	double	weight_;	// 边的权重
};


inline Edge::Edge(size_t v, size_t w, double weight)
	: v_(v)
	, w_(w)
	, weight_(weight)
{
}


inline double Edge::Weight() const
{
	return weight_;
}


inline size_t Edge::Either() const
{
	return v_;
}


inline size_t Edge::Other(size_t v) const
{
	if (v == v_) { return w_; }
	if (v == w_) { return v_; }
	assert(0);
	return std::numeric_limits<size_t>::max();
}


inline std::string Edge::ToString() const
{
	char buffer[64];
	sprintf_s(buffer, "%d-%d %.5f", v_, w_, weight_);
	return buffer;
}


inline bool Edge::operator<(Edge const &other) const
{
	return this->weight_ < other.weight_;
}


inline bool Edge::operator>(Edge const &other) const
{
	return this->weight_ > other.weight_;
}

#endif // EDGE_H
