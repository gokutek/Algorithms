#ifndef INDEX_MIN_PQ_H
#define INDEX_MIN_PQ_H

#include <assert.h>
#include <vector>
#include <limits>

/*
===============================================================================
说明一下这几个成员变量：
std::vector<T>		keys_;
std::vector<size_t>	pq_;
std::vector<size_t>	qp_;
1. 这几个数组的第0个位置都未使用（仅为了方便计算父、子节点，可以参考MinPQ优化掉）；
2. keys_不是二叉堆，keys_[k]表示索引k对应的元素；
3. pq_是二叉堆，pq_[i]表示二叉堆中第i个元素的索引是k；
4. qp_也不是二叉堆，qp_[k]表示索引k的元素，在pq_中的位置；
5. 因qp_[k]=n_， pq_[n_]=k，所以有：pq_[qp_[i]] = qp_[pq_[i]] = i；
===============================================================================
*/
template<typename T>
class IndexMinPQ
{
public:
	// 创建一个最大容量为maxN的优先队列，索引的取值范围为0至maxN-1
	explicit IndexMinPQ(size_t maxN);

	// 插入一个元素，将它和索引k相关联
	void Insert(size_t k, T const &val);

	// 将索引为K的元素设为val
	void ChangeKey(size_t k, T const &val);

	// 是否存在索引为k的元素
	bool Contains(size_t k) const;

	// 删去索引k及其相关联的元素
	void Delete(size_t k);

	// 返回最小元素
	T const& MinKey() const;

	// 返回最小元素的索引
	size_t MinIndex() const;

	// 删除最小元素并返回它的索引
	size_t DelMin();

	// 优先队列是否为空
	bool IsEmpty() const;

	// 优先队列中的元素数量
	size_t Size() const;

private:
	// 二叉堆中的第i个元素是否小于第j个元素
	bool Compare(size_t i, size_t j);

	// 交换堆中的两个元素
	void Exchange(size_t i, size_t j);

private:
	// 上浮
	void Swim(size_t k);
	
	// 下沉
	void Sink(size_t k);

private:
	size_t const		maxN_;
	size_t				n_;
	std::vector<T>		keys_;
	std::vector<size_t>	pq_;
	std::vector<size_t>	qp_;
};



template<typename T>
inline IndexMinPQ<T>::IndexMinPQ(size_t maxN)
	: maxN_(maxN)
	, n_(0)
{
	keys_.resize(maxN + 1);
	pq_.resize(maxN + 1, std::numeric_limits<size_t>::max());
	qp_.resize(maxN + 1, std::numeric_limits<size_t>::max());
}


template<typename T>
inline void IndexMinPQ<T>::Insert(size_t k, T const &val)
{
	assert(k < maxN_);
	assert(!Contains(k));
	++n_;
	qp_[k] = n_;
	pq_[n_] = k;
	keys_[k] = val;
	Swim(n_);
}


template<typename T>
inline void IndexMinPQ<T>::ChangeKey(size_t k, T const &val)
{
	keys_[k] = val;
	Swim(qp_[k]);
	Sink(qp_[k]);
}


template<typename T>
inline bool IndexMinPQ<T>::Contains(size_t k) const
{
	return std::numeric_limits<size_t>::max() != qp_[k];
}


template<typename T>
inline void IndexMinPQ<T>::Delete(size_t k)
{
	assert(Contains(k));
	size_t const index = qp_[k];
	qp_[k] = std::numeric_limits<size_t>::max();
	Exchange(index, n_--);
	Swim(index);
	Sink(index);
}


template<typename T>
inline T const& IndexMinPQ<T>::MinKey() const
{
	return keys_[MinIndex()];
}


template<typename T>
inline size_t IndexMinPQ<T>::MinIndex() const
{
	assert(!IsEmpty());
	return pq_[1];
}


template<typename T>
inline size_t IndexMinPQ<T>::DelMin()
{
	assert(!IsEmpty());
	size_t const min = pq_[1];
	Exchange(1, n_--);
	Sink(1);
	qp_[min] = std::numeric_limits<size_t>::max();
	pq_[n_ + 1] = std::numeric_limits<size_t>::max();
	return min;
}


template<typename T>
inline bool IndexMinPQ<T>::IsEmpty() const
{
	return 0 == n_;
}


template<typename T>
inline size_t IndexMinPQ<T>::Size() const
{
	return n_;
}


template<typename T>
bool IndexMinPQ<T>::Compare(size_t i, size_t j)
{
	return keys_[pq_[i]] < keys_[pq_[j]];
}


template<typename T>
void IndexMinPQ<T>::Exchange(size_t i, size_t j)
{
	std::swap(pq_[i], pq_[j]);
	qp_[pq_[i]] = i;
	qp_[pq_[j]] = j;
}


template<typename T>
inline void IndexMinPQ<T>::Swim(size_t k)
{
	while (k > 1 && Compare(k, k / 2)) {
		Exchange(k, k / 2);
		k /= 2;
	}
}


template<typename T>
inline void IndexMinPQ<T>::Sink(size_t k)
{
	while (k * 2 <= n_) {
		size_t j = k * 2;
		if (j + 1 <= n_ && Compare(j + 1, j)) {
			++j;
		}
		if (Compare(k, j)) { break; }
		Exchange(k, j);
		k = j;
	}
}

#endif // INDEX_MIN_PQ_H
