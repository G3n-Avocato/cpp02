/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:45:54 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/23 16:10:13 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"

class	Warlock {
	public:
		
		Warlock(std::string const &name, std::string const &title);
		~Warlock(void);
	
		std::string const &	getName(void) const;
		std::string const &	getTitle(void) const;
		void	setTitle(std::string const &title);

		void	introduce(void) const;

		void	learnSpell(ASpell* learn);
		void	forgetSpell(std::string const &forget);
		void	launchSpell(std::string const &spell, ATarget& tar);

	private:

		ASpell**	_learnSpell;
		int			_size;

		std::string const _name;
		std::string	_title;

		Warlock(void);
		Warlock(const Warlock& src);
		Warlock&	operator=(const Warlock& rhs);
};

#endif
