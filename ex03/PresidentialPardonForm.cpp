
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : Form("default_president", 25, 5), _target("target") {
    
    std::cout << CYAN "PresidentialPardonForm:: " GREEN "Default constructor called" END << std::endl;

    return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form("default_president", 25, 5), _target(target) {

    std::cout << CYAN "PresidentialPardonForm:: " GREEN "Parametric constructor called" END << std::endl;

    return ;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : Form("default_president", 25, 5), _target(src.getTarget()) {

    std::cout << CYAN "PresidentialPardonForm:: " GREEN "Copy constructor called" END << std::endl;
    *this = src;
    
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {

    std::cout << CYAN "PresidentialPardonForm:: " RED "Destructor called" END << std::endl;

    return ;
}

const std::string   &PresidentialPardonForm::getTarget( void )const {

    return (this->_target);
}

void    PresidentialPardonForm::execute( Bureaucrat const & executor )const {

    Form::execute(executor);

    std::cout << YELLOW << this->getTarget() << " has been forgiven by our Lord Zaphod Beeblebox" END << std::endl;

    return ;
}

const char    *PresidentialPardonForm::GradeTooLowException::what()const throw() {
    
    return (RED "Error: grade too low." END);
}

const char  *PresidentialPardonForm::GradeTooHighException::what()const throw() {
    
    return (RED "Error: grade too high." END);
}

PresidentialPardonForm   &PresidentialPardonForm::operator=( PresidentialPardonForm const &src ) {

    std::cout << "Operator = called." << std::endl; 
    (void)src;

    return (*this);
}

std::ostream    &operator<<( std::ostream &o, PresidentialPardonForm const &src) {

    std::cout << WHITE << src.getName() << ", PresidentialPardonForm grade " END << std::endl;
    (void)src;

    return (o);
}
