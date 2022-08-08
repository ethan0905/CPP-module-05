/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:19:36 by esafar            #+#    #+#             */
/*   Updated: 2022/08/08 14:35:44 by esafar           ###   ########.fr       */
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

    Bureaucrat  Y("Luffy", 149);
    
    std::cout << Y << std::endl;
    Y.decreaseGrade();
    std::cout << Y << std::endl;
    Y.decreaseGrade();    
        
    try
    {
        Bureaucrat  bureau("Ethan", 1);
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
