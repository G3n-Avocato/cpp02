/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 00:14:16 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/20 00:16:44 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

#include "ATarget.hpp"

class	Dummy : public ATarget {
	public:
		Dummy(void);
		Dummy(const Dummy& src);
		Dummy&	operator=(const Dummy& rhs);
		~Dummy(void);

		Dummy*	clone(void) const;
};

#endif
