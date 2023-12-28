/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:43:35 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/28 20:44:47 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "ASpell.hpp"

class	Polymorph : public ASpell {
	public :
		Polymorph();
		~Polymorph();

		Polymorph*	clone() const;
};
