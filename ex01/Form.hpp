/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:58:02 by esafar            #+#    #+#             */
/*   Updated: 2022/08/02 19:45:06 by esafar           ###   ########.fr       */
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

class Form {
    
    public:
        Form( void );
        Form( std::string name, int gradeSigned, int gradeRequired );
        ~Form( void );

        //getter
        const std::string &getName( void );
        bool     isSigned( void );
        int      getGradeSigned( void );
        int      getGradeRequired( void );

        void    beSigned( Bureaucrat const & rhs );

        Form  &operator=( Form const & rhs );

        class   GradeTooLowException : public std::exception {
            public:
                virtual const char* what()const throw();
        };
        class   GradeTooHighException : public std::exception {
            public:
                virtual const char* what()const throw();
        };
        
    private:
        const std::string _name;
        bool _signed;
        const int _gradeRequiredToSignIt;
        const int _gradeRequiredToExecuteIt;

};

std::ostream    &operator<<( std::ostream &o, Form &rhs);

#endif