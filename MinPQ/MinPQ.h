#ifndef MIN_PQ_H
#define MIN_PQ_H

#include <assert.h>
#include <vector>
#include <algorithm>

/*
===============================================================================
PQ：Priority Queue；

STL中对应的数据结构为std::priority_queue；

书中的Java实现未使用数组的第0个位置，下面的实现使用了该位置。
k的两个子节点为：k*2+1,k*2+2
k的父节点为：(k-1)/2
===============================================================================
*/
template<typename T>
class MinPQ
{
public:
	// 创建一个初始容量为initCapacity的优先队列
	MinPQ(size_t initCapacity = 1);

	// 返回队列是否为空
	bool IsEmpty() const;

	// 返回优先队列中的元素个数
	size_t Size() const;

	// 返回最小元素
	T& Min() const;

	// 向优先队列中插入一个元素
	void Insert(T const &value);

	// 删除并返回最小元素
	T DelMin();

private:
	// 上浮
	void Swim(size_t k);

	// 下沉
	void Sink(size_t k);

private:
	std::vector<T>	pq_;
};



template<typename T>
MinPQ<T>::MinPQ(size_t initCapacity)
{
	pq_.reserve(initCapacity);
}


template<typename T>
bool MinPQ<T>::IsEmpty() const
{
	return pq_.empty();
}


template<typename T>
size_t MinPQ<T>::Size() const
{
	return pq_.size();
}


template<typename T>
T& MinPQ<T>::Min() const
{
	assert(!IsEmpty());
	return pq_[0];
}


template<typename T>
void MinPQ<T>::Insert(T const &value)
{
	pq_.push_back(value);
	Swim(pq_.size() - 1);
}


template<typename T>
void MinPQ<T>::Swim(size_t k)
{
	// k的父节点为：(k - 1) / 2
	assert(k < pq_.size());
	while (k > 0 && pq_[k] < pq_[(k - 1) / 2]) {
		std::swap(pq_[k], pq_[(k - 1) / 2]);
		k = (k - 1) / 2;
	}
}


template<typename T>
T MinPQ<T>::DelMin()
{
	assert(!IsEmpty());
	T const val = pq_[0];
	pq_[0] = pq_.back();
	pq_.pop_back();
	Sink(0);
	return val;
}


template<typename T>
void MinPQ<T>::Sink(size_t k)
{
	// k的两个子节点为：k * 2 + 1, k * 2 + 2
	while (k * 2 + 1 < pq_.size()) {
		size_t j = k * 2 + 1;
		if (j + 1 < pq_.size() && pq_[j + 1] < pq_[j]){
			++j;
		}

		if (pq_[k] < pq_[j]) { 
			break; 
		}

		std::swap(pq_[k], pq_[j]);
		k = j;
	}
}

#endif // MIN_PQ_H
