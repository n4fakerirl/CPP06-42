/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:55:08 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/12 15:18:47 by ocviller         ###   ########.fr       */
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

int valid_char(int c)
{
    if (isdigit(c) || c == '+' || c == '-')
        return (1);
    return (0);
}

int find_type(std::string va, std::string *keywords)
{
    unsigned long i = 0;
    int count_d = 0;
    int count_f = 0;
    
    for (int i = 0; i < 6; i++)
    {
        if (keywords[i] == va || va.length() == 1 || va == "\\")
            return (1);
    }
    if (va[i] == '+' || va[i] == '-')
        i++;
    if (va.length() != 1 && !isdigit(va[i]))
        return (std::cout << "3error: format\n", 0);
    for (; va[i]; i++)
    {
        if (va[i] == '.')
            count_d++;
        if (va[i] == 'f')
            count_f++;
        if ((!isdigit(va[i]) && va[i] != '.' && va[i] != 'f') || (i > 0 && va[i - 1] == '.' && !isdigit(va[i])))
            return (std::cout << "2error: format\n", 0);
    }
    if (count_d > 1 || count_f > 1 || va[va.length() - 1] == '.' || va[0] == '.' || (count_f == 1 && va[va.length() - 1] != 'f'))
        return (std::cout << "1error: format\n", 0);
    return (1);
}

std::string find_typee(std::string va, std::string *keywords)
{
    unsigned long i = 0;
    for (i = 0; i < 6; i++)
    {
        if (keywords[i] == va)
            return ("char");
    }
    if ((va.length() == 1 && !isdigit(va[0])) || va == "\\")
        return ("char");
    for (i = 0; va[i] && valid_char(va[i]); i++)
    {}
    if (i == va.length())
        return ("int");
    if (va[va.length() - 1] == 'f')
        return ("float");
    else
        return ("double");
    return ("error");
}

void char_print(double ref)
{
    if (ref < 0 || ref > 127)
        std::cout << "char: impossible\n";
    else if (ref < 32 || ref == 127)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(round(ref)) << "'\n";
}

void fromInt(double ref)
{
    std::cout << "THIS IS INT : " << ref << "\n";
    char_print(ref);
    std::cout << "int: " << ref << "\n";
    std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(ref) << "f\n";
    std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(ref) << "\n";
}

void fromChar(std::string va, std::string *keywords)
{
    std::cout << "THIS IS CHAR : " << va[0] << "\n";
    for (int i = 0; i < 6; i++)
    {
        if (va == keywords[i])
            std::cout << "char: impossible\n";
    }
    if (va == "\\")
        std::cout << "\\\n";
    std::cout << "char: '" << va[0] << "'\n";
    std::cout << "int: " << static_cast<int>(va[0]) << "\n";
    std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(va[0]) << "f\n";
    std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(va[0]) << "\n";
}

void fromFloat(double ref)
{
    std::cout << "THIS IS FLOAT : " << ref << "\n";
    char_print(ref);
    std::cout << "int: " << static_cast<int>(round(ref)) << "\n";
    if (round(ref) == ref)
    {
        std::cout << std::fixed << std::setprecision(1) << "float: " << ref << "f\n";
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(ref) << "\n";
    }
    else
    {
        std::cout << "float: " << ref << "f\n";
        std::cout << "double: " << static_cast<double>(ref) << "\n";
    }
}

void fromDouble(double ref)
{
    std::cout << "THIS IS DOUBLE : " << ref << "\n";
    char_print(ref);
    std::cout << "int: " << static_cast<int>(round(ref)) << "\n";
    if (round(ref) == ref)
    {
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(ref) << "f\n";
        std::cout << std::fixed << std::setprecision(1) << "double: " << ref << "\n";
    }
    else
    {
        std::cout << "float: " << static_cast<float>(ref) << "f\n";
        std::cout << "double: " << ref << "\n";
    }
}

void ScalarConverter::convert(std::string va)
{
    //
    std::string keywords[6] = {"+inf", "-inf", "+inff", "-inff", "nan", "nanf"};
    std::cout << "STRING DE BASE : " << va << "\n";
    if (!find_type(va, keywords))
        return ;
    std::string type = find_typee(va, keywords);
    double ref = std::strtod(va.c_str(), NULL);
    std::cout << "STRING TYPE : " << type << "\n";
    if (type == "int")
        fromInt(static_cast<int>(round(ref)));
    if (type == "char")
        fromChar(va, keywords);
    if (type == "float")
        fromFloat(static_cast<float>(ref));
    if (type == "double")
        fromDouble(ref);
    std::cout << "\n\n";
}
