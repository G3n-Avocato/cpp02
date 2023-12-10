/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:20:22 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/10 22:49:09 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	try {
		if (argc != 2)
			throw RPN::Error();
		RPN		test(argv[1]);

	}
	catch(std::exception& e) {
		std::cout << e.what();
	}
	return (0);
}
