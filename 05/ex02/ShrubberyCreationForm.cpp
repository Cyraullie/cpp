#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", this->_grade_to_sign, this->_grade_to_exec), _target("")
{
	std::cout << GREEN << "Default ShrubberyCreationForm constructor called" << RESET << std::endl;
}

// Data constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", this->_grade_to_sign, this->_grade_to_exec), _target(target)
{
	std::cout << LIGHT_GREEN << "ShrubberyCreationForm constructor called for " << ITALIC << target << RESET << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy) : AForm(cpy.getName(), cpy.getGradeToSign(), cpy.getGradeToExec()), _target(cpy.getTarget())
{
	std::cout << LIGHT_GREEN << "ShrubberyCreationForm copy constructor called for " << ITALIC << cpy._target << RESET << std::endl;
}

//TODO a check
// Copy assignment
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << LIGHT_GREEN << "ShrubberyCreationForm assignment operator called" << RESET << std::endl;
	if (this != &src) {
		this->_target = src.getTarget();
	}
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm destructor called for " << ITALIC << this->getTarget() << RESET << std::endl;
};

const std::string& ShrubberyCreationForm::getTarget() const 
{
	return this->_target;
}

void ShrubberyCreationForm::doExecute() const
{
	std::string filename(this->getTarget() + "_shrubbery");
	std::ifstream treefile(ARTFILENAME);
	std::ofstream shrub(filename);
	std::string buf;

	while (std::getline(treefile, buf))
		shrub << buf << std::endl;
	
	std::cout << ITALIC << filename << " has been created!" << RESET << std::endl;

	shrub.close();
	treefile.close();
}
