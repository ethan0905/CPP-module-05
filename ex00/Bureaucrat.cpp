/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:10:31 by esafar            #+#    #+#             */
/*   Updated: 2022/08/08 15:47:32 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("default"), _grade(150) {
    
    std::cout << CYAN "Bureaucrat:: " GREEN "Default constructor called" END << std::endl;

    return ;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade) {

    std::cout << CYAN "Bureaucrat:: " GREEN "Parametric constructor called" END << std::endl;

    //#version 2
    // try
    // {
    if (this->getGrade() < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        std::cout << GREEN "Success: value is OK." END << std::endl;
    // else
    //     throw Bureaucrat::GradeIsValidException();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    //#version 1
    // try
    // {
    //     if (_grade < 1)
    //         throw -1;
    //     else if (_grade > 150)
    //         throw -2;
    //     else
    //         throw 0;
    // }
    // catch( int errorCode )
    // {
    //     if (errorCode == 0)
    //         std::cout << GREEN "Sucess: value is OK." END << std::endl;
    //     else if (errorCode == -1)
    //         GradeTooHighException();
    //     else if (errorCode == -2)
    //         GradeTooLowException();
    // }

    return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & rhs ) : _name(rhs.getName()), _grade(rhs.getGrade()) {

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

/*  Based on subject, throwing exception inside increase/decrease Grade function.
    The program end directly after error got catched, so I decided to implement the
    try/catch block inside the function directly, in order to keep the programme
    testing based on main.
    Another possibility would be to send error message on cerr. */

void    Bureaucrat::increaseGrade( void ) {
    
    try
    {
        if (this->_grade > 1)
        {
            this->_grade -= 1;
            std::cout << YELLOW "Moved from " << this->_grade + 1 << " -> " << this->_grade << END << std::endl;
        }
        else
            throw Bureaucrat::HighestPossibleGradeReachedException();
        // else
        //     std::cerr << RED "Error: incremGrade(): highest possible grade reached." END << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return ;
}

void    Bureaucrat::decreaseGrade( void ) {

    try
    {
        if (this->_grade < 150)
        {
            this->_grade += 1;
            std::cout << MAGENTA "Moved from " << this->_grade - 1 << " -> " << this->_grade << END << std::endl;   
        }
        else
            throw Bureaucrat::LowestPossibleGradeReachedException();
        // else
            // std::cerr << RED "Error: decremGrade(): lowest possible grade reached." END << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return ;
}

const char    *Bureaucrat::GradeTooLowException::what()const throw() {
    
    return (RED "Error: grade too low." END);
}

const char  *Bureaucrat::GradeTooHighException::what()const throw() {
    
    return (RED "Error: grade too high." END);
}

const char    *Bureaucrat::LowestPossibleGradeReachedException::what()const throw() {
    
    return (RED "Error: lowest possible grade reached." END);
}

const char    *Bureaucrat::HighestPossibleGradeReachedException::what()const throw() {
    
    return (RED "Error: highest possible grade reached." END);
}

Bureaucrat   &Bureaucrat::operator=( Bureaucrat const &rhs ) {

    std::cout << CYAN "Bureaucrat:: Copy assignement operator called" END << std::endl;
    static_cast<std::string>(this->_name)= static_cast<std::string>(rhs.getName());
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
