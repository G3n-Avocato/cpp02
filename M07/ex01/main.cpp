/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:26:40 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/17 19:15:26 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"iter.hpp"

int main(void) {
	
	std::string	str[2] = {"La maison saucissee\n", "coucou"};
	int					nb[5] = {5, 3, 78, 9, 28};
	char				tab[12] = {"Hello World"};
	float				ftab[5] = {5.5f, 8.0f, 231313.34f, 12121.2112f, 42.02f}; 

	iter(str, 2, ft_print);
	std::cout << std::endl;
	iter(nb, 5, ft_print);
	std::cout << std::endl;
	iter(tab, 12, ft_print);
	std::cout << std::endl;
	iter(ftab, 5, ft_print);
	std::cout << std::endl;
		
	const char	itc[25] = "const la maison saucisse";
	iter(itc, 25, ft_print);
	std::cout << std::endl;
	return (0);
}
