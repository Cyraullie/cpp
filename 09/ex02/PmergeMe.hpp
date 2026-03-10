#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "colors.hpp"

# include <iostream>
# include <vector>
# include <deque>
# include <ctime>
# include <cstdlib>
# include <algorithm>

# define vit std::vector<unsigned int>::iterator
# define vi std::vector<unsigned int>

class PmergeMeVector
{
	private:
		vi _data;
		size_t _order;
		std::clock_t _start;

		void exchangePair(int i, int j);
		void pairSort();
		void insertSort();
		void swap(int i, int j);
		void jacobSort(vi *main, vi *pend, vi *trash);
		vi jacobsthal(size_t size);
		void jacobsthalBinary(vi *main, vi *pend, vit ite);
		void standardBinary(vi *main, vi *pend);
		void insert(vi *main, vi *pend, vit it, size_t pendPos);
		void binarySearch(vi &main, vit sbegin, vit send, vit start, vit end);


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

# define dit std::deque<unsigned int>::iterator
# define di std::deque<unsigned int>

class PmergeMeDeque
{
	private:
		di _data;
		size_t _order;
		std::clock_t _start;

		void exchangePair(int i, int j);
		void pairSort();
		void insertSort();
		void swap(int i, int j);
		void jacobSort(di *main, di *pend, di *trash);
		di jacobsthal(size_t size);
		void jacobsthalBinary(di *main, di *pend, dit ite);
		void standardBinary(di *main, di *pend);
		void insert(di *main, di *pend, dit it, size_t pendPos);
		void binarySearch(di &main, dit sbegin, dit send, dit start, dit end);


	public:
		// *** CANONICAL METHODS***
		PmergeMeDeque();										// Default constructor
		PmergeMeDeque(char **args);						// Data constructor
		PmergeMeDeque(const PmergeMeDeque& cpy);				// Copy constructor
		~PmergeMeDeque();									// Destructor

		PmergeMeDeque& operator=(const PmergeMeDeque& src);	// Copy assignment

		void sort();
		void printContainer(std::string msg);
		void printTime();
};

#endif