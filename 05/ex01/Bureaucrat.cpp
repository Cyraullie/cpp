#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("Patrick"), _grade(150)
{
	std::cout << GREEN << "Default Bureaucrat constructor called" << RESET << std::endl;
}

// Data constructor
Bureaucrat::Bureaucrat(int grade, std::string const name) : _name(name)
{
	std::cout << LIGHT_GREEN << "Bureaucrat constructor called for " << ITALIC << name << RESET << std::endl;
	checkGrade(grade);
	this->_grade = grade;

}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& cpy) : _name(cpy._name), _grade(cpy._grade)
{
	std::cout << LIGHT_GREEN << "Bureaucrat copy constructor called for " << ITALIC << cpy._name << RESET << std::endl;
}

// Copy assignment
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this->_grade != src._grade) {
		this->_grade = src._grade;
	}
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat destructor called for " << ITALIC << this->_name << RESET << std::endl;
};

const std::string& Bureaucrat::getName() const 
{
	return this->_name;
}

const int& Bureaucrat::getGrade() const 
{
	return this->_grade;
}

void Bureaucrat::downgrade()
{
	checkGrade(this->_grade + 1);
	std::cout << LIGHT_YELLOW << "downgrade " << this->_name << RESET << std::endl;
	this->_grade++;
}

void Bureaucrat::upgrade()
{
	checkGrade(this->_grade - 1);
	std::cout << LIGHT_YELLOW << "upgrade " << this->_name << RESET << std::endl;
	this->_grade--;
}

void Bureaucrat::checkGrade(int grade)
{
	if (grade > LOWERGRADE)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < HIGHERGRADE)
		throw (Bureaucrat::GradeTooHighException());
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &src)
{
	stream << src.getName() << " bureaucrat grade " << src.getGrade();
	return (stream);
}

char const * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

char const * Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}