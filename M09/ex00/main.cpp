/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:06:11 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/08 23:12:03 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
	
	return (0);
}
