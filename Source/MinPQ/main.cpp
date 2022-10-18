#include <assert.h>
#include <queue>
#include <vector>
#include <iostream>
#include <functional>
#include <time.h>
#include "MinPQ.h"

int main()
{
	srand((unsigned int)time(NULL));

	std::vector<int> randValues(500);
	for (size_t i = 0; i < 100; ++i) {
		randValues[i] = rand();
	}

	std::priority_queue<int, std::vector<int>, std::greater<int> > stdMinPQ;
	MinPQ<int> pq;

	for (int v : randValues) {
		stdMinPQ.push(v);
		pq.Insert(v);
	}

	assert(pq.Size() == stdMinPQ.size());
	while (!pq.IsEmpty()) {
		int const v1 = pq.DelMin();
		int const v2 = stdMinPQ.top();
		stdMinPQ.pop();
		assert(v1 == v2);
		std::cout << v1 << std::endl;
	}

	return 0;
}
