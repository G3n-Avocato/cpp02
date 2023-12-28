/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 00:17:49 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/28 20:12:40 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget("Target Practice Dummy") {
}

Dummy::~Dummy(void) {
}

Dummy*	Dummy::clone(void) const {
	Dummy*	tmp = new Dummy();
	return (tmp);
}
