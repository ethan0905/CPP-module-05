/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c2h6 <c2h6@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:19:36 by esafar            #+#    #+#             */
/*   Updated: 2022/08/03 09:46:15 by c2h6             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat  bureaucrat("Zoro", 3);
        
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

        // Form    form("Formulaire", 1, 1);
        Form    form("Formulaire", 150, 150);

        std::cout << YELLOW "Name: " << form.getName() << std::endl;
        std::cout << "Grade required to execute it: " << form.getGradeRequired() << std::endl;
        std::cout << "Grade required to sign it: " << form.getGradeSigned() << std::endl;
        std::cout << "Already signed or not: " << form.isSigned() << END << std::endl << std::endl;
        
        form.beSigned(bureaucrat);

        std::cout << YELLOW "Name: " << form.getName() << std::endl;
        std::cout << "Grade required to execute it: " << form.getGradeRequired() << std::endl;
        std::cout << "Grade required to sign it: " << form.getGradeSigned() << std::endl;
        std::cout << "Already signed or not: " << form.isSigned() << END << std::endl << std::endl;

        // bureaucrat.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
