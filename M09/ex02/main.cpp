/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:03:42 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/12 01:50:02 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	try {
		if (argc < 2)
			throw PmergeMe::Error();
		PmergeMe	test(argc, argv);

	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
	return (0);
}
