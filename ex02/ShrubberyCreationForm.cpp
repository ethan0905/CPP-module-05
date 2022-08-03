
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("default_shrub", 145, 137), _target("target") {
    
    std::cout << CYAN "ShrubberyCreationForm:: " GREEN "Default constructor called" END << std::endl;

    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("default_shrub", 145, 137), _target(target) {

    std::cout << CYAN "ShrubberyCreationForm:: " GREEN "Parametric constructor called" END << std::endl;

    createShrubberyFile();

    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm & src ) : Form("default_shrub", 145, 137), _target(src.getTarget()) {

    std::cout << CYAN "ShrubberyCreationForm:: " GREEN "Copy constructor called" END << std::endl;
    *this = src;
    
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

    std::cout << CYAN "ShrubberyCreationForm:: " RED "Destructor called" END << std::endl;

    return ;
}

const std::string   &ShrubberyCreationForm::getTarget( void )const {

    return (this->_target);
}

#include <fstream>

void    ShrubberyCreationForm::createShrubberyFile( void ) {

    std::ofstream outfile;
    std::string fileName = this->getTarget() + "__lala";

    outfile.open(fileName.c_str(), std::ofstream::out);

    outfile << "ARBRE ABRE" << std::endl;

    outfile.close();

    return ;
}

// void    printTree( void ) {

//     return ;
// }

const char    *ShrubberyCreationForm::GradeTooLowException::what()const throw() {
    
    return (RED "Error: grade too low." END);
}

const char  *ShrubberyCreationForm::GradeTooHighException::what()const throw() {
    
    return (RED "Error: grade too high." END);
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &src ) {

    std::cout << "Operator = called." << std::endl; 
    (void)src;

    return (*this);
}

std::ostream    &operator<<( std::ostream &o, ShrubberyCreationForm &src) {

    std::cout << WHITE << src.getName() << ", ShrubberyCreationForm grade " END << std::endl;
    (void)src;

    return (o);
}
