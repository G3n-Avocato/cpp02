/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:04:57 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/01 21:02:20 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include<stack>

template<typename T>
class MutantStack : public std::stack<T> {
	
	public:
		
		MutantStack<T>() : std::stack<T>() {}
		MutantStack<T>(const MutantStack<T> &src) : std::stack<T>(src) {
			*this = src;
		}
		MutantStack<T>&	operator=(const MutantStack<T> &rhs) {
			if (this != &rhs)
				this = rhs.c->operator=(rhs);
			return (*this);
		}
		~MutantStack<T>();
	
		typedef MutantStack<T>::std::stack<T>::

	private:

};
