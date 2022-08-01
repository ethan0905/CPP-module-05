/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:10:31 by esafar            #+#    #+#             */
/*   Updated: 2022/08/01 16:27:46 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) {
    
    std::cout << CYAN "Bureaucrat:: " GREEN "Default constructor called" END << std::endl;

    return ;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade) {

    std::cout << CYAN "Bureaucrat:: " GREEN "Parametric constructor called" END << std::endl;

    try
    {
        if (_grade < 1)
            throw -1;
        else if (_grade > 150)
            throw -2;
        else
            throw 0;
    }
    catch( int errorCode )
    {
        if (errorCode == 0)
            std::cout << GREEN "Sucess: value is OK." END << std::endl;
        else if (errorCode == -1)
            GradeTooHighException();
        else if (errorCode == -2)
            GradeTooLowException();
    }
    
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

void    Bureaucrat::incremGrade( void ) {
    
    if (this->_grade > 1)
        this->_grade -= 1;
    else
        std::cerr << "Error: highest possible grade reached." << std::endl;
    return ;
}

void    Bureaucrat::decremGrade( void ) {

    if (this->_grade < 150)
        this->_grade += 1;
    else
        std::cerr << "Error: lowest possible grade reached." << std::endl;
    return ;
}

void    Bureaucrat::GradeTooLowException( void ) {
    
    std::cerr << RED "Error: grade too low." END << std::endl;
    return ;
}

void    Bureaucrat::GradeTooHighException( void ) {
    
    std::cerr << RED "Error: grade too high." END << std::endl;
    return ;
}

Bureaucrat   &Bureaucrat::operator=( Bureaucrat const &rhs ) {

    std::cout << CYAN "Bureaucrat:: Copy assignement operator called" END << std::endl;
    this->_grade= rhs.getGrade();
    // this->_name = rhs.getName();
    
    return (*this);
}

std::ostream    &operator<<( std::ostream &o, Bureaucrat &rhs) {

    std::cout << WHITE << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << END << std::endl;
    
    return (o);
}