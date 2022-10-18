#ifndef TRANSITIVE_CLOSURE_H
#define TRANSITIVE_CLOSURE_H

#include <memory>
#include "Digraph/Digraph.h"
#include "DirectedDFS/DirectedDFS.h"

/*
===============================================================================
4.2.5.4：有向图顶点对的可达性
===============================================================================
*/
class TransitiveClosure
{
public:
	TransitiveClosure(Digraph const &G);
	
	// w是从v可达的吗？
	bool Reachable(size_t v, size_t w) const;

private:
	std::vector<std::unique_ptr<DirectedDFS>> all_;
};



inline TransitiveClosure::TransitiveClosure(Digraph const &G)
{
	all_.reserve(G.V());
	for (size_t i = 0; i < G.V(); ++i) {
		all_.push_back(std::make_unique<DirectedDFS>(G, i));
	}
}


inline bool TransitiveClosure::Reachable(size_t v, size_t w) const
{
	return all_[v]->Marked(w);
}

#endif // TRANSITIVE_CLOSURE_H
