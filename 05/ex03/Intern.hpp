#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "colors.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	private:
		AForm *createShrubbery(std::string const & target);
		AForm *createRobotomy(std::string const & target);
		AForm *createPresidential(std::string const & target);

	public:
		Intern();										// Default constructor
		Intern(const Intern& cpy);				// Copy constructor
		~Intern();									// Destructor

		Intern& operator=(const Intern& src);	// Copy assignment

		AForm *makeForm(std::string const & name, std::string const & target);

		class InvalidFormException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif // INTERN_HPP
