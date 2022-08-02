/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:19:36 by esafar            #+#    #+#             */
/*   Updated: 2022/08/02 19:19:44 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat  Z("Zoro", 3);
        
        std::cout << Z << std::endl;
        Z.increaseGrade();
        std::cout << Z << std::endl;
        Z.decreaseGrade();
        std::cout << Z << std::endl;
        Z.increaseGrade();
        std::cout << Z << std::endl;
        Z.increaseGrade();
        std::cout << Z << std::endl;
        Z.increaseGrade();
        std::cout << Z << std::endl;
        Z.decreaseGrade();
        std::cout << Z << std::endl;
        Z.decreaseGrade();
        std::cout << Z << std::endl;
        Z.decreaseGrade();
        std::cout << Z << std::endl;
        Z.decreaseGrade();
        std::cout << Z << std::endl;

        Form    F("test", 1, 1);
        
        std::cout << "name: " << F.getName() << std::endl;
        std::cout << "grade required: " << F.getGradeRequired() << std::endl;
        std::cout << "grade signed: " << F.getGradeSigned() << std::endl;
        std::cout << "signed or not: " << F.isSigned() << std::endl << std::endl;
        
        F.beSigned(Z);

        std::cout << "name: " << F.getName() << std::endl;
        std::cout << "grade required: " << F.getGradeRequired() << std::endl;
        std::cout << "grade signed: " << F.getGradeSigned() << std::endl;
        std::cout << "signed or not: " << F.isSigned() << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
