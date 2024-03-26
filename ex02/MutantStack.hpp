/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:55:06 by acomet            #+#    #+#             */
/*   Updated: 2024/02/27 20:46:31 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <iterator>

template<typename T>
class	MutantStack : public std::stack<T>
{

public:

	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

	MutantStack(void) : std::stack<T>() {}
	MutantStack(const MutantStack<T> &src) : std::stack<T>() {
		*this = src;
	} 
	~MutantStack(void) {}
	MutantStack<T>	&operator=(MutantStack<T> const &src) {
		std::stack<T>::operator=(src);
		return *this;
	}

	iterator				begin(void);
	iterator				end(void);
	reverse_iterator		rbegin(void);
	reverse_iterator		rend(void);
	const_iterator			cbegin(void);
	const_iterator			cend(void);
	const_reverse_iterator	crbegin(void);
	const_reverse_iterator	crend(void);

};

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (std::stack<T>::c.end());
}

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin(void)
{
	return (std::stack<T>::c.rbegin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend(void)
{
	return (std::stack<T>::c.rend());
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cbegin(void)
{
	return (std::stack<T>::c.cbegin());
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cend(void)
{
	return (std::stack<T>::c.cend());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crbegin(void)
{
	return (std::stack<T>::c.crbegin());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crend(void)
{
	return (std::stack<T>::c.crend());
}



#endif