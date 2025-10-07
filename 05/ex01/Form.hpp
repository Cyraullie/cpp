/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:43:11 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/07 11:50:08 by cgoldens         ###   ########.fr       */
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
		Form(std::string name);						// Data constructor
		Form(const Form& cpy);				// Copy constructor
		Form& operator=(const Form& src);	// Copy assignment
		~Form();									// Destructor

		// --- Example methods ---
		const std::string& getName() const;

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

#endif // FORM_HPP
