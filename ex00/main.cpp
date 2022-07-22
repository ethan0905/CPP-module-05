/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:19:36 by esafar            #+#    #+#             */
/*   Updated: 2022/07/22 18:43:13 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat  bureau("ethan", 20);

    std::cout << "Bureaucrat name is : [" << bureau.getName() << "]" << "\n";
    std::cout << "Bureaucrat grade is : [" << bureau.getGrade() << "]" << "\n";

    std::cout << bureau;

    Bureaucrat  table("alex", 300);

    std::cout << table;

    return (0);
}
