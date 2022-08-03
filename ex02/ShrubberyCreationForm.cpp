
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) {
    
    std::cout << CYAN "ShrubberyCreationForm:: " GREEN "Default constructor called" END << std::endl;

    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string name, int grade ) {

    std::cout << CYAN "ShrubberyCreationForm:: " GREEN "Parametric constructor called" END << std::endl;

    if (this->getGrade() < 1)
        throw ShrubberyCreationForm::GradeTooHighException();
    else if (this->getGrade() > 150)
        throw ShrubberyCreationForm::GradeTooLowException();
    else
        std::cout << GREEN "Success: value is OK." END << std::endl;

    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm & src ) {

    std::cout << CYAN "ShrubberyCreationForm:: " GREEN "Copy constructor called" END << std::endl;
    *this = src;
    
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

    std::cout << CYAN "ShrubberyCreationForm:: " RED "Destructor called" END << std::endl;

    return ;
}

const char    *ShrubberyCreationForm::GradeTooLowException::what()const throw() {
    
    return (RED "Error: grade too low." END);
}

const char  *ShrubberyCreationForm::GradeTooHighException::what()const throw() {
    
    return (RED "Error: grade too high." END);
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs ) {
    
    if (this->getGrade() < 1)
        throw ShrubberyCreationForm::GradeTooHighException();
    else if (this->getGrade() > 150)
        throw ShrubberyCreationForm::GradeTooLowException();
    else
        std::cout << GREEN "Success: value is OK." END << std::endl;

    return (*this);
}

std::ostream    &operator<<( std::ostream &o, ShrubberyCreationForm &rhs) {

    std::cout << WHITE << rhs.getName() << ", ShrubberyCreationForm grade " << rhs.getGrade() << END << std::endl;
    
    return (o);
}
