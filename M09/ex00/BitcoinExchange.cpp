/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:03:45 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/07 21:04:00 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstddef>
#include <fstream>
#include <iterator>
#include <sstream>
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

void	BitcoinExchange::_checkInputFile(const std::string& file) {
	std::fstream		infile;
	std::stringstream	buf;
	std::string			data;

	infile.open(file);
	if (!infile)
		throw BitcoinExchange::ErrorOpenFile();
	//peut etre verfier le .txt du file pas sur
	buf << infile.rdbuf(); //peut etre ajouter une verif en cas d'echec
	data = buf.str();
	this->_parsingInputFile(data);

}

void	BitcoinExchange::_parsingInputFile(std::string data) {
	std::string::iterator	it = data.begin();
	std::string::iterator	ite = data.end();
	std::string::iterator	cmp = it;

	std::string				Stmp;
	int						Vtmp;
	while (it != ite) {
		while (*it != '\n') {
			it++;
		}
		Stmp.assign(cmp, it);
		this->_fillInfile(Stmp);

	}

}

void	BitcoinExchange::_fillInfile(std::string Stmp) {
	std::string::iterator	it = Stmp.begin();
	std::string::iterator	ite = Stmp.end();

	while (it != ite) {
		if ()

	}
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
