/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:49:05 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/21 23:26:12 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

uintptr_t	Serializer::serialize(Data* ptr) {
	uintptr_t nptr = reinterpret_cast<uintptr_t>(ptr);
	return (nptr);
}

Data*	Serializer::deserialize(uintptr_t raw) {
	Data*	nptr = reinterpret_cast<Data*>(raw);
	return (nptr);
}
