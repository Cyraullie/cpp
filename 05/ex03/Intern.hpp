#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

class Intern
{
	private:
		std::string _name;

	public:
		Intern();										// Default constructor
		Intern(std::string name);						// Data constructor
		Intern(const Intern& cpy);				// Copy constructor
		Intern& operator=(const Intern& src);	// Copy assignment
		~Intern();									// Destructor

		// --- Example methods ---
		void setName(const std::string& name);
		const std::string& getName() const;

};

#endif // INTERN_HPP
