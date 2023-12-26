/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:47:05 by lamasson          #+#    #+#             */
/*   Updated: 2023/12/26 15:57:47 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	BitcoinExchange::_parsingInputFile(std::string data) {
	size_t			i = 0;
	size_t			pos = data.find("\n", i);
	std::string		tmp = data.substr(i, pos - i);

	if (!tmp.compare("date | value"))
		i = pos + 1;
	while (i < data.size()) {
		pos = data.find("\n", i);
		if (pos != std::string::npos) {
			tmp = data.substr(i, pos - i);
			this->_parsinglineFile(tmp);
			i = pos + 1;
		}
		else
			break ;
	}
}

