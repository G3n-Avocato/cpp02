/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:00:28 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/14 22:48:33 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Array.hpp"
#include <iostream>

int main(void) {
	{
		std::cout << "-- Test 01 int-char-std::exception[] --\n" << std::endl;
		
		Array<int>	i(5);
		Array<char>	c(9);
		std::string	tmp = "Saucisse\n";	

		int *a = new int();
		(void)a;

		for (int j = 0; i.size() > static_cast<unsigned int>(j); j++)
			i[j] = j;

		for (int j = 0; c.size() > static_cast<unsigned int>(j); j++)
			c[j] = tmp[j];

		try {	
			for (int j = 0; i.size() > static_cast<unsigned int>(j); j++)
				std::cout << i[j] << " ";
			std::cout << std::endl;
			for (int k = 0; c.size() >= static_cast<unsigned int>(k); k++)
				std::cout << c[k];
		}
		catch (const std::exception& e) {
			std::cout << e.what();
		}
		delete a;
	}
	{
		std::cout << std::endl;
		std::cout << "-- Test 02 std::string str--\n" << std::endl;

		Array<std::string>	str(19);
		str[0] = static_cast<std::string>("La maison saucisse\n");
		try {
			for (int i = 0; str.size() > static_cast<unsigned int>(i); i++)
				std::cout << str[i];
			std::cout << "str size: " << str.size() << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what();
		}
	}
	{
		std::cout << std::endl;
		std::cout << "-- Test Array 03 constructeur vide--\n" << std::endl;

		Array<int>	test;
		try {
			std::cout << "test = " << test[0] << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what();
		}
	}
	{
		std::cout << std::endl;
		std::cout << "-- Test 04 constructeur de copy --\n" << std::endl;

		Array<int>	org(10);
		
		for(int i = 0; org.size() > static_cast<unsigned int>(i); i++)
			org[i] = 66;
		
		Array<int>	cpy(org);
		
		try {
			std::cout << "org before:\n";
			for(int i = 0; org.size() > static_cast<unsigned int>(i); i++)
				std::cout << org[i] << " ";
			std::cout << "\ncpy before:\n";
			for (int i = 0; cpy.size() > static_cast<unsigned int>(i); i++)
				std::cout << cpy[i] << " ";
			
			std::cout << "\ncpy modif:\n";
			for (int i = 0; cpy.size() > static_cast<unsigned int>(i); i++) {
				cpy[i] += 1;
				std::cout << cpy[i] << " ";
			}
			std::cout << "\norg after modif cpy:\n";
			for (int i = 0; org.size() > static_cast<unsigned int>(i); i++) {
				std::cout << org[i] << " ";
				org[i] -=1;
			}
			
			std::cout << "\norg modif:\n";
			for (int i = 0; org.size() > static_cast<unsigned int>(i); i++)
				std::cout << org[i] << " ";
			std::cout << "\ncpy after modif org:\n";
			for (int i = 0; cpy.size() > static_cast<unsigned int>(i); i++) {
				std::cout << cpy[i] << " ";
			}
			std::cout << std::endl;
		}	
		catch (const std::exception& e) {
			std::cout << e.what();
		}
	}
	{
		std::cout << "\n-- Test 05 constructeur de copy with data --\n" << std::endl;
		
		Array<int>	a(5);

		for (unsigned int i = 0; a.size() > i; i++)
			a[i] = 6;
		std::cout << "array a = " << a[0] << std::endl;
		Array<int>	b(6);
		
		for (unsigned int i = 0; b.size() > i; i++)
			b[i] = 39;
		std::cout << "array b = " << b[0] << std::endl;
		std::cout << "a = b" << std::endl;	
		a = b;
		for (unsigned int i = 0; a.size() > i; i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "\n-- Test 06 -- test subject int a new --\n" << std::endl;
		
		int	*a = new int();
	
		std::cout << "display *a = "<< *a << std::endl;
		
		delete a;
	}
	return (0);
}
