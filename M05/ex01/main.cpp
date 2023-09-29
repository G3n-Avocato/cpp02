/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:29:09 by lamasson          #+#    #+#             */
/*   Updated: 2023/09/28 16:13:59 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    {
        std::cout << std::endl;
        std::cout << "----- TEST 1 -----" << std::endl;
        std::cout << std::endl;
    
        Bureaucrat  Steve("Steve", 150);
        Bureaucrat  Robert("Robert", 2);

        std::cout << Robert << std::endl;
        std::cout << Steve << std::endl;
        
        Robert.upGrade();

        std::cout << Robert << std::endl;
        std::cout << Steve << std::endl;

        Robert.upGrade();
        Steve.downGrade();

        std::cout << Steve << std::endl;
    }
    {
        std::cout << std::endl;
        std::cout << "----- TEST 2 -----" << std::endl;
        std::cout << std::endl;
    
        Bureaucrat  Alice;
        Bureaucrat  Jeanne("Jeanne", 17);
        Bureaucrat  Vee("Vee", 149);
        Bureaucrat  Johny("Johny", 176);

        std::cout << Alice << std::endl;
        std::cout << Jeanne << std::endl;
        std::cout << Vee << std::endl;
        std::cout << Johny << std::endl;

        Alice.downGrade();
        Vee = Jeanne;
        Jeanne.upGrade();
        
        std::cout << Alice << std::endl;
        std::cout << Jeanne << std::endl;
        std::cout << Vee << std::endl;
    }
	{
		std::cout << std::endl;
        std::cout << "----- TEST 3 -----" << std::endl;
        std::cout << std::endl;
    	
		Bureaucrat	Joseph("Joseph", 6);
		Bureaucrat	Steve("Steve", 5);
		Form	Aff("A56", 5, 5);

        std::cout << std::endl;
		Aff.beSigned(Joseph);
        std::cout << std::endl;
		Joseph.signForm(Aff);
        
		std::cout << std::endl;
		Aff.beSigned(Steve);
		Steve.signForm(Aff);
        std::cout << std::endl;
		
		std::cout << Joseph;
        std::cout << std::endl;

		std::cout << Steve;
        std::cout << std::endl;
		
		std::cout << Aff;
        std::cout << std::endl;
	}
	{
		std::cout << std::endl;
        std::cout << "----- TEST 4 -----" << std::endl;
        std::cout << std::endl;
    	
		Bureaucrat	Boss("Boss", 1);
		Form	Aff("C56", 1, 10);
		Form	Bff(Aff);

		std::cout << Bff;


	}
	return (0);
}
