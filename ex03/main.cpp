/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:19:36 by esafar            #+#    #+#             */
/*   Updated: 2022/08/05 17:55:39 by esafar           ###   ########.fr       */
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
            Intern someRandomIntern;
            // Form* rrf;
            
            // rrf = 
            someRandomIntern.makeForm("shrubbery creation form", "Bender");
            someRandomIntern.makeForm("robotomy request", "Bender");
            someRandomIntern.makeForm("presidential pardon form", "Bender");

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
