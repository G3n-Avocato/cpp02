/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:47:47 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/28 23:12:25 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"
#include "ATarget.hpp"
#include "BrickWall.hpp"
#include "Dummy.hpp"
#include <cstring>

TargetGenerator::TargetGenerator() {
}

TargetGenerator::~TargetGenerator() {
	for (std::map<std::string, ATarget*>::iterator it = this->_generator.begin(); it != this->_generator.end(); it++)
		delete it->second ;
	this->_generator.clear();
}

void	TargetGenerator::learnTargetType(ATarget *target) {
	this->_generator[target->getType()] = target->clone();
}

void	TargetGenerator::forgetTargetType(const std::string &type) {
	std::map<std::string, ATarget*>::iterator	it = this->_generator.find(type);

	if (it != this->_generator.end()) {
		delete it->second ;
		this->_generator.erase(it);
	}
}

ATarget*	TargetGenerator::createTarget(const std::string &type) {
	std::map<std::string, ATarget*>::iterator it = this->_generator.find(type);
	ATarget*	tmp = NULL;
	if (it != this->_generator.end())
		tmp = it->second;
	return (tmp);
}
