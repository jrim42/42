#ifndef MAP_HPP
# define MAP_HPP

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

# include <functional>
# include <memory>
# include <utility> // pair header (tmp)
// # include "./pair.hpp"
# include "./random_access_iterator.hpp"
# include "./reverse_iterator.hpp"

namespace ft 
{
	template <typename U, typename V, class Compare = std::less<U>,
				class Allocator = std::allocator<std::pair<const U, V>>>
	class map 
	{
		private:
			// key_compare		_key;
			// value_compare	_val;

		public:
			// members

			// OCCF
				// map();
				// map(const map& m);
				// map&	operator=(const map& m);
				// ~map();

			// iterators (const & non-const)
				// begin
				// end
				// rbegin
				// rend

			// size
				// size
				// max_size
				// empty

			// accessor
				// []
				// at

			// modifiers
				// insert
				// erase
				// swap
				// clear

			// compare
				// key_comp
				// value_comp

			// functions
				// find
				// count
				// upper_bound
				// lower_bound
				// equal_range

			// allocator
				// get_allocator
	}; // end of class map

// comparison operator
// swap

} // end of namespace ft

#endif