/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:02:31 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/09 19:28:08 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name("default"), _gradeSign(1), _gradeExec(1) {
	this->_signed = false;
}

Form::Form(std::string const name, int const Sign, int const Exec): _name(name), _gradeSign(Sign), _gradeExec(Exec) {
	this->_signed = false;
	if (Sign > 150 || Exec > 150)
		throw GradeTooLowException();
	else if (Sign < 1 || Exec < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &src): _name(src._name), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {
	*this = src;
}

Form&	Form::operator=(const Form &rhs) {
	if (this != &rhs) {
		this->_signed = rhs._signed;
	}
	return (*this);
}

Form::~Form(void) {
}

void	Form::beSigned(const Bureaucrat &src) {
	if (src.getGrade() <= this->_gradeSign)
		this->_signed = true;
	if (!this->_signed)
		throw GradeTooLowException();
}

std::string const Form::getName(void) const {
	return (this->_name);
}

bool	Form::getBool(void) const {
	return (this->_signed);
}

int		Form::getGradeSign(void) const {
	return (this->_gradeSign);
}

int		Form::getGradeExec(void) const {
	return (this->_gradeExec);
}

const char*	Form::GradeTooHighException::what(void) const throw() {
	return ("Form Grade too high exception.\n");
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return ("Form Grade too low exception.\n");
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs) {
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
