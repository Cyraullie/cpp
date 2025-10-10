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
	std::string	tab[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm		*(Intern::*form[3])(std::string const &) = {&Intern::createShrubbery , &Intern::createRobotomy, &Intern::createPresidential};
	for (int i = 0; i < 3; i++)
	{
		if (name == tab[i])
		{
			std::cout << LIGHT_BLUE << "Intern creates " << name << std::endl;
			return ((this->*form[i])(target));
		}
	}
	throw Intern::InvalidFormException();
}

const char *Intern::InvalidFormException::what() const throw()
{
	return ("Invalid form name!");
}
