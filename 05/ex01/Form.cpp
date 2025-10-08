/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:43:08 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/08 14:55:34 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Default constructor
Form::Form() : _name("Referandom"), _isSigned(0), _gradeToSign(100), _gradeToExec(50)
{
	std::cout << GREEN << "Default Form constructor called" << RESET << std::endl;
}

// Data constructor
Form::Form(std::string name, int sign, int exec) : _name(name), _isSigned(0), _gradeToSign(sign), _gradeToExec(exec)
{
	std::cout << LIGHT_GREEN << "Form constructor called for " << ITALIC << name << RESET << std::endl;
}

// Copy constructor
Form::Form(const Form& cpy) : _name(cpy._name), _isSigned(cpy._isSigned), _gradeToSign(cpy._gradeToSign), _gradeToExec(cpy._gradeToExec)
{
	std::cout << LIGHT_GREEN << "Form copy constructor called for " << ITALIC << cpy._name << RESET << std::endl;
}

// Copy assignment
Form& Form::operator=(const Form& src)
{
	std::cout << LIGHT_GREEN << "Form assignment operator called" << RESET << std::endl;
	if (this->_isSigned != src._isSigned)
		this->_isSigned = src._isSigned;
	return *this;
}

// Destructor
Form::~Form()
{
	std::cout << RED << "Form destructor called for " << ITALIC << this->_name << RESET << std::endl;
};


const std::string& Form::getName() const 
{
	return this->_name;
}


const bool& Form::getIsSigned() const
{
	return this->_isSigned;
}

const int& Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

const int& Form::getGradeToExec() const
{
	return this->_gradeToExec;
}

void Form::beSigned(const Bureaucrat & bureaucrat)
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
	throw (Form::GradeTooLowException());
}



void Form::checkGrade(int grade)
{
	if (grade > LOWERGRADE)
		throw (Form::GradeTooLowException());
	else if (grade < HIGHERGRADE)
		throw (Form::GradeTooHighException());
}

std::ostream &operator<<(std::ostream &stream, const Form &src)
{
	stream << src.getName() << " needed grade " << src.getGradeToSign() << " to be signed and grade " << src.getGradeToExec() << " to be exec " << std::endl;
	if (src.getIsSigned())
		stream << src.getName() << " is signed" << std::endl;
	else
		stream << src.getName() << " is not signed" << std::endl;
	return (stream);
}

char const * Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

char const * Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}