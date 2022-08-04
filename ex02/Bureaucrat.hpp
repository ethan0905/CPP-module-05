/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:10:43 by esafar            #+#    #+#             */
/*   Updated: 2022/08/04 18:54:51 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define END "\033[0m"

#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define WHITE "\033[1;37m"

#define LIGHTDARK "\033[1;90m"

class Form;

class Bureaucrat {
    
    public:
        Bureaucrat( void );
        Bureaucrat( std::string name, int grade );
        Bureaucrat( Bureaucrat & rhs );
        ~Bureaucrat( void );


        const std::string &getName( void )const;
        int     getGrade( void )const;

        void    increaseGrade( void );
        void    decreaseGrade( void );
        bool    signForm( Form & src );

        Bureaucrat  &operator=( Bureaucrat const &rhs );
        
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
        int _grade;

};

std::ostream    &operator<<( std::ostream &o, Bureaucrat const &rhs);

#endif