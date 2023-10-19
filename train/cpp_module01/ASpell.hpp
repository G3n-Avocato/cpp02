/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:30:42 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/19 15:07:41 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <string>

class ATarget;

class	ASpell{
	public:
		ASpell(void);
		ASpell(std::string const& name, std::string const& effects);
		ASpell(const ASpell& src);
		ASpell&	operator=(const ASpell& rhs);
		virtual ~ASpell(void);
		
		std::string const& getName(void) const;
		std::string const& getEffects(void) const;

		virtual	ASpell* clone() const = 0;

		void	attack(const ATarget& vic) const;

	protected:
		std::string _name;
		std::string	_effects;
};

#endif
