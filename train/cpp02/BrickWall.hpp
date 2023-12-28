/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:48:36 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/28 20:50:03 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "ATarget.hpp" 

class BrickWall : public ATarget {
	public :
		BrickWall();
		~BrickWall();

		BrickWall*	clone(void) const;
};
