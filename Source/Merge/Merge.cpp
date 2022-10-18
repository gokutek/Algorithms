#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <time.h>


/*
===============================================================================
归并排序：
分治思想，对左右两半部分分别排序，然后归并。
缺点是需要一份临时内存空间（下面实现中的vec_）。
===============================================================================
*/
class Merge
{
public:
	void sort(std::vector<int>& vec)
	{
		vec_ = vec;
		sort(vec, 0, vec.size() - 1);
	}

private:
	void sort(std::vector<int>& vec, size_t low, size_t high)
	{
		if (high <= low) { return; }
		size_t mid = low + (high - low) / 2;
		// 将左右两部分元素分别排序，然后再归并
		sort(vec, low, mid);
		sort(vec, mid + 1, high);
		merge(vec, low, high, mid);
	}

	void merge(std::vector<int>& vec, size_t low, size_t high, size_t mid)
	{
		// [low, mid]和(mid, high]都是有序的，将这两部分归并以确保[low, high]有序
		for (size_t i = low; i <= high; ++i) {
			vec_[i] = vec[i];
		}
		size_t i = low;
		size_t j = mid + 1;
		size_t idx = low;
		while (i <= mid || j <= high) {
			if (i > mid) {
				vec[idx++] = vec_[j++];
			} else if (j > high) {
				vec[idx++] = vec_[i++];
			} else if (vec_[i] > vec_[j]) {
				vec[idx++] = vec_[j++];
			} else {
				vec[idx++] = vec_[i++];
			}
		}
	}

private:
	std::vector<int> vec_;
};


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

	Merge merge;
	merge.sort(vec);

	for (size_t i = 0; i < vec.size(); ++i) {
		assert(vec[i] == vec2[i]);
	}

	return 0;
}
