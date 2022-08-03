
#ifndef ROBOTOMY_HPP
# define ROBOTOMY_HPP

#include "Form.hpp"

// class Form;

class RobotomyRequestForm : public Form {
    
    public:
        RobotomyRequestForm( void );
        RobotomyRequestForm( std::string target );
        RobotomyRequestForm( RobotomyRequestForm const & src );
        ~RobotomyRequestForm( void );

        const std::string &getTarget( void )const;

        void    robotomizeTarget( void );

        RobotomyRequestForm  &operator=( RobotomyRequestForm const &src );
        
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

std::ostream    &operator<<( std::ostream &o, RobotomyRequestForm const &src);

#endif