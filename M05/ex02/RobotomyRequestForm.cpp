/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:09:34 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/06 22:36:58 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : _target("default"), AForm() {
	std::cout << "Vrrrrrr .. Vrrrrrr .." << std::endl;
	std::cout << "The robotomy failed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : _target(target), AForm("Robot", 72, 45) {
	int	random = std::rand() % 2;
	std::cout << "Vrrrrrr .. Vrrrrrr .." << std::endl;
	if (random == 0)
		std::cout << this->_target << " has been robotomized successfully this time." << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : _target(src._target), AForm(src) {
	*this = src;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}
