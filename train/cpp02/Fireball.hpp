/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:38:09 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/28 20:40:17 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "ASpell.hpp"

class Fireball : public ASpell {
	public:
		Fireball();
		~Fireball();
		
		Fireball* clone(void) const;
};
