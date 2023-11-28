/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:08:53 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/28 19:47:10 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main(void) {

	{
		std::cout << "-- vector test 01 --\n" << std::endl;
		
		std::vector<int>	first;
		first.assign(5, 50);

		std::cout << "vector first: ";
		for (std::vector<int>::iterator it = first.begin(); it != first.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		try {
			std::cout << "search: 18\nfind: " << *easyfind(first, 18) << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what();
		}
		
		std::cout << std::endl;
	}
	{
		std::cout << "-- vector test 02 --\n" << std::endl;
	
		std::vector<int>	second;
		for(int i = 0; i <= 10; i++)
			second.push_back(i);
		
		std::cout << "vector second: ";
		for (std::vector<int>::iterator it = second.begin(); it != second.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		try {
			std::cout << "search: 8\nfind: " << *easyfind(second, 8) << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what();
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-- list test 01 --\n" << std::endl;

		int	tab[] = {53, 494, 26, 4, 18, 71};
		std::list<int>	first(tab, tab + sizeof(tab) / sizeof(int));

		std::cout << "list first: ";
		for (std::list<int>::iterator it = first.begin(); it != first.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		try {
			std::cout << "search: 71\nfind: " << *easyfind(first, 71) << std::endl;;
		}
		catch (std::exception& e) {
			std::cout << e.what();
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-- list test 02 --\n" << std::endl;

		int	tab[] = {68, 69, 70, 71, 72, 73};
		std::list<int>	second(tab, tab + sizeof(tab) / sizeof(int));

		std::cout << "list second: ";
		for (std::list<int>::iterator it = second.begin(); it != second.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		try {
			std::cout << "search: 67\nfind: " << *easyfind(second, 67) << std::endl;;
		}
		catch (std::exception& e) {
			std::cout << e.what();
		}
		std::cout << std::endl;
	}
	return (0);
}
