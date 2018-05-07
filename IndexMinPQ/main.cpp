#include <assert.h>
#include <iostream>
#include <time.h>
#include <vector>
#include "IndexMinPQ.h"

int main()
{
	srand((unsigned int)time(NULL));
	std::vector<int> vec;
	for (size_t i = 0; i < 100; ++i) {
		vec.push_back(rand());
	}

	IndexMinPQ<int> pq(vec.size());
	for (size_t i = 0; i < vec.size(); ++i) {
		pq.Insert(i, vec[i]);
	}

	while (!pq.IsEmpty()) {
		std::cout << pq.MinIndex() << ": " << pq.MinKey() << std::endl;
		assert(vec[pq.MinIndex()] == pq.MinKey());
		pq.DelMin();
	}

	return 0;
}
