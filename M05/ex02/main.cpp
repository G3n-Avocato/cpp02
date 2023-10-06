/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:29:09 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/02 19:37:08 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
    
		try {
			Bureaucrat	Joseph("Joseph", 6);
			Bureaucrat	Steve("Steve", 5);
			AForm	Aff("A56", 5, 5);

			std::cout << Joseph;
			std::cout << Steve;
			std::cout << Aff;
			Aff.beSigned(Joseph);
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what();
		}
		catch (AForm::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (AForm::GradeTooLowException& e) {
			std::cout << e.what();
		}
		
	}
	{
	std::cout << std::endl;
        std::cout << "----- TEST 2.2 -----" << std::endl;
        std::cout << std::endl;
    		
		try {
			Bureaucrat	Boss("Boss", 1);
			AForm	Aff("C56", 1, 10);
			AForm	Bff(Aff);

			std::cout << Bff;
			std::cout << Aff;
			std::cout << Boss;
			Bff.beSigned(Boss);
			std::cout << Aff;
			Aff = Bff;
			std::cout << Aff;

		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what();
		}
		catch (AForm::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (AForm::GradeTooLowException& e) {
			std::cout << e.what();
		}
	}
	{
	std::cout << std::endl;
        std::cout << "----- TEST 2.3 -----" << std::endl;
        std::cout << std::endl;
    		
		try {

			AForm	Aff;
	
			std::cout << Aff;
			AForm	Bff("WH.56", 0, 5);

			std::cout << Bff;

		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what();
		}
		catch (AForm::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (AForm::GradeTooLowException& e) {
			std::cout << e.what();
		}
	}
	{
	std::cout << std::endl;
        std::cout << "----- TEST 2.4 -----" << std::endl;
        std::cout << std::endl;
    		
		try {

			AForm	Aff;
			Bureaucrat	Assist("Assist", 1);
	
			std::cout << Aff;
			Aff.beSigned(Assist);
			std::cout << Aff;

			AForm	Bff("WH.56", 5, 0);
			AForm	Cff("WH.57", 151, 1);

			std::cout << Bff;

		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what();
		}
		catch (AForm::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (AForm::GradeTooLowException& e) {
			std::cout << e.what();
		}
	}
	return (0);
}
