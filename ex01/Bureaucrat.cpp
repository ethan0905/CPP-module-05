/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c2h6 <c2h6@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:10:31 by esafar            #+#    #+#             */
/*   Updated: 2022/08/03 09:30:31 by c2h6             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( void ) {
    
    std::cout << CYAN "Bureaucrat:: " GREEN "Default constructor called" END << std::endl;

    return ;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade) {

    std::cout << CYAN "Bureaucrat:: " GREEN "Parametric constructor called" END << std::endl;

    if (this->getGrade() < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        std::cout << GREEN "Success: value is OK." END << std::endl;

    return ;
}

Bureaucrat::Bureaucrat( Bureaucrat & rhs ) {

    std::cout << CYAN "Bureaucrat:: " GREEN "Copy constructor called" END << std::endl;
    *this = rhs;
    
    return ;
}

Bureaucrat::~Bureaucrat( void ) {

    std::cout << CYAN "Bureaucrat:: " RED "Destructor called" END << std::endl;

    return ;
}

const std::string &Bureaucrat::getName( void )const {

    return (this->_name);
}

int     Bureaucrat::getGrade( void )const {

    return (this->_grade);
}

void    Bureaucrat::increaseGrade( void ) {
    
    if (this->_grade > 1)
    {
        this->_grade -= 1;
        std::cout << YELLOW "Moved from " << this->_grade + 1 << " -> " << this->_grade << END << std::endl;
    }
    else
        std::cerr << RED "Error: incremGrade(): highest possible grade reached." END << std::endl;

    return ;
}

void    Bureaucrat::decreaseGrade( void ) {

    if (this->_grade < 150)
    {
        this->_grade += 1;
        std::cout << MAGENTA "Moved from " << this->_grade - 1 << " -> " << this->_grade << END << std::endl;   
    }
    else
        std::cerr << RED "Error: decremGrade(): lowest possible grade reached." END << std::endl;
    
    return ;
}

bool    Bureaucrat::signForm( Form & src ) {

    if (src.isSigned())
    {
        std::cout << this->getName()<< " signed " << src.getName() << std::endl;
        return (true);
    }
    else
    {
        std::cout << this->getName()<< " couldn't sign " << src.getName() << " because ";
        if (this->getGrade() >= src.getGradeSigned() && this->getGrade() >= src.getGradeRequired())
            std::cout << "grade required to sign it and execute it, was too low." << std::endl;
        else if (this->getGrade() >= src.getGradeRequired())
            std::cout << "grade required to execute it was too low." << std::endl;
        else if (this->getGrade() >= src.getGradeSigned())
            std::cout << "grade required to sign it was too low." << std::endl;
        return (false);
    }
}

const char    *Bureaucrat::GradeTooLowException::what()const throw() {
    
    return (RED "Error: grade too low." END);
}

const char  *Bureaucrat::GradeTooHighException::what()const throw() {
    
    return (RED "Error: grade too high." END);
}

Bureaucrat   &Bureaucrat::operator=( Bureaucrat const &rhs ) {

    if (this->getGrade() < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        std::cout << GREEN "Success: value is OK." END << std::endl;
    this->_grade= rhs.getGrade();
    
    return (*this);
}

std::ostream    &operator<<( std::ostream &o, Bureaucrat &rhs) {

    std::cout << WHITE << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << END << std::endl;
    
    return (o);
}
