/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:48:40 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/28 23:21:19 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include "ASpell.hpp"
#include <cstring>
#include <string>

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title) {
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void) {
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

std::string const & Warlock::getName(void) const {
	return (this->_name);
}
std::string const & Warlock::getTitle(void) const {
	return (this->_title);
}

void	Warlock::setTitle(const std::string &title) {
	this->_title = title;
}

void	Warlock::introduce(void) const {
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *learn) {
	this->_spellBook.learnSpell(learn);
	delete learn ;
}

void	Warlock::forgetSpell(const std::string spell) {
	this->_spellBook.forgetSpell(spell);
}

void	Warlock::launchSpell(const std::string spell, ATarget const &tar) {	
	ASpell*	launch = this->_spellBook.createSpell(spell);

	if (launch)
		tar.getHitBySpell(*launch);
}
