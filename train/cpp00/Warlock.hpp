/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:45:54 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/19 13:15:35 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>

class	Warlock {
	public:
		
		Warlock(void);
		Warlock(std::string const &name, std::string const &title);
		~Warlock(void);
	
		std::string const &	getName(void) const;
		std::string const &	getTitle(void) const;
		void	setTitle(std::string const &title);

		void	introduce(void) const;

	private:
	
		std::string const _name;
		std::string	_title;
};

#endif
