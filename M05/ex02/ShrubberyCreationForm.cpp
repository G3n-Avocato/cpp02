/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:19:18 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/06 21:47:32 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : _target("default"), AForm() {

	std::ofstream	file_def(_target + "_shrubbery");

	file_def << "default" << std::endl;
	file_def << "default" << std::endl;
	file_def << "default" << std::endl;
	file_def.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target), AForm("Shrubbery", 145, 137) {
	
	std::ofstream	file(_target + "_shrubbery");

	file << "ASCII trees" << std::endl;
	file << "ASCII trees" << std::endl;
	file << "ASCII trees" << std::endl;
	file << "ASCII trees" << std::endl;
	file.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : _target(src._target), AForm(src) {
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

