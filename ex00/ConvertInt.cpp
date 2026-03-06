/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertInt.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:38:20 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/06 10:10:05 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void convert_int(std::string va, std::string type)
{
    long long nbr = atoll(va.c_str());
    float nbr_f = static_cast<float>(atof(va.c_str()));
    double nbr_d = atof(va.c_str());
    
    if (type == "int")
        std::cout << "int: " << static_cast<int>(nbr) << "\n";
    if (type == "char" && va.length() == 1)
        std::cout << "int: " << static_cast<int>(va[0]) << "\n";
    if (type == "float")
        std::cout << "int: " << static_cast<int>(round(nbr_f));
    if (type == "double")
        std::cout << "int: " << static_cast<int>(round(nbr_d));
}
