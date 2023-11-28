/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:05:53 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/28 20:38:19 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) {
}

Span::Span(unsigned int N) : _N(N) , _arr

const char*	Span::FullArray::what() const throw() {
	return ("std::exception: Add element impossible: Array already full\n");
}

const char*	Span::EmptyArray::what() const throw() {
	return ("std::exception: Empty Array or.. almost\n");
}
