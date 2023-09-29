/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:29:09 by lamasson          #+#    #+#             */
/*   Updated: 2023/09/29 15:31:56 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
        std::cout << "----- TEST 2 -----" << std::endl;
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
	return (0);
}
