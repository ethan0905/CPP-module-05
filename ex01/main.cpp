/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:19:36 by esafar            #+#    #+#             */
/*   Updated: 2022/08/08 15:55:34 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat  bu("Zoro", 16);
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

        // Form    form("Formulaire", 1, 1);
        Form    fo("Formulaire", 15, 15);
        Form    form(fo);

        std::cout << form << std::endl;
        
        form.beSigned(bureaucrat);
        
        std::cout << form << std::endl;

        // bureaucrat.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
