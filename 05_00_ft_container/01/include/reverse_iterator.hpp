/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:08:07 by jrim              #+#    #+#             */
/*   Updated: 2023/02/25 22:08:08 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "./iterator_traits.hpp"

namespace ft 
{
	template <class Iterator>
	class reverse_iterator 
	{
		private:
			Iterator	_ite;
		
		public:
			typedef Iterator										iterator_type;
			typedef ft::iterator_traits<iterator_type>				_iterator_traits;
			typedef typename _iterator_traits::value_type 			value_type;
			typedef typename _iterator_traits::difference_type 		difference_type;
			typedef typename _iterator_traits::iterator_category 	iterator_category;
			typedef typename _iterator_traits::pointer 				pointer;
			typedef typename _iterator_traits::reference 			reference;
		
			// constructor & destructor
			reverse_iterator(void) 
				: _ite(iterator_type()) {}
			reverse_iterator(iterator_type i) 
				: _ite(i) {}
			template <class _Up>
			reverse_iterator(const reverse_iterator<_Up>& i) 
				: _ite(i.base()) {}
			~reverse_iterator(void) {}

			// assignment operator
			template <class _Up>
			reverse_iterator& operator=(const reverse_iterator<_Up>& i) 
			{
				_ite = i.base();
				return *this;
			}

			// accessors
			iterator_type   base(void) const  { return _ite; }
			reference   operator*(void) const 
			{
				iterator_type	tmp = _ite;
				return *(--tmp);
			}
			reference   operator[](difference_type n) const 
			{
				return *(*this + n);
			}
			pointer operator->(void) const 
			{ 
				return &operator*(); 
			}
			
			// increment & decrement
			reverse_iterator& operator++(void) 
			{
				--_ite;
				return *this;
			}
			reverse_iterator& operator--(void) 
			{
				++_ite;
				return *this;
			}
			reverse_iterator operator++(int) 
			{
				reverse_iterator	tmp(*this);
				--_ite;
				return tmp;
			}
			reverse_iterator operator--(int) 
			{
				reverse_iterator	tmp(*this);
				++_ite;
				return tmp;
			}

			// arithmetic operators
			reverse_iterator operator+(difference_type n) const 
			{
				return reverse_iterator(_ite - n);
			}
			reverse_iterator operator-(difference_type n) const 
			{
				return reverse_iterator(_ite + n);
			}
			reverse_iterator& operator+=(difference_type n) 
			{
				_ite -= n;
				return *this;
			}
			reverse_iterator& operator-=(difference_type n) 
			{
				_ite += n;
				return *this;
			}
	}; // end of class reverse_iterator

	template <class Iterator>
	reverse_iterator<Iterator> operator+
		(typename reverse_iterator<Iterator>::difference_type n,
		 const reverse_iterator<Iterator>& ite) 
	{
		return reverse_iterator<Iterator>(ite.base() - n);
	}

	template <class Ite1, class Ite2>
	typename reverse_iterator<Ite1>::difference_type operator-
		(const reverse_iterator<Ite1>& x,
		 const reverse_iterator<Ite2>& y) 
	{
		return y.base() - x.base();
	}

	// comparison operators
	template <class Ite1, class Ite2>
	bool operator==(const reverse_iterator<Ite1>& x,
					const reverse_iterator<Ite2>& y) 
	{
		return x.base() == y.base();
	}

	template <class Ite1, class Ite2>
	bool operator!=(const reverse_iterator<Ite1>& x,
					const reverse_iterator<Ite2>& y) 
	{
		return x.base() != y.base();
	}

	template <class Ite1, class Ite2>
	bool operator<(const reverse_iterator<Ite1>& x,
				   const reverse_iterator<Ite2>& y) 
	{
		return x.base() > y.base();
	}

	template <class Ite1, class Ite2>
	bool operator<=(const reverse_iterator<Ite1>& x,
					const reverse_iterator<Ite2>& y) 
	{
		return x.base() >= y.base();
	}

	template <class Ite1, class Ite2>
	bool operator>(const reverse_iterator<Ite1>& x,
				   const reverse_iterator<Ite2>& y) 
	{
		return x.base() < y.base();
	}

	template <class Ite1, class Ite2>
	bool operator>=(const reverse_iterator<Ite1>& x,
					const reverse_iterator<Ite2>& y) 
	{
		return x.base() <= y.base();
	}
}  // end of namespace ft

#endif