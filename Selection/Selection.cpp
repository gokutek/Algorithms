#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <time.h>


// 选择排序
void sort(std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i) {
		// 找到[i，end)中最小的元素
		size_t min = i;
		for (size_t j = i + 1; j < vec.size(); ++j) {
			if (vec[j] < vec[min]) {
				min = j;
			}
		}
		// 将找到的最小元素与vec[i]交换
		std::swap(vec[i], vec[min]);
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
