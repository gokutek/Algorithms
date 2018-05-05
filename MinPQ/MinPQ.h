#ifndef MIN_PQ_H
#define MIN_PQ_H

#include <vector>

/*
===============================================================================
PQ表示：Priority Queue
===============================================================================
*/
template<typename T>
class MinPQ
{
public:

private:
	std::vector<T>	pq_;
	size_t			n_;
};

#endif // MIN_PQ_H
