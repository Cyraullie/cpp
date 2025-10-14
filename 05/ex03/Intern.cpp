#include "Intern.hpp"

// Default constructor
Intern::Intern()
{
	std::cout << GREEN << "Default Intern constructor called" << RESET << std::endl;
}

// Copy constructor
Intern::Intern(const Intern& cpy)
{
	(void)cpy;
	std::cout << LIGHT_GREEN << "Intern copy constructor called " << RESET << std::endl;
}

// Destructor
Intern::~Intern()
{
	std::cout << RED << "Intern destructor called for " << RESET << std::endl;
};

// Copy assignment
Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	std::cout << LIGHT_GREEN << "Intern assignment operator called" << RESET << std::endl;
	return *this;
}

AForm *Intern::createShrubbery(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomy(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidential(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string const & name, std::string const & target)
{
int	i = 0;
	std::string	names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	while (i < 4)
	{
		if (name == names[i])
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << names[i] << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern creates " << names[i] << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << names[i] << std::endl;
			return new PresidentialPardonForm(target);
		default:
			throw (InvalidFormException());
	}
}

const char *Intern::InvalidFormException::what() const throw()
{
	return ("Invalid form name!");
}
