/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:49:43 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/16 02:31:43 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {
	srand(time(NULL));
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
				std::cout << "Span vide test fillSpan: " << std::endl;
				test.fillSpan();
			}
		}	
		std::cout << std::endl;
	}
	{
		std::cout << "-- Test error 02 --\n" << std::endl;

		Span	test(3);

		std::cout << "Fill Span > max _N: " << std::endl;
		test.addNumber(1);
		test.addNumber(2);
		test.addNumber(3);
		test.addNumber(4);
		std::cout << "Span full test fillspan: " << std::endl;
		test.fillSpan();
		try {
			std::cout << "short: " << test.shortestSpan() << std::endl;
			std::cout << "long: " << test.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std ::cout << e.what();
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-- Test copy/ operator= 01 --\n" << std::endl;

		Span	first(5);

		try {
			
			for (int i = 0; i < 5; i++)
				first.addNumber(i);
			Span	cpy(first);
			
			std::cout << "shortest cpy: " << cpy.shortestSpan() << std::endl;
			std::cout << "longest cpy: " << cpy.longestSpan() << std::endl;
			
			Span	second(8);

			second.fillSpan();
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

		full.fillSpan();
		try {	
			
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

		full.fillSpan();
		full.fillSpan();
		try {
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
