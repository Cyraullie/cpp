#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <stack>
# include "colors.hpp"

class RPN
{
	private:
		std::string _name;

	public:
		// *** CANONICAL METHODS***
		RPN();										// Default constructor
		RPN(std::string name);						// Data constructor
		RPN(const RPN& cpy);				// Copy constructor
		~RPN();									// Destructor

		RPN& operator=(const RPN& src);	// Copy assignment

		// *** SET METHODS***
		void setName(const std::string& name);

		// *** GET METHODS***
		const std::string& getName() const;

		// *** OTHER METHODS***

};

#endif // RPN_HPP
