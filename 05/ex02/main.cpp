/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:55:29 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/09 11:09:57 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try // Should not work
	{
		std::cout << BOLD << "Declare a too low grade:" << RESET << std::endl;
		Bureaucrat	yvette(151, "Yvette");
		std::cout << GREEN << yvette << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try // Should not work
	{
		std::cout << BOLD << "Declare a too high grade:" << RESET << std::endl;
		Bureaucrat	yvon(-1, "Yvon");
		std::cout << GREEN << yvon << RESET << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try // Should work
	{
		std::cout << BOLD << "Declare a valid grade:" << RESET << std::endl;
		Bureaucrat yvan(1, "Yvan");
		std::cout << GREEN << yvan << RESET << std::endl;
	}
	catch(std:: exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try // Should work
	{
		std::cout << BOLD << "With a default constructor" << RESET << std::endl;
		Bureaucrat alph;
		std::cout << GREEN << alph << RESET << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try // Should not work
	{
		Bureaucrat yvan(1, "Yvan");
		std::cout << BOLD << "Try to downgrade Yvan" << RESET << std::endl;
		std::cout << "Berfore downgrade:" << std::endl;
		std::cout << GREEN << yvan << RESET << std::endl;
		yvan.downgrade();
		std::cout << "After downgrade:" << std::endl;
		std::cout << GREEN << yvan << RESET << std::endl;
		std::cout << BOLD << "Try to upgrade Yvan two times" << RESET << std::endl;
		yvan.upgrade();
		yvan.upgrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << BOLD << "----------FORM TEST----------" << RESET << std::endl;

	std::cout << BOLD << "*** Shrubbery Form ***" << RESET << std::endl;
	try
	{
		Bureaucrat clitorin(100, "Clitorin");
		ShrubberyCreationForm shrub("My_penthouse");
		clitorin.signForm(shrub);
		clitorin.excecuteForm(shrub);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << BOLD << "*** Robotomy request Form ***" << RESET << std::endl;
	try
	{
		Bureaucrat clitorin(40, "Clitorin");
		RobotomyRequestForm robotomy("Big_brain");
		clitorin.signForm(robotomy);
		clitorin.excecuteForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << BOLD << "*** President Pardon Form ***" << RESET << std::endl;
	try // Should not work
	{
		std::cout << BOLD << "*** Test with grade to low for execute ***" << RESET << std::endl;
		Bureaucrat clitorin(25, "Clitorin");
		PresidentPardonForm oupsi("Oupsii");
		clitorin.signForm(oupsi);
		clitorin.excecuteForm(oupsi);
	}

	catch(const std::exception& e) // Should work
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat clitorin(5, "Clitorin");
		PresidentPardonForm oupsi("Oupsii");
		clitorin.signForm(oupsi);
		clitorin.excecuteForm(oupsi);
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}