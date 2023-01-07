#ifndef STACK_HPP
# define STACK_HPP

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

namespace ft
{
    template <typename T, class Container = ft::vector<T>>
    class stack
    {
        protected:
            container_type  c;

        public:
            typedef Container                                   container_type;
            typedef typename container_type::value_type         value_type;
            typedef typename container_type::reference          reference;
            typedef typename container_type::const_reference    const_reference;
            typedef typename container_type::size_type          size_type;

            // constructors and destructor
            // assignment operator
            // top, empty, size
            // push, pop
            // boolean operators
    }
}

#endif