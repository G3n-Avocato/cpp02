/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:43:41 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/17 22:01:21 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstring>

Intern::Intern(void) {
}

Intern::Intern(const Intern &src) {
	(void)src;
}

Intern&	Intern::operator=(const Intern &rhs) {
	(void)rhs;
	return (*this);
}
Intern::~Intern(void) {
}

AForm*	Intern::makeForm(const std::string name, const std::string target) const {
	const char	*forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	AForm*	tmp;

	while (i < 3 && strcmp(name.c_str(), forms[i]) != 0)
		i++;
	switch (i) {
		case 0:
			tmp = new ShrubberyCreationForm(target);
			break ;
		case 1:
			tmp = new RobotomyRequestForm(target);
			break ;
		case 2:
			tmp = new PresidentialPardonForm(target);
			break ;
		default:
			throw FormFileException();
	}
	std::cout << "Intern creates " << tmp->getName() << std::endl;
	return (tmp);
}

const char*	Intern::FormFileException::what(void) const throw() {
	return ("Form does't exist. Form File Exception!\n");
}
