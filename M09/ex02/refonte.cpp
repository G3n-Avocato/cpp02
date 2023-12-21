/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refonte.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:15:44 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/22 00:43:41 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <utility>
#include <climits>
#include <cstdlib>

PmergeMe::PmergeMe(int argc, char** argv) {
	this->_parsingARG(argc, argv);
	
	size_t sizep = this->_LnoSort.size();
	if (sizep < 2)
		return ;
	std::list<std::pair<int, int> >	list_b;
	this->_list_step_FJA(sizep, &list_b);
	this->_list_sort_Min(&list_b);

	for (std::list<int>::iterator it = this->_LSort.begin(); it != this->_LSort.end(); it++)
		std::cout << "_Lsort = " << *it << std::endl;
	for (std::list<std::pair<int,int> >::iterator it = list_b.begin(); it != list_b.end(); it++)
		std::cout << " list b = " << it->first << " : " << it->second << std::endl;


}	

PmergeMe::~PmergeMe() {
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

void	PmergeMe::_list_sort_Max(std::list<int>::iterator it) {
	std::list<int>::iterator	itt = this->_LSort.begin();
	
	if (!this->_LSort.empty()) {
		while (*it > *itt && itt != this->_LSort.end())
			itt++;
	}
	this->_LSort.insert(itt, *it);
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
		std::cout << "ok" << std::endl;
		this->_list_sort_Max(it);
	}
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

std::list<int>::iterator	PmergeMe::_list_binary_search(std::list<std::pair<int,int> >::iterator val, std::list<int>::iterator& ref) {
	
//	std::list<int>::iterator	start = this->_LSort.begin();
//	std::list<int>::iterator	end = this->_LSort.end();
	
	std::list<int>::iterator	it = ref;
	while (it != this->_LSort.begin()) {
		if (val->first < *it) {
			if (std::distance(this->_LSort.begin(), it) > 2)
				std::advance(it, -2);
			else
				it--;
		}
		else if (val->first >= *it) {
			it++;
			return (it);
		}
	}
	return (it);
}

const char*	PmergeMe::Error::what() const throw() {
	return ("Error\n");
}
