/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:05:53 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/29 22:56:44 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <time.h>
#include <climits>

Span::Span(void) : _N(0) {
}

Span::Span(unsigned int N) : _N(N) {
}

Span::Span(const Span &src) {
	*this = src;
}

Span&	Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->_N = rhs._N;	
		this->_arr = rhs._arr;
	}
	return (*this);
}

Span::~Span(void) {
}

void	Span::addNumber(int nb) {
	if (static_cast<unsigned int>(this->_arr.size()) < this->_N)
		this->_arr.push_back(nb);
	else
		throw FullArray();
}

void	Span::fillSpan(void) {
	if (static_cast<unsigned int>(this->_arr.size()) < this->_N) {
		int nb;
		srand(time(NULL));
		for (std::list<int>::iterator it = this->_arr.begin(); static_cast<unsigned int>(this->_arr.size()) < this->_N; it++) {
			nb = rand() % INT_MAX;
			this->_arr.insert(it, nb);
		}
	}
	else
		throw FullArray();
}

int		Span::shortestSpan(void) {
	if (static_cast<int>(this->_arr.size()) > 1) {
		this->_arr.sort();
		std::list<int>::iterator	itb = this->_arr.begin();
		std::list<int>::iterator	itb1 = this->_arr.begin();
		itb1++;
		int	dist = *itb1 - *itb;
		while (itb1 != this->_arr.end()) {
			if ((*itb1 - *itb) < dist)
				dist = *itb1 - *itb;
			itb++;
			itb1++;
		}
		return (dist);
	}
	else
		throw EmptyArray();
}

int		Span::longestSpan(void) {
	if (static_cast<int>(this->_arr.size()) > 1) {
		this->_arr.sort();
		int	start = this->_arr.front();
		int	end	= this->_arr.back();
		int	dist = end - start;
		return (dist);
	}
	else
		throw EmptyArray();
}

const char*	Span::FullArray::what() const throw() {
	return ("std::exception: Add element impossible: Array already full\n");
}

const char*	Span::EmptyArray::what() const throw() {
	return ("\nstd::exception: Empty Array or.. almost\n");
}
