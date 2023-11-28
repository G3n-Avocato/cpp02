/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:02:41 by lamasson          #+#    #+#             */
/*   Updated: 2023/11/25 20:57:44 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<cstdlib>
#include<exception>

template<typename T>
class	Array {
	
	public:

		Array<T>(void);
		Array<T>(unsigned int n);
		Array<T>(const Array<T> &src);
		Array<T>	&operator=(const Array<T> &rhs);
		~Array<T>(void);
	
		T	&operator[](unsigned int pos) const;

		unsigned int const&	size(void) const { return this->_size; }

		class PosOutOfRange : public std::exception { 
				public: 
					virtual const char* what() const throw() { return ("std::exception: Index pos Out of Range\n"); }; 
		};
		
	private:

		unsigned int	_size;
		T				*_arr;
};

template<typename T>
Array<T>::Array(void) : _size(0), _arr(new T[_size]) {
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _arr(new T[n]) {
}

template<typename T>
Array<T>::Array(const Array<T> &src) {
	this->_size = 0;
	*this = src;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array<T> &rhs) {
	if (this != &rhs) {
		if (this->_size > 0)
			delete [] this->_arr;
		this->_size = rhs._size;
		this->_arr = new T[this->_size];
		for (int i = 0; static_cast<unsigned int>(i) < this->_size; i++)
			this->_arr[i] = rhs._arr[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array(void) {
	delete [] this->_arr;
}

template<typename T>
T	&Array<T>::operator[](unsigned int pos) const {
	if (pos >= this->_size) {
		throw PosOutOfRange();
	}
	return (this->_arr[pos]);
}
