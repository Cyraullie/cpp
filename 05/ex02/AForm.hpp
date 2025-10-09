/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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

class AForm {
	protected:
		static const unsigned int _grade_to_sign = 100;
		static const unsigned int _grade_to_exec = 50;

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;
		void				checkGrade(int grade);

	public:
		AForm();										// Default constructor
		AForm(std::string name, int sign, int exec);	// Data constructor
		AForm(const AForm& cpy);						// Copy constructor
		AForm& operator=(const AForm& src);			// Copy assignment
		~AForm();									// Destructor

		const std::string&	getName() const;
		const bool&			getIsSigned() const;
		const int&			getGradeToSign() const;
		const int&			getGradeToExec() const;
		void				beSigned(const Bureaucrat & bureaucrat);
		void				execute(const Bureaucrat & executor) const;
		virtual void		doExecute() const = 0;

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

		class NotSignedException : public std::exception
		{
			public:
				virtual char const* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &stream, const AForm& src);

#endif // FORM_HPP
