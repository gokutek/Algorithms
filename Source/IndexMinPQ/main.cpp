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

	for (size_t i = 0; i < 10; ) {
		size_t const k = rand() % vec.size();
		if (pq.Contains(k)) {
			pq.Delete(k);
			++i;
		}
	}

	size_t count = 0;
	for (size_t i = 0; i < vec.size(); ++i) {
		count += (pq.Contains(i) ? 1 : 0);
	}

	assert(count == 90);

	while (!pq.IsEmpty()) {
		std::cout << pq.MinIndex() << ": " << pq.MinKey() << std::endl;
		assert(vec[pq.MinIndex()] == pq.MinKey());
		pq.DelMin();
	}

	return 0;
}
