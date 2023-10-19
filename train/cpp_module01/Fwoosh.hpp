/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:12:30 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/20 00:10:57 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
# define FWOOSH_HPP

#include "ASpell.hpp"

class	Fwoosh : public ASpell {

	public:
		Fwoosh(void);
		Fwoosh(const Fwoosh& src);
		Fwoosh&	operator=(const Fwoosh& rhs);
		~Fwoosh(void);
		
		Fwoosh*	clone(void) const;
};

#endif
