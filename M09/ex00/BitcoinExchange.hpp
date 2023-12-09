/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:07:19 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/08 23:32:46 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once 

#include <exception>
#include <string>
#include <iostream>
#include <map>


class	BitcoinExchange {
	
	public:
	
		BitcoinExchange(char*);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange&	operator=(const BitcoinExchange &rhs);
		~BitcoinExchange();
		
		class	ErrorOpenFile : public std::exception { //test utilisation main si fct dans private ??
			public:
				virtual const char*	what() const throw();
		};

	private:
		
		BitcoinExchange();

		void	_checkInputFile(char*);

		void	_checkDataBase();
		void	_parsingDataBase(std::string);
		void	_fillDataBase(std::string);





		void	_parsingInputFile(std::string);
		void	_fillInfile(std::string);

		std::map<std::string const, float>	_DataBase;
		std::map<std::string, float>				_Infile;

		class	ErrorOpenDataBase : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
};
