#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const &) {}
PmergeMe &PmergeMe::operator=(PmergeMe const &) { return *this; }
PmergeMe::~PmergeMe() {}

void fordJohnsonSort(std::vector<int> &v, std::vector<std::size_t> &idx)
{
	if (v.size() < 2)
	{
		idx.resize(v.size());
		for (std::size_t i = 0; i < v.size(); ++i)
			idx[i] = i;
		return;
	}

	std::vector<int> big;
	std::vector<int> small;
	std::vector<std::size_t> bigIdx;
	std::vector<std::size_t> smallIdx;

	for (std::size_t i = 0; i + 1 < v.size(); i += 2)
	{
		if (v[i] > v[i + 1])
		{
			big.push_back(v[i]);
			bigIdx.push_back(idx[i]);
			
			small.push_back(v[i + 1]);
			smallIdx.push_back(idx[i + 1]);
		}
		else
		{
			big.push_back(v[i + 1]);
			bigIdx.push_back(idx[i + 1]);
			
			small.push_back(v[i]);
			smallIdx.push_back(idx[i]);
		}
	}

	if (v.size() % 2)
	{
		small.push_back(v.back());
		smallIdx.push_back(idx.back());
	}

	std::vector<std::size_t> pairIdx(big.size());
	for (std::size_t i = 0; i < big.size(); ++i)
		pairIdx[i] = i;
	fordJohnsonSort(big, pairIdx);

	std::vector<std::size_t> permBigIdx(big.size());
	for (std::size_t i = 0; i < big.size(); ++i)
		permBigIdx[i] = bigIdx[pairIdx[i]];
	bigIdx.swap(permBigIdx);

	std::vector<int> chain;
	std::vector<std::size_t> chainIdx;
	std::vector<std::size_t> aPos(big.size());

	chain.push_back(small[pairIdx[0]]);
	chainIdx.push_back(smallIdx[pairIdx[0]]);
	chain.insert(chain.end(), big.begin(), big.end());
	chainIdx.insert(chainIdx.end(), bigIdx.begin(), bigIdx.end());
	for (std::size_t i = 0; i < big.size(); ++i)
		aPos[i] = i + 1;

	std::size_t jPrev = 1;
	std::size_t jCurr = 3;

	while (jPrev < big.size())
	{
		std::size_t end = jCurr;
		if (end > big.size())
			end = big.size();

		for (std::size_t k = end; k > jPrev; --k)
		{
			std::size_t i = k - 1;
			int val = small[pairIdx[i]];
			std::size_t valIdx = smallIdx[pairIdx[i]];

			std::vector<int>::iterator bound = chain.begin() + aPos[i];
			std::vector<int>::iterator where = std::lower_bound(chain.begin(), bound, val);
			std::size_t dist = static_cast<std::size_t>(where - chain.begin());
			chain.insert(where, val);
			chainIdx.insert(chainIdx.begin() + dist, valIdx);
			for (std::size_t j = 0; j < aPos.size(); ++j)
				if (aPos[j] >= dist) ++aPos[j];
		}

		std::size_t next = jCurr + 2 * jPrev;
		jPrev = jCurr;
		jCurr = next;
	}

	std::size_t pendSize = small.size();
	for (std::size_t k = pendSize; k > big.size(); --k)
	{
		std::size_t i = k - 1;
		int val = small[i];
		std::size_t valIdx = smallIdx[i];

		std::vector<int>::iterator where =
			std::lower_bound(chain.begin(), chain.end(), val);
		std::size_t dist = static_cast<std::size_t>(where - chain.begin());
		chain.insert(where, val);
		chainIdx.insert(chainIdx.begin() + dist, valIdx);
	}

	v.swap(chain);
	idx.swap(chainIdx);
}

void fordJohnsonSort(std::deque<int> &d, std::deque<std::size_t> &idx)
{
	if (d.size() < 2)
	{
		idx.resize(d.size());
		for (std::size_t i = 0; i < d.size(); ++i)
			idx[i] = i;
		return;
	}

	std::deque<int> big;
	std::deque<int> small;
	std::deque<std::size_t> bigIdx;
	std::deque<std::size_t> smallIdx;

	for (std::size_t i = 0; i + 1 < d.size(); i += 2)
	{
		if (d[i] > d[i + 1])
		{
			big.push_back(d[i]);     bigIdx.push_back(idx[i]);
			small.push_back(d[i + 1]); smallIdx.push_back(idx[i + 1]);
		}
		else
		{
			big.push_back(d[i + 1]); bigIdx.push_back(idx[i + 1]);
			small.push_back(d[i]);     smallIdx.push_back(idx[i]);
		}
	}

	if (d.size() % 2)
	{
		small.push_back(d.back());
		smallIdx.push_back(idx.back());
	}

	std::deque<std::size_t> pairIdx(big.size());
	for (std::size_t i = 0; i < big.size(); ++i)
		pairIdx[i] = i;
	fordJohnsonSort(big, pairIdx);

	std::deque<std::size_t> permBigIdx(big.size());
	for (std::size_t i = 0; i < big.size(); ++i)
		permBigIdx[i] = bigIdx[pairIdx[i]];
	bigIdx.swap(permBigIdx);

	std::deque<int> chain;
	std::deque<std::size_t> chainIdx;
	std::vector<std::size_t> aPos(big.size());

	chain.push_back(small[pairIdx[0]]);
	chainIdx.push_back(smallIdx[pairIdx[0]]);
	chain.insert(chain.end(), big.begin(), big.end());
	chainIdx.insert(chainIdx.end(), bigIdx.begin(), bigIdx.end());
	for (std::size_t i = 0; i < big.size(); ++i)
		aPos[i] = i + 1;

	std::size_t jPrev = 1;
	std::size_t jCurr = 3;

	while (jPrev < big.size())
	{
		std::size_t end = jCurr;
		if (end > big.size())
			end = big.size();

		for (std::size_t k = end; k > jPrev; --k)
		{
			std::size_t i = k - 1;
			int val = small[pairIdx[i]];
			std::size_t valIdx = smallIdx[pairIdx[i]];

			std::deque<int>::iterator bound =
				chain.begin() + aPos[i];
			std::deque<int>::iterator where =
				std::lower_bound(chain.begin(), bound, val);
			std::size_t dist = static_cast<std::size_t>(where - chain.begin());
			chain.insert(where, val);
			chainIdx.insert(chainIdx.begin() + dist, valIdx);
			for (std::size_t j = 0; j < aPos.size(); ++j)
				if (aPos[j] >= dist) ++aPos[j];
		}

		std::size_t next = jCurr + 2 * jPrev;
		jPrev = jCurr;
		jCurr = next;
	}

	std::size_t pendSize = small.size();
	for (std::size_t k = pendSize; k > big.size(); --k)
	{
		std::size_t i = k - 1;
		int val = small[i];
		std::size_t valIdx = smallIdx[i];

		std::deque<int>::iterator where =
			std::lower_bound(chain.begin(), chain.end(), val);
		std::size_t dist = static_cast<std::size_t>(where - chain.begin());
		chain.insert(where, val);
		chainIdx.insert(chainIdx.begin() + dist, valIdx);
	}

	d.swap(chain);
	idx.swap(chainIdx);
}

void PmergeMe::fordJohnson(std::vector<int> &v)
{
	std::vector<std::size_t> idx(v.size());
	for (std::size_t i = 0; i < v.size(); ++i)
		idx[i] = i;
	fordJohnsonSort(v, idx);
}

void PmergeMe::fordJohnson(std::deque<int> &d)
{
	std::deque<std::size_t> idx(d.size());
	for (std::size_t i = 0; i < d.size(); ++i)
		idx[i] = i;
	fordJohnsonSort(d, idx);
}

void PmergeMe::sort(int argc, char **argv)
{
	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; i < argc; ++i)
	{
		std::string arg(argv[i]);
		for (size_t j = 0; j < arg.size(); ++j)
		{
			if (!std::isdigit(arg[j]) && !(j == 0 && arg[j] == '+'))
				throw std::runtime_error("Error");
		}
		int n = std::atoi(arg.c_str());
		if (n < 0)
			throw std::runtime_error("Error");
		vec.push_back(n);
		deq.push_back(n);
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); ++i)
	{
		if (i > 0) std::cout << " ";
		std::cout << vec[i];
	}
	std::cout << std::endl;

	clock_t start = clock();
	fordJohnson(vec);
	clock_t end = clock();
	double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	fordJohnson(deq);
	end = clock();
	double deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); ++i)
	{
		if (i > 0) std::cout << " ";
		std::cout << vec[i];
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size()
	          << " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
	          << " elements with std::deque : " << deqTime << " us" << std::endl;
}
