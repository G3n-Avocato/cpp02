/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:10:44 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/17 20:00:03 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstddef>
#include <string>

ScalarConverter::~ScalarConverter(void) {
}

//algo 1 chercher type envoyee
//		2 convertir en le type qu'il est 
//		3 puis les 3 autres prints
void	ScalarConverter::convert(const std::string &str) {
	
	DetectType(str);

}

int	ScalarConverter::DetectType(const std::string &str) const {
	if (str.size() == 1)
		return (0);
	std::size_t	foundInt = str.find_first_not_of("0123456789-");
	if (foundInt == std::string::npos) {
		//verif max et min int ?
		return (1);
	}
	std::size_t	foundDouble = str.find_first_not_of("0123456789-.");
	if (foundDouble == std::string::npos) {

		return (3);
	}
	std::size_t	foundFloat = str.find_first_not_of("0123456789-.f");
	if (foundFloat == std::string::npos) {

		return (2);
	}
	if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
		return (4);
	if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
		return (5);
	return (-1);
}


