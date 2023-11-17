/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:48:40 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/27 16:00:29 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include "ASpell.hpp"
#include <cstring>
#include <string>

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title) {
	this->_size = 0;
	this->_learnSpell = NULL;
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void) {
	if (this->_learnSpell) {
		for (int i = 0; i < this->_size; i++)
			delete this->_learnSpell[i];
		delete [] this->_learnSpell;
	}
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
	this->_size++;
	
	ASpell**	tmp = new ASpell*[this->_size];

	if (this->_learnSpell) {
		for (int i = 0; this->_learnSpell[i] && i < this->_size; i++)
			tmp[i] = this->_learnSpell[i];
	}
	
	tmp[this->_size - 1] = learn;

	if (this->_learnSpell) {
		for (int i = 0; this->_learnSpell[i]; i++)
			delete this->_learnSpell[i];
	
	delete [] this->_learnSpell ;
	}
	this->_learnSpell = tmp;
}

void	Warlock::forgetSpell(const std::string forget) {
	int i = 0;

	if (this->_learnSpell) {
		while (strcmp(this->_learnSpell[i]->getName().c_str(), forget.c_str()) != 0 && i < this->_size)
			i++;
	}
	if (i == this->_size)
		return ;

	this->_size--;
	if (this->_size == 0) {
		for (int j = 0; j <= this->_size; j++)
			delete this->_learnSpell[j];
		delete [] this->_learnSpell;
		this->_learnSpell = NULL;
		return ;
	}

	ASpell**	tmp = new ASpell*[this->_size];
	int	j = 0;
	int	k = 0;

	while (this->_learnSpell[j]) {
		if (j == i)
			;
		else {
			tmp[k] = this->_learnSpell[j];
			k++;
		}
		j++;
	}
	for (int j = 0; this->_learnSpell[j]; j++)
		delete this->_learnSpell[j];
	delete [] this->_learnSpell;
	this->_learnSpell = tmp;
}

void	Warlock::launchSpell(const std::string spell, ATarget const &tar) {
	int i = 0;

	if (this->_learnSpell) {
		while (strcmp(this->_learnSpell[i]->getName().c_str(), spell.c_str()) != 0 && i < this->_size)
			i++;
	}
	if (i == this->_size)
		return ;
	else
		tar.getHitBySpell(*this->_learnSpell[i]);
}
