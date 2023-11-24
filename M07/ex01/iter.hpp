/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:27:18 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/23 17:49:51 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>

template<typename T>
void	iter(T *arr, int length, void (*fonction)(T)) {
	for(int i = 0; i < length; i++)
		fonction(arr[i]);
}

template<typename T>
void	ft_print(T pos) {
	std::cout << std::fixed << std::setprecision(1) << pos << " ";
}
