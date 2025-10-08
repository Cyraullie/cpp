#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

# define GRADETOSIGN 145
# define GRADETOEXEC 137

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

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
