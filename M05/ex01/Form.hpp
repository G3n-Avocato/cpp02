/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:02:49 by lamasson          #+#    #+#             */
/*   Updated: 2023/09/26 23:24:24 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>

class Form {
    
    public:
        
        Form(void);
        Form(std::string const name, int const Sign, int const Exec);
        Form(const Form &src);
        Form&   operator=(const Form &rhs);
        ~Form(void);

        void    beSigned(Bureaucrat const &src);

        std::string const getName(void) const;
        bool    getBool(void) const;
        int		getGradeSign(void) const;
        int		getGradeExec(void) const;

    private:

        std::string const _name;
        bool    _signed;
        const int   _gradeSign;
        const int   _gradeExec;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
        void    exceptionSign(void) const;
		void	exceptionExec(void) const;
};

std::ostream&   operator<<(std::ostream &o, Form const &rhs);

#endif
