/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:26:40 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/23 01:21:38 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"iter.hpp"

int main(void) {

	std::string	str = "La maison saucisse";
	int			nb[5];
	char		tab[11];
	float		ftab[5];

	nb[0] = 5;
	nb[1] = 3;
	nb[2] = 78;
	nb[3] = 9;
	nb[4] = 28;

	tab[0] = 'H';
	tab[1] = 'e';
	tab[2] = 'l';
	tab[3] = 'l';
	tab[4] = 'o';
	tab[5] = ' ';
	tab[6] = 'W';
	tab[7] = 'o';
	tab[8] = 'r';
	tab[9] = 'l';
	tab[10] = 'd';

	ftab[0] = 5.5f;
	ftab[1] = 8.0f;
	ftab[2] = 2344325.34f;
	ftab[3] = 321321.2222222f;
	ftab[4] = 42.0f;

	iter(&str[0], str.length(), ft_print);
	std::cout << std::endl;
	iter(nb, 5, ft_print);
	std::cout << std::endl;
	iter(tab, 11, ft_print);
	std::cout << std::endl;
	iter(ftab, 5, ft_print);
	std::cout << std::endl;

	iter(tab, 11, plusone);
	iter(tab, 11, ft_print);
	std::cout << std::endl;

	return (0);
}
