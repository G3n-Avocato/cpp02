/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:51:17 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/28 20:24:25 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"
#include <iostream>
#include "ASpell.hpp"

ATarget::ATarget(void) {
}

ATarget::ATarget(std::string const& type) : _type(type) {
}

ATarget::ATarget(const ATarget& src) {
	*this = src;
}

ATarget&	ATarget::operator=(const ATarget& rhs) {
	this->_type = rhs.getType();
	return (*this);
}

ATarget::~ATarget(void) {
}

std::string const&	ATarget::getType(void) const {
	return (this->_type);
}

void	ATarget::getHitBySpell(const ASpell& hit) const {
	std::cout << this->_type << " has been " << hit.getEffects() << "!" << std::endl;
}
