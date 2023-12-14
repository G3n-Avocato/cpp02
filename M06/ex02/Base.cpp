/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 00:30:18 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/14 00:04:06 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base::~Base(void) {
}

Base*	Base::generate(void) {
	Base*	al = NULL;
	srand(time(NULL));
	int		nb = rand() %3 + 1;
	switch (nb) {
		case 1: {
			al = new A();
			std::cout << "Base class generate: A" << std::endl;
			break ;
		}
		case 2: {
			al = new B();
			std::cout << "Base class generate: B" << std::endl;
			break ;
		}
		case 3: {
			al = new C();
			std::cout << "Base class generate: C" << std::endl;
			break ;
		}
	}
	return (al);
}

void	Base::identify(Base* p) {
	A*	aa = dynamic_cast<A*>(p);
	if (aa != NULL) {
		std::cout << "Base class PTR: A" << std::endl;
		return ;
	}
	B*	bb = dynamic_cast<B*>(p);
	if (bb != NULL) {
		std::cout << "Base class PTR: B" << std::endl;
		return ;
	}
	C*	cc = dynamic_cast<C*>(p);
	if (cc != NULL) {
		std::cout << "Base class PTR: C" << std::endl;
		return ;
	}
}

void	Base::identify(Base& p) {
	try {
		A&	aa = dynamic_cast<A&>(p);
		(void)aa;
		std::cout << "Base class REF: A" << std::endl;
	}
	catch (std::exception &e) {
		try {
			B&	bb = dynamic_cast<B&>(p);
			(void)bb;
			std::cout << "Base class REF: B" << std::endl;
		}
		catch (std::exception &e) {
			try {
				C&	cc = dynamic_cast<C&>(p);
				(void)cc;
				std::cout << "Base class REF: C" << std::endl;
			}
			catch (std::exception &e) {
				std::cout << "No Conversion find for Base REF" << std::endl;
			}
		}
	}
}
