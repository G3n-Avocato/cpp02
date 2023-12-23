/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:12:07 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/23 15:57:56 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cfloat>
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(char* arg) {
	std::string	dataDB = this->_checkallfd("data.csv");
	this->_parsingDataBase(dataDB);
	std::string	dataIn = this->_checkallfd(arg);
	this->_parsingInputFile(dataIn);
}

BitcoinExchange::~BitcoinExchange(void) {
}

std::string	BitcoinExchange::_checkallfd(std::string file) const {
	std::fstream		infile;
	std::stringstream	buf;
	std::string			data;

	infile.open(file.c_str());
	if (file == "data.csv" && !infile.is_open())
		throw ErrorOpenDataBase();
	if (!infile.is_open())
		throw ErrorOpenFile();
	buf << infile.rdbuf();
	data = buf.str();
	infile.close();
	return (data);
}

void	BitcoinExchange::_parsingDataBase(std::string data) {
	size_t		i = 0;
	size_t		pos = data.find("\n", i);
	std::string	tmp = data.substr(i, pos - i);
	
	if (!tmp.compare("date,exchange_rate"))
		i = pos + 1;	
	while (i < data.size()) {
		pos = data.find("\n", i);
		if (pos != std::string::npos) {
			tmp = data.substr(i, pos - i);
			this->_fillDataBase(tmp);
			i = pos + 1;
		}
		else
			break ;
	}
}

void	BitcoinExchange::_fillDataBase(std::string data) {

	size_t		pos = data.find(",");
	std::string	dstr = data.substr(0, pos);
	
	if (this->_parsingAllDateandValue(dstr, '-') == 1)
		throw ErrorBadInputDataBase();
	if (this->_validYear(dstr))
		throw ErrorInvalidDateDB();

	pos++;
	std::string	vstr = data.substr(pos, data.size() - pos);
	
	if (this->_parsingAllDateandValue(vstr, '.') == 1)
		throw ErrorBadInputDataBase();
	
	double val = strtod(vstr.c_str(), NULL);
	
	if (val < 0 || val > DBL_MAX)
		throw ErrorBadInputDataBase();
	this->_DataBase[dstr] = val;
}

void	BitcoinExchange::_parsingInputFile(std::string data) {
	size_t			i = 0;
	size_t			pos = data.find("\n", i);
	std::string		tmp = data.substr(i, pos - i);

	if (!tmp.compare("date | value"))
		i = pos + 1;
	while (i < data.size()) {
		pos = data.find("\n", i);
		if (pos != std::string::npos) {
			tmp = data.substr(i, pos - i);
			this->_parsinglineFile(tmp);
			i = pos + 1;
		}
		else
			break ;
	}
}

void	BitcoinExchange::_parsinglineFile(std::string data){

	size_t		pos = data.find(" | ");
	std::string	dstr = data.substr(0, pos);

	if (this->_parsingAllDateandValue(dstr, '-') == 1 || this->_validYear(dstr)) {
		std::cout << "Error: bad input => " << data << std::endl;
		return ;
	}
	
	pos += 3;
	std::string	vstr = data.substr(pos, data.size() - pos);

	if (this->_parsingAllDateandValue(vstr, '.') == 1) {
		std::cout << "Error: bad input => " << data << std::endl;
		return ;
	}

	double val = strtod(vstr.c_str(), NULL);
	if (val < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return ;
	}
	if (val > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return ;
	}
	this->_findDateinDB(dstr, val);
}

int	BitcoinExchange::_parsingAllDateandValue(std::string str, char tok) const {
	int		b = 0;
	size_t	i = 0;

	while (i < str.size()) {
		if (isdigit(str[i]) || (tok == '.' && str[i] == '-'))
			i++;
		else if (str[i] == tok) {
			b++;
			i++;
		}
		else
			break ;
	}
	if (i != str.size())
		return (1);
	if (tok == '.' && b > 1)
		return (1);
	if (tok == '-' && b != 2)
		return (1);
	return (0);
}

int		BitcoinExchange::_validYear(std::string	data) const {
	std::string	tmp;
	size_t pos = data.find("-");
	size_t npos;

	long int	year;
	tmp = data.substr(0, pos);
	year = strtol(tmp.c_str(), NULL, 10);
	
	long int	month;
	pos++;
	npos = data.find("-", pos);
	tmp = data.substr(pos, npos - pos);
	month = strtol(tmp.c_str(), NULL, 10);
	
	long int	day;
	npos++;
	tmp = data.substr(npos, data.size() - npos);
	day = strtol(tmp.c_str(), NULL, 10);

	//variable leap year. 0 = 365 / 1 = 366
	int		bis = 0;
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				bis = 1;
		}
	}
	//month check
	if (month < 1 || month > 12)
		return (1);
	//day check 30 or 31
	if (day == 31) {
		if (month != 1 && month != 3 && month != 5 && month != 7 && month != 8 && month != 10 && month != 12)
			return (1);
	}
	//year check bis 28/02 or 29/02 only if bis = 1
	if (day == 29 && month == 2) {
		if (bis != 1)
			return (1);
	}
	return (0);
}

void	BitcoinExchange::_findDateinDB(std::string dstr, double val) {
	std::map<std::string,double>::iterator	it = this->_DataBase.find(dstr);

	if (it == this->_DataBase.end()) {
		it = this->_DataBase.lower_bound(dstr);
		it--;
	}
	if (it == this->_DataBase.end())
		std::cout << "Error: file date out of range database." << std::endl;
	else
		std::cout << dstr << " => " << val << " = " << (val * it->second) << std::endl;
}

const char*	BitcoinExchange::ErrorOpenFile::what() const throw() {
	return ("Error: could not open file.\n");
}

const char*	BitcoinExchange::ErrorOpenDataBase::what() const throw() {
	return ("Error: could not open database.\n");
}

const char*	BitcoinExchange::ErrorBadInputDataBase::what() const throw() {
	return ("Error: bad input in database.\n");
}

const char*	BitcoinExchange::ErrorInvalidDateDB::what() const throw() {
	return ("Error: invalid date in database.\n");
}
