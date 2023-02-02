#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <algorithm>
# include <memory>
# include <exception>
# include <stdexcept>

# include "./random_access_iterator.hpp"

# define T_RED "\033[0;31m"
# define T_GRN "\033[0;32m"
# define T_YLW "\033[0;33m"
# define T_BLU "\033[0;36m"
# define T_GRY "\033[90m"
# define T_DFT "\033[0;37m"

namespace ft
{
    // template <typename T, class Container = ft::vector<T>>
    template <typename T, typename Allocator = std::allocator<T>>
    class vector
    {
        private:
            iterator        _begin;
            iterator        _end;
            iterator        _cap_end;
            allocator_type  _alloc;

        public:
            typedef T           value_type;
            typedef Allocator   allocator_type;  

            typedef typename allocator_type::size_type       size_type;
            typedef typename allocator_type::difference_type difference_type;

            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            
            typedef ft::random_access_iterator<value_type>          iterator;
            typedef ft::random_access_iterator<const value_type>    const_iterator;
            typedef ft::reverse_iterator<iterator>                  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
            
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
                return (static_cast<size_type>(_end - _begin);)
            }
            size_type   max_size() const
            {
            }
            void        resize(size_type size)
            {
            }
            size_type   capacity() const
            {
                return (static_cast<size_type>(_cap_end - _begin);)
            }
            bool        empty()
            {
                if (_begin == _end)
                    return (true);
                return (false);
            }
            void        reserve(size_type size)
            {
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
            void        assign()
            {

            }

            void        push_back(value_type& val)
            {
            }

            void        push_back(const value_type& val)
            {

            }

            void        pop_back()
            {

            }

            iterator    insert(const_iterator pos, const value_type& x)
            {

            }

            iterator    insert(const_iterator pos, value_type& x)
            {

            }

            iterator    erase(const_iterator pos)
            {

            }

            iterator    erase(const_iterator begin, const_iterator end)
            {

            }

            void        swap(vector &v)
            {

            }

            void        clear()
            {

            }


            // allocator
            allocator_type get_allocator(void) const    { return _alloc; }
            
            // memory
                // _init
                // _construct
                // _destruct
    };
}  // end of namespace ft

// comparison operator
template <typename T, class Allocator>
bool    operator==(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y);

template <typename T, class Allocator>
bool    operator!=(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y);

template <typename T, class Allocator>
bool    operator>(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y);

template <typename T, class Allocator>
bool    operator>=(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y);

template <typename T, class Allocator>
bool     operator<(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y);

template <typename T, class Allocator>
bool    operator<=(const ft::vector<T, Allocator>& x, const ft::vector<T, Allocator>& y);

#endif