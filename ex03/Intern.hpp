#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Intern {
    
    public:
        Intern( void );
        Intern( Intern const & src );
        virtual ~Intern( void );

		Form	*makeForm(std::string formName, std::string formTarget)const;

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
        typedef struct s_data{
            std::string formName;
            Form    *formType;
        }              t_data;
};

std::ostream    &operator<<( std::ostream &o, Intern const &src);

#endif