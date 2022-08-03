
#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

#include "Form.hpp"

// class Form;

class ShrubberyCreationForm : public Form {
    
    public:
        ShrubberyCreationForm( void );
        ShrubberyCreationForm( std::string target );
        ShrubberyCreationForm( ShrubberyCreationForm & rhs );
        ~ShrubberyCreationForm( void );

        const std::string &getTarget( void )const;

        virtual void    createShrubberyFile( void ) = 0;

        ShrubberyCreationForm  &operator=( ShrubberyCreationForm const &rhs );
        
        class   GradeTooLowException : public std::exception {
            public:
                virtual const char* what()const throw();
        };
        class   GradeTooHighException : public std::exception {
            public:
                virtual const char* what()const throw();
        };
    private:
        const std::string   _target;

};

std::ostream    &operator<<( std::ostream &o, ShrubberyCreationForm &rhs);

#endif