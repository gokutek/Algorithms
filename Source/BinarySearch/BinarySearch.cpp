#include <algorithm>
#include <vector>
#include <time.h>
#include <assert.h>


/*
===============================================================================
二分查找：
vec必须已经排好序。
下面的这个实现中，如果vec中存在多个val，返回的可能并不是第一个val的索引。
===============================================================================
*/
size_t search(const std::vector<int>& vec, int val)
{
	size_t low = 0;
	size_t high = vec.size();
	while (low < high) {
		size_t mid = (low + high) / 2;
		if (vec[mid] == val) {
			return mid; 
		} else if (vec[mid] < val) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	return -1;
}


int main()
{
	srand((unsigned int)time(NULL));

	std::vector<int> vec;
	vec.reserve(100);
	for (int i = 0; i < 100; ++i) {
		vec.push_back(rand());
	}
	std::sort(vec.begin(), vec.end());

	for (size_t i = 0; i < vec.size(); ++i) {
		size_t idx = search(vec, vec[i]);
		assert(idx >= 0 && idx < vec.size());
		assert(vec[i] == vec[idx]);
	}
	return 0;
}
