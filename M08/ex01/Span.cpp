/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:05:53 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/19 01:14:29 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
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
	try {
		if (static_cast<unsigned int>(this->_arr.size()) < this->_N)
			this->_arr.push_back(nb);
		else
			throw FullArray();
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
}

void	Span::fillSpan(void) {
	try {
		if (static_cast<unsigned int>(this->_arr.size()) < this->_N) {
			int nb;
			while (static_cast<unsigned int>(this->_arr.size()) < this->_N) {
				nb = rand() % INT_MAX;
				this->_arr.insert(this->_arr.begin(), nb);
			}
		}
		else
			throw FullArray();
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
}

int		Span::shortestSpan(void) {
	if (static_cast<int>(this->_arr.size()) > 1) {
		std::sort(this->_arr.begin(), this->_arr.end());
		std::deque<int>::iterator	itb = this->_arr.begin();
		std::deque<int>::iterator	itb1 = this->_arr.begin();
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
		std::sort(this->_arr.begin(), this->_arr.end());
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
