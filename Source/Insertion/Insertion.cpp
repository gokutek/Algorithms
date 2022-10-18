#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <time.h>


// 插入排序
void sort(std::vector<int>& vec)
{
	for (size_t i = 1; i < vec.size(); ++i) {
		// vec[i]之前的元素已经是有序的了，将vec[i]插入到合适的位置
		for (size_t j = i; j > 0 && vec[j] < vec[j-1]; --j) {
			std::swap(vec[j], vec[j-1]);
		}
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
