#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

# define GRADETOSIGN 25
# define GRADETOEXEC 5

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();										// Default constructor
		PresidentialPardonForm(std::string target);						// Data constructor
		PresidentialPardonForm(const PresidentialPardonForm& cpy);				// Copy constructor
		PresidentialPardonForm& operator=(const PresidentialPardonForm& src);	// Copy assignment
		~PresidentialPardonForm();									// Destructor

		const std::string& getTarget() const;
		void doExecute() const;

};

#endif // PRESIDENTIALPARDONFORM_HPP
