/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:12:42 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/28 22:15:16 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <map>
#include <iostream>
#include "ASpell.hpp"

class	SpellBook {
	public :
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell*);
		void	forgetSpell(std::string const&);
		ASpell*	createSpell(std::string const&);
	
	private :

		std::map<std::string, ASpell*>	_book;

		SpellBook(const SpellBook&);
		SpellBook&	operator=(const SpellBook&);

};
