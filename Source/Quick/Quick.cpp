#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <time.h>
#include <random>


/*
===============================================================================
快速排序的算法核心就是这个partition函数。
选择一个元素作为分界（下面的实现中，取第一个元素作为界），
然后将数组分割成两部分，左边的元素都不比它大，右边的元素都不比它小。
函数返回分割后，这个界的索引。
===============================================================================
*/
size_t partition(std::vector<int>& vec, size_t low, size_t high)
{
	const int v = vec[low];
	size_t i = low;
	size_t j = high + 1;

	while (true) {
		while (vec[++i] < v) {
			if (i == high) { break; }
		}

		while (vec[--j] > v) {
			if (j == low) { break; }
		}

		if (i >= j) { break; }

		std::swap(vec[i], vec[j]);
	}

	std::swap(vec[low], vec[j]);
	return j;
}


// 辅助函数
void sort(std::vector<int>& vec, size_t low, size_t high)
{
	if (high <= low) { return; }
	size_t j = partition(vec, low, high);
	sort(vec, low, j > 0 ? j - 1 : 0);
	sort(vec, j + 1, high);
}


// 快速排序
void sort(std::vector<int>& vec)
{
	if (vec.empty()) { return; }

	// 先将数组元素随机打乱顺序
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(vec.begin(), vec.end(), g);

	sort(vec, 0, vec.size() - 1);
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
