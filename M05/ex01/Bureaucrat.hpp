/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:29:53 by lamasson          #+#    #+#             */
/*   Updated: 2023/09/28 21:24:43 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Form;

class	Bureaucrat {

	public:
        Bureaucrat(void);
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &src);
        Bureaucrat& operator=(Bureaucrat const &rhs);
        ~Bureaucrat(void);

		std::string	const getName(void) const;
		int	getGrade(void) const;

		void	upGrade();
		void	downGrade();
		void	signForm(Form const &src) const;
		class	GradeTooHighException : public std::exeption {
			public:
				virtual const char* what() const throw();
		}
		class	GradeTooLowException : 

	private:
		std::string const	_name;
		int					_grade;

        void    exception(void);
        void    GradeTooHighException(void);
        void    GradeTooLowException(void);
};

std::ostream    &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif

// c'est la fonction sign de form qui appel la fontion besigned de bureaucrat, dnas les 2 exo il faut que je declare ma class dans la class mere, les try and catch doivent etre dans le main directement et non en tant que fonction membre 
