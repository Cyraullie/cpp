#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", GRADETOSIGN, GRADETOEXEC), _target("")
{
	std::cout << GREEN << "Default RobotomyRequestForm constructor called" << RESET << std::endl;
}

// Data constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", GRADETOSIGN, GRADETOEXEC), _target(target)
{
	std::cout << LIGHT_GREEN << "RobotomyRequestForm constructor called for " << ITALIC << target << RESET << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy) : AForm(cpy.getName(), cpy.getGradeToSign(), cpy.getGradeToExec()), _target(cpy.getTarget())
{
	std::cout << LIGHT_GREEN << "RobotomyRequestForm copy constructor called for " << ITALIC << cpy.getTarget() << RESET << std::endl;
}

// Copy assignment
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << LIGHT_GREEN << "RobotomyRequestForm assignment operator called" << RESET << std::endl;
	if (this != &src) {
		this->_target = src.getTarget();
	}
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm destructor called for " << ITALIC << this->getTarget() << RESET << std::endl;
};

const std::string& RobotomyRequestForm::getTarget() const 
{
	return this->_target;
}
