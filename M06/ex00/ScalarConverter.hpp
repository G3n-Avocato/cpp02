/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:23:49 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/18 11:47:32 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class	ScalarConverter {

	public:
		ScalarConverter(void);
		~ScalarConverter(void);
		
		static void	convert(std::string const &argv);

	private:
		
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter& operator=(const ScalarConverter &rhs);
		
		char	_c;
		int	_i;
		float	_f;
		double	_d;

		int	DetectType(std::string const &argv) const;
		void	ConvertType(std::string const &argv, int type);
		void	PrintType(void) const;
};

#endif
