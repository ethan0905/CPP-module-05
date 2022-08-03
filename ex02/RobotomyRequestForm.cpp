
#include "RobotomyRequestForm.hpp"
#include <stdlib.h> //rand() function
// #include <fstream> //std::random_default_engine

RobotomyRequestForm::RobotomyRequestForm( void ) : Form("default_shrub", 72, 45), _target("target") {
    
    std::cout << CYAN "RobotomyRequestForm:: " GREEN "Default constructor called" END << std::endl;

    return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form("default_shrub", 72, 45), _target(target) {

    std::cout << CYAN "RobotomyRequestForm:: " GREEN "Parametric constructor called" END << std::endl;

    // robotomizeTarget();

    return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : Form("default_shrub", 72, 45), _target(src.getTarget()) {

    std::cout << CYAN "RobotomyRequestForm:: " GREEN "Copy constructor called" END << std::endl;
    *this = src;
    
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {

    std::cout << CYAN "RobotomyRequestForm:: " RED "Destructor called" END << std::endl;

    return ;
}

const std::string   &RobotomyRequestForm::getTarget( void )const {

    return (this->_target);
}

void    RobotomyRequestForm::robotomizeTarget( void ) {

    std::cout << WHITE "brrr.. shrrrrrrrr... shrrr brshrrrrr" END << std::endl;

    /*---require c++11 version---*/

    // std::random_device rd;
    // std::default_random_engine eng(rd());
    // std::uniform_int_distribution<int> distr(0, 1);

    int nb = rand() % 2;

    switch (nb)
    {
        case 0:
            std::cout << RED << this->getTarget() << " couldn't be robotize properly." END << std::endl;
            break ;
        case 1:
            std::cout << GREEN << this->getTarget() << " has been successfully robotize." END << std::endl;
            break ;
        default:
            break ;
    }

    return ;
}

const char    *RobotomyRequestForm::GradeTooLowException::what()const throw() {
    
    return (RED "Error: grade too low." END);
}

const char  *RobotomyRequestForm::GradeTooHighException::what()const throw() {
    
    return (RED "Error: grade too high." END);
}

RobotomyRequestForm   &RobotomyRequestForm::operator=( RobotomyRequestForm const &src ) {

    std::cout << "Operator = called." << std::endl; 
    (void)src;

    return (*this);
}

std::ostream    &operator<<( std::ostream &o, RobotomyRequestForm const &src) {

    std::cout << WHITE << src.getName() << ", RobotomyRequestForm grade " END << std::endl;
    (void)src;

    return (o);
}
