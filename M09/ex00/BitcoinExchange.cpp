/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:03:45 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/06 23:16:21 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>

BitcoinExchange::BitcoinExchange(const std::string& file) {

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	*this = src;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	if (this != &rhs)
	{
	

	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {

}


void	_checkImputFile(const std::string& file) {
	std::fstream	infile;

	infile.open(file);
	if (!infile)
		throw BitcoinExchange::ErrorOpenFile();

}

const char*	BitcoinExchange::ErrorOpenFile::what() const throw() {
	return ("Error: could not open file.\n");
}

//fct membre private //parsing file envoyer
//fct membre private //rangement parsing (valeur d'erreur)

//fct membre private //rec database
//fct membre private //parsing file
//variable private //rangement

//action
//recherche 
//calcul 
//print (gestion d'erreur)
//boucle


