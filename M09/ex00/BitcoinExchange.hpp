/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:07:19 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/06 22:19:05 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once 

#include <exception>
#include <string>
#include <map>

class	BitcoinExchange {
	
	public:
	
		BitcoinExchange(const std::string&);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange&	operator=(const BitcoinExchange &rhs);
		~BitcoinExchange();
		
		class	ErrorOpenFile : std::exception { //test utilisation main si fct dans private ??
			public:
				virtual const char*	what() const throw();
		};

	private:
		
		BitcoinExchange();

		void	_checkInputFile(const std::string&);
		void	_parsingInputFile(const std::string&);
		
		void	_fillInfile();

		std::map<std::string const, int const>	_DataBase;
		std::map<std::string, int>				_Infile;

};
