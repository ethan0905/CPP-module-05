/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:19:36 by esafar            #+#    #+#             */
/*   Updated: 2022/08/08 16:44:08 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(int ac, char **av)
{
    (void)av;
    
    if (ac == 1)
    {
        try
        {
            // Form    *form;

            // form = new ShrubberyCreationForm form1;
            
            // ShrubberyCreationForm test("target");

            // test.beSigned(bureaucrat);
            // test.createShrubberyFile(bureaucrat);

            // RobotomyRequestForm test2("target2");

            // test2.robotomizeTarget(bureaucrat);
            // test2.robotomizeTarget(bureaucrat);
            // test2.robotomizeTarget(bureaucrat);
            // test2.robotomizeTarget(bureaucrat);
            // test2.robotomizeTarget(bureaucrat);

            // PresidentialPardonForm test3("Ethan");

            // test3.forgiveTarget(bureaucrat);

            Bureaucrat CEO("CEO", 1);
            std::cout << CEO << std::endl;
            Bureaucrat Ethan("Ethan", 25);
            std::cout << Ethan << std::endl;

            Form *Shrubbery = new ShrubberyCreationForm("Garden");
            std::cout << *Shrubbery << std::endl;
            Shrubbery->beSigned(CEO);
            Shrubbery->execute(Ethan);

            delete Shrubbery;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        try
        {
            Bureaucrat CEO("CEO", 1);
            Bureaucrat Ethan("Ethan", 25);

            Form *Robotomy = new RobotomyRequestForm("Wall-E");
            std::cout << *Robotomy << std::endl;
            // Ethan.executeForm(*Robotomy); // test to know if executeForm function print explicit error message
            Robotomy->beSigned(CEO);
            Robotomy->execute(Ethan);
            Ethan.executeForm(*Robotomy);
            Ethan.executeForm(*Robotomy);
            
            delete Robotomy;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        try
        {
            Bureaucrat CEO("CEO", 1);
            Bureaucrat Ethan("Ethan", 25);
            
            Form *President = new PresidentialPardonForm("Ethan");
            std::cout << *President << std::endl;
            CEO.signForm(*President);
            President->execute(CEO);

            delete President;

            std::cout << std::endl;
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
