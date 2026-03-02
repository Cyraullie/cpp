#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <list>
# include <algorithm>
# include "colors.hpp"

class RPN
{
	private:
		std::list<float> _lst;

	public:
		// *** CANONICAL METHODS***
		RPN();										// Default constructor
		RPN(std::string name);						// Data constructor
		RPN(const RPN& cpy);				// Copy constructor
		~RPN();									// Destructor

		RPN& operator=(const RPN& src);	// Copy assignment

		// *** SET METHODS***
		void pushData(float n);
		// *** GET METHODS***
		void listData();

		// *** OTHER METHODS***
		void addition();
		void substraction();
		void division();
		void multiple();
		void clearList(int len);
		int countListContent();

};

#endif // RPN_HPP
