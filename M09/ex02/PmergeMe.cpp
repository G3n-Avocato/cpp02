/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:13:33 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/18 23:32:24 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <iterator>
#include <utility>

PmergeMe::PmergeMe(int argc, char** argv) {
	this->_parsingARG(argc, argv);
	this->_list_step_OneTwo_FJA();
/*
	size_t i = 0;
	std::list<int>::iterator it = this->_LnoSort.begin();

	while (i < this->_DSort.size()) {
		std::cout << "deque : " << this->_DSort[i] << std::endl;
		std::cout << "list : " << *it << std::endl;
		i++;
		it++;
	}
*/
}

PmergeMe::PmergeMe(const PmergeMe& src) {
	*this = src;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &rhs) {
	(void)	rhs;
	return (*this);
}

PmergeMe::~PmergeMe(void) {
	/*
	time_t	end = time(NULL);
	double	seconds = difftime(this->_begin, end);
	std::cout << "time = " << std::fixed << std::setprecision(5) << seconds << " us" << std::endl;
*/
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
		this->_DSort.push_back(val);
		this->_LSort.push_back(val);
	}
}

void	PmergeMe::_list_step_OneTwo_FJA(void) {
	
	std::list< std::pair<int,int> >	pair;
	size_t	size_p	= this->_LSort.size() / 2;
	size_t	i = 0;

	std::list<int>::iterator	itt = this->_LSort.begin();
	itt++;
	std::list<int>::iterator it = this->_LSort.begin();

	while (!this->_LSort.empty() || i < size_p) {
		if (*it > *itt)
			pair.push_back(std::make_pair(*itt, *it));
		else
			pair.push_back(std::make_pair(*it, *itt));
		std::advance(it, 2);
		if (!this->_LSort.empty())
			this->_LSort.pop_front();
		std::advance(itt, 2);
		if (!this->_LSort.empty())
			this->_LSort.pop_front();
		if (itt == this->_LSort.end())
			break ;
		i++;
	}
	if (!this->_LSort.empty() && this->_LSort.size() == 1) {
		pair.push_back(std::make_pair(-1, *it));
		this->_LSort.pop_front();
	}
//	this->_list_step_Three_FJA(&pair);
	size_t size = pair.size();
	std::list<std::pair<int,int> >::iterator itn = pair.begin();
	std::advance(it, size - 1);
	this->test_triInsertion_Rec(&pair, itn, size);


///////////////
	for (std::list<std::pair<int,int> >::iterator	it = pair.begin(); it != pair.end(); it++) {
		std::cout << "pair = " << it->first << " = "<< it->second << std::endl;
	}
//////////////
}
/*
void	PmergeMe::_triInsertion(std::list<std::pair<int,int> > *pair, size_t size) {
	if (size < 1)
			return ;
	std::list<std::pair<int,int> >::iterator	it = pair->begin();
	std::list<std::pair<int,int> >::iterator itt = pair->begin();
	std::advance(it, size);
	std::advance(itt, size - 1);
	
	while (itt != pair->begin()) {
		if (it->second < itt->second) {	
			while (itt->second > it->second && itt != pair->begin())
				itt--;
			pair->insert(itt, 1, std::make_pair(it->first, it->second));
			pair->erase(it);
			it = pair->begin();
			itt = pair->begin();
			std::advance(it, size - 1);
			std::advance(itt, size - 2);
		}
		else {
			it--;
			itt--;
		}
	}
}

void	PmergeMe::_list_step_Three_FJA(std::list<std::pair<int,int> > *pair) {
	size_t	size = pair->size() - 1;
	if (size < 1)
		return ;
	this->_triInsertion(pair, size);
}*/

void	PmergeMe::test_InsertionTab(std::list<std::pair<int,int> >* pair, std::list<std::pair<int, int> >::iterator it, size_t size) {
	
	std::list<std::pair<int,int> >::iterator	it = pair->begin();
	std::list<std::pair<int,int> >::iterator itt = pair->begin();
	std::advance(it, size - 1);
	std::advance(itt, size - 2);
	
	if (it->second < itt->second) {	
		while (itt->second > it->second && itt != pair->begin())
			itt--;
		pair->insert(itt, 1, std::make_pair(it->first, it->second));
		pair->erase(it);
	}
}


void	PmergeMe::test_triInsertion_Rec(std::list<std::pair<int, int> >* pair, std::list<std::pair<int, int> >::iterator it, size_t size) {

	if (size > 1) {
		this->test_InsertionTab(pair, size - 1);
		this->test_triInsertion_Rec(pair, size - 1);
	}
}


const char*	PmergeMe::Error::what() const throw() {
	return ("Error\n");
}
