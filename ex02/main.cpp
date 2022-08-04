/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:19:36 by esafar            #+#    #+#             */
/*   Updated: 2022/08/04 18:17:39 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        // Bureaucrat  bu("Zoro", 3);
        // Bureaucrat  bureaucrat(bu);
        
        // std::cout << bureaucrat << std::endl;
        // bureaucrat.increaseGrade();
        // std::cout << bureaucrat << std::endl;
        // bureaucrat.decreaseGrade();
        // std::cout << bureaucrat << std::endl;
        // bureaucrat.increaseGrade();
        // std::cout << bureaucrat << std::endl;
        // bureaucrat.increaseGrade();
        // std::cout << bureaucrat << std::endl;
        // bureaucrat.increaseGrade();
        // std::cout << bureaucrat << std::endl;
        // bureaucrat.decreaseGrade();
        // std::cout << bureaucrat << std::endl;
        // bureaucrat.decreaseGrade();
        // std::cout << bureaucrat << std::endl;
        // bureaucrat.decreaseGrade();
        // std::cout << bureaucrat << std::endl;
        // bureaucrat.decreaseGrade();
        // std::cout << bureaucrat << std::endl;

        // // Form    fo("Formulaire", 15, 15);
        // // Form    form(fo);

        // // std::cout << YELLOW "Name: " << form.getName() << std::endl;
        // // std::cout << "Grade required to execute it: " << form.getGradeRequired() << std::endl;
        // // std::cout << "Grade required to sign it: " << form.getGradeSigned() << std::endl;
        // // std::cout << "Already signed or not: " << form.isSigned() << END << std::endl << std::endl;
        
        // // form.beSigned(bureaucrat);

        // // std::cout << YELLOW "Name: " << form.getName() << std::endl;
        // // std::cout << "Grade required to execute it: " << form.getGradeRequired() << std::endl;
        // // std::cout << "Grade required to sign it: " << form.getGradeSigned() << std::endl;
        // // std::cout << "Already signed or not: " << form.isSigned() << END << std::endl << std::endl;

        // // bureaucrat.signForm(form);

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

        	Bureaucrat supervisor("Supervisor", 1);
            std::cout << supervisor << std::endl;
            Bureaucrat francis("Francis", 25);
            std::cout << francis << std::endl;

            Form *shrub = new ShrubberyCreationForm("home");
            std::cout << *shrub << std::endl;
            shrub->beSigned(supervisor);
            shrub->execute(francis);

            Form *pres = new PresidentialPardonForm("Francis");
            std::cout << *pres << std::endl;
            supervisor.signForm(*pres);
            pres->execute(supervisor);

            Form *robot = new RobotomyRequestForm("Bender");
            std::cout << *robot << std::endl;
            robot->beSigned(supervisor);
            robot->execute(francis);
            // francis.executeForm(*robot);
            // francis.executeForm(*robot);

            std::cout << "---" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
