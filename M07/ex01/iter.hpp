/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:27:18 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/17 19:10:17 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>

template<typename T>
void	iter(T *arr, size_t size, void (&fonction)(T&)) {
	for(size_t i = 0; i < size; i++)
		fonction(arr[i]);
}

template<typename T>
void	iter(const T *arr, size_t size, void (&fonction)(const T&)) {
	for(size_t i = 0; i < size; i++)
		fonction(arr[i]);
}

template<typename T>
void	ft_print(const T &pos) {
	std::cout << std::fixed << std::setprecision(1) << pos << " ";
}
