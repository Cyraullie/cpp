#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

		static const unsigned int _grade_to_sign = 25;
		static const unsigned int _grade_to_exec = 5;

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
