#ifndef MAP_HPP
# define MAP_HPP

# define T_RED "\033[0;31m"
# define T_GRN "\033[0;32m"
# define T_YLW "\033[0;33m"
# define T_BLU "\033[0;36m"
# define T_GRY "\033[90m"
# define T_DFT "\033[0;37m"

# include <functional>
# include <memory>
// # include <utility> // pair header (tmp)
# include "./pair.hpp"
# include "./rbtree.hpp"
# include "./random_access_iterator.hpp"
# include "./reverse_iterator.hpp"

namespace ft 
{
	template <typename U, typename V, class Compare = std::less<U>,
				class Allocator = std::allocator<std::pair<const U, V>>>
	class map 
	{
		typedef U						key_type;
		typedef V 						mapped_type;
		typedef ft::pair<const U, V>	value_type;
		typedef Compare 				key_compare;

		typedef Allocator													allocator_type;
		typedef typename allocator_type::template rebind<value_type>::other	type_allocator;
		typedef std::allocator_traits<type_allocator> 						type_traits;

		typedef typename allocator_type::reference       reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer         pointer;
		typedef typename allocator_type::const_pointer   const_pointer;

		typedef typename allocator_type::size_type       size_type;
		typedef typename allocator_type::difference_type difference_type;

		typedef typename ft::bst<value_type, key_type, value_compare, allocator_type>::iterator 		iterator;
		typedef typename ft::bst<value_type, key_type, value_compare, allocator_type>::const_iterator 	const_iterator;
		typedef ft::reverse_iterator<iterator> 			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> 	const_reverse_iterator;

		private:
			key_compare		key;
			value_compare	val;
			ft::rbtree<value_type, key_type, value_compare, allocator>	tree;

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
			iterator	find(const key_type& key) 
			{
				return _bst.find(key);
			}
			const_iterator	find(const key_type& key) const 
			{
				return _bst.find(key);
			}
			size_type	count(const key_type& key) const 
			{
				return !(find(key) == end());
			}
			iterator	lower_bound(const key_type& key) 
			{
				return _bst.lower_bound(key);
			}
			const_iterator	lower_bound(const key_type& key) const 
			{
				return _bst.lower_bound(key);
			}
			iterator 	upper_bound(const key_type& key) 
			{
				return _bst.upper_bound(key);
			}
			const_iterator	upper_bound(const key_type& key) const 
			{
				return _bst.upper_bound(key);
			}
			ft::pair<iterator, iterator>	equal_range(const key_type& key) 
			{
				return _bst.equal_range(key);
			}
			ft::pair<const_iterator, const_iterator>	equal_range(const key_type& key) const 
			{
				return _bst.equal_range(key);
			}

			// allocator
				// get_allocator
	}; // end of class map

// comparison operator
template <typename U, typename V, class Compare, class Allocator>
bool operator==(const ft::map<U, V, Compare, Allocator>& x,
                const ft::map<U, V, Compare, Allocator>& y) 
{
	return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
}

template <typename U, typename V, class Compare, class Allocator>
bool operator!=(const ft::map<U, V, Compare, Allocator>& x,
                const ft::map<U, V, Compare, Allocator>& y) 
{
	return !(x == y);
}

template <typename U, typename V, class Compare, class Allocator>
bool operator<(const ft::map<U, V, Compare, Allocator>& x,
               const ft::map<U, V, Compare, Allocator>& y) 
{
	// return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <typename U, typename V, class Compare, class Allocator>
bool operator<=(const ft::map<U, V, Compare, Allocator>& x,
                const ft::map<U, V, Compare, Allocator>& y) 
{
	return !(y < x);
}

template <typename U, typename V, class Compare, class Allocator>
bool operator>(const ft::map<U, V, Compare, Allocator>& x,
               const ft::map<U, V, Compare, Allocator>& y) 
{
	return y < x;
}

template <typename U, typename V, class Compare, class Allocator>
bool operator>=(const ft::map<U, V, Compare, Allocator>& x,
                const ft::map<U, V, Compare, Allocator>& y) 
{
	return !(x < y);
}

// swap
template <typename U, typename V, class Compare, class Allocator>
void swap(ft::map<U, V, Compare, Allocator>& x,
          ft::map<U, V, Compare, Allocator>& y) 
{
	// x.swap(y);
}

} // end of namespace ft

#endif