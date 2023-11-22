/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:55:07 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/22 02:58:21 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void) {
	Base* test01 = Base::generate();

	Base::identify(test01);
	Base::identify(*test01);
	
	delete test01;
	return (0);
}
