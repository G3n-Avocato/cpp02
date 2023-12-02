/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:01:02 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/02 20:08:35 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int	main(void) {
	{
		std::cout << "-- Test main 01 --\n" << std::endl;

		MutantStack<int>	mstack;
		
		mstack.push(5);
		mstack.push(17);

		//top stack = bottom tab = last element added
		std::cout << "last add: " << mstack.top() << std::endl;
		
		mstack.pop();
		
		std::cout << "size: " << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		
		std::stack<int>	s(mstack);
		std::cout << "- test operateur cpy sur container stack -" << std::endl;
			std::cout << std::endl;
	}
	{
		std::cout << "-- Test comparateur main 01 [container list] --\n" << std::endl;
		
		std::list<int>	mlist;
		
		mlist.push_back(5);
		mlist.push_back(17);

		//with container list, top stack = last element of list, fct membre back()
		std::cout << "last add: " << mlist.back() << std::endl;
		
		mlist.pop_back();
		
		std::cout << "size: "<< mlist.size() << std::endl;
		
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		//[...]
		mlist.push_back(0);
		
		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
	
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int>	s(mlist);
		std::cout << std::endl;
	}
	{
		std::cout << "-- Test copy/operateur = 01 --\n" << std::endl;

		//test conatiner stack avec char
		MutantStack<char>	mstack;

		mstack.push('1');
		mstack.push('-');

		std::cout << "last add: " << mstack.top() << std::endl;
		mstack.pop();		
		std::cout << "size: " << mstack.size() << std::endl;

		std::string	tmp = "La maison saucisse!\n";
		for (std::string::iterator it = tmp.begin(); it != tmp.end(); it++)
			mstack.push(*it);

		std::cout << "size: " << mstack.size() << std::endl;

		MutantStack<char>::iterator it = mstack.begin();
		MutantStack<char>::iterator	ite = mstack.end();

		++it;
		--it;
		std::cout << " :MutantStack mstack (char): " << std::endl;
		while (it != ite)
		{
			std::cout << *it;
			it++;
		}

		//test operateur=
		MutantStack<char>	op;
		op = mstack;
		
		MutantStack<char>::iterator ito = op.begin();
		MutantStack<char>::iterator iteo = op.end();
		std::cout << " :MutantStack operateur= : " << std::endl;
		while (ito != iteo)
		{
			std::cout << *ito;
			ito++;
		}

		//test contructeur par copy + test const_iterator
		const MutantStack<char>	cpy(op);

		MutantStack<char>::const_iterator	itc = cpy.begin();
		MutantStack<char>::const_iterator	const itec = cpy.end();
		std::cout << " :MutantStack copy + const_iterator: " << std::endl;
		while (itc != itec)
		{
			std::cout << "Deb: " << *itc << " Fin: " << *itec << std::endl;
			itc++;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-- Test comparaison container list + const_iterator --" << std::endl;

		const std::list<char> list;
		
		std::list<char>::iterator	



	}
	return (0);
}
