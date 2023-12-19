/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:10:54 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/19 00:36:52 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <algorithm>

class	NoOccurenceFind : public std::exception {
	public:
		virtual const char*	what() const throw() {
			return("std::exception: No occurence find!\n");
		};
};

template<typename T>
typename T::iterator	easyfind(T arr, int i) {
	typename T::iterator it = find(arr.begin(), arr.end(), i);
	if (it != arr.end())
			return (it);
	throw NoOccurenceFind();
}
