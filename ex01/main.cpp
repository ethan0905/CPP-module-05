/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:19:36 by esafar            #+#    #+#             */
/*   Updated: 2022/08/02 19:43:59 by esafar           ###   ########.fr       */
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

        Form    form("test", 1, 1);
        
        std::cout << "name: " << form.getName() << std::endl;
        std::cout << "grade required: " << form.getGradeRequired() << std::endl;
        std::cout << "grade signed: " << form.getGradeSigned() << std::endl;
        std::cout << "signed or not: " << form.isSigned() << std::endl << std::endl;
        
        // form.beSigned(bureaucrat);

        // std::cout << "name: " << form.getName() << std::endl;
        // std::cout << "grade required: " << form.getGradeRequired() << std::endl;
        // std::cout << "grade signed: " << form.getGradeSigned() << std::endl;
        // std::cout << "signed or not: " << form.isSigned() << std::endl << std::endl;

        bureaucrat.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
