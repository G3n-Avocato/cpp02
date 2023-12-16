/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:10:54 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/16 00:40:48 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

class	NoOccurenceFind : public std::exception {
	public:
		virtual const char*	what() const throw() {
			return("std::exception: No occurence find!\n");
		};
};

template<typename T>
typename T::iterator	easyfind(T arr, int i) {
	typename T::iterator it = arr.begin();
	while (it != arr.end()) {
		if (*it == i)
			return (it);
		it++;
	}
	throw NoOccurenceFind();
}
