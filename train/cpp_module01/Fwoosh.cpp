/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:59:32 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/20 00:13:08 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void) : ASpell("Fwoosh", "fwooshed"){
	this->_name = "Fwoosh";
	this->_effects = "fwooshed";
}

Fwoosh::Fwoosh(const Fwoosh& src) : ASpell(src) {
	*this = src;
}

Fwoosh&	Fwoosh::operator=(const Fwoosh& rhs) {
	(void)rhs;
	return (*this);
}

Fwoosh::~Fwoosh(void) {
}

Fwoosh*	Fwoosh::clone(void) const {
	Fwoosh*	tmp = new Fwoosh();
	return (tmp);
}
