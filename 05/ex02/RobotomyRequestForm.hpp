#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

		static const unsigned int _grade_to_sign = 72;
		static const unsigned int _grade_to_exec = 45;

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
