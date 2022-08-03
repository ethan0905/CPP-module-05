/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:19:36 by esafar            #+#    #+#             */
/*   Updated: 2022/08/03 16:28:30 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat  bu("Zoro", 3);
        Bureaucrat  bureaucrat(bu);
        
        std::cout << bureaucrat << std::endl;
        bureaucrat.increaseGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.decreaseGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.increaseGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.increaseGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.increaseGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.decreaseGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.decreaseGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.decreaseGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.decreaseGrade();
        std::cout << bureaucrat << std::endl;

        // Form    fo("Formulaire", 15, 15);
        // Form    form(fo);

        // std::cout << YELLOW "Name: " << form.getName() << std::endl;
        // std::cout << "Grade required to execute it: " << form.getGradeRequired() << std::endl;
        // std::cout << "Grade required to sign it: " << form.getGradeSigned() << std::endl;
        // std::cout << "Already signed or not: " << form.isSigned() << END << std::endl << std::endl;
        
        // form.beSigned(bureaucrat);

        // std::cout << YELLOW "Name: " << form.getName() << std::endl;
        // std::cout << "Grade required to execute it: " << form.getGradeRequired() << std::endl;
        // std::cout << "Grade required to sign it: " << form.getGradeSigned() << std::endl;
        // std::cout << "Already signed or not: " << form.isSigned() << END << std::endl << std::endl;

        // bureaucrat.signForm(form);

        // Form    *form;
        
        // form = new ShrubberyCreationForm("target");
        
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
