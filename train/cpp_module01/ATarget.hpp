/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:40:21 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/19 15:09:40 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <string>

class ASpell;

class ATarget {

	public:
		ATarget(void);
		ATarget(std::string const& type);
		ATarget(const ATarget& src);
		ATarget& operator=(const ATarget& rhs);
		virtual ~ATarget(void);

		std::string const&	getType(void) const;

		virtual ATarget*	clone(void) const = 0;

		void	getHitBySpell(const ASpell& hit) const;

	protected:
		std::string	_type;
};

#endif
