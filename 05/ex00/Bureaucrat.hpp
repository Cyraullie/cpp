/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:02:54 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/07 11:36:57 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

# define HIGHERGRADE 1
# define LOWERGRADE 150

class Bureaucrat {
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();										// Default constructor
		Bureaucrat(int grade, std::string const name);		// Data constructor
		Bureaucrat(const Bureaucrat& cpy);					// Copy constructor
		Bureaucrat& operator=(const Bureaucrat& src);		// Copy assignment
		~Bureaucrat();										// Destructor

		const std::string&	getName() const;
		const int&			getGrade() const;
		void				downgrade();
		void				upgrade();
		void				checkGrade(int grade);

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

std::ostream &operator<<(std::ostream &stream, const Bureaucrat& src);

#endif // BUREAUCRAT_HPP
