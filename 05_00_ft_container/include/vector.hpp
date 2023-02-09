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

# define T_RED "\033[0;31m"
# define T_GRN "\033[0;32m"
# define T_YLW "\033[0;33m"
# define T_BLU "\033[0;36m"
# define T_GRY "\033[90m"
# define T_DFT "\033[0;37m"

namespace ft
{
    template <typename T, class Allocator = std::allocator<T> >
    class vector
    {
        public:
            typedef T           value_type;
            typedef Allocator   allocator_type;  
            
            typedef typename allocator_type::template rebind<value_type>::other	type_allocator;
			typedef std::allocator_traits<type_allocator> 						type_traits;

            typedef typename std::size_t        size_type;
            typedef typename std::ptrdiff_t     difference_type;

            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            
            typedef ft::random_access_iterator<value_type>          iterator;
            typedef ft::random_access_iterator<const value_type>    const_iterator;
            typedef ft::reverse_iterator<iterator>                reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;

        private:
            pointer         _begin;
            pointer         _end;
            pointer         _c_end;
            allocator_type  _alloc;

        public:
            // OCCF
            explicit vector(const allocator_type& alloc = allocator_type())
                : _begin(NULL), _end(NULL), _c_end(NULL), _alloc(alloc) {};
            explicit vector(size_type _size, const value_type& value = value_type(), const allocator_type& alloc = allocator_type())
                : _alloc(alloc)
            {
                _init(_size);
                _construct(_size, value);
            };
			// template < class InputIterator >
			// vector(InputIterator first, InputIterator last,
			// 		const allocator_type& alloc = allocator_type(),
			// 		typename ft::enable_if<
			// 			!ft::is_integral< InputIterator >::value >::type* = ft::nil)
			// 	: _alloc(alloc) {
			// 	size_type n = last - first;
			// 	this->_begin = this->_alloc.allocate(n);
			// 	this->_c_end = this->_begin + n;
			// 	this->_end = this->_begin;
			// 	while (n--) this->_alloc.construct(this->_end++, *first++);
			// };
            vector(const vector& ref)
            {
                size_type   _size = ref.size();
                _init(ref.capacity());
                _construct(_size);
                std::copy(ref._begin, ref._end, _begin);
            }
            vector& operator=(const vector& ref)
            {
                if (this != &ref)
                    assign(ref._begin, ref._end);
                return *this;
            }
            ~vector(void) 
            {
                if (_begin == ft::nil)
                    return ;
                _destruct(_begin);
                _alloc.deallocate(_begin, capacity());
            };

            // iterators
            iterator                begin()         { return iterator(_begin); }
            iterator                end()           { return iterator(_end); }
            const_iterator          begin() const   { return const_iterator(_begin); }
            const_iterator          end() const     { return const_iterator(_begin); }
            
            reverse_iterator        rbegin()        { return reverse_iterator(end()); }
            reverse_iterator        rend()          { return reverse_iterator(end()); }
            const_reverse_iterator  rbegin() const  { return reverse_iterator(begin()); }
            const_reverse_iterator  rend() const    { return reverse_iterator(begin()); }

            // size
            size_type   size() const
            {
                return static_cast<size_type>(_end - _begin);
            }
            size_type   max_size() const
            {
                return std::min<size_type>
                    (std::numeric_limits<size_type>::max(), type_traits::max_size(type_allocator()));
            }
            void        resize(size_type _size, value_type _val = value_type())
            {
                size_type   diff;

                if (size() > _size)
                {
                    diff = size() - _size;
                    _destruct(diff);
                }
                else if (size() < _size)
                {
                    diff = _size - size();
                    if (capacity() < _size)
                        reserve(_size);
                    _construct(diff, _val);
                }
            }
            size_type   capacity() const
            {
                return static_cast<size_type>(_c_end - _begin);
            }
            bool    empty()
            {
                return (_begin == _end);
            }

            void        reserve(size_type _size)
            {
                if (_size > this->max_size())
                    throw std::out_of_range("Error: ft::vector: Out Of Range");
                if (this->capacity() >= _size)
                    return;

                pointer     pre_begin = this->_begin;
                pointer     pre_end = this->_end;
                size_type   pre_cap = this->capacity();

                this->_begin = this->_alloc.allocate(_size);
                this->_c_end = this->_begin + _size;
                this->_end = this->_begin;

                for (pointer ptr = pre_begin ; ptr != pre_end; ptr++)
                    this->_alloc.construct(this->_end++, *ptr);
                
                for (size_type len = pre_end - pre_begin ; len > 0; len--)
                    this->_alloc.destroy(--pre_end);
                
                this->_alloc.deallocate(pre_begin, pre_cap);
            }
            
            // // access operator
                // data
            reference       operator[](size_type n)         { return _begin[n]; }
            const_reference operator[](size_type n) const   { return _begin[n]; }
            reference       at(size_type n)
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
            
            reference       front()         {return (*_begin);}
            const_reference front() const   {return (*_begin);}
            reference       back()          {return *(_end - 1);}
            const_reference back() const    {return *(_end - 1);}

            // modifiers
            template <class iIter>
            void	assign(iIter first, iIter last,
						   typename ft::enable_if<!ft::is_integral<iIter>::value>::type* = 0)
            {
				size_type	_size = std::distance(first, last);
				if (capacity() < _size)
					reserve(_size);
				std::copy(first, last, _begin);
				_end = _begin + _size;
            }

			void 	assign(size_type _size, const value_type& _val)
			{
				if (capacity() < _size)
					reserve(_size);
				std::fill_n(_begin, _size, _val);
				_end = _begin + _size;
			}

            void	push_back(const value_type& _val)
            {
				if (this->_c_end == this->_end) 
				{
					size_type	capacity = (this->size() == 0) ? 1 : (this->_c_end - this->_begin) * 2;
					this->reserve(capacity);
				}
				// this->_alloc.construct(this->_end++, _val);
				// _alloc.construct(_end++, _val);
				_construct(1);
				*(_end - 1) = _val;
            }

            void	pop_back(void)
            {
				_destruct(1);
            }

            iterator	insert(const_iterator _pos, const value_type& _val)
            {
				size_type	diff = _pos - begin();
				if (capacity() < size() + 1)
					reserve(size() + 1);

				iterator	it = _begin + diff;
				_construct(1);
				std::copy_backward(it, _end - 1, _end);
				*it = _val;
				return it;
            }

            void	insert(const_iterator _pos, size_type _size, value_type& _val)
            {
				size_type	diff = _pos - begin();
				if (capacity() < size() + _size)
					reserve(size() + _size);

				iterator	it = _begin + diff;
				_construct(_size);
				std::copy_backward(it, _end - _size, _end);
				for (size_type i = 0; i < _size; i++)
					*(it + i) = _val;
            }

            iterator	erase(const_iterator _pos)
            {
				size_type   diff = _pos - begin();
                iterator    it = _begin + diff;
                std::copy(it + 1, _end, it);
                _destruct(1);
                return it;
            }

            iterator	erase(const_iterator first, const_iterator last)
            {
                size_type   _size = std::distance(first, last);
                std::copy(last, end(), first);
                _destruct(_size);
                return first;
            }

            void	swap(vector &v)
            {
                std::swap(_begin, v._begin);
                std::swap(_end, v._end);
                std::swap(_c_end, v._c_end);
                std::swap(_alloc, v._alloc);

            }

            void	clear()
            {
                _destruct(_begin);
            }

            // allocator
            allocator_type get_allocator(void) const    { return _alloc; }

        // memory: init, construct, destruct
        private:
            void    _init(size_type _size)
            {
                if (_size > max_size())
                    throw std::length_error("Error: ft::vector: Too Big Allocation");
                _begin = _alloc.allocate(_size);
                _end = _begin;
                _c_end = _begin + _size;
            }
            void    _construct(size_type _size)
            {
				while (_size--)
                    _alloc.construct(_end++);
            }
            void    _construct(size_type _size, T _val)
            {
				while (_size--)
                    _alloc.construct(_end++, _val);
            }
            void    _destruct(size_type _size)
            {
				while (_size--)
                    _alloc.destroy(_end++);
            }
            void    _destruct(pointer ptr)
            {
				while (_end != ptr)
                    _alloc.destroy(_end--);
            }
    }; // end of class vector

    // comparison operator
    template <typename T, class Allocator>
    bool    operator==(const ft::vector<T, Allocator>& x, 
                    const ft::vector<T, Allocator>& y)
    {
        return (x.size() == y.size() &&
                ft::equal(x.begin(), x.end(), y.begin()));
    }

    template <typename T, class Allocator>
    bool    operator!=(const ft::vector<T, Allocator>& x, 
                    const ft::vector<T, Allocator>& y)
    {
        return !(x == y);
    }

    template <typename T, class Allocator>
    bool    operator<(const ft::vector<T, Allocator>& x, 
                    const ft::vector<T, Allocator>& y)
    {
        return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
    }

    template <typename T, class Allocator>
    bool    operator<=(const ft::vector<T, Allocator>& x, 
                    const ft::vector<T, Allocator>& y)
    {
        return (x == y || x < y);
    }

    template <typename T, class Allocator>
    bool     operator>(const ft::vector<T, Allocator>& x, 
                    const ft::vector<T, Allocator>& y)
    {
        return !(x <= y);
    }

    template <typename T, class Allocator>
    bool    operator>=(const ft::vector<T, Allocator>& x, 
                    const ft::vector<T, Allocator>& y)
    {
        return (x == y || x > y);
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