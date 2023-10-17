/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:02:49 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/09 17:24:41 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
    
    public:

        AForm(void);
        AForm(std::string const name, int const Sign, int const Exec);
        AForm(const AForm &src);
        AForm&   operator=(const AForm &rhs);
        virtual ~AForm(void);

		void    beSigned(Bureaucrat const &src);
		virtual void	execute(Bureaucrat const &executor) const = 0;

        std::string const getName(void) const;
        bool    getBool(void) const;
        int		getGradeSign(void) const;
        int		getGradeExec(void) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class UnsignedFormException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

    private:

        std::string const _name;
        bool    _signed;
        const int   _gradeSign;
        const int   _gradeExec;
};

std::ostream&   operator<<(std::ostream &o, AForm const &rhs);

#endif
