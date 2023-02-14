#ifndef RBITER_HPP
# define RBITER_HPP

# define T_RED "\033[0;31m"
# define T_GRN "\033[0;32m"
# define T_YLW "\033[0;33m"
# define T_BLU "\033[0;36m"
# define T_GRY "\033[90m"
# define T_DFT "\033[0;37m"

# define R 1
# define B 0

# include <iostream>
# include <memory>
# include "./pair.hpp"
# include "./rbnode.hpp"
# include "./iterator_traits.hpp"
# include "./type_traits.hpp"

namespace ft
{
    template <typename U, typename V>
    class rbiter
    {
		public:
			typedef U 				value_type;
			typedef V* 				iterator_type;
			typedef value_type* 	pointer;
			typedef value_type& 	reference;

			typedef typename ft::rbnode<value_type>*	NodePtr;
			// typedef typename ft::iterator_traits<iterator_type>::pointer 			ndoe_ptr;
			// typedef typename ft::iterator_traits<iterator_type>::value_type 		node_type;
			// typedef typename ft::iterator_traits<iterator_type>::reference 			node_reference;
			// typedef typename ft::iterator_traits<iterator_type>::iterator_category 	iterator_category;
			// typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
		
		private:
			NodePtr	_node;
			NodePtr	_cur;
			NodePtr	_nil;

		public:
			// OCCF
			rbiter(void)
				: _cur(0), _nil(0) {}
			rbiter(NodePtr _cur, NodePtr _nil)
				: _cur(_cur), _nil(_nil) {}
			rbiter(const rbiter& ref)
				: _cur(ref._cur), _nil(ref._nil) {}
			~rbiter(void) {}

			rbiter& operator=(const rbiter& ref)
			{
				if (this != &ref)
				{
					_cur = ref._cur;
					_nil = ref._nil;
				}
				return *this;
			}

			// access
			NodePtr		base(void) const 		{ return _cur; }
			pointer 	operator->(void) const	{ return &_cur->val; }
			reference 	operator*(void) const	{ return _cur->val; }

            // 아직 안 함 // increment & decrement
            void	_increase_rbiter(void)
			{
				if (_node->right != 0) 
				{
					_node = _node->right;
					while (_node->left != 0)
						_node = _node->left;
				}
				else 
				{
					NodePtr tmp = _node->parent;
					while (_node == tmp->right) 
					{
						_node = tmp;
						tmp = tmp->parent;
					}
					if (_node->right != tmp)
						_node = tmp;
				}
			}
			void	_decrease_rbiter(void)
			{
				if (_node->color == R &&
					_node->parent->parent == _node)
					_node = _node->right;
				else if (_node->left != 0) 
				{
					NodePtr tmp = _node->left;
					while (tmp->right != 0)
						tmp = tmp->right;
					_node = tmp;
				}
				else 
				{
					NodePtr tmp = _node->parent;
					while (_node == tmp->left) 
					{
						_node = tmp;
						tmp = tmp->parent;
					}
					_node = tmp;
				}
			}
            rbiter&	operator++(void) 
            {
                _increase_rbiter();
				return *this;
            }
            rbiter&	operator--(void) 
            {
				_decrease_rbiter();
				return *this;
            }
            rbiter	operator++(int) 
            {
				rbiter	tmp = *this;
                _increase_rbiter();
				return tmp;
            }
            rbiter	operator--(int) 
            {
				rbiter	tmp = *this;
                _decrease_rbiter();
				return tmp;
            }

			bool operator==(const rbiter& a, const rbiter& b)
			{
				return a._node == b._node;
			}
			bool operator==(const rbiter& a, const rbiter& b)
			{
				return a._node != b._node;
			}
    }; // end of rbiter
}

#endif