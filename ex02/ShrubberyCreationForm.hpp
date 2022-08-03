
#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

#include "Form.hpp"

// class Form;

class ShrubberyCreationForm : public Form {
    
    public:
        ShrubberyCreationForm( void );
        ShrubberyCreationForm( std::string name, int grade );
        ShrubberyCreationForm( ShrubberyCreationForm & rhs );
        ~ShrubberyCreationForm( void );


        const std::string &getName( void )const;
        int     getGrade( void )const;

        void    increaseGrade( void );
        void    decreaseGrade( void );
        bool    signForm( Form & src );

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