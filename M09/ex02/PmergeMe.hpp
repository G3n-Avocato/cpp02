/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:05:04 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/22 00:26:51 by lamasson         ###   ########.fr       */
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
		PmergeMe(int, char**);
		~PmergeMe();

		class	Error : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

	private:

		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe&	operator=(const PmergeMe& rhs);

		void	_parsingARG(int, char**);
		
		void	_list_step_OneTwo_FJA(void);
		void	_list_step_Three_FJA(std::list<std::pair<int,int> >*);
		void	_triInsertIt(std::list<std::pair<int,int> >*, std::list<std::pair<int,int> >::iterator, size_t);
//		void	test_triInsertRec(std::list<std::pair<int,int> >*, std::list<std::pair<int,int> >::iterator);
		void	_list_step_Four_FJA(std::list<std::pair<int, int> >* list_a, std::list<std::pair<int, int> >* list_b);
		//void	_deque_step_OneTwo_FJA(void);
		

		void						_list_step_FJA(size_t sizep, std::list<std::pair<int, int> >*);
		void						_list_sort_Max(std::list<int>::iterator);
		void						_list_sort_Min(std::list<std::pair<int, int> >*);
		std::list<int>::iterator	_list_binary_search(std::list<std::pair<int, int> >::iterator val, std::list<int>::iterator& ref);

		std::list<int>	_LnoSort;

		std::list<int>	_LSort;
		std::deque<int>	_DSort;

		time_t			_beginL;
		time_t			_beginD;
};
