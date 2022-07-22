/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:10:31 by esafar            #+#    #+#             */
/*   Updated: 2022/07/22 18:18:56 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) {
    
    std::cout << CYAN "Bureaucrat:: " GREEN "Default constructor called" END << std::endl;

    return ;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade) {

    std::cout << CYAN "Bureaucrat:: " GREEN "Modified constructor called" END << std::endl;

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
            std::cout << "Sucess: value is OK." << std::endl;
        else if (errorCode == -1)
            GradeTooHighException();
        else if (errorCode == -2)
            GradeTooLowException();
    }
    
    return ;
}

Bureaucrat::~Bureaucrat( void ) {

    std::cout << CYAN "Bureaucrat:: " RED "Destructor called" END << std::endl;

    return ;
}

std::string &Bureaucrat::getName( void ) {

    return (this->_name);
}

int     Bureaucrat::getGrade( void ) {

    return (this->_grade);
}

void    Bureaucrat::GradeTooLowException( void ) {
    
    std::cerr << "Error: grade too low." << std::endl;
    return ;
}

void    Bureaucrat::GradeTooHighException( void ) {
    
    std::cerr << "Error: grade too high." << std::endl;
    return ;
}

// Bureaucrat   &Bureaucrat::operator=( Bureaucrat const &rhs ) {

//     std::cout << CYAN "Bureaucrat:: Copy assignement operator called" END << std::endl;
//     // this->_type_ = rhs.getType();

//     return (*this);
// }