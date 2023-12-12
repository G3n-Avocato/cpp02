/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:05:04 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/12 02:37:51 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once 

#include <exception>
#include <string>
#include <list>
#include <deque>
#include <cstring>
#include <iostream>

class	PmergeMe {

	public:
		PmergeMe();
		PmergeMe(int, char**);
		PmergeMe(const PmergeMe& src);
		PmergeMe&	operator=(const PmergeMe& rhs);
		~PmergeMe();

		class	Error : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

	private:

		void	_parsingARG(int, char**);

		std::list<int>	_LnoSort;

		std::list<int>	_LSort;
		std::deque<int>	_DSort;

		time_t			_beginL;
		time_t			_beginD;
};
