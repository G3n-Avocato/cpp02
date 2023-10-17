/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:36:25 by lamasson          #+#    #+#             */
/*   Updated: 2023/10/17 22:00:52 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <exception>

class	Intern {

	public:
		Intern(void);
		Intern(const Intern &src);
		Intern&	operator=(const Intern &rhs);
		~Intern(void);

		AForm*	makeForm(const std::string name, const std::string target) const;
		
		class	FormFileException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
};

#endif
