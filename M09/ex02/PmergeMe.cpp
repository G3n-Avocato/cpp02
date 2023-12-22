/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:13:33 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/22 22:24:20 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <climits>
#include <ctime>
#include <utility>
#include <iomanip>

PmergeMe::PmergeMe(int argc, char** argv) {

	this->_parsingARG(argc, argv);
	size_t sizep = this->_LnoSort.size();
	if (sizep < 2)
		return ;
	
	std::cout << "Before: ";
	for (std::list<int>::iterator it = this->_LnoSort.begin(); it != this->_LnoSort.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::clock_t	beginl = std::clock();
	
	std::list<std::pair<int, int> >	list_b;
	this->_list_step_FJA(sizep, &list_b);
	this->_list_sort_Min(&list_b);
	
	std::clock_t	endl = std::clock();
	
	std::cout << "After: ";
	for (std::list<int>::iterator it = this->_LSort.begin(); it != this->_LSort.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::clock_t	begind = std::clock();
	
	std::deque<std::pair<int, int> > deque_b;
	this->_deque_step_FJA(sizep, &deque_b);
	this->_deque_sort_Min(&deque_b);
	
	std::clock_t	endd = std::clock();
	
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << std::fixed << std::setprecision(5) << 1000.0 * (endl - beginl) / CLOCKS_PER_SEC << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << std::fixed << std::setprecision(5) << 1000.0 * (endd - begind) / CLOCKS_PER_SEC << " us" << std::endl;
}

PmergeMe::~PmergeMe(void) {
}

void	PmergeMe::_parsingARG(int argc, char** argv) {
	this->_beginL = time(NULL);
	this->_beginD = time(NULL);
	long int	val = 0;

	for (int i = 1; i != argc; i++) {
		for (size_t j = 0; j != strlen(argv[i]); j++) {
			if (!isdigit(argv[i][j]))
				throw Error();
		}
		val = strtol(argv[i], NULL, 10);
		if (val < 0 || val > INT_MAX)
			throw Error();
		this->_LnoSort.push_back(val);
	}
}

void	PmergeMe::_list_step_FJA(size_t sizep, std::list<std::pair<int, int> >* list_b) {
	std::list<int>::iterator	it = this->_LnoSort.begin();
	std::advance(it, sizep - 1);
	std::list<int>::iterator	itt = this->_LnoSort.begin();
	std::advance(itt, sizep - 2);
	
	if (sizep > 1) {
		list_b->push_back((*it < *itt) ? std::make_pair(*it, *itt) : std::make_pair(*itt, *it));
		this->_list_sort_Max((*it < *itt) ? itt : it);
	}
	if (sizep > 1)
		this->_list_step_FJA(sizep - 2, list_b);
	if (sizep == 1) {
		this->_list_sort_Max(it);
		return ;
	}
}

void	PmergeMe::_list_sort_Max(std::list<int>::iterator it) {
	std::list<int>::iterator	itt = this->_LSort.begin();
	
	if (!this->_LSort.empty()) {
		while (itt != this->_LSort.end() && *it > *itt) 
			itt++;
	}
	this->_LSort.insert(itt, *it);
}

void	PmergeMe::_list_sort_Min(std::list<std::pair<int, int> >* list_b) {
	std::list<int>::iterator	itt;

	for (std::list<std::pair<int, int> >::iterator	itb = list_b->begin(); itb != list_b->end(); itb++) {
		itt = this->_LSort.begin();
		while (*itt != itb->second)
			itt++;
		if (itb->first != *itt)
			itt = this->_list_binary_search(itb, itt);
		this->_LSort.insert(itt, itb->first);
	}
}

std::list<int>::iterator	PmergeMe::_list_binary_search(std::list<std::pair<int,int> >::iterator val, std::list<int>::iterator end) {
	std::list<int>::iterator 	start = this->_LSort.begin();
	
	while (start != end) {
		std::list<int>::iterator	mid = start; 
		std::advance(mid, std::distance(start, end) / 2);
		if (val->first > *mid) {
			mid++;
			start = mid;
		}
		else
			end = mid;
	}
	return (start);
}

void	PmergeMe::_deque_step_FJA(size_t sizep, std::deque<std::pair<int, int> >* deque_b) {
	std::list<int>::iterator	it = this->_LnoSort.begin();
	std::advance(it, sizep - 1);
	std::list<int>::iterator	itt = this->_LnoSort.begin();
	std::advance(itt, sizep - 2);
	
	if (sizep > 1) {
		deque_b->push_back((*it < *itt) ? std::make_pair(*it, *itt) : std::make_pair(*itt, *it));
		this->_deque_sort_Max((*it < *itt) ? itt : it);
	}
	if (sizep > 1)
		this->_deque_step_FJA(sizep - 2, deque_b);
	if (sizep == 1) {
		this->_deque_sort_Max(this->_LnoSort.begin());
		return ;
	}
}

void	PmergeMe::_deque_sort_Max(std::list<int>::iterator it) {
	std::deque<int>::iterator	itt = this->_DSort.begin();
	
	if (!this->_DSort.empty()) {
		while (itt != this->_DSort.end() && *it > *itt)
			itt++;
	}
	this->_DSort.insert(itt, *it);
}

void	PmergeMe::_deque_sort_Min(std::deque<std::pair<int, int> >* deque_b) {
	std::deque<int>::iterator	itt;

	for (std::deque<std::pair<int, int> >::iterator	itb = deque_b->begin(); itb != deque_b->end(); itb++) {
		itt = this->_DSort.begin();
		while (*itt != itb->second)
			itt++;
		if (itb->first != *itt)
			itt = this->_deque_binary_search(itb, itt);
		this->_DSort.insert(itt, itb->first);
	}
}

std::deque<int>::iterator	PmergeMe::_deque_binary_search(std::deque<std::pair<int,int> >::iterator val, std::deque<int>::iterator end) {
	std::deque<int>::iterator 	start = this->_DSort.begin();
	
	while (start != end) {
		std::deque<int>::iterator	mid = start; 
		std::advance(mid, std::distance(start, end) / 2);
		if (val->first > *mid) {
			mid++;
			start = mid;
		}
		else
			end = mid;
	}
	return (start);
}

const char*	PmergeMe::Error::what() const throw() {
	return ("Error\n");
}
