/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:05:04 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/18 21:14:26 by lamasson         ###   ########.fr       */
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
		void	_list_step_OneTwo_FJA(void);

	//	void	_list_step_Three_FJA(std::list<std::pair<int,int> >*);
	//	void	_triInsertion(std::list<std::pair<int,int> >*, size_t);

		void	test_InsertionTab(std::list<std::pair<int,int> >* pair, size_t size);
		void	test_triInsertion_Rec(std::list<std::pair<int, int> >* pair, size_t size);

		std::list<int>	_LnoSort;

		std::list<int>	_LSort;
		std::deque<int>	_DSort;

		time_t			_beginL;
		time_t			_beginD;
};
