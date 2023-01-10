#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <algorithm>
# include <initializer_list>
# include <memory>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

namespace ft
{
    // template <typename T, class Container = ft::vector<T>>
    template <typename T, typename Allocator = std::allocator<T>>
    class vector
    {
        private:

        public:
            typedef T                                        value_type;
            typedef Allocator                                allocator_type;  
            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::size_type       size_type;
            typedef typename allocator_type::difference_type difference_type;
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            
            typedef ft::random_access_iterator<value_type>          iterator;
            typedef ft::random_access_iterator<const value_type>    const_iterator;
            typedef ft::reverse_iterator<iterator>                  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
            
            vector();
            vector(const vector& ref);
            vector& operator=(const vector& ref);
            ~vector(void) {};
    };
}

#endif