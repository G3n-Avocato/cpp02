/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:03:45 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/09 01:00:40 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstddef>
#include <fstream>
#include <iterator>
#include <sstream>
#include <cstring>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(char* arg) {
//	this->_checkInputFile(argv);
	(void)arg;
	this->_checkDataBase();
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

void	BitcoinExchange::_checkDataBase(void) {
	std::fstream	fileDB;
	std::stringstream	buf;
	std::string		data;

	fileDB.open("data.csv");
	if (!fileDB.is_open())
		throw ErrorOpenDataBase();
	buf << fileDB.rdbuf();
	data = buf.str();
	this->_parsingDataBase(data);	

	

	fileDB.close();
}

void	BitcoinExchange::_parsingDataBase(std::string data) {
	std::string				tmp;
	int						i = 0;

	while (data[i] != '\0') {
		std::cerr << "i =" << i << std::endl;
		tmp = data.substr(i, data.find("\n"));
		std::cerr << "tmp = " << tmp << std::endl;
		if (tmp.compare("date,exchange_rate"))
			this->_fillDataBase(tmp);
		i+= data.find("\n") + 1;
	}
}

void	BitcoinExchange::_fillDataBase(std::string data) {
	(void)data;
//	std::cerr << data.substr(0, data.find("-")) << std::endl;
//	int		sss = data.find("-");
//	std::cerr << data.substr(sss + 1, data.find("-", sss)) << std::endl;

}

void	BitcoinExchange::_checkInputFile(char *file) {
	std::fstream		infile;
	std::stringstream	buf;
	std::string			data;

	infile.open(file);
	if (!infile.is_open())
		throw ErrorOpenFile();
	//peut etre verfier le .txt du file pas sur
	buf << infile.rdbuf(); //peut etre ajouter une verif en cas d'echec
	data = buf.str();
	this->_parsingInputFile(data);

	//testeur officiel du print de tes grands morts
	std::map<std::string, float>::iterator	it = this->_Infile.begin();
	std::map<std::string, float>::iterator	ite = this->_Infile.end();

	while (it != ite) {
		std::cout << it->first << " => " << it->second << std::endl;
		it++;
	}

}

void	BitcoinExchange::_parsingInputFile(std::string data) {

	std::string::iterator	it = data.begin();
	std::string::iterator	ite = data.end();
	std::string::iterator	cmp = it;

	std::string				Stmp;
//	int						Vtmp;
	while (it != ite) {
		while (*it != '\n') {
			it++;
		}
		Stmp.assign(cmp, it);
		std::cout << Stmp << std::endl;
		if (Stmp.compare("date | value") != 0)
			this->_fillInfile(Stmp);
		it++;
		cmp = it;
	}
}

void	BitcoinExchange::_fillInfile(std::string Stmp) {
	std::string::iterator	it = Stmp.begin();
	std::string::iterator	ite = Stmp.end();

	//parsing date
	while (it != ite) {
		if (isdigit(*it) || *it == '-')
			it++;
		else
			break;
	}
	std::string	date;
	date.assign(Stmp.begin(), it);
	
	//parsing entre
	while (it != ite) {
		if (*it != ' ' || *it != '|')
			break ;
		it++;
	}
	
	//parsing int
	std::string::iterator	beg = it;
	std::string				sval;
	if (*it == '-')
		it++;
	while (it != ite) {
		if (!isdigit(*it))
			break ;
		it++;
	}
//	if (it != ite)
		//error
	long	int				val;
	sval.assign(beg, it);
	val = strtol(sval.c_str(), NULL, 0);
	this->_Infile[date] = val;
}

const char*	BitcoinExchange::ErrorOpenFile::what() const throw() {
	return ("Error: could not open file.\n");
}

const char*	BitcoinExchange::ErrorOpenDataBase::what() const throw() {
	return ("Error: could not open database.\n");
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
