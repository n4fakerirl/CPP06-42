/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertFloat.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:38:17 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/06 10:51:55 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int is_round(float x)
{
    if (round(x) == x)
        return (1);
    else
        return (0);
}

void convert_float(std::string va, std::string type, long long nbr, float nbr_f, double nbr_d)
{
    if (type == "char" && va.length() == 1)
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(va[0]) << "f\n";
    if (type == "int")
        std::cout << "float: " << static_cast<float>(nbr) << "f\n";
    if (type == "float")
        std::cout << "float: " << nbr_f << "f\n";
    if (type == "double")
        std::cout << "float: " << nbr_d << "f\n";
}
