#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <time.h>


/*
===============================================================================
œ£∂˚≈≈–Ú£∫
œ£∂˚≈≈–Ú∏ƒΩ¯¡À≤Â»Î≈≈–Ú°£
===============================================================================
*/
void sort(std::vector<int>& vec)
{
	const size_t n = vec.size();
	
	size_t h = 1;
	while (h < n / 3) { h = 3 * h + 1; }

	while (h >= 1) {
		for (size_t i = h; i < n; ++i) {
			for (size_t j = i; j >= h && vec[j] < vec[j - h]; j -= h) {
				std::swap(vec[j], vec[j - h]);
			}
		}
		h /= 3;
	}
}


int main()
{
	srand((unsigned int)time(NULL));

	std::vector<int> vec;
	vec.reserve(100);
	for (int i = 0; i < 100; ++i) {
		vec.push_back(rand());
	}

	std::vector<int> vec2(vec);
	std::sort(vec2.begin(), vec2.end());

	sort(vec);

	for (size_t i = 0; i < vec.size(); ++i) {
		assert(vec[i] == vec2[i]);
	}

	return 0;
}
