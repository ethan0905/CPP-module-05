/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:58:02 by esafar            #+#    #+#             */
/*   Updated: 2022/08/04 18:54:45 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define END "\033[0m"

#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define WHITE "\033[1;37m"

#define LIGHTDARK "\033[1;90m"

class Bureaucrat;
class Form;

class Form {
    
    public:
        Form( void );
        Form( std::string name, int gradeSigned, int gradeRequired );
        Form( Form const & src );
        ~Form( void );

        /*---getter (always put them as const functions, in order to use copy constructor)---*/
        const std::string   &getName( void )const;
        bool                isSigned( void )const;
        int                 getGradeSigned( void )const;
        int                 getGradeRequired( void )const;

        void    beSigned( Bureaucrat const & rhs );

        virtual void    execute( Bureaucrat const & executor )const = 0;

        Form  &operator=( Form const & rhs );

        class   GradeTooLowException : public std::exception {
            public:
                virtual const char* what()const throw();
        };
        class   GradeTooHighException : public std::exception {
            public:
                virtual const char* what()const throw();
        };
        class   CannotExecuteSubFunctionException : public std::exception {
            public:
                virtual const char* what()const throw();
        };
        
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeRequiredToSignIt;
        const int           _gradeRequiredToExecuteIt;
};

std::ostream    &operator<<( std::ostream &o, Form const &rhs);

#endif