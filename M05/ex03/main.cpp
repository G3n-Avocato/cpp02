/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:29:09 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/17 22:11:09 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

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
		std::cout << "----- Test 2 -----" << std::endl;
		std::cout << std::endl;
		try {
				Bureaucrat Jo("Jo", 150);
	
				AForm	*Tu = new ShrubberyCreationForm("Lokroom");

				std::cout << Jo << std::endl;
				std::cout << *Tu << std::endl;
				Jo.signForm(*Tu);
				delete Tu ;
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
		std::cout << "----- Test 2.1 -----" << std::endl;
		std::cout << std::endl;
		try {
			Bureaucrat Yos("Yos", 151);
			AForm *Yu = new RobotomyRequestForm("Lokroom");

			std::cout << Yos << std::endl;
			std::cout << Yu << std::endl;
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
		std::cout << "----- Test 3 -----" << std::endl;
		std::cout << std::endl;
		try {
			Bureaucrat Boss("Boss", 1);
			AForm*	Su = new ShrubberyCreationForm("maison");
	
			Boss.signForm(*Su);
			std::cout << std::endl;
			Boss.executeForm(*Su);
			std::cout << std::endl;
			std::cout << *Su << std::endl;
			delete Su ;
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what();
		}
	}
	{
		std::cout << "----- Test 4 -----" << std::endl;
		std::cout << std::endl;
		try {
			Bureaucrat	Steve("Steve", 10);
			AForm*	Tu = new RobotomyRequestForm("saucisse");
	
			Steve.executeForm(*Tu);
			std::cout << std::endl;
			std::cout << *Tu << std::endl;
			Steve.signForm(*Tu);
			std::cout << std::endl;
			Steve.executeForm(*Tu);
			std::cout << std::endl;
			std::cout << *Tu << std::endl;
			delete Tu ;
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what();
		}
	}
	{
		std::cout << "----- Test 5 -----" << std::endl;
		std::cout << std::endl;
		try {
			
			Bureaucrat	Jules("Jules", 4);
			Bureaucrat	Ru("Ru", 25);
			AForm	*Wu = new PresidentialPardonForm("Rick");
			AForm	*Yu = new ShrubberyCreationForm("Wu");

			std::cout << *Wu << std::endl;
			std::cout << Jules << std::endl;
			std::cout << Ru << std::endl;
			Ru.signForm(*Wu);
			std::cout << std::endl;
			Jules.executeForm(*Wu);
			std::cout << std::endl;
			
			std::cout << *Yu << std::endl;
			*Yu = *Wu;

			std::cout << *Yu << std::endl;
			Jules.executeForm(*Yu);

			delete Wu ;
			delete Yu ;
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
		std::cout << "----- Test 6 -----" << std::endl;
		std::cout << std::endl;
		try {
			RobotomyRequestForm sau("usa");
			RobotomyRequestForm tau(sau);
			RobotomyRequestForm	tmp("no");
			Bureaucrat	You("You", 45);
			Bureaucrat	Rue("Rue", 72);

			std::cout << sau << std::endl;
			std::cout << tau << std::endl;
			std::cout << Rue << std::endl;
			Rue.signForm(tau);
			std::cout << sau << std::endl;
			std::cout << tau << std::endl;

			std::cout << You << std::endl;
			Rue = You;
			std::cout << Rue << std::endl;
			Rue.executeForm(tau);
			std::cout << std::endl;

			std::cout << tmp << std::endl;
			tmp = tau;
			std::cout << tmp << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what();
		}
	}
	{
		std::cout << "----- Test 7 -----" << std::endl;
		std::cout << std::endl;
		try {
			Intern	anybody;
			AForm*	form_list;

			Bureaucrat	You("You", 1);

			form_list = anybody.makeForm("robotomy request", "bender");
			std::cout << *form_list << std::endl;
			You.signForm(*form_list);
			std::cout << std::endl;
			You.executeForm(*form_list);
			
			delete form_list ;
		}
		catch (Intern::FormFileException& e) {
			std::cout << e.what();
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
		std::cout << "----- Test 7.1 -----" << std::endl;
		std::cout << std::endl;
		try {
			Intern	anybody;
			AForm*	form_list;

			Bureaucrat	You("You", 1);

			form_list = anybody.makeForm("shrubbery creation", "louvre");
			
			std::cout << *form_list << std::endl;
			You.signForm(*form_list);
			std::cout << std::endl;
			You.executeForm(*form_list);

			delete form_list ;
		}
		catch (Intern::FormFileException& e) {
			std::cout << e.what();
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
		std::cout << "----- Test 7.2 -----" << std::endl;
		std::cout << std::endl;
		try {
			Intern	anybody;
			AForm*	form_list;

			Bureaucrat	You("You", 1);

			form_list = anybody.makeForm("presidential pardon", "Rico");
			
			std::cout << *form_list << std::endl;
			You.signForm(*form_list);
			std::cout << std::endl;
			You.executeForm(*form_list);

			delete form_list ;
		}
		catch (Intern::FormFileException& e) {
			std::cout << e.what();
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
		std::cout << "----- Test 7.3 -----" << std::endl;
		std::cout << std::endl;
		try {
			Intern	anybody;
			AForm*	form_list;

			Bureaucrat	You("You", 1);

			form_list = anybody.makeForm("lettre de demition", "Boss lol");
			
			std::cout << *form_list << std::endl;
			You.signForm(*form_list);
			std::cout << std::endl;
			You.executeForm(*form_list);

			delete form_list ;
		}
		catch (Intern::FormFileException& e) {
			std::cout << e.what();
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
