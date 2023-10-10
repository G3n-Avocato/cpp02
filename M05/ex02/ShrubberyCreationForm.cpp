/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:19:18 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/09 17:39:53 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(), _target("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) {
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!this->getBool())
		throw UnsignedFormException();
	else if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	
	std::string str = _target + "_shrubbery";
	std::ofstream	file(str.c_str());

	file << "ASCII trees" << std::endl;
	file << "ASCII trees" << std::endl;
	file << "ASCII trees" << std::endl;
	file << "ASCII trees" << std::endl;
	file.close();
}
