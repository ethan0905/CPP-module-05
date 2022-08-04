
#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

// class Form;

class ShrubberyCreationForm : public Form {
    
    public:
        ShrubberyCreationForm( void );
        ShrubberyCreationForm( std::string target );
        ShrubberyCreationForm( ShrubberyCreationForm & src );
        ~ShrubberyCreationForm( void );

        const std::string &getTarget( void )const;

        void    createShrubberyFile( Bureaucrat const & executor );

        ShrubberyCreationForm  &operator=( ShrubberyCreationForm const &src );
        
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

std::ostream    &operator<<( std::ostream &o, ShrubberyCreationForm &src);

#endif