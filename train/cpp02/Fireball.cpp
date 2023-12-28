/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:40:30 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/28 20:42:57 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball(void) : ASpell("Fireball", "burnt to a crisp") {
}

Fireball::~Fireball(void) {
}

Fireball* Fireball::clone() const {
	Fireball* tmp = new Fireball();
	return (tmp);
}
