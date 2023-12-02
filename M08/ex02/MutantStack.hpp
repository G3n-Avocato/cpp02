/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:04:57 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/02 19:25:57 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include<iterator>
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
				this->std::stack<T>::operator=(rhs);
			return (*this);
		}
		~MutantStack<T>() {}
	
		//typedef typename ?? apparemment l'un sans l'autre creer erreur de compil ? 
		typedef typename MutantStack<T>::container_type::iterator		iterator;
		iterator begin() {
			MutantStack<T>::iterator	it = this->c.begin();
			return (it);
		}
		iterator end() {
			MutantStack<T>::iterator	ite = this->c.end();
			return (ite);
		}

		typedef typename MutantStack<T>::container_type::const_iterator	const_iterator;
		const_iterator begin() const {
			MutantStack<T>::const_iterator	it = this->c.begin();
			return (it);
		}
		const_iterator end() const {
			MutantStack<T>::const_iterator ite = this->c.end() ;
			return (ite);
		}
};
