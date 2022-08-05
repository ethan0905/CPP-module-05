
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("default_shrubbery", 145, 137), _target("target") {
    
    std::cout << CYAN "ShrubberyCreationForm:: " GREEN "Default constructor called" END << std::endl;

    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("shrubbery", 145, 137), _target(target) {

    std::cout << CYAN "ShrubberyCreationForm:: " GREEN "Parametric constructor called" END << std::endl;

    // createShrubberyFile();

    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm & src ) : Form("shrubbery", 145, 137), _target(src.getTarget()) {

    std::cout << CYAN "ShrubberyCreationForm:: " GREEN "Copy constructor called" END << std::endl;
    *this = src;
    
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

    std::cout << CYAN "ShrubberyCreationForm:: " RED "Destructor called" END << std::endl;

    return ;
}

const std::string   &ShrubberyCreationForm::getTarget( void )const {

    return (this->_target);
}

void    ShrubberyCreationForm::execute( Bureaucrat const & executor )const {

    Form::execute(executor);

    std::ofstream outfile;
    std::string fileName = this->getTarget() + "_shrubbery";

    outfile.open(fileName.c_str(), std::ofstream::out);

    outfile << "                .        +          .      .          ." << std::endl;
    outfile << "        .            _        .                    ." << std::endl;
    outfile << "    ,              /;-._,-.____        ,-----.__" << std::endl;
    outfile << "    ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
    outfile << "    `                 Z   _|`\"=:_::.`.);  Z __/ /" << std::endl;
    outfile << "                        ,    `./  Z:. `.   )==-'  ." << std::endl;
    outfile << "        .      ., ,-=-.  ,Z, +#./`   Z:.  / /           ." << std::endl;
    outfile << "    .           Z/:/`-' , ,Z '` ` `   ): , /_  -o" << std::endl;
    outfile << "        .    /:+- - + +- : :- + + -:'  /(o-) Z)     ." << std::endl;
    outfile << "    .      ,=':  Z    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
    outfile << "    `.   (    Z: Z,-._` ` + 'Z, ,\"   _,--._,---\":.__/" << std::endl;
    outfile << "                Z:  `  X` _| _,Z/'   .-'" << std::endl;
    outfile << "    .               \":._:`Z____  /:'  /      .           ." << std::endl;
    outfile << "                        Z::.  :Z/:'  /              +" << std::endl;
    outfile << "    .                 `.:.  /:'  }      ." << std::endl;
    outfile << "            .           ):_(:;   Z           ." << std::endl;
    outfile << "                        /:. _/ ,  |" << std::endl;
    outfile << "                    . (|::.     ,`                  ." << std::endl;
    outfile << "        .                |::.    {Z " << std::endl;
    outfile << "                        |::.Z  Z `." << std::endl;
    outfile << "                        |:::(Z    |" << std::endl;
    outfile << "                O       |:::/{ }  |                  (o" << std::endl;
    outfile << "                )  ___/#Z::`/ (O \"==._____   O, (O  /`" << std::endl;
    outfile << "            ~~~w/w~\"~~,Z` `:/,-(~`\"~~~~~~~~\"~o~Z~/~w|/~" << std::endl;
    outfile << "          ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~Z|/~~" << std::endl;

    outfile.close();

    return ;
}

const char    *ShrubberyCreationForm::GradeTooLowException::what()const throw() {
    
    return (RED "Error: grade too low." END);
}

const char  *ShrubberyCreationForm::GradeTooHighException::what()const throw() {
    
    return (RED "Error: grade too high." END);
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &src ) {

    std::cout << "Operator = called." << std::endl; 
    (void)src;

    return (*this);
}

std::ostream    &operator<<( std::ostream &o, ShrubberyCreationForm const &src) {

    std::cout << WHITE << src.getName() << ", ShrubberyCreationForm grade " END << std::endl;
    (void)src;

    return (o);
}
