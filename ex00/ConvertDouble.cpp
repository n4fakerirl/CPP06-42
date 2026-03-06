/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertDouble.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:38:14 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/06 12:23:02 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void is_round_double(float x, double y, char c)
{
    if (c == 'f')
    {
        if (round(x) == x)
            std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(x) << "\n";
        else
            std::cout << std::setprecision(15) << "double: " << static_cast<double>(x) << "\n";
    }
    if (c == 'd')
    {
        if (round(y) == y)
            std::cout << std::fixed << std::setprecision(1) << "double: " << y << "\n";
        else
            std::cout << std::setprecision(15) << "double: " << y << "\n";
    }
}

void convert_double(std::string va, std::string type, long long nbr, float nbr_f, double nbr_d)
{
    if (type == "char" && va.length() == 1)
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(va[0]) << "\n";
    if (type == "int")
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(nbr) << "\n";
    if (type == "float")
        is_round_double(nbr_f, nbr_d, 'f');//std::cout << std::setprecision(15) << "double: " << static_cast<double>(nbr_f) << "\n";
    if (type == "double")
        is_round_double(nbr_f, nbr_d, 'd');//std::cout << std::setprecision(15) << "double: " << nbr_d << "\n";
}
