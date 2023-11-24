/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:00:28 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/24 19:47:35 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Array.hpp"
#include "iostream"

int main(void) {

	try {
	Array<int>	i(5);
	Array<char>	c(8);
	Array<char> libre;
	
	int *a = new int();
	(void)a;

	i[0] = 1;
	i[1] = 2;
	i[2] = 3;
	i[3] = 4;
	i[4] = 5;

	c[0] = 'S';
	c[1] = 'a';
	c[2] = 'u';
	c[3] = 's';
	c[4] = 's';
	c[5] = 'i';
	c[6] = 'c';
	c[7] = 'e';

	//std::cout << "libre: " << libre[0] << std::endl;
	
	for (int j = 0; i.size() > static_cast<unsigned int>(j); j++)
		std::cout << i[j] << std::endl;
	for (int k = 0; c.size() >= static_cast<unsigned int>(k); k++)
		std::cout << c[k];
	}
	catch (Array<T>::PosOutOfRange& e) {
		std::cout << e.what();
	}
	return (0);
}
