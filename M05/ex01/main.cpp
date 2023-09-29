/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:29:09 by lamasson          #+#    #+#             */
/*   Updated: 2023/09/29 15:36:44 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    {
        std::cout << std::endl;
        std::cout << "----- TEST 1 -----" << std::endl;
        std::cout << std::endl;
    
        try {
			Bureaucrat  Steve("Steve", 149);
			
			std::cout << Steve << std::endl;
			Steve.downGrade();
			std::cout << Steve << std::endl;
			Steve.downGrade();
			std::cout << Steve << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what();
		}

        std::cout << std::endl;
        std::cout << "----- TEST 1.2 -----" << std::endl;
        std::cout << std::endl;
    
		try {
			Bureaucrat  Robert("Robert", 0);

        	std::cout << Robert << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what();
		}

        std::cout << std::endl;
        std::cout << "----- TEST 1.3 -----" << std::endl;
        std::cout << std::endl;
		
		try {
			Bureaucrat  Alice;

        	std::cout << Alice << std::endl;
			Alice.downGrade();
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what();
		}

        std::cout << std::endl;
        std::cout << "----- TEST 1.4 -----" << std::endl;
        std::cout << std::endl;
		
		try {
			Bureaucrat  Saucisse("Sau", 3);

        	std::cout << Saucisse << std::endl;
			Saucisse.upGrade();
        	std::cout << Saucisse << std::endl;
			Saucisse.upGrade();
        	std::cout << Saucisse << std::endl;
			Saucisse.upGrade();
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what();
		}
    }
    {
        std::cout << std::endl;
        std::cout << "----- TEST 1.5 -----" << std::endl;
        std::cout << std::endl;
   
		try {
			Bureaucrat	Johny("Johny", 89);
        	Bureaucrat  Jeanne("Jeanne", 17);
        	Bureaucrat  Vee(Jeanne);

        	std::cout << Jeanne << std::endl;
        	std::cout << Vee << std::endl;

        	Jeanne.upGrade();
        	std::cout << Jeanne << std::endl;
        	std::cout << Vee << std::endl;
			Johny = Vee;
			std::cout << Johny << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what();
		}
	}
	


	{
		std::cout << std::endl;
        std::cout << "----- TEST 2.1 -----" << std::endl;
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
