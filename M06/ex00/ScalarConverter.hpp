/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:23:49 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/17 19:07:04 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class	ScalarConverter {

	public:
		~ScalarConverter(void);
		
		static void	convert(std::string const&);

	private:
	
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter& operator=(const ScalarConverter &rhs);
		
		char	_c;
		int		_i;
		float	_f;
		double	_d;
/*
		operator	double() { return static_cast<double>(this->_i); }
		operator	int() {return static_cast<int>(this->_d); }
		operator	char() {return static_cast<char>(this->_i); }
*/
		int		DetectType(std::string const &) const;
		void	ConvertType(std::string const &, int);
		void	PrintType(void) const;
};

#endif
