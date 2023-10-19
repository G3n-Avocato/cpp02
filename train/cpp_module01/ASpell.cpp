/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:57:48 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/19 15:09:16 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(void) {
}

ASpell::ASpell(std::string const& name, std::string const& effects) : _name(name), _effects(effects) {
}

ASpell::ASpell(const ASpell& src) {
	(void)src;
}

ASpell&	ASpell::operator=(const ASpell &rhs) {
	(void)rhs;
	return (*this);
}

ASpell::~ASpell(void) {
}

std::string const& ASpell::getEffects(void) const {
	return (this->_effects);
}

std::string const& ASpell::getName(void) const {
	return (this->_name);
}

void	ASpell::attack(const ATarget &vic) const {
	vic.getHitBySpell(*this);
}
