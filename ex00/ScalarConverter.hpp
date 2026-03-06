/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:54:37 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/06 09:37:32 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits.h>

std::string find_type(std::string str);
void convert_int(std::string va, std::string type);
void convert_char(std::string va, std::string type);
void convert_float(std::string va, std::string type);

class ScalarConverter
{
    private:

    public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter& operator=(const ScalarConverter &other);
    ~ScalarConverter();

    static void convert(std::string va)
    {
        std::string type = find_type(va);
        std::cout << "STRING DE BASE : " << va << "\n";
        std::cout << "TYPE DE LA STRING : " << type << "\n\n";
        convert_char(va, type);
        //convert_int(va, type);
        //convert_float(va, type);
        std::cout << "\n\n";
    }
};

void convert_char(std::string va, std::string type);