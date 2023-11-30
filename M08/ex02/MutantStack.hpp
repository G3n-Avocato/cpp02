/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:04:57 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/30 21:03:44 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iterator>
#include<stack>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack<T>(void);
		~MutantStack<T>(void);
		
		class	iterator : public std::iterator<> {
			public:
		};

	private:

};
