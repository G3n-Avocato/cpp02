/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:02:31 by lamasson          #+#    #+#             */
/*   Updated: 2023/09/26 23:24:39 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <exception>
#include <ostream>

Form::Form(void): _name("default"), _gradeSign(1), _gradeExec(1) {
	this->_signed = false;
	this->exceptionSign();
	this->exceptionExec();
}

Form::Form(std::string const name, int const Sign, int const Exec): _name(name), _gradeSign(Sign), _gradeExec(Exec) {
	this->_signed = false;
	this->exceptionSign();
	this->exceptionExec();
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
	try {
		if (src.getGrade() <= this->_gradeSign)
			this->_signed = true;
		else
			throw GradeTooLowException();
	}
	catch (GradeTooLowException& e) {
		std::cout << src.getName() << ", " << src.getGrade() << e.what() << std::endl;
		std::cout << "Grade -" << this->_gradeSign << "- is required." << std::endl;
	}
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
	return (" grade, too high exception.");
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return (" grade, too low exception.");
}

void	Form::exceptionSign(void) const {
	try {
		if (this->_gradeSign > 150)
			throw GradeTooLowException();
		else if (this->_gradeSign < 1)
			throw GradeTooHighException();
	}
	catch (GradeTooHighException& e) {
		std::cout << this->_name << ", " << this->_gradeSign << e.what() << std::endl;
	}
	catch (GradeTooLowException& e) {
		std::cout << this->_name << ", " << this->_gradeSign << e.what() << std::endl;
	}
}

void	Form::exceptionExec(void) const {
	try {
		if (this->_gradeExec > 150)
			throw GradeTooLowException();
		else if (this->_gradeExec < 1)
			throw GradeTooHighException();
	}
	catch (GradeTooHighException& e) {
		std::cout << this->_name << ", " << this->_gradeExec << e.what() << std::endl;
	}
	catch (GradeTooLowException& e) {
		std::cout << this->_name << ", " << this->_gradeExec << e.what() << std::endl;
	}
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
