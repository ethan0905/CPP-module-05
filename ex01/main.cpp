/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:19:36 by esafar            #+#    #+#             */
/*   Updated: 2022/08/02 18:43:50 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
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

    Form    F("test", 50, 50);
    
    std::cout << F.isSigned() << std::endl;
    
    try
    {
        Bureaucrat  bureau("Ethan", 20);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat  A("Alex", 150);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat  M("Mikael", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Bureaucrat  D("Dimitri", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
