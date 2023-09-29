/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:29:53 by lamasson          #+#    #+#             */
/*   Updated: 2023/09/29 15:39:17 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

class	Bureaucrat {

	public:
        Bureaucrat(void);
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &src);
        Bureaucrat& operator=(Bureaucrat const &rhs);
        ~Bureaucrat(void);

		std::string	const getName(void) const ;
		int	getGrade(void) const ;

		void	upGrade() ;
		void	downGrade();
		void	signForm() const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
	private:
		std::string const	_name;
		int					_grade;
};

std::ostream    &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
