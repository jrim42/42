#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <algorithm>
# include <memory>
# include <exception>
# include <stdexcept>

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
    template <typename T, class Allocator = std::allocator<T>>
    class vector
    {
        public:
            typedef T           value_type;
            typedef Allocator   allocator_type;  

            typedef typename std::size_t        size_type;
            typedef typename std::ptrdiff_t     difference_type;

            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            
            typedef ft::random_access_iterator<value_type>          iterator;
            typedef ft::random_access_iterator<const value_type>    const_iterator;
            typedef ft::reverse_iterator<iterator>                  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;

        private:
            iterator        _begin;
            iterator        _end;
            iterator        _c_end;
            allocator_type  _alloc;

        public:
            vector(const allocator_type& alloc = allocator_type())
            {
                //
            }
            vector(const vector& ref)
            {
                //
            }
            vector& operator=(const vector& ref)
            {
                if (this != &ref)
                    assign(v._begin, v._end);
            }
            ~vector(void) {};

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
            size_type   size() cosnt
            {
                return static_cast<size_type>(_end - _begin);
            }
            size_type   max_size() const
            {
                //
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
            bool        empty()
            {
                return (_begin == _end);
            }
            void        reserve(size_type _size)
            {
                if (_size <= size() || _size <= capacity())
                    return;
                if (_size < capacity() * 2)
                    _size = capacity() * 2;
                
                pointer begin = _alloc.allocate(_size);
                std::unintialized_copy(_begin, _end, begin);
                _destruct(_begin);
                _alloc.deallocate(_begin, capacity());
                _begin = begin;
                _end = _begin + size();
                _c_end = _begin + _size;

            }

            // access operator
                // data
            reference       operator[](size_type n)         { return _begin[n]; }
            const_reference operator[](size_type n) const   { return _begin[n]; }
            reference       at(size_type n)
            {
                if (n >= size())
                    throw std::out_of_range("Error: Out of Range");
                return (_begin[n]);
            }
            const_reference at(size_type n) const
            {
                if (n >= size())
                    throw std::out_of_range("Error: Out of Range");
                return (_begin[n]);
            }
            
            reference       front()         {return (*_begin);}
            const_reference front() const   {return (*_begin);}
            reference       back()          {return *(end - 1);}
            const_reference back() const    {return *(end - 1);}

            // modifiers
            template <class iIter>
            void	assign(iIter first, iIter last,
						   typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil))
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

            void	push_back(const value_type& val)
            {
				size_type	_size = size() + 1;
				if (capacity() < _size)
					reserve(_size);
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
                    throw std::lengh_error("Error: Allocation Size Too Big")
                _begin = _alloc.allocate();
                _end = _begin;
                _c_end = _begin + _size;
            }
            void    _construct(size_type _size)
            {
                for ( ; _size > 0; _end++, _size--)
                    _alloc.contruct(_end);
            }
            void    _construct(size_type _size, T _val)
            {
                for ( ; _size > 0; _end++, _size--)
                {
                    _alloc.contruct(_end);
                    *(_end) = _val;
                }
            }
            void    _destruct(size_type _size)
            {
                for ( ; _size > 0; _end++, _size--)
                    _alloc.destroy(_end);
            }
            void    _destruct(pointer ptr)
            {
                for ( ; _end != ptr && _end--; )
                    _alloc.destroy(_end);
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