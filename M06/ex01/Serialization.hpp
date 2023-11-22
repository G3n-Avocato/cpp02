/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:07:05 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/21 23:39:28 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

struct Data {
	int	nb;	
};

class	Serializer {

	public:

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:

		Serializer(void);
		Serializer(const Serializer &src);
		Serializer&	operator=(const Serializer &rhs);
		~Serializer(void);

};
