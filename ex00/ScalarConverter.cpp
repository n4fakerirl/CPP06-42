/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:55:08 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/05 18:08:51 by ocviller         ###   ########.fr       */
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

void convert_int(std::string va, std::string type)
{
    long long nbr = atoll(va.c_str());
    if (type == "char" && va.length() == 1)
    {
        std::cout << "int: " << static_cast<int>(va[0]) << "\n"; 
        return ;
    }
    for (int i = 0; va[i]; i++)
    {
        if ((nbr == 0) && va[i] != '0' && va[i] != '-' && va[i] != '+')
        {
            std::cout << "int: impossible\n";
            return;
        }
    }
    if (nbr > INT_MAX || nbr < INT_MIN)
    {
        std::cout << "int: impossible\n";
        return;
    }
    std::cout << "int: " << static_cast<int>(nbr) << "\n";  
}

void convert_char(std::string va, std::string type)
{
    long long nbr = atoll(va.c_str());
    if (type == "char" && va.length() != 1)
        return ;
    if (type == "char")
        std::cout << "char: " << va << "\n";
    else
    {
        if (nbr >= 0 && nbr < 128)
        {
            if (nbr <= 32 || nbr == 127)
                std::cout << "char: Non displayable\n";
            else
                std::cout << "char: '" << static_cast<char>(nbr) << "'\n";
        }
        else
            std::cout << "char: impossible\n";
    }
}

void convert_float(std::string va, std::string type)
{
    long long nbr = atoll(va.c_str());
    if (type == "int")
    {
        float int_u = static_cast<float>(nbr);
        std::cout << "float: " << int_u << ".0f" << "\n";
    }
    if (type == "double")
    {
        float int_u = atof(va.c_str());
        std::cout << "float: " << int_u << "\n";
    }
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
