#ifndef DIRECTED_EDGE_H
#define DIRECTED_EDGE_H

class DirectedEdge
{
public:
	DirectedEdge(size_t v, size_t w, double weight);

	size_t From() const;
	
	size_t To() const;

	double Weight() const;

private:
	size_t const v_;
	size_t const w_;
	double const weight_;
};


inline DirectedEdge::DirectedEdge(size_t v, size_t w, double weight)
	: v_(v)
	, w_(w)
	, weight_(weight)
{
}


inline size_t DirectedEdge::From() const
{
	return v_;
}


inline size_t DirectedEdge::To() const
{
	return w_;
}


inline double DirectedEdge::Weight() const
{
	return weight_;
}

#endif // DIRECTED_EDGE_H
