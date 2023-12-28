/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:48:08 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/28 21:55:14 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator {
	public :
		TargetGenerator();
		~TargetGenerator();

		void	learnTargetType(ATarget*);
		void	forgetTargetType(std::string const&);
		ATarget*	createTarget(std::string const&);

	private :

		std::map<std::string, ATarget*>	_generator;

		TargetGenerator(const TargetGenerator&);
		TargetGenerator&	operator=(const TargetGenerator&);

};
