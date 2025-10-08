/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:43:08 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/08 14:55:34 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Default constructor
AForm::AForm() : _name("Referandom"), _isSigned(0), _gradeToSign(100), _gradeToExec(50)
{
	std::cout << GREEN << "Default AForm constructor called" << RESET << std::endl;
}

// Data constructor
AForm::AForm(std::string name, int sign, int exec) : _name(name), _isSigned(0), _gradeToSign(sign), _gradeToExec(exec)
{
	std::cout << LIGHT_GREEN << "AForm constructor called for " << ITALIC << name << RESET << std::endl;
	checkGrade(sign);
	checkGrade(exec);
}

// Copy constructor
AForm::AForm(const AForm& cpy) : _name(cpy._name), _isSigned(cpy._isSigned), _gradeToSign(cpy._gradeToSign), _gradeToExec(cpy._gradeToExec)
{
	std::cout << LIGHT_GREEN << "AForm copy constructor called for " << ITALIC << cpy._name << RESET << std::endl;
}

// Copy assignment
AForm& AForm::operator=(const AForm& src)
{
	std::cout << LIGHT_GREEN << "AForm assignment operator called" << RESET << std::endl;
	if (this->_isSigned != src._isSigned)
		this->_isSigned = src._isSigned;
	return *this;
}

// Destructor
AForm::~AForm()
{
	std::cout << RED << "AForm destructor called for " << ITALIC << this->_name << RESET << std::endl;
};


const std::string& AForm::getName() const 
{
	return this->_name;
}


const bool& AForm::getIsSigned() const
{
	return this->_isSigned;
}

const int& AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

const int& AForm::getGradeToExec() const
{
	return this->_gradeToExec;
}

void AForm::beSigned(const Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		if (this->getIsSigned())
			std::cout << this->getName() << " is already signed !" << std::endl;
		else
		{
			this->_isSigned = true;
			std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
		}
		return ;
	}
	throw (AForm::GradeTooLowException());
}



void AForm::checkGrade(int grade)
{
	if (grade > LOWERGRADE)
		throw (AForm::GradeTooLowException());
	else if (grade < HIGHERGRADE)
		throw (AForm::GradeTooHighException());
}

std::ostream &operator<<(std::ostream &stream, const AForm &src)
{
	stream << src.getName() << " needed grade " << src.getGradeToSign() << " to be signed and grade " << src.getGradeToExec() << " to be exec " << std::endl;
	if (src.getIsSigned())
		stream << src.getName() << " is signed" << std::endl;
	else
		stream << src.getName() << " is not signed" << std::endl;
	return (stream);
}

char const * AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

char const * AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

char const * AForm::NotSignedException::what() const throw()
{
	return ("The form is not signed!");
}