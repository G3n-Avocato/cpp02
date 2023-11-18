/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:10:44 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/18 21:43:40 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstddef>
#include <string>
#include <climits>
#include <iostream>

ScalarConverter::~ScalarConverter(void) {
}

void	ScalarConverter::convert(const std::string &str) {
	
	int	T = DetectType(str);

}

int	ScalarConverter::DetectType(const std::string &str) {
	if (str.size() == 1)
		return (1);
	std::size_t	foundInt = str.find_first_not_of("0123456789-");
	if (foundInt == std::string::npos)
		return (2);
	std::size_t	foundDouble = str.find_first_not_of("0123456789-.");
	if (foundDouble == std::string::npos)
		return (4);
	std::size_t	foundFloat = str.find_first_not_of("0123456789-.f");
	if (foundFloat == std::string::npos)
		return (3);
	return (-1);
}

void	ScalarConverter::ConvertType(std::string const &str, int T) {
	switch (T) {

		case 1: //si c un int -convert puis -verif char -print char puis -convert float print -convert double print

		case 2: //si c un float 

		case 3: //si c un double -convert puis -convert en int -verif char -print char int -convert float print puis print double 

		case 4:

		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
	}


}

void	ScalarConverter::ConvertToInt(std::string const &str) {
	long int	Inb	= strtol(str.c_str(), NULL, 0);
	
	if (Inb > LONG_MAX || Inb < LONG_MIN)
		std::cout << "int: error max/min" << std::endl;
	else if


}

void	ScalarConverter::ConvertToChar(int Inb) {
	
	if (!(Inb > 0 && Inb < 127) && !isprint(Inb))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << In << "\'" << std::endl;

}
