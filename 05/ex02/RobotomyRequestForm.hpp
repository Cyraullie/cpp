#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

# define GRADETOSIGN 72
# define GRADETOEXEC 45

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm();										// Default constructor
		RobotomyRequestForm(std::string target);						// Data constructor
		RobotomyRequestForm(const RobotomyRequestForm& cpy);				// Copy constructor
		RobotomyRequestForm& operator=(const RobotomyRequestForm& src);	// Copy assignment
		~RobotomyRequestForm();									// Destructor

		const std::string& getTarget() const;
		void doExecute() const;

};

#endif // ROBOTOMYREQUESTFORM_HPP
