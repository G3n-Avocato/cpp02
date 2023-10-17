/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:09:34 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/09 19:45:06 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm(), _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robot", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src), _target(src._target) {
	*this = src;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!this->getBool())
		throw UnsignedFormException();
	else if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	
	int	random = std::rand() % 2;
	std::cout << "Vrrrrrr .. Vrrrrrr .." << std::endl;
	if (random == 0)
		std::cout << this->_target << " has been robotomized successfully this time." << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}
