/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:59:32 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/28 20:13:24 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void) : ASpell("Fwoosh", "fwooshed") {
}

Fwoosh::~Fwoosh(void) {
}

Fwoosh*	Fwoosh::clone(void) const {
	Fwoosh*	tmp = new Fwoosh();
	return (tmp);
}
