#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iterator>
# include "./iterator_traits.hpp"

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

namespace ft 
{
	template <typename T>
	class random_access_iterator: 
		public std::iterator<std::random_access_iterator_tag, T> 
	{
		private:
			pointer	_ptr;

		public:
			typedef T* 	iterator_type;
			
			typedef typename ft::iterator_traits<iterator_type>::value_type 		value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type 	difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer 			pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference 			reference;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category 	iterator_category;

			// constructor & destructor
			random_access_iterator(void): _ptr(ft::nil) {}
			random_access_iterator(T* pointer) : _ptr(pointer) {}
			template <typename U>
			random_access_iterator(const random_access_iterator<U>& ite) : _ptr(ite.base()) {}
			~random_access_iterator(void) {}

			// member functions
			template <typename U>
			random_access_iterator& operator=(const random_access_iterator<U>& ite) 
			{
				_ptr = ite.base();
				return *this;
			}

			iterator_type base(void) const 					{ return _ptr; }
			pointer operator->(void) const 					{ return _ptr; }
			reference operator*(void) const 				{ return *_ptr; }
			reference operator[](difference_type n) const	{ return _ptr[n]; }

			// increment & decrement
			random_access_iterator& operator++(void) 
			{
				++_ptr;
				return *this;
			}
			random_access_iterator& operator--(void) 
			{
				--_ptr;
				return *this;
			}
			random_access_iterator operator++(int) 
			{
				random_access_iterator	tmp(*this);
				++_ptr;
				return tmp;
			}
			random_access_iterator operator--(int) 
			{
				random_access_iterator	tmp(*this);
				--_ptr;
				return tmp;
			}

			// arithmetic operators
			random_access_iterator operator+(difference_type n) const 
			{
				return random_access_iterator(_ptr + n);
			}
			random_access_iterator operator-(difference_type n) const 
			{
				return random_access_iterator(_ptr - n);
			}
			random_access_iterator& operator+=(difference_type n) 
			{
				_ptr += n;
				return *this;
			}
			random_access_iterator& operator-=(difference_type n) 
			{
				_ptr -= n;
				return *this;
			}
	}; // end of class random_access_operator

	// comparison operators
	template <typename T1, typename T2>
	bool operator==(const random_access_iterator<T1>& a,
					const random_access_iterator<T2>& b) 
	{
		return a.base() == b.base();
	}

	template <typename T1, typename T2>
	bool operator!=(const random_access_iterator<T1>& a,
					const random_access_iterator<T2>& b) 
	{
		return a.base() != b.base();
	}

	template <typename T1, typename T2>
	bool operator>(const random_access_iterator<T1>& a,
				   const random_access_iterator<T2>& b) 
	{
		return a.base() > b.base();
	}

	template <typename T1, typename T2>
	bool operator>=(const random_access_iterator<T1>& a,
					const random_access_iterator<T2>& b) 
	{
		return a.base() >= b.base();
	}

	template <typename T1, typename T2>
	bool operator<(const random_access_iterator<T1>& a,
				   const random_access_iterator<T2>& b) 
	{
		return a.base() < b.base();
	}

	template <typename T1, typename T2>
	bool operator<=(const random_access_iterator<T1>& a,
					const random_access_iterator<T2>& b) 
	{
		return a.base() <= b.base();
	}

	// arithmetic operators
	template <typename T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n,
										const random_access_iterator<T>& ite) 
	{
		return random_access_iterator<T>(ite.base() + n);
	}

	template <typename T1, typename T2>
	typename random_access_iterator<T1>::difference_type operator-(const random_access_iterator<T1>& a,
																   const random_access_iterator<T2>& b) 
	{
		return a.base() - b.base();
	}
}  // end of namespace ft

#endif