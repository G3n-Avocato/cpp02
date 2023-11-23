/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:01:50 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/22 21:16:17 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>

template<typename T>
T const &	max(T const &x, T const &y) {
	return (x > y ? x : y);
}

template<typename T>
T const &	min(T const &x, T const &y) {
	return (x < y ? x : y);
}

template<typename T>
void	swap(T &x, T &y) {
	T tmp = x;
	x = y;
	y = tmp;
}
