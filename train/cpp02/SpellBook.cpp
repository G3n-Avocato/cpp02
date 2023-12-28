/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:12:17 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/28 23:09:45 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"
#include <cstring>
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "Fwoosh.hpp"

SpellBook::SpellBook() {
}

SpellBook::~SpellBook() {
	for (std::map<std::string, ASpell*>::iterator it = this->_book.begin(); it != this->_book.end(); it++)
		delete it->second ;
	this->_book.clear();
}

void	SpellBook::learnSpell(ASpell *spell) {
	this->_book[spell->getName()] = spell->clone();
}

void	SpellBook::forgetSpell(const std::string &spell) {
	std::map<std::string, ASpell*>::iterator	it = this->_book.find(spell);

	if (it != this->_book.end()) {
		delete it->second ;
		this->_book.erase(it);
	}
}

ASpell*	SpellBook::createSpell(const std::string &spell) {
	std::map<std::string, ASpell*>::iterator it = this->_book.find(spell);
	ASpell*	tmp = NULL;
	if (it != this->_book.end())
		tmp = it->second;
	return (tmp);
}
