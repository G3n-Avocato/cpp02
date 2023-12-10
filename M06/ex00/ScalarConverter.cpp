/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:10:44 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/21 22:03:33 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <cfloat>
//#include <cmath>

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <iomanip>

void	ScalarConverter::convert(const std::string &str) {
	
	int	T = DetectType(str);
	ConvertType(str, T);
}

int	ScalarConverter::DetectType(const std::string &str) {
	std::size_t	foundInt = str.find_first_not_of("0123456789-");
	if (foundInt == std::string::npos)
		return (2);
	if (str.size() == 1)
		return (1);
	std::size_t	foundDouble = str.find_first_not_of("0123456789-.");
	if (foundDouble == std::string::npos)
		return (4);
	std::size_t	foundFloat = str.find_first_not_of("0123456789-.f");
	if (foundFloat == std::string::npos)
		return (3);
	return (-1);
}

void	ScalarConverter::ConvertType(std::string const &str, int T) {
	long int	Inb;
	float		Fnb;
	double		Dnb;

	switch (T) {

		case 1:
			Inb = static_cast<char>(str[0]);
			ConvertToChar(Inb);
			ConvertToInt(Inb);
			Fnb = static_cast<float>(Inb);
			ConvertToFloat(Fnb);
			Dnb = static_cast<double>(Fnb);
			ConvertToDouble(Dnb);
			break ;

		case 2:
			Inb = strtol(str.c_str(), NULL, 0); //pb 0 10 
			ConvertToChar(Inb);
			ConvertToInt(Inb);
			Fnb = static_cast<float>(Inb);
			ConvertToFloat(Fnb);
			Dnb = static_cast<double>(Fnb);
			ConvertToDouble(Dnb);
			break ;
	
		case 3:
			Fnb = strtof(str.c_str(), NULL);
			Inb = static_cast<long int>(Fnb);
			ConvertToChar(Inb);
			ConvertToInt(Inb);
			ConvertToFloat(Fnb);
			Dnb = static_cast<double>(Fnb);
			ConvertToDouble(Dnb);
			break ;

		case 4:
			Dnb = strtod(str.c_str(), NULL);
			Inb = static_cast<long int>(Dnb);
			ConvertToChar(Inb);
			ConvertToInt(Inb);
			Fnb = static_cast<float>(Dnb);
			ConvertToFloat(Fnb);
			ConvertToDouble(Dnb);
			break ;
		
		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
	}
}
/*
bool	ScalarConverter::FloatIsInt(float Fnb) {
	if (Fnb == std::floor(Fnb))
		return true ;
	else
		return false;
}*/

void	ScalarConverter::ConvertToDouble(double Dnb) {
	if (Dnb < DBL_MIN || Dnb > DBL_MAX) {
		if (Dnb < DBL_MIN)
			std::cout << "double: " << Dnb << std::endl;
		else if (Dnb > DBL_MAX)
			std::cout << "double: +" << Dnb << std::endl;
	}
	else
		std::cout << "double: " << Dnb << std::endl;
}

void	ScalarConverter::ConvertToFloat(float Fnb) {
	if (Fnb < FLT_MIN || Fnb > FLT_MAX) {
		if (Fnb == 0)
			std::cout << "float: " << std::fixed << std::setprecision(1) << Fnb << "f" << std::endl;
		else if (Fnb < FLT_MIN)
			std::cout << "float: " << Fnb << "f" << std::endl;
		else if (Fnb > FLT_MAX)
			std::cout << "float: +" << Fnb << "f" << std::endl;
	}
//	else if (FloatIsInt(Fnb))
//		std::cout << "float: " << std::fixed << std::setprecision(1) << Fnb << "f" << std::endl;
	else
		std::cout << "float: " << Fnb << "f" << std::endl;
}

void	ScalarConverter::ConvertToInt(long int Inb) {
	if (Inb < INT_MIN || Inb > INT_MAX)
		std::cout << "int: Non displayable" << std::endl;
	else
		std::cout << "int: " << Inb << std::endl;
}

void	ScalarConverter::ConvertToChar(long int Inb) {
	if ( !(Inb > 0 && Inb < 127) || !isprint(Inb))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << static_cast<char>(Inb) << "\'" << std::endl;
}
