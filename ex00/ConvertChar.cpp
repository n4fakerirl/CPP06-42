/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertChar.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:37:16 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/06 10:00:21 by ocviller         ###   ########.fr       */
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

void convert_char(std::string va, std::string type)
{
    if (type != "char" && !small_check(va))
    {
        std::cout << "error: string format is not recognized.\n";
        return;
    }
    long long nbr_i = atoll(va.c_str());
    
    if (type == "char")
    {
        if (va.length() == 1)
            std::cout << "char: '" << va << "'\n";
        else
            std::cout << "char: impossible\n";
    }
    if (type == "int" || type == "float" || type == "double")
        check_char(nbr_i);
}
