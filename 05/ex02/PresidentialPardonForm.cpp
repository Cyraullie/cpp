#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", this->_grade_to_sign, this->_grade_to_exec), _target("")
{
	std::cout << GREEN << "Default PresidentialPardonForm constructor called" << RESET << std::endl;
}

// Data constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", this->_grade_to_sign, this->_grade_to_exec), _target(target)
{
	std::cout << LIGHT_GREEN << "PresidentialPardonForm constructor called for " << ITALIC << target << RESET << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy) : AForm(cpy.getName(), cpy.getGradeToSign(), cpy.getGradeToExec()), _target(cpy.getTarget())
{
	std::cout << LIGHT_GREEN << "PresidentialPardonForm copy constructor called for " << ITALIC << cpy.getTarget() << RESET << std::endl;
}

// Copy assignment
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	std::cout << LIGHT_GREEN << "PresidentialPardonForm assignment operator called" << RESET << std::endl;
	if (this != &src) {
		this->_target = src.getTarget();
	}
	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm destructor called for " << ITALIC << this->getTarget() << RESET << std::endl;
};

const std::string& PresidentialPardonForm::getTarget() const 
{
	return this->_target;
}
