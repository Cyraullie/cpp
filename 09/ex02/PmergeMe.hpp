#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "colors.hpp"

# include <iostream>
# include <vector>
# include <deque>
# include <ctime>
# include <cstdlib>
# include <algorithm>

//std::deque<unsigned int> _deq;
# define vit std::vector<unsigned int>::iterator
# define vi std::vector<unsigned int>

class PmergeMeVector
{
	private:
		vi _data;
		size_t _order;
		std::clock_t _start;

		void pairSort();
		void insertSort();
		void swap(int i, int j);
		void jacobSort(vi *main, vi *pend, vi *trash);


	public:
		// *** CANONICAL METHODS***
		PmergeMeVector();										// Default constructor
		PmergeMeVector(char **args);						// Data constructor
		PmergeMeVector(const PmergeMeVector& cpy);				// Copy constructor
		~PmergeMeVector();									// Destructor

		PmergeMeVector& operator=(const PmergeMeVector& src);	// Copy assignment

		void sort();
		void printContainer(std::string msg);
		void printTime();
};

#endif