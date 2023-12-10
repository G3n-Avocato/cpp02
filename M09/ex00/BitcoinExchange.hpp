/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:07:19 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/10 02:42:12 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once 

#include <exception>
#include <string>
#include <iostream>
#include <map>
#include <iterator>

class	BitcoinExchange {
	
	public:
	
		BitcoinExchange(char*);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange&	operator=(const BitcoinExchange &rhs);
		~BitcoinExchange();
		
		class	ErrorOpenFile : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

	private:
		
		BitcoinExchange();
		std::map<std::string,double>	_DataBase;
	
		std::string	_checkallfd(std::string) const;
		void		_parsingDataBase(std::string);
		void		_fillDataBase(std::string);
		void		_parsingInputFile(std::string);
		void		_parsinglineFile(std::string);
		int			_parsingAllDateandValue(std::string, char) const;
		int			_validYear(std::string) const;

		void		_findDateinDB(std::string, double);

		class	ErrorOpenDataBase : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class	ErrorBadInputDataBase : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class	ErrorInvalidDateDB : public std::exception {
			public:
				virtual const char* what() const throw();
		};

};
