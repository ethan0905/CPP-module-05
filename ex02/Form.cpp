/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:58:17 by esafar            #+#    #+#             */
/*   Updated: 2022/08/03 18:02:22 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name("default"), _gradeRequiredToSignIt(150), _gradeRequiredToExecuteIt(150) {
    
    std::cout << CYAN "Form:: " GREEN "Default constructor called" END << std::endl;
    this->_signed = false;

    return ;
}

Form::Form( std::string name, int gradeSigned, int gradeRequired ) : _name(name), _gradeRequiredToSignIt(gradeSigned), _gradeRequiredToExecuteIt(gradeRequired) {

    std::cout << CYAN "Form:: " GREEN "Parameter constructor called" END << std::endl;
    this->_signed = false;

    return ;
}

Form::Form( Form const & src ) : _name(src.getName()), _gradeRequiredToSignIt(src.getGradeSigned()), _gradeRequiredToExecuteIt(src.getGradeRequired()) {

    std::cout << CYAN "Form:: " GREEN "Copy constructor called" END << std::endl;
    *this = src;

    return ;
}

Form::~Form( void ) {

    std::cout << CYAN "Form:: " RED "Destructor called" END << std::endl;

    return ;
}

const std::string &Form::getName( void )const {

    return (this->_name);
}

bool     Form::isSigned( void )const {

    return (this->_signed);
}

int   Form::getGradeSigned( void )const {

    return (this->_gradeRequiredToSignIt);
}

int   Form::getGradeRequired( void )const {

    return (this->_gradeRequiredToExecuteIt);
}

void    Form::beSigned( Bureaucrat const &rhs ) {

    if (rhs.getGrade() < this->getGradeSigned())
    {
        if (this->isSigned() == false)
        {
            this->_signed = true;
            std::cout << GREEN "Success: form has been signed successfully." END << std::endl;
        }
        else
            std::cerr << CYAN "Error: form has already been signed." END << std::endl;
    }
    else if (rhs.getGrade() > this->getGradeSigned())
        // std::cerr << CYAN "Error: grade too low to be signed." END << std::endl;
        throw Form::GradeTooLowException();
        
    return ;
}

// void    Form::createShrubberyFile( void ) = 0 {

//     return ;
// }


const char    *Form::GradeTooLowException::what()const throw() {
    
    return (RED "Error: grade too low." END);
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