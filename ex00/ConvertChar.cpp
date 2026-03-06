/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertChar.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:37:16 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/06 14:35:47 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void check_char(int nbr)
{
    if (nbr < 0 || nbr > 127)
        std::cout << "char: impossible\n";
    else if (nbr < 32 || nbr == 127)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(nbr) << "'\n";
}

void convert_char(std::string va, std::string type, long long nbr, float nbr_f, double nbr_d)
{
    if (type == "char" && va.length() == 1)
        std::cout << "char: '" << va << "'\n";
    else if (type == "char")
        std::cout << "char: impossible\n";
    if (type == "int")
        check_char(nbr);
    if (type == "float")
        check_char(static_cast<int>(round(nbr_f)));
    if (type == "double")
        check_char(static_cast<int>(round(nbr_d)));
}
