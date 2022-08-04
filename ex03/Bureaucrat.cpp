/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:10:31 by esafar            #+#    #+#             */
/*   Updated: 2022/08/04 19:53:09 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( void ) : _name("default_bureaucrat"), _grade(150) {
    
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

Bureaucrat::Bureaucrat( Bureaucrat & src ) : _name(src.getName()), _grade(getGrade()) {

    std::cout << CYAN "Bureaucrat:: " GREEN "Copy constructor called" END << std::endl;
    *this = src;
    
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

void    Bureaucrat::signForm( Form & src ) {

    if (!src.isSigned())
    {
        src.beSigned(*this);
        std::cout << WHITE << this->getName()<< " signed " << src.getName() << END << std::endl;
        return ;
    }
    else
    {
        /*--- For debug purpose ---*/

        // std::cout << WHITE << "Bureaucrat:: datas:" << std::endl;
        // std::cout << "Name: " << src.getName() << std::endl;
        // std::cout << "Grade: " << this->getGrade() << std::endl;
        // std::cout << "Is form signed: ";
        // if (src.isSigned())
        //     std::cout << "true" << std::endl;
        // else
        //     std::cout << "false" << std::endl;
        // std::cout << "Grade required to sign: " << src.getGradeSigned() << "/150" << std::endl;
        // std::cout << "Grade required to exec: " << src.getGradeRequired() << "/150" END << std::endl;
            
        std::cout << WHITE <<this->getName()<< " couldn't sign " << src.getName() << " because ";
        if (this->getGrade() >= src.getGradeSigned() && this->getGrade() >= src.getGradeRequired())
            std::cout << "grade required to sign it and execute it, was too low." END << std::endl;
        else if (this->getGrade() >= src.getGradeRequired())
            std::cout << "grade required to execute it was too low." END << std::endl;
        else if (this->getGrade() >= src.getGradeSigned())
            std::cout << "grade required to sign it was too low." END << std::endl;
        return ;
    }
}

void    Bureaucrat::executeForm( Form const & src ) {

    if (this->getGrade() >= src.getGradeSigned() && this->getGrade() >= src.getGradeRequired())
        std::cerr << MAGENTA << "Error: Couldn't execute " << src.getName() << " because grade required to sign it and execute it, was too low." END << std::endl;
    else if (this->getGrade() >= src.getGradeRequired())
        std::cerr << MAGENTA << "Error: Couldn't execute " << src.getName() << " grade required to execute it was too low." END << std::endl;
    else if (this->getGrade() >= src.getGradeSigned())
        std::cerr << MAGENTA << "Error: Couldn't execute " << src.getName() << " grade required to sign it was too low." END << std::endl;
    else if (!src.isSigned())
        std::cerr << MAGENTA << "Error: Couldn't execute " << src.getName() << " because form is not signed." END << std::endl;
    else
        std::cout << MAGENTA << "Success: " << this->getName() << " executed " << src.getName() << std::endl;
    src.execute(*this);
    
    return ;
}

const char    *Bureaucrat::GradeTooLowException::what()const throw() {
    
    return (RED "Error: grade too low." END);
}

const char  *Bureaucrat::GradeTooHighException::what()const throw() {
    
    return (RED "Error: grade too high." END);
}

Bureaucrat   &Bureaucrat::operator=( Bureaucrat const &rhs ) {

    this->_grade= rhs.getGrade();
    
    if (this->getGrade() < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        std::cout << GREEN "Success: value is OK." END << std::endl;

    return (*this);
}

std::ostream    &operator<<( std::ostream &o, Bureaucrat const &rhs) {

    std::cout << WHITE << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << END << std::endl;
    
    return (o);
}
