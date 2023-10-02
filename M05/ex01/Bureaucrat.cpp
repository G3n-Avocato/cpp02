/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:01:31 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/02 19:48:24 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src._name) {
    *this = src;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &rhs) {
    if (this != &rhs) {
        this->_grade = rhs.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(void) {
}

std::string const Bureaucrat::getName(void) const {
    return (this->_name);
}

int Bureaucrat::getGrade(void) const {
    return (this->_grade);
}

void    Bureaucrat::upGrade(void) {
	if ((this->_grade - 1) < 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void    Bureaucrat::downGrade(void) {
		if ((this->_grade + 1) > 150)
			throw GradeTooLowException();
		else
			this->_grade++;
}

void	Bureaucrat::signForm(void) const {
	if ()

}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade too high Exception!\n");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade too Low Exception!\n");
}

std::ostream    &operator<<(std::ostream &o, Bureaucrat const &rhs) {
    o << rhs.getName();
    o << ", bureaucrat grade ";
    o << rhs.getGrade();
    o << ".";
    return (o);
}
