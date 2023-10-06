/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:02:31 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/02 19:54:36 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _name("default"), _gradeSign(1), _gradeExec(1) {
	this->_signed = false;
}

AForm::AForm(std::string const name, int const Sign, int const Exec): _name(name), _gradeSign(Sign), _gradeExec(Exec) {
	this->_signed = false;
	if (Sign > 150 || Exec > 150)
		throw GradeTooLowException();
	else if (Sign < 1 || Exec < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &src): _name(src._name), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {
	*this = src;
}

AForm&	AForm::operator=(const AForm &rhs) {
	if (this != &rhs) {
		this->_signed = rhs._signed;
	}
	return (*this);
}

AForm::~AForm(void) {
}

void	AForm::beSigned(const Bureaucrat &src) {
	if (src.getGrade() <= this->_gradeSign)
		this->_signed = true;
	src.signForm(*this);
	if (!this->_signed)
		throw GradeTooLowException();
}

std::string const AForm::getName(void) const {
	return (this->_name);
}

bool	AForm::getBool(void) const {
	return (this->_signed);
}

int		AForm::getGradeSign(void) const {
	return (this->_gradeSign);
}

int		AForm::getGradeExec(void) const {
	return (this->_gradeExec);
}

const char*	AForm::GradeTooHighException::what(void) const throw() {
	return ("Form Grade too high exception.\n");
}

const char* AForm::GradeTooLowException::what(void) const throw() {
	return ("Form Grade too low exception.\n");
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs) {
	o << rhs.getName();
	o << " form, grade to sign ";
	o << rhs.getGradeSign();
	o << ", grade to execute ";
	o << rhs.getGradeExec();
	o << ", form status: ";
	if (rhs.getBool())
		o << "signed.\n";
	else
		o << "unsigned.\n";
	return (o);
}
