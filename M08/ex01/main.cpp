/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:49:43 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/29 23:17:22 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <iostream>

int main(void) {
	{
		std::cout << "-- Test main 01 --\n" << std::endl;

		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << std::endl;
	}
	{
		std::cout << "-- Test error 01 --\n" << std::endl;

		Span	test;

		try {
			std::cout << "longest: " << test.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what();
			try {
				std::cout << "shortest: " << test.shortestSpan() << std::endl;
			}
			catch (std::exception& e) {
				std::cout << e.what();
				try {
					std::cout << "Span vide test fillSpan: " << std::endl;
					test.fillSpan();
				}
				catch (std::exception& e) {
					std::cout << e.what();
				}
			}
		}	
		std::cout << std::endl;
	}
	{
		std::cout << "-- Test error 02 --\n" << std::endl;

		Span	test(3);

		try {
			std::cout << "Fill Span > max _N: " << std::endl;
			test.addNumber(1);
			test.addNumber(2);
			test.addNumber(3);
			test.addNumber(4);
		}
		catch (std::exception &e) {
			std::cout << e.what();
			try {
				std::cout << "Span full test fillspan: " << std::endl;
				test.fillSpan();
			}
			catch (std::exception& e) {
				std::cout << e.what();
			}
		}
		std::cout << std::endl; 
	}
	{
		std::cout << "-- Test copy/ operator= 01 --\n" << std::endl;

		Span	first(5);

		try {
			
			for (int i = 0; i < 5; i++)
				first.addNumber(i);
			//test operator de copy	
			Span	cpy(first);
			
			std::cout << "shortest cpy: " << cpy.shortestSpan() << std::endl;
			std::cout << "longest cpy: " << cpy.longestSpan() << std::endl;
			
			Span	second(8);

			second.fillSpan();
			//test operator =
			cpy = second;

			std::cout << "shortest cpy operator= : " << cpy.shortestSpan() << std::endl;
			std::cout << "longest cpy operator= : " << cpy.longestSpan() << std::endl;
			
		}
		catch (std::exception& e) {
			std::cout << e.what();
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-- Test fillSpan-10 01 --\n" << std::endl;

		Span	full(10);

		try {
			full.fillSpan();
			
			std::cout << "shortest: " << full.shortestSpan() << std::endl;
			std::cout << "longest: " << full.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what();
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-- Test fillSpan-10000 02 --\n" << std::endl;

		Span	full(10000);

		try {
			full.fillSpan();
			
			std::cout << "shortest: " << full.shortestSpan() << std::endl;
			std::cout << "longest: " << full.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what();
		}
		std::cout << std::endl;
	}
	return (0);
}
