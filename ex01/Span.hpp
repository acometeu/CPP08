/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:55:06 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 20:46:31 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPAN_HPP
#define SPAN_HPP

#include <iostream>

class	OutOfBoundsException : public std::exception
{
public:
	virtual const char	*what() const throw() {
		return ("Index is Out of Bound !"); }
};

class	NotEnoughSpaceException : public std::exception
{
public:
	virtual const char	*what() const throw() {
		return ("Not enough space !"); }
};

class	NotEnoughNumberException : public std::exception
{
public:
	virtual const char	*what() const throw() {
		return ("Not enough number !"); }
};

class	Span
{

public:

	Span(void);
	Span(unsigned int N);
	Span(Span const &src);
	~Span(void);
	Span	&operator=(Span const &src);
	int		operator[](unsigned int index) const;

	unsigned int	get_max(void) const;
	unsigned int	get_number(void) const;

	void 			addNumber(int new_nbr);
	unsigned int	shortestSpan(void) const;
	unsigned int	longestSpan(void) const;
	template<typename T>
	void 			addManyNumber(T const &src)
	{
		unsigned int    size = static_cast<unsigned int>(src.size());
		unsigned int    i = this->_number;

		if (size + this->_number > this->_max)
			throw NotEnoughSpaceException();
		this->_number += size;
		size += i;
		while (i < size)
		{
			this->_member[i] = src[i];
			i++;
		}
	}


private:

	unsigned int	_max;
	unsigned int	_number;
	int				*_member;

};

#endif