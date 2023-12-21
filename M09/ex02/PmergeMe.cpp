/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:13:33 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/21 21:01:10 by lamasson         ###   ########.fr       */
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

	this->_deque_step_OneTwo_FJA();


//testeur list sort end //
	for (std::list<int>::iterator it = _LSort.begin(); it != _LSort.end(); it++)
		std::cout << "_LSort = " << *it << std::endl;

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

	this->_list_step_Three_FJA(&pair);
//////////////////////////////////
/* testeur de pair trier en duo */
//////////////////////////////////
/*	for (std::list<std::pair<int,int> >::iterator	it = pair.begin(); it != pair.end(); it++) {
		std::cout << "pair = " << it->first << " = "<< it->second << std::endl;
	}
/////////////////////////////////*/
}

void	PmergeMe::_list_step_Three_FJA(std::list<std::pair<int,int> > *pair) {
	size_t	size = pair->size() - 1;
	if (size < 1)
		return ;
	std::list<std::pair<int, int> >::iterator it = pair->begin();
	std::advance(it, size);
	this->_triInsertIt(pair, it, size);
//	this->test_triInsertRec(pair, it);

	std::list<std::pair<int,int> >	list_a;
	std::list<std::pair<int,int> > list_b;
	it = pair->begin();
	int	i = pair->size();
	std::advance(it, i);
	while (it-- != pair->begin()) {
		list_a.push_front(std::make_pair(i, it->second));
		list_b.push_front(std::make_pair(i, it->first));
		i--;
	}
	
	this->_list_step_Four_FJA(&list_a, &list_b);

////////////////////////////////////////
/* testeur de chaine list a et list b */
////////////////////////////////////////
/*	for (std::list<std::pair<int,int> >::iterator	it = list_a.begin(); it != list_a.end(); it++) {
		std::cout << "list_A = " << it->first << " = "<< it->second << std::endl;
	
	}
	for (std::list<std::pair<int, int> >::iterator it = list_b.begin(); it != list_b.end(); it++) {
		std::cout << "list_B = " << it->first << " = "<< it->second << std::endl;
	}
*////////////////////////////////////////
}

/*
 * fct Insertion sort ::_triInsertionIt in iteratif take less shot than fct in recursif ::test_triInsertionRec
 */

void	PmergeMe::_triInsertIt(std::list<std::pair<int,int> > *pair, std::list<std::pair<int, int> >::iterator it, size_t size) {
	std::list<std::pair<int,int> >::iterator itt = pair->begin();
	std::advance(itt, size - 1);
	
	while (itt != pair->begin()) {
		if (it->second < itt->second) {
			while (itt->second > it->second && itt != pair->begin())
				itt--;
			pair->insert(itt, std::make_pair(it->first, it->second));
			pair->erase(it);
			it = pair->begin();
			itt = pair->begin();
			std::advance(it, size);
			std::advance(itt, size - 1);
		}
		else {
			it--;
			itt--;
		}
	}
}

/*
 * fct Recursive Insertion Sort
 *
void	PmergeMe::test_triInsertRec(std::list<std::pair<int,int> >* pair, std::list<std::pair<int, int> >::iterator it) {
	std::list<std::pair<int,int> >::iterator itt = it;
	itt--;
	std::list<std::pair<int, int> >::iterator pos = it;
	pos--;
	if (it->second < itt->second) {	
		while (itt->second > it->second && itt != pair->begin())
			itt--;
		pair->insert(itt, 1, std::make_pair(it->first, it->second));
		pair->erase(it);
	}
	if (pos-- != pair->begin())
		this->test_triInsertRec(pair, pos);
}
*
*/

void	PmergeMe::_list_step_Four_FJA(std::list<std::pair<int, int> >* list_a, std::list<std::pair<int, int> >* list_b) {
	std::list<std::pair<int, int> >::iterator	itb = list_b->begin();
	if (itb->second >= 0)
		list_a->push_front(std::make_pair(itb->first, itb->second));
	list_b->erase(itb);
		
	do {
		itb = list_b->begin();
		std::list<std::pair<int, int> >::iterator	ita = list_a->begin();
		std::list<std::pair<int, int> >::iterator	ita_b = list_a->begin();
		while (itb->first != ita_b->first)
			ita_b++;
		ita = ita_b;
		ita--;
		while (itb->second < ita->second && ita != list_a->begin())
			ita--;
		if (itb->second >= 0) {
			if (ita == list_a->begin() && ita->second > itb->second)
				list_a->push_front(std::make_pair(itb->first, itb->second));
			else {
				ita++;
				list_a->insert(ita, std::make_pair(itb->first, itb->second));
			}
		}
		list_b->erase(itb);
	} while (!list_b->empty());  

	for (std::list<std::pair<int, int> >::iterator	ita = list_a->begin(); ita != list_a->end(); ita++)
		this->_LSort.push_back(ita->second);
}
//////////////////////////////////////////////////////////////
//itb = nb a mettre ds a 									//
//ita = pos ita->second compare avec itb->second			//
//ita_b = ita->first == itb->first // check avant cette pos //
//////////////////////////////////////////////////////////////

void	PmergeMe::_deque_step_OneTwo_FJA(void) {
	std::deque< std::pair<int, int> >	pair;
	size_t	size_p = this->_DSort.size() / 2;
	size_t i = 0;

	
}

const char*	PmergeMe::Error::what() const throw() {
	return ("Error\n");
}
