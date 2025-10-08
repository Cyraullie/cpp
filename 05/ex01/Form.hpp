/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:43:11 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/08 14:48:02 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "colors.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExec;
		void				checkGrade(int grade);

	public:
		Form();										// Default constructor
		Form(std::string name, int sign, int exec);	// Data constructor
		Form(const Form& cpy);						// Copy constructor
		Form& operator=(const Form& src);			// Copy assignment
		~Form();									// Destructor

		const std::string&	getName() const;
		const bool&			getIsSigned() const;
		const int&			getGradeToSign() const;
		const int&			getGradeToExec() const;
		void				beSigned(const Bureaucrat & bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual char const* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual char const* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &stream, const Form& src);

#endif // FORM_HPP
