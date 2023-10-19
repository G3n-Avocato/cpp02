/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 00:17:49 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/20 00:21:08 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget("Target Practice Dummy") {
	this->_type = "Target Practice Dummy";
}

Dummy::Dummy(const Dummy& src) : ATarget(src) {
	*this = src;
}

Dummy&	Dummy::operator=(const Dummy &rhs) {
	(void)rhs;
	return(*this);
}

Dummy::~Dummy(void) {
}

Dummy*	Dummy::clone(void) const {
	Dummy*	tmp = new Dummy();
	return (tmp);
}
