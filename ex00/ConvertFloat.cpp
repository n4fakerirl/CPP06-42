/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertFloat.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:38:17 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/06 14:28:16 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void print_nan(std::string va, char t)
{
    if ((t == 'f') && (va == "nan" || va == "nanf"))
        std::cout << "float: nanf\n";
    else if ((t == 'd') && (va == "nan" || va == "nanf"))
        std::cout << "double: nan\n";
    if ((t == 'f') && (va == "-nan" || va == "-nanf"))
        std::cout << "float: -nanf\n";
    else if ((t == 'd') && (va == "-nan" || va == "-nanf"))
        std::cout << "double: -nan\n";
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
        if (round(x) == x)
            std::cout << std::fixed << std::setprecision(1) << "float: " << x << "f\n";
        else
            std::cout << std::setprecision(6) << "float: " << x << "f\n";
    }
    if (c == 'd')
    {
        if (std::isnan(static_cast<float>(y)) == 1)
        {
            std::cout << "float: nanf\n";
            return ;
        }
        if (round(y) == y)
            std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(y) << "f\n";
        else
            std::cout << std::setprecision(6) << "float: " << static_cast<float>(y) << "f\n";
    }
}

void convert_float(std::string va, std::string type, long long nbr, float nbr_f, double nbr_d)
{
    //float test = 314.0;
    if (type == "char" && va.length() == 1)
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(va[0]) << "f\n";
    else if (type == "char")
        print_nan(va, 'f');
    if (type == "int")
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(nbr) << "f\n";
    if (type == "float")
        is_round_float(nbr_f, nbr_d, 'f');
    if (type == "double")
        is_round_float(nbr_f, nbr_d, 'd');
}
