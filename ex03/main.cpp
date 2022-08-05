/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:19:36 by esafar            #+#    #+#             */
/*   Updated: 2022/08/05 19:15:58 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(int ac, char **av)
{
    (void)av;
    
    if (ac == 1)
    {
        try
        {
            Bureaucrat  Ethan("Ethan", 2);
            Intern someRandomIntern;
            Form* rrf;
            
                        /*--- shrubbery creation form test ---*/

            rrf = someRandomIntern.makeForm("shrubbery creation form", "Bender");

            std::cout << Ethan << std::endl;
            std::cout << *rrf << std::endl;

            rrf->beSigned(Ethan);

            std::cout << *rrf << std::endl;

            rrf->execute(Ethan);
            delete rrf;

            std::cout << YELLOW "============================================================" END<< std::endl;
            
                        /*--- robotomy request test ---*/
            
            rrf = someRandomIntern.makeForm("robotomy request", "Bender");

            std::cout << Ethan << std::endl;
            std::cout << *rrf << std::endl;

            rrf->beSigned(Ethan);

            std::cout << *rrf << std::endl;

            rrf->execute(Ethan);
            delete rrf;

            std::cout << YELLOW "============================================================" END<< std::endl;

                        /*--- presidential pardon form test ---*/
            
            rrf = someRandomIntern.makeForm("presidential pardon form", "Bender");

            std::cout << Ethan << std::endl;
            std::cout << *rrf << std::endl;

            rrf->beSigned(Ethan);

            std::cout << *rrf << std::endl;

            rrf->execute(Ethan);
            delete rrf;
            
            std::cout << YELLOW "============================================================" END<< std::endl;
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cerr << "Error: invalid syntax. Try using ./Bureaucrat" << std::endl;

    return (0);
}
