/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:13:33 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/12 02:45:17 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <climits>
#include <iomanip>

PmergeMe::PmergeMe(int argc, char** argv) {
	this->_parsingARG(argc, argv);
	
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

const char*	PmergeMe::Error::what() const throw() {
	return ("Error\n");
}
