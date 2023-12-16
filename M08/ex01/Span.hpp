/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:52:04 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/16 02:29:44 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <exception>
#include <list>
#include <iostream>
#include <time.h>
#include <cstdlib>

class	Span{

	public:
	
		Span();
		Span(unsigned int);
		Span(const Span& src);
		Span&	operator=(const Span& rhs);
		~Span();

		void	addNumber(int);
		void	fillSpan(void);
		class	FullArray : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		
		int		shortestSpan();
		int		longestSpan();
		class	EmptyArray : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

	private:
		
		unsigned int	_N;
		std::list<int>	_arr;

};
