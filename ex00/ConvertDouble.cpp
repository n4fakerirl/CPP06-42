/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertDouble.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:38:14 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/06 16:37:01 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void keywrd_do(std::string va)
{
    if (va == "nanf" || va == "nan")
        std::cout << "double: nan\n";
    if (va == "-inff" || va == "-inf")
        std::cout << "double: " << -INFINITY << "\n";
    if (va == "+inff" || va == "+inf")
        std::cout << "double: +" << INFINITY << "\n";
}

void is_round_double(float x, double y, char c)
{
    if (c == 'f')
    {
        if (std::isnan(static_cast<double>(x)) == 1)
        {
            std::cout << "double: nan\n";
            return ;
        }
        if (static_cast<float>(x) >= INFINITY)
            std::cout << std::fixed << std::setprecision(15 + 1) << "float: +" << static_cast<double>(x) << "\n";
        else if (round(static_cast<float>(x)) == static_cast<float>(x))
            std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<double>(x) << "\n";
        else
            std::cout << std::fixed << std::setprecision(15 + 1) << "float: " << static_cast<double>(x) << "\n";
    }
    if (c == 'd')
    {
        if (std::isnan(y) == 1)
        {
            std::cout << "double: nan\n";
            return ;
        }
        if (y >= INFINITY)
            std::cout << std::fixed << std::setprecision(15 + 1) << "double: +" << y << "\n";
        else if (round(y) == y)
            std::cout << std::fixed << std::setprecision(1) << "double: " << y << "\n";
        else
            std::cout << std::fixed << std::setprecision(15 + 1) << "double: " << y << "\n";
    }
}

void convert_double(std::string va, std::string type, long long nbr, float nbr_f, double nbr_d)
{
    if (type == "char" && va.length() == 1)
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(va[0]) << "\n";
    else if (type == "char")
        keywrd_do(va);
    if (type == "int")
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(nbr) << "\n";
    if (type == "float")
        is_round_double(nbr_f, nbr_d, 'f');
    if (type == "double")
        is_round_double(nbr_f, nbr_d, 'd');
}
