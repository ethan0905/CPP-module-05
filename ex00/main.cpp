/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:19:36 by esafar            #+#    #+#             */
/*   Updated: 2022/08/01 17:06:58 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat  bureau("Ethan", 20);

    // std::cout << "Bureaucrat name is : [" << bureau.getName() << "]" << "\n";
    // std::cout << "Bureaucrat grade is : [" << bureau.getGrade() << "]" << "\n";

    std::cout << bureau << std::endl;

    Bureaucrat  A("Alex", 150);
    std::cout << A << std::endl;

    Bureaucrat  M("Mikael", 2);
    std::cout << M << std::endl;

    Bureaucrat  D("Dimitri", 151);
    std::cout << D << std::endl;

    A.incremGrade();
    std::cout << A << std::endl;
    A.decremGrade();
    std::cout << A << std::endl;
    A.decremGrade();
    std::cout << A << std::endl;

    M.incremGrade();
    std::cout << M << std::endl;
    M.incremGrade();
    std::cout << M << std::endl;
    M.incremGrade();
    std::cout << M << std::endl;

    return (0);
}
