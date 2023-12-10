/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:20:28 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/10 22:48:00 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>

RPN::RPN(std::string line) {
	if (this->_parsingsurfaceRPN(line))
		throw Error();
	this->_detailRPN(line);
}

RPN::RPN(const RPN& src) {
	(void)src;
}

RPN& RPN::operator=(const RPN& rhs) {
	(void)rhs;
	return (*this);
}

RPN::~RPN() {
}

int	RPN::_parsingsurfaceRPN(std::string& line) const {
	int		digit = 0;
	int		space = 0;
	int		tok	= 0;

	if (!isdigit(line[0]) || !isdigit(line[2]))
		return (1);
	for (size_t i = 0; i < line.size(); i++) {	
		if (isdigit(line[i]))
			digit++;
		else if (line[i] == '+' || line[i] == '-' || line[i] == '/' || line[i] == '*')
			tok++;
		else if (line[i] == ' ')
			space++;
		else
			return (1);
	}
	if (digit + tok != space + 1 || digit - 1 != tok)
		return (1);
	return (0);
}

void	RPN::_detailRPN(std::string line) {
	std::string	tmp;
	size_t		i = 0;
	size_t		pos = 0;

	while (i < line.size()) {
		pos = line.find(" ", i);
		if (pos != std::string::npos) {
			tmp = line.substr(i, pos - i);
			this->_myNameIs(tmp);
			i = pos + 1;
		}
		else if (pos == std::string::npos && i + 1 == line.size()) {
			tmp = line.substr(i, 1);
			this->_myNameIs(tmp);
			std::cout << this->_calcul.top() << std::endl;
			i++;
		}
		else
			break ;
	}
}

void	RPN::_myNameIs(std::string tmp) {
	long int	val = 0;

	if (isdigit(tmp[0]) && tmp.size() == 1) {
		val = strtol(tmp.c_str(), NULL, 10);
		if (val < 0 || val > 9)
			throw Error();
		this->_calcul.push(val);
	}
	if (!isdigit(tmp[0]) && tmp.size() == 1) {
		if (this->_calcul.empty() || this->_calcul.size() < 2)
			throw Error();
		int	a = this->_calcul.top();
		this->_calcul.pop();
		int	b = this->_calcul.top();
		this->_calcul.pop();
		if (tmp[0] == '-')
			val = b - a;
		else if (tmp[0] == '+')
			val = b + a;
		else if (tmp[0] == '/')
			val = b / a;
		else if (tmp[0] == '*')
			val = b * a;
		this->_calcul.push(val);
	}
}

const char*	RPN::Error::what() const throw() {
	return ("Error\n");
}
