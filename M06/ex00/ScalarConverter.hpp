/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:23:49 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/19 21:51:16 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class	ScalarConverter {

	public:
	
		static void	convert(std::string const&);

	private:
	
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter& operator=(const ScalarConverter &rhs);
		~ScalarConverter(void);
		
		static int		DetectType(std::string const &);
		static void		ConvertType(std::string const &, int);

		static void		ConvertToChar(long int);
		static void		ConvertToInt(long int);
		static void		ConvertToFloat(float Fnb);
		static void		ConvertToDouble(double Dnb);
};

#endif
