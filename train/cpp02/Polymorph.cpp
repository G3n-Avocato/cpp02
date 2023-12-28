/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:45:17 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/28 20:46:47 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph(void) : ASpell("Polymorph", "turned into a critter") {
}

Polymorph::~Polymorph() {
}

Polymorph*	Polymorph::clone() const {
	Polymorph*	tmp = new Polymorph();
	return (tmp);
}
