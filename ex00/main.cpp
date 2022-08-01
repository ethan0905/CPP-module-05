/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:19:36 by esafar            #+#    #+#             */
/*   Updated: 2022/07/28 13:11:22 by esafar           ###   ########.fr       */
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

    Bureaucrat  M("Mikael", 0);
    std::cout << M << std::endl;

    Bureaucrat  D("Dimitri", 151);
    std::cout << D << std::endl;

    return (0);
}
