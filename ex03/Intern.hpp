#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Intern {
    
    public:
        Intern( void );
        Intern( Intern const & src );
        ~Intern( void );

		Form	*makeForm(std::string formName, std::string formTarget);

        Intern  &operator=( Intern const &src );
        
        class   GradeTooLowException : public std::exception {
            public:
                virtual const char* what()const throw();
        };
        class   GradeTooHighException : public std::exception {
            public:
                virtual const char* what()const throw();
        };
    private:
};

std::ostream    &operator<<( std::ostream &o, Intern const &src);

#endif