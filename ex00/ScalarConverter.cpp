/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:55:08 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/06 09:37:08 by ocviller         ###   ########.fr       */
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

int is_int(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+')
            return (0);
    }
    return (1);
}

int is_float(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f' && str[i] != '-' && str[i] != '+')
            return (0);
    }
    return (1);
}

int is_double(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-' && str[i] != '+')
            return (0);
    }
    return (1);
}

// int atol_verif(std::string va)
// {
//     long long nbr = atoll(va.c_str());
//     for (int i = 0; va[i]; i++)
//     {
//         if (nbr == 0 && va[i] != '0' && va[i] != '-' && va[i] != '+')
//         {
//             std::cout << "int: impossible\n";
//             return (0);
//         }
//     }
//     return (1);
// }

    // if (type == "char")
    // else if (type == "int")
    // else if (type == "float")
    // else if (type == "double")

void convert_int(std::string va, std::string type)
{
    (void)va;
    (void)type;
}



void convert_float(std::string va, std::string type)
{
    (void)va;
    (void)type;
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
