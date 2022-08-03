/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:19:36 by esafar            #+#    #+#             */
/*   Updated: 2022/08/03 15:32:44 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat  A("Zoro", 3);
    Bureaucrat  Z(A);

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
