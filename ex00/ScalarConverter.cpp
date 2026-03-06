/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:55:08 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/06 10:05:24 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default ScalarConverter constructor called\n";
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor ScalarConverter called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
	std::cout << "Copy Constructor called of ScalarConverter\n";
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
    {
    }
	return (*this);
}

int small_check(std::string va)
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
        return (0);
    if (minus == 1 && plus == 1)
        return (0);
    int len = va.length();
    if ((minus || plus) && (va.at(0) != '+' && va.at(0) != '-'))
        return (0);
    if (f && va.at(len - 1) != 'f')
        return (0);
    if (dot && (va.at(0) == '.' || va.at(len - 1) == '.'))
        return (0);
    return (1);
}

int is_int(std::string str)
{
    int flag = 0;
    
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+')
            return (0);
        if (isdigit(str[i]))
            flag = 1;
    }
    if (flag == 0)
        return (0);
    return (1);
}

int is_float(std::string str)
{
    int flag = 0;
    
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f' && str[i] != '-' && str[i] != '+')
            return (0);
        if (isdigit(str[i]))
            flag = 1;
    }
    if (flag == 0)
        return (0);
    return (1);
}

int is_double(std::string str)
{
    int flag = 0;
    
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-' && str[i] != '+')
            return (0);
        if (isdigit(str[i]))
            flag = 1;
    }
    if (flag == 0)
        return (0);
    return (1);
}

std::string find_type(std::string str)
{
    std::string type = "char";
    
    if (is_float(str))
        type = "float";
    if (is_double(str))
        type = "double";
    if (is_int(str))
        type = "int";
    return (type);
}
