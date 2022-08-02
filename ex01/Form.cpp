/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:58:17 by esafar            #+#    #+#             */
/*   Updated: 2022/08/02 18:43:34 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name("default"), _gradeRequiredToSignIt(150), _gradeRequiredToExecuteIt(150) {
    
    std::cout << CYAN "Form:: " GREEN "Default constructor called" END << std::endl;

    return ;
}

Form::Form( std::string name, int gradeSigned, int gradeRequired ) : _name(name), _gradeRequiredToSignIt(gradeSigned), _gradeRequiredToExecuteIt(gradeRequired) {

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

    return (this->_gradeRequiredToSignIt);
}

const int   Form::getGradeRequired( void ) {

    return (this->_gradeRequiredToExecuteIt);
}

// void    Form::beSigned( Bureaucrat const &rhs ) {

//     if (rhs.getGrade() > this->getGradeRequired())
//         this->_signed = true;
//     else if (rhs.getGrade() < this->getGradeRequired())
//         throw Form::GradeTooLowException();
//     else if (this->_signed)
//         throw Form::GradeTooHighException();
//     return ;
// }

const char    *Form::GradeTooLowException::what()const throw() {
    
    return (RED "Error: grade too low." END);
}

const char  *Form::GradeTooHighException::what()const throw() {
    
    return (RED "Error: grade too high." END);
}

Form   &Form::operator=( Form const & rhs ) {

    std::cout << CYAN "Form:: Copy assignement operator called" END << std::endl;
    this->_signed= rhs._signed;

    return (*this);
}

std::ostream    &operator<<( std::ostream &o, Form &rhs) {

    std::cout << WHITE << rhs.getName() << ", Form grade " << END << std::endl;
    
    return (o);
}