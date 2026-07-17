#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(PmergeMe const &other);
	PmergeMe &operator=(PmergeMe const &other);
	~PmergeMe();

	void sort(int argc, char **argv);

private:
	void fordJohnson(std::vector<int> &vec);
	void fordJohnson(std::deque<int> &deq);
};

/* internal: sorts v and returns where each element came from in idx */
void fordJohnsonSort(std::vector<int> &v, std::vector<std::size_t> &idx);
void fordJohnsonSort(std::deque<int> &d, std::deque<std::size_t> &idx);

#endif
