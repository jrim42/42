#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <algorithm>
# include <memory>
# include <exception>
# include <stdexcept>
# include <iostream>

# include "./compare.hpp"
# include "./random_access_iterator.hpp"
# include "./reverse_iterator.hpp"
# include "./iterator_traits.hpp"
# include "./type_traits"

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T		   										value_type;
			typedef Allocator   									allocator_type;  

			typedef typename std::size_t							size_type;
			typedef typename std::ptrdiff_t	 						difference_type;

			typedef value_type&								  		reference;
			typedef const value_type&								const_reference;
			typedef value_type*										pointer;
			typedef const value_type*						  		const_pointer;
			
			typedef ft::random_access_iterator<value_type>			iterator;
			typedef ft::random_access_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		private:
			pointer		 	_begin;
			pointer		 	_end;
			pointer		 	_c_end;
			allocator_type  _alloc;

		public:
			// constructor
			explicit vector(const allocator_type& alloc = allocator_type())
				: _begin(NULL), _end(NULL), _c_end(NULL), _alloc(alloc) {};
			explicit vector(size_type sz, const value_type& val = value_type(), 
							const allocator_type& alloc = allocator_type())
				: _alloc(alloc)
			{
				_initialize(sz);
				_construct(sz, val);
			};
			template < class iIter >
			vector(iIter first, iIter last, const allocator_type& alloc = allocator_type(),
				   typename ft::enable_if<!ft::is_integral<iIter>::value>::type* = NULL)
				: _alloc(alloc) 
			{
				size_type   sz = last - first;

				_begin = _alloc.allocate(sz);
				_c_end = _begin + sz;
				_end = _begin;
				while (sz--) 
					_construct(1, *first++);
			};
			vector(const vector& ref)
			{
				size_type   sz = ref.size();

				_initialize(ref.capacity());
				_construct(sz);
				std::copy(ref._begin, ref._end, _begin);
			}
			// destructor
			~vector(void) 
			{
				if (_begin == NULL)
					return ;
				_destruct(_begin);
				_alloc.deallocate(_begin, capacity());
			};
			// assignment operator
			vector&	operator=(const vector& ref)
			{
				if (this != &ref)
					assign(ref._begin, ref._end);
				return *this;
			}

			// iterators
			iterator				begin()		 	{ return iterator(_begin); }
			iterator				end()		   	{ return iterator(_end); }
			const_iterator			begin() const   { return const_iterator(_begin); }
			const_iterator			end() const	 	{ return const_iterator(_end); }
			reverse_iterator		rbegin()		{ return reverse_iterator(end()); }
			reverse_iterator		rend()			{ return reverse_iterator(begin()); }
			const_reverse_iterator  rbegin() const  { return const_reverse_iterator(end()); }
			const_reverse_iterator  rend() const	{ return const_reverse_iterator(begin()); }

			// size
			size_type   size() const
			{
				return static_cast<size_type>(_end - _begin);
			}
			size_type   max_size() const
			{
				return std::min<size_type>(_alloc.max_size(), size_type(-1) / sizeof(value_type));
			}
			void	resize(size_type sz, value_type val = value_type())
			{
				size_type	cs = size();

				if (cs < sz)
				{
					if (capacity() * 2 < sz)
						reserve(sz);
					else if	(capacity() < sz)
						reserve(capacity() * 2 > 0 ? capacity() * 2 : 1);
					std::uninitialized_fill(_end, _begin + sz, val);
					_end = _begin + sz;
				}
				else if (cs > sz) 
				{
					pointer	ptr = _begin + sz;
					_destruct(ptr);
					_end = _begin + sz;
				}
			}
			size_type   capacity() const
			{
				return static_cast<size_type>(_c_end - _begin);
			}
			bool	empty() const
			{
				return (_begin == _end);
			}
			void	reserve(size_type sz)
			{
				if (sz > max_size())
					throw std::out_of_range("Error: ft::vector: Out Of Range");
				if (capacity() >= sz)
					return ;

				pointer	 	pre_begin = _begin;
				pointer	 	pre_end = _end;
				size_type   pre_cap = capacity();

				_begin = _alloc.allocate(sz);
				_c_end = _begin + sz;
				_end = _begin;
				for (pointer ptr = pre_begin ; ptr != pre_end; ptr++)
					_alloc.construct(_end++, *ptr);
				for (size_type len = pre_end - pre_begin ; len > 0; len--)
					_alloc.destroy(--pre_end);
				_alloc.deallocate(pre_begin, pre_cap);
			}
			
			// // access operator
			reference		operator[](size_type n)		 	{ return _begin[n]; }
			const_reference	operator[](size_type n) const   { return _begin[n]; }
			reference	   	at(size_type n)
			{
				if (n >= size())
					throw std::out_of_range("Error: ft::vector: Out of Range");
				return (_begin[n]);
			}
			const_reference at(size_type n) const
			{
				if (n >= size())
					throw std::out_of_range("Error: ft::vector: Out of Range");
				return (_begin[n]);
			}
			reference	   	front()		 	{ return (*_begin); }
			reference	   	back()		  	{ return *(_end - 1); }
			const_reference front() const   { return (*_begin); }
			const_reference back() const	{ return *(_end - 1); }

			// modifiers
			template <class iIter>
			void	assign(iIter first, iIter last,
						   typename ft::enable_if<!ft::is_integral<iIter>::value>::type* = 0)
			{
				size_type	sz = std::distance(first, last);

				if (sz > capacity())
					reserve(sz);
				std::copy(first, last, _begin);
				_end = _begin + sz;
			}
			void 	assign(size_type sz, const value_type& val)
			{
				if (sz > capacity())
					reserve(sz);
				std::fill_n(_begin, sz, val);
				_end = _begin + sz;
			}
			void	push_back(const value_type& val)
			{
				if (_c_end == _end) 
				{
					size_type	capa = capacity() * 2 > 0 ? capacity() * 2 : 1;
					reserve(capa);
				}
				_construct(1, val);
			}
			void	pop_back(void)
			{
				_alloc.destroy(--_end);
			}

			// insert (value)
			iterator	insert(iterator pos, const value_type& val)
			{
				difference_type	diff = pos - begin();

				if (_c_end == _end) 
				{
					size_type	cap = capacity() * 2 > 0 ? capacity() * 2 : 1;
					reserve(cap);
				}
				if (capacity() < size() + 1) 
					reserve(size() + 1);
				pointer ptr = _begin + diff;
				_construct(1);
				std::copy_backward(ptr, _end - 1, _end);
				*ptr = val;
				return iterator(ptr);
			}
			// insert (fill)
			void	insert(iterator pos, size_type sz, const value_type& val)
			{
				difference_type	diff =  pos - begin();
				if (_c_end == _end) 
				{
					size_type	cap = capacity() * 2 > 0 ? capacity() * 2 : 1;
					reserve(cap);
				}
				if (capacity() < size() + sz)
					reserve(size() + sz);
				pointer ptr = _begin + diff;
				_construct(sz);
				std::copy_backward(ptr, _end - sz, _end);
				for (size_type i = 0; i < sz; i++)
					*(ptr + i) = val;
			}
			// insert (iter)
			template <class iIter>
			void	insert(const_iterator pos, iIter first, iIter last,
						typename ft::enable_if<!ft::is_integral<iIter>::value>::type* = NULL) 
			{
				size_type		n = size_type(last - first);
				difference_type	diff = pos - begin();
				if (_c_end == _end) 
				{
					size_type	cap = capacity() * 2 > 0 ? capacity() * 2 : 1;
					reserve(cap);
				}
				if (capacity() < size() + n)
					reserve(size() + n);
				pointer ptr = _begin + diff;
				_construct(n);
				std::copy_backward(ptr, _end - n, _end);
				for (iIter ite = first ; ite != last ; ite++, ptr++)
					*ptr = *ite;
			}

			// erase(value)
			iterator	erase(iterator pos) 
			{
				_alloc.destroy(pos.base());
				std::uninitialized_copy(pos.base() + 1, _end, pos.base());
				_alloc.destroy(_end--);
				return pos;
			}
			// erase(range)
			iterator	erase(iterator first, iterator last) 
			{
				pointer ptr = std::copy(last.base(), _end, first.base());
				while (ptr != _end)
					_alloc.destroy(ptr++);
				_end -= last - first;
				return first;
			}

			// swap
			void	swap(vector &v)
			{
				if (this == &v)
					return ;

				pointer	tmp_begin = _begin;
				pointer	tmp_end = _end;
				pointer	tmp_c_end = _c_end;

				_begin = v._begin;
				_end = v._end;
				_c_end = v._c_end;
				v._begin = tmp_begin;
				v._end = tmp_end;
				v._c_end = tmp_c_end;
			}

			void	clear()
			{
				_destruct(_begin);
			}

			// allocator
			allocator_type get_allocator(void) const	{ return _alloc; }

		// memory: init, construct, destruct
		private:
			void	_initialize(size_type sz)
			{
				if (sz > max_size())
					throw std::length_error("Error: ft::vector: Too Big Allocation");
				_begin = _alloc.allocate(sz);
				_end = _begin;
				_c_end = _begin + sz;
			}
			void	_construct(size_type sz)
			{
				while (sz--)
					_alloc.construct(_end++);
			}
			void	_construct(size_type sz, T val)
			{
				while (sz--)
					_alloc.construct(_end++, val);
			}
			void	_destruct(size_type sz)
			{
				while (sz--)
					_alloc.destroy(_end--);
			}
			void	_destruct(pointer ptr)
			{
				while (_end != ptr)
					_alloc.destroy(_end--);
			}
			void	_destruct(void)
			{
				if (_begin == NULL) 
					return ;
				pointer	ptr = _begin;

				while (ptr != _end)
					_alloc.destroy(ptr++);
				_alloc.deallocate(_begin, _c_end - _begin);
				_begin = NULL;
				_end = NULL;
				_c_end = NULL;
			}
	}; // end of class vector

	// comparison operator
	template <typename T, class Allocator>
	bool	operator==(const ft::vector<T, Allocator>& x, 
					   const ft::vector<T, Allocator>& y)
	{
		return (x.size() == y.size() &&
				ft::equal(x.begin(), x.end(), y.begin()));
	}

	template <typename T, class Allocator>
	bool	operator!=(const ft::vector<T, Allocator>& x, 
					   const ft::vector<T, Allocator>& y)
	{
		return !(x == y);
	}

	template <typename T, class Allocator>
	bool	operator<(const ft::vector<T, Allocator>& x, 
					   const ft::vector<T, Allocator>& y)
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <typename T, class Allocator>
	bool	operator<=(const ft::vector<T, Allocator>& x, 
					   const ft::vector<T, Allocator>& y)
	{
		return !(y < x);
	}

	template <typename T, class Allocator>
	bool	 operator>(const ft::vector<T, Allocator>& x, 
					   const ft::vector<T, Allocator>& y)
	{
		return !(x <= y);
	}

	template <typename T, class Allocator>
	bool	operator>=(const ft::vector<T, Allocator>& x, 
					   const ft::vector<T, Allocator>& y)
	{
		return !(x < y);
	}

	// swap
	template <typename T, class Allocator>
	void swap(ft::vector<T, Allocator>& x,
			  ft::vector<T, Allocator>& y) 
	{
		x.swap(y);
	}
}  // end of namespace ft

#endif