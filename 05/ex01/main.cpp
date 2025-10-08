/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:55:29 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/08 14:53:41 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

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
	try // Should not work
	{
		std::cout << BOLD << MAGENTA << "Too low grade for exec:" << RESET << std::endl;
		Form formA("FormA", 50, 152);
		std::cout << GREEN << formA << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try // Should not work
	{
		std::cout << BOLD << MAGENTA << "To hight grade for sign:" << RESET << std::endl;
		Form formB("FormB", 0, 140);
		std::cout << GREEN << formB << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try // Should work
	{
		std::cout << BOLD << MAGENTA << "try to create a Form with valid arguments:" << RESET << std::endl;
		Form formC("FormC", 50, 15);
		std::cout << GREEN << formC << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED <<  e.what() << RESET << std::endl;
	}
	std::cout << BOLD << MAGENTA << "Create with a default constructor:" << RESET << std::endl;
	Form bestForm;
	std::cout << GREEN << bestForm << RESET << std::endl;
	Bureaucrat clitorin(100, "Clitorin");
	std::cout << BOLD << MAGENTA << "Try to sign it with Clitorin" << RESET << std::endl;
	clitorin.signForm(bestForm); // Should work
	std::cout << GREEN << bestForm << RESET << std::endl;
	std::cout << BOLD << MAGENTA << "Try to sign it with Clitorin (after a downgrade)" << std::endl;
	clitorin.downgrade();
	clitorin.signForm(bestForm); // Should not work

	return (0);
}