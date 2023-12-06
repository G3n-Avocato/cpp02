/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:06:11 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/06 22:42:06 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
	{
	try {
		if (argc != 2)
			throw BitcoinExchange::ErrorOpenFile();
		BitcoinExchange		test(argv[1]);
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
	}
	
	{
		//test cpy et operateur = mais ne pas ajouter au main rendu

	}
	return (0);
}
