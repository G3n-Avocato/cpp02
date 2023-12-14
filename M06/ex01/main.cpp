/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:05:54 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/22 00:05:36 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <iostream>

int	main(void) {
	Data	ptr;
	Data*	nptr = NULL;
	
	ptr.nb = 42;

	std::cout << "Data ptr: " << &ptr << std::endl;
	std::cout << "Data int ptr: " << ptr.nb << std::endl;

	uintptr_t addr = Serializer::serialize(&ptr);
	std::cout << "addr serializer Data: contenue: " << addr << " addr ptr: " << &addr << std::endl;

	std::cout << "Data nptr: " << nptr << std::endl;
	nptr = Serializer::deserialize(addr);
	std::cout << "Data nptr deserializer: " << nptr << std::endl;
	std::cout << "Data int nptr: " << nptr->nb << std::endl;
	return (0);
}
