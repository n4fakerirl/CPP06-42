/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertFloat.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:38:17 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/06 16:34:39 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void keywrd_fl(std::string va)
{
    if (va == "nanf" || va == "nan")
        std::cout << "float: nanf\n";
    if (va == "-inff" || va == "-inf")
        std::cout << "float: " << -INFINITY << "f\n";
    if (va == "+inff" || va == "+inf")
        std::cout << "float: +" << INFINITY << "f\n";
}

int inff_check(std::string type, long long nbr, float f, double d)
{
    if (type == "int")
    {
        if (static_cast<float>(nbr) >= INFINITY)
            return (std::cout << "float: +" << INFINITY << "f\n", 0);
        if (static_cast<float>(nbr) <= -INFINITY)
            return (std::cout << "float: " << -INFINITY << "f\n", 0);
    }
    if (type == "float")
    {
        if (f >= INFINITY)
            return (std::cout << "float: +" << INFINITY << "f\n", 0);
        if (f <= -INFINITY)
            return (std::cout << "float: " << -INFINITY << "f\n", 0);
    }
    if (type == "double")
    {
        if (static_cast<float>(d) >= INFINITY)
            return (std::cout << "float: +" << INFINITY << "f\n", 0);
        if (static_cast<float>(d) <= -INFINITY)
            return (std::cout << "float: " << -INFINITY << "f\n", 0);
    }
    return (1);
}

void is_round_float(float x, double y, char c)
{
    if (c == 'f')
    {
        if (std::isnan(x) == 1)
        {
            std::cout << "float: nanf\n";
            return ;
        }
        if (x >= INFINITY)
            std::cout << std::fixed << std::setprecision(6 + 1) << "float: +" << x << "f\n";
        else if (round(x) == x)
            std::cout << std::fixed << std::setprecision(1) << "float: " << x << "f\n";
        else
            std::cout << std::fixed << std::setprecision(6 + 1) << "float: " << x << "f\n";
    }
    if (c == 'd')
    {
        if (std::isnan(static_cast<float>(y)) == 1)
        {
            std::cout << "float: nanf\n";
            return ;
        }
        if (static_cast<float>(y) >= INFINITY)
            std::cout << std::fixed << std::setprecision(6 + 1) << "float: +" << static_cast<float>(y) << "f\n";
        else if (round(static_cast<float>(y)) == static_cast<float>(y))
            std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(y) << "f\n";
        else
            std::cout << std::fixed << std::setprecision(6 + 1) << "float: " << static_cast<float>(y) << "f\n";
    }
}

void convert_float(std::string va, std::string type, long long nbr, float nbr_f, double nbr_d)
{
    if (type == "char" && va.length() == 1)
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(va[0]) << "f\n";
    else if (type == "char")
        keywrd_fl(va);
    if (type == "int")
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(nbr) << "f\n";
    if (type == "float")
        is_round_float(nbr_f, nbr_d, 'f');
    if (type == "double")
        is_round_float(nbr_f, nbr_d, 'd');
}
