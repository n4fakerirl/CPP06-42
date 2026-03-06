/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:43:13 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/06 14:30:50 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void printerr(std::string message)
{
    std::cout << "error: " << message << "\n";
}

int parse_char(std::string va)
{
    if (va.length() == 1)
    {
        if (va[0] < 32 || va[0] == 127)
            return (printerr("non-printable characters as input is forbidden"), 0);
    }
    else
    {
        if (va != "nan" && va != "nanf" && va != "+inff" && va != "-inff" && va != "+inf" && va != "-inf")
            return (printerr("string format is not recognized"), 0);
    }
    return (1);
}

int nbr_parsing(std::string va)
{
    int minus = 0, plus = 0, dot = 0, f = 0;

    for (int i = 0; va[i]; i++)
    {
        if (va[i] == '-')
            minus++;
        if (va[i] == '+')
            plus++;
        if (va[i] == '.')
            dot++;
        if (va[i] == 'f')
            f++;
    }
    if (minus > 1 || plus > 1 || dot > 1 || f > 1)
        return (printerr("multiples -, +, . or f"), 0);
    if (minus == 1 && plus == 1)
        return (printerr("- and + at the same time"), 0);
    int len = va.length();
    if ((minus || plus) && (va.at(0) != '+' && va.at(0) != '-'))
        return (printerr("+ or - char is wrongly placed"), 0);
    if (f && va.at(len - 1) != 'f')
        return (printerr("f char is wrongly place"), 0);
    if (dot && (va.at(0) == '.' || va.at(len - 1) == '.'))
        return (printerr(". char is wrongly placed"), 0);
    return (1);
}

int max_parsing(std::string va, std::string type)
{
    if (!nbr_parsing(va))
        return (0);
    long long nbr_i = atoll(va.c_str());
    long double nbr_d = atof(va.c_str());
    if (type == "int")
    {
        if (nbr_i > INT_MAX || nbr_i < INT_MIN)
            return (printerr("string type: int, the value is over min or max limits"), 0);
    }
    if (type == "float")
    {
        if (static_cast<float>(nbr_d) > std::numeric_limits<float>::max() || static_cast<float>(nbr_d) < -std::numeric_limits<float>::max())
            return (printerr("string type: float, the value is over min or max limits"), 0);
    }
    if (type == "double")
    {
        if (nbr_d > std::numeric_limits<double>::max() || nbr_d < -std::numeric_limits<double>::max())
            return (printerr("string type: double, the value is over min or max limits"), 0);
    }
    return (1);
}
