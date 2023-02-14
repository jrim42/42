#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# define T_RED "\033[0;31m"
# define T_GRN "\033[0;32m"
# define T_YLW "\033[0;33m"
# define T_BLU "\033[0;36m"
# define T_GRY "\033[90m"
# define T_DFT "\033[0;37m"

#include <cstddef>
#include <iterator>

namespace ft 
{
    template <class Iterator>
    struct iterator_traits 
    {
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::iterator_category    iterator_category;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
    };

    template <typename T>
    struct iterator_traits<T*> 
    {
        typedef std::ptrdiff_t                      difference_type;
        typedef T                                   value_type;
        typedef T*                                  pointer;
        typedef T&                                  reference;
        typedef std::random_access_iterator_tag     iterator_category;
    };

    template <typename T>
    struct iterator_traits<const T*> 
    {
        typedef std::ptrdiff_t                      difference_type;
        typedef T                                   value_type;
        typedef const T*                            pointer;
        typedef const T&                            reference;
        typedef std::random_access_iterator_tag     iterator_category;
    };
}

#endif