/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertInt.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:38:20 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/06 14:08:36 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void convert_int(std::string va, std::string type, long long nbr, float nbr_f, double nbr_d)
{
    if (type == "int")
        std::cout << "int: " << static_cast<int>(nbr) << "\n";
    if (type == "char" && va.length() == 1)
        std::cout << "int: " << static_cast<int>(va[0]) << "\n";
    else if (type == "char")
        std::cout << "int: impossible\n";
    if (type == "float")
        std::cout << "int: " << static_cast<int>(round(nbr_f)) << "\n";
    if (type == "double")
        std::cout << "int: " << static_cast<int>(round(nbr_d)) << "\n";
}
