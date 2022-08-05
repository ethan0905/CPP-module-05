#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void ) {
    
    std::cout << CYAN "Intern:: " GREEN "Default constructor called" END << std::endl;

    return ;
}

Intern::Intern( Intern const & src ) {

    std::cout << CYAN "Intern:: " GREEN "Copy constructor called" END << std::endl;
    *this = src;
    
    return ;
}

Intern::~Intern( void ) {

    std::cout << CYAN "Intern:: " RED "Destructor called" END << std::endl;

    return ;
}

Form	*Intern::makeForm(std::string formName, std::string formTarget)const {

	Form *dest = NULL;

    t_data  LookupTable[3] = {
        {"shrubbery creation form", new ShrubberyCreationForm(formTarget)},
        {"robotomy request", new RobotomyRequestForm(formTarget)},
        {"presidential pardon form", new PresidentialPardonForm(formTarget)}
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == LookupTable[i].formName)
        {
            std::cout << MAGENTA "Entered in [" << i << "] with " << LookupTable[i].formName << "\n" END;
            dest = LookupTable[i].formType;
        }

        // delete LookupTable[i].formType;
    }

	std::cout << WHITE "Form Name: " << formName << std::endl << "Form target: " << formTarget << END << std::endl;

	// std::cout << "Intern creates " << std::endl;
	return (dest); // function shoudl return a pointer to a Form object, initialized with parameters from the function;
 }


const char    *Intern::GradeTooLowException::what()const throw() {
    
    return (RED "Error: grade too low." END);
}

const char  *Intern::GradeTooHighException::what()const throw() {
    
    return (RED "Error: grade too high." END);
}

Intern   &Intern::operator=( Intern const &src ) {

    (void)src;
    return (*this);
}

std::ostream    &operator<<( std::ostream &o, Intern const &src) {

    std::cout << WHITE << ", Intern grade " << END << std::endl;
    (void)src;

    return (o);
}
