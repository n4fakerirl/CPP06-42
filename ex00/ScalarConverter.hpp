/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:54:37 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/06 14:13:59 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <iomanip>
#include <limits>

int parse_char(std::string va);
int max_parsing(std::string va, std::string type);
std::string find_type(std::string str);
void convert_char(std::string va, std::string type, long long nbr, float nbr_f, double nbr_d);
void convert_int(std::string va, std::string type, long long nbr, float nbr_f, double nbr_d);
void convert_float(std::string va, std::string type, long long nbr, float nbr_f, double nbr_d);
void convert_double(std::string va, std::string type, long long nbr, float nbr_f, double nbr_d);
void print_nan(std::string va, char t);

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
        if (type == "char" && !parse_char(va))
            return ;
        else if (!max_parsing(va, type))
            return ;
        std::cout << "STRING DE BASE : " << va << "\n";
        std::cout << "TYPE DE LA STRING : " << type << "\n\n";
        long long nbr = atoll(va.c_str());
        float nbr_f = static_cast<float>(atof(va.c_str()));
        double nbr_d = atof(va.c_str());
        convert_char(va, type, nbr, nbr_f, nbr_d);
        convert_int(va, type, nbr, nbr_f, nbr_d);
        convert_float(va, type, nbr, nbr_f, nbr_d);
        convert_double(va, type, nbr, nbr_f, nbr_d);
        std::cout << "\n\n";
    }
};
