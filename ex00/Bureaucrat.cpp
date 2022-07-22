/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:10:31 by esafar            #+#    #+#             */
/*   Updated: 2022/07/22 17:35:00 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) {
    
    std::cout << CYAN "Bureaucrat:: " GREEN "Default constructor called" END << std::endl;

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

void    Bureaucrat::GradeTooLowException( int grade ) {
    
    std::cerr << "Error: grade too low." << std::endl;
    return ;
}

void    Bureaucrat::GradeTooHighException( int grade ) {
    
    std::cerr << "Error: grade too high." << std::endl;
    return ;
}

Bureaucrat   &Bureaucrat::operator=( Bureaucrat const &rhs ) {

    std::cout << CYAN "Bureaucrat:: Copy assignement operator called" END << std::endl;
    // this->_type_ = rhs.getType();

    return (*this);
}