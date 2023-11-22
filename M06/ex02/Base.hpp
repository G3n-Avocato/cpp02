/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 00:11:39 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/22 02:57:55 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Base {
	
	public:

		virtual ~Base(void);

		static Base*	generate(void);
		static void		identify(Base* p);
		static void		identify(Base& p);

		class exception { public: virtual const char* what() const throw(); };

};
