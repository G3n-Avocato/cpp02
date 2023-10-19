/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:48:40 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/19 13:16:28 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(void) {
}

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
