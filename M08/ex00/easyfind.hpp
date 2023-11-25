/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:10:54 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/25 22:40:40 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
typename T::iterator	easyfind(T arr, int i) {
	typename T::iterator it = arr.begin();
	while (it != arr.end()) {
		if (*it == i)
			return (it);
		it++;
	}
	return (it);
}
