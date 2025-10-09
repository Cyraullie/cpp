#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

# define ARTFILENAME "Tree_ASCII_Art"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

		static const unsigned int _grade_to_sign = 145;
		static const unsigned int _grade_to_exec = 137;

	public:
		ShrubberyCreationForm();										// Default constructor
		ShrubberyCreationForm(std::string target);						// Data constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& cpy);				// Copy constructor
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);	// Copy assignment
		~ShrubberyCreationForm();									// Destructor

		const std::string& getTarget() const;
		void doExecute() const;

};

#endif // SHRUBBERYCREATIONFORM_HPP
