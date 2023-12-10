/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:23:17 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/10 19:41:58 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <exception>
#include <iostream>
#include <string>
#include <stack>

class	RPN	{
	
	public:
		
		RPN();
		RPN(std::string);
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();
		
		class	Error : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

	private:

		std::stack<int>	_calcul;

		int		_parsingsurfaceRPN(std::string&) const;
		void	_detailRPN(std::string);
		void	_myNameIs(std::string);
};
