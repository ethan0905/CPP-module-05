/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:58:17 by esafar            #+#    #+#             */
/*   Updated: 2022/07/22 20:19:23 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) {
    
    std::cout << CYAN "Form:: " GREEN "Default constructor called" END << std::endl;

    return ;
}

Form::Form( std::string name, int grade ) : _name(name) {

    std::cout << CYAN "Form:: " GREEN "Parameter constructor called" END << std::endl;
    
    return ;
}

Form::~Form( void ) {

    std::cout << CYAN "Form:: " RED "Destructor called" END << std::endl;

    return ;
}

std::string &Form::getName( void ) {

    return (this->_name);
}

bool     Form::isSigned( void ) {

    return (this->_signed);
}

const int   Form::getGradeSigned( void ) {

    return (this->_gradeSigned);
}

const int   Form::getGradeRequired( void ) {

    return (this->_gradeRequired);
}

void    Form::beSigned( Bureaucrat &rhs ) {

    if (rhs.getGrade() > this->getGradeRequired())
        this->_signed = true;
    else if (rhs.getGrade() < this->getGradeRequired())
        throw Form::GradeTooLowException;
    else if (this->_signed)
        throw Form::GradeTooHighException;
    return ;
}


void    Form::GradeTooLowException( void ) {
    
    std::cerr << RED "Error: grade too low." END << std::endl;
    return ;
}

void    Form::GradeTooHighException( void ) {
    
    std::cerr << RED "Error: grade too high." END << std::endl;
    return ;
}

Form   &Form::operator=( Form &rhs ) {

    std::cout << CYAN "Form:: Copy assignement operator called" END << std::endl;
    this->_name = rhs.getName();

    return (*this);
}

std::ostream    &operator<<( std::ostream &o, Form &rhs) {

    std::cout << WHITE << rhs.getName() << ", Form grade " << END << std::endl;
    
    return (o);
}