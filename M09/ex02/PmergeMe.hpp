/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:05:04 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/23 17:35:37 by lamasson         ###   ########.fr       */
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
		PmergeMe(const PmergeMe&);
		PmergeMe&	operator=(const PmergeMe&);

		void						_parsingARG(int, char**);

		void						_list_step_FJA(size_t, std::list<std::pair<int, int> >*);
		void						_list_sort_Max(std::list<int>::iterator);
		void						_list_sort_Min(std::list<std::pair<int, int> >*);
		std::list<int>::iterator	_list_binary_search(std::list<std::pair<int, int> >::iterator val, std::list<int>::iterator end);
		void						_deque_step_FJA(size_t, std::deque<std::pair<int, int> >*);
		void						_deque_sort_Max(std::list<int>::iterator);
		void						_deque_sort_Min(std::deque<std::pair<int, int> >*);
		std::deque<int>::iterator	_deque_binary_search(std::deque<std::pair<int, int> >::iterator val, std::deque<int>::iterator end);

		std::list<int>	_LnoSort;
		std::list<int>	_LSort;
		std::deque<int>	_DSort;
};
