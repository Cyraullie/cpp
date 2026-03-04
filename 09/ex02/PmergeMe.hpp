#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include "colors.hpp"
# include <iostream>
# include <vector>
# include <deque>
#include <ctime>

//std::deque<unsigned int> _deq;

class PmergeMeVector
{
	private:
		std::vector<unsigned int> _vec;
		 std::clock_t _start;


	public:
		// *** CANONICAL METHODS***
		PmergeMeVector();										// Default constructor
		PmergeMeVector(std::string name);						// Data constructor
		PmergeMeVector(const PmergeMeVector& cpy);				// Copy constructor
		~PmergeMeVector();									// Destructor

		PmergeMeVector& operator=(const PmergeMeVector& src);	// Copy assignment
		
		void sort();
		void printContainer();
};

#endif