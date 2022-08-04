
#ifndef PRESIDENTIAL_HPP
# define PRESIDENTIAL_HPP

#include "Form.hpp"

// class Form;

class PresidentialPardonForm : public Form {
    
    public:
        PresidentialPardonForm( void );
        PresidentialPardonForm( std::string target );
        PresidentialPardonForm( PresidentialPardonForm const & src );
        virtual ~PresidentialPardonForm( void );

        const std::string &getTarget( void )const;

        void    execute( Bureaucrat const & executor )const;

        PresidentialPardonForm  &operator=( PresidentialPardonForm const &src );
        
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

std::ostream    &operator<<( std::ostream &o, PresidentialPardonForm const &src);

#endif