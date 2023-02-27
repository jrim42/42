/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:08:02 by jrim              #+#    #+#             */
/*   Updated: 2023/02/25 22:08:02 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <algorithm>
# include <limits>
# include <memory>

# include "./utility.hpp"

# define RED	false
# define BLACK	true

# define LEFT	false
# define RIGHT	true

namespace ft 
{
	//============================ rbnode ============================//
	template <typename T>
	struct rbnode 
	{
		typedef T		value_type;
		typedef bool	Color;

		value_type		_n_val;
		Color			_n_color;
		rbnode<T>*		_n_parent;
		rbnode<T>*		_n_left;
		rbnode<T>*		_n_right;

		// constructor & destructor
		rbnode(void)
			: _n_val(value_type()), _n_color(Color()),
			  _n_parent(NULL), _n_left(NULL), _n_right(NULL) {}
		rbnode(const value_type& val)
			: _n_val(val), _n_color(Color()),
			  _n_parent(NULL), _n_left(NULL), _n_right(NULL) {}
		rbnode(const rbnode& ref)
			: _n_val(ref._n_val), _n_color(ref._n_color), 
 			  _n_parent(ref._n_parent), _n_left(ref._n_left), _n_right(ref._n_right) {}
		~rbnode(void) {}

		rbnode& operator=(const rbnode& ref) 
		{
			if (this != &ref) 
			{
				_n_val = ref._n_val;
				_n_color = ref._n_color;
				_n_parent = ref._n_parent;
				_n_left = ref._n_left;
				_n_right = ref._n_right;
			}
			return *this;
		}
	}; // end of struct rbnode

	//============================ rbiter ============================//
	template <typename U, typename V>
	class rbiter 
	{
		public:

			typedef U 				value_type;
			typedef value_type*		pointer;
			typedef value_type&		reference;
			typedef V* 				iterator_type;

			typedef ft::iterator_traits<iterator_type>				_iterator_traits;
			typedef typename _iterator_traits::iterator_category 	iterator_category;
			typedef typename _iterator_traits::value_type 			node_type;
			typedef typename _iterator_traits::pointer 				node_pointer;
			typedef typename _iterator_traits::reference 			node_reference;
			typedef typename _iterator_traits::difference_type 		difference_type;

		private:
			node_pointer _n_cur;
			node_pointer _n_nil;

		public:
			// constructor & destructor
			rbiter(void) 
				: _n_cur(NULL), _n_nil(NULL) {}
			rbiter(node_pointer cur, node_pointer nil)
				: _n_cur(cur), _n_nil(nil) {}
			rbiter(const rbiter& ref)
				: _n_cur(ref._n_cur), _n_nil(ref._n_nil) {}
			~rbiter(void) {}

			rbiter& operator=(const rbiter& ref) 
			{
				if (this != &ref) 
				{
					_n_cur = ref._n_cur;
					_n_nil = ref._n_nil;
				}
				return *this;
			}

			// access
			node_pointer	base(void) const 		{ return _n_cur; }
			pointer 		operator->(void) const 	{ return &_n_cur->_n_val; }
			reference 		operator*(void) const 	{ return _n_cur->_n_val; }

			// increment & decrement
			rbiter&	operator++(void) 
			{
				_n_cur = getNextNode(_n_cur, _n_nil);
				return *this;
			}
			rbiter& operator--(void) 
			{
				_n_cur = getPrevNode(_n_cur, _n_nil);
				return *this;
			}
			rbiter operator++(int) 
			{
				rbiter	tmp(*this);

				++(*this);
				return tmp;
			}
			rbiter operator--(int) 
			{
				rbiter	tmp(*this);
				
				--(*this);
				return tmp;
			}

			// comparison operator
			template <typename T>
			bool	operator==(const rbiter<T, node_type>& ite) const 	{ return _n_cur == ite.base(); }
			template <typename T>
			bool	operator!=(const rbiter<T, node_type>& ite) const 	{ return !(*this == ite); }

			// utils
			operator	rbiter<const value_type, node_type>(void) const 
			{
				return rbiter<const value_type, node_type>(_n_cur, _n_nil);
			}
			friend bool	operator==(const rbiter& x, const rbiter& y)	{ return x._n_cur == y._n_cur;}
			friend bool	operator!=(const rbiter& x, const rbiter& y)	{ return !(x == y);}
	}; // end of class rbiter

	//============================ utils ============================//
	template <class NodePtr>
	bool	getDirection(const NodePtr& ptr)
	{
		if (ptr == ptr->_n_parent->_n_left)
			return LEFT;
		else
			return RIGHT;
	}

	template <class NodePtr>
	bool	getColor(const NodePtr& ptr) 
	{
		if (ptr->_n_color == BLACK)
			return BLACK;
		else
			return RED;
	}

	template <class NodePtr>
	NodePtr getMinNode(NodePtr ptr, NodePtr nil) 
	{
		while (ptr->_n_left != nil) 
			ptr = ptr->_n_left;
		return ptr;
	}

	template <class NodePtr>
	NodePtr getMaxNode(NodePtr ptr, NodePtr nil) 
	{
		while (ptr->_n_right != nil) 
			ptr = ptr->_n_right;
		return ptr;
	}

	template <class NodePtr>
	NodePtr getNextNode(NodePtr ptr, NodePtr nil) 
	{
		if (ptr->_n_right != nil) 
			return getMinNode(ptr->_n_right, nil);
		while (getDirection(ptr) == RIGHT) 
			ptr = ptr->_n_parent;
		return ptr->_n_parent;
	}

	template <class NodePtr>
	NodePtr getPrevNode(NodePtr ptr, NodePtr nil) 
	{
		if (ptr->_n_left != nil) 
			return getMaxNode(ptr->_n_left, nil);
		while (getDirection(ptr) == LEFT) 
			ptr = ptr->_n_parent;
		return ptr->_n_parent;
	}

	template <typename U, typename V, class Comp>
	bool	isEqual(const U& u, const V& v, Comp comp) 
	{
		return !comp(u, v) && !comp(v, u);
	}

	//============================ rbtree ============================//
	template <typename T, class Key, class Comp, class Allocator>
	class rbtree 
	{
		public:
			typedef T 		value_type;
			typedef Key 	key_type;
			typedef Comp 	compare_type;

			typedef rbnode<value_type> 						node_type;
			typedef rbnode<value_type>* 					node_pointer;
			typedef rbiter<value_type, node_type>			iterator;
			typedef rbiter<const value_type, node_type> 	const_iterator;
			typedef std::size_t 							size_type;
			typedef std::ptrdiff_t 							difference_type;

			typedef Allocator 													allocator_type;
			typedef typename allocator_type::template rebind<node_type>::other	node_allocator;

		private:
			node_pointer 	_t_root;
			node_pointer 	_t_leaf;
			node_pointer	_n_nil;
			compare_type 	_t_comp;
			node_allocator 	_t_alloc;
			size_type 		_t_size;

		public:
			// constructor & destructor
			rbtree(const compare_type& comp, const allocator_type& alloc)
				: _t_comp(comp), _t_alloc(alloc), _t_size(size_type()) 
			{
				_n_nil = _t_alloc.allocate(1);
				_t_alloc.construct(_n_nil, value_type());
				_n_nil->_n_color = BLACK;
				_n_nil->_n_parent = _n_nil;
				_n_nil->_n_left = _n_nil;
				_n_nil->_n_right = _n_nil;
				_t_leaf = constructNode(value_type());
				_t_leaf->_n_color = BLACK;
				_t_root = _t_leaf;
			}
			rbtree(const rbtree& ref)
				: _t_comp(ref._t_comp), _t_alloc(ref._t_alloc), _t_size(size_type()) 
			{
				_n_nil = _t_alloc.allocate(1);
				_t_alloc.construct(_n_nil, value_type());
				_n_nil->_n_color = BLACK;
				_n_nil->_n_parent = _n_nil;
				_n_nil->_n_left = _n_nil;
				_n_nil->_n_right = _n_nil;
				_t_leaf = constructNode(value_type());
				_t_leaf->_n_color = BLACK;
				_t_root = _t_leaf;
				insert(ref.begin(), ref.end());
			}
			~rbtree(void) 
			{
				destructAll(_t_leaf);
				destructNode(_n_nil);
			}

			rbtree& operator=(const rbtree& ref) 
			{
				if (this != &ref) 
				{
					rbtree tmp(ref);
					swap(tmp);
				}
				return *this;
			}

			// iterator
			iterator		begin(void) 			{ return iterator(_t_root, _n_nil); }
			iterator 		end(void) 				{ return iterator(_t_leaf, _n_nil); }
			const_iterator 	begin(void) const 		{ return const_iterator(_t_root, _n_nil); }
			const_iterator 	end(void) const 		{ return const_iterator(_t_leaf, _n_nil); }

			// size, max_size, empty
			size_type		size(void) const 		{ return _t_size; }
			size_type 		max_size(void) const 	{ return size_type(-1); }
			bool 			empty(void) const 		{ return _t_size == 0; }

			// modifiers: insert, erase
			ft::pair<iterator, bool>	insert(const value_type& val) 
			{
				node_pointer ptr = findParent(val);
				if (ptr != _t_leaf && isEqual(ptr->_n_val, val, _t_comp))
					return ft::make_pair(iterator(ptr, _n_nil), RED);
				return ft::make_pair(iterator(__insert(val, ptr), _n_nil), BLACK);
			}
			iterator	insert(iterator pos, const value_type& val) 
			{
				node_pointer ptr = findParent(val, pos.base());
				if (ptr != _t_leaf && isEqual(ptr->_n_val, val, _t_comp))
					return iterator(ptr, _n_nil);
				return iterator(__insert(val, ptr), _n_nil);
			}
			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last) 
			{
				for ( ; first != last ; first++)
					insert(*first);
			}
			
			iterator	erase(iterator pos) 
			{
				if (_t_size == 0)
					return iterator(_n_nil, _n_nil);
				iterator tmp(pos);
				++tmp;
				if (pos == begin())
					_t_root = tmp.base();
				--_t_size;
				__delete(pos.base());
				destructNode(pos.base());
				return tmp;
			}
			template <typename U>
			size_type	erase(const U& val) 
			{
				iterator i(__find(val), _n_nil);
				if (i == end())
					return 0;
				if (i == begin()) 
				{
					iterator tmp(i);
					++tmp;
					_t_root = tmp.base();
				}
				--_t_size;
				__delete(i.base());
				destructNode(i.base());
				return 1;
			}
			void	erase(iterator first, iterator last) 
			{
				for ( ; first != last ; )
					first = erase(first);
			}
			
			void	swap(rbtree& t) 
			{
				if (this == &t)
					return ;
				std::swap(_n_nil, t._n_nil);
				std::swap(_t_root, t._t_root);
				std::swap(_t_leaf, t._t_leaf);
				std::swap(_t_comp, t._t_comp);
				std::swap(_t_alloc, t._t_alloc);
				std::swap(_t_size, t._t_size);
			}
			void	clear(void) 
			{
				rbtree	tmp(_t_comp, _t_alloc);
				swap(tmp);
			}

			iterator 		find(const key_type& key) 				{ return iterator(__find(key), _n_nil); }
			const_iterator 	find(const key_type& key) const 		{ return const_iterator(__find(key), _n_nil); }
			iterator 		lower_bound(const key_type& key) 		{ return iterator(__lower_bound(key), _n_nil); }
			const_iterator 	lower_bound(const key_type& key) const 	{ return const_iterator(__lower_bound(key), _n_nil); }
			iterator 		upper_bound(const key_type& key) 		{ return iterator(__upper_bound(key), _n_nil); }
			const_iterator 	upper_bound(const key_type& key) const	{ return const_iterator(__upper_bound(key), _n_nil); }
			
			ft::pair<iterator, iterator> 				equal_range(const key_type& key) 		{ return __equal(key); }
			ft::pair<const_iterator, const_iterator>	equal_range(const key_type& key) const	{ return __equal(key); }

			// allocator
			allocator_type	get_allocator(void) const	{ return _t_alloc; }

		private:
			// root
			node_pointer	getRoot(void) const 
			{
				return _t_leaf->_n_left;
			}
			void	setRoot(const node_pointer ptr) 
			{
				ptr->_n_parent = _t_leaf;
				_t_leaf->_n_left = ptr;
			}

			// node constructor & destructor
			node_pointer 	constructNode(const value_type& val) 
			{
				node_pointer ptr = _t_alloc.allocate(1);

				_t_alloc.construct(ptr, val);
				ptr->_n_parent = _n_nil;
				ptr->_n_left = _n_nil;
				ptr->_n_right = _n_nil;
				ptr->_n_color = RED;
				return ptr;
			}
			void 	destructNode(node_pointer ptr) 
			{
				_t_alloc.destroy(ptr);
				_t_alloc.deallocate(ptr, 1);
			}
			void	destructAll(node_pointer ptr) 
			{
				if (ptr == _n_nil)
					return;
				destructAll(ptr->_n_left);
				destructAll(ptr->_n_right);
				destructNode(ptr);
			}

			node_pointer 	findParent(const value_type& val, node_pointer pos = NULL) 
			{
				if (pos && pos != _t_leaf) 
				{
					if (_t_comp(val, pos->_n_val) && pos->_n_left == _n_nil) 
					{
						iterator prev = iterator(pos, _n_nil);
						if (prev == begin() || _t_comp(*--prev, val))
							return pos;
					} 
					else if (pos->_n_right == _n_nil) 
					{
						iterator next = iterator(pos, _n_nil);
						if (next == end() || _t_comp(val, *++next))
							return pos;
					}
				}
				node_pointer	cur = getRoot();
				node_pointer	tmp = _t_leaf;
				for ( ; cur != _n_nil ; ) 
				{
					tmp = cur;
					if (_t_comp(val, cur->_n_val))
						cur = cur->_n_left;
					else if (_t_comp(cur->_n_val, val))
						cur = cur->_n_right;
					else
						return cur;
				}
				return tmp;
			}
			
			// insert
			node_pointer	__insert(const value_type& val, node_pointer parent) 
			{
				node_pointer	ptr = constructNode(val);

				if (parent == _t_leaf)
					setRoot(ptr);
				else if (_t_comp(val, parent->_n_val))
					parent->_n_left = ptr;
				else
					parent->_n_right = ptr;
				ptr->_n_parent = parent;
				__insertFix(ptr);

				if (_t_root == _t_leaf || _t_comp(ptr->_n_val, _t_root->_n_val))
					_t_root = ptr;
				_t_size++;
				return ptr;
			}
			
			void	__insertFix(node_pointer ptr) 
			{
				while (getColor(ptr->_n_parent) == RED) 
				{
					if (getDirection(ptr->_n_parent) == LEFT) 
					{
						node_pointer	uncle = ptr->_n_parent->_n_parent->_n_right;

						if (getColor(uncle) == RED) 
						{
							ptr->_n_parent->_n_color = BLACK;
							uncle->_n_color = BLACK;
							uncle->_n_parent->_n_color = RED;
							ptr = uncle->_n_parent;
						} 
						else 
						{
							if (getDirection(ptr) == RIGHT) 
							{
								ptr = ptr->_n_parent;
								__rotateLeft(ptr);
							}
							ptr->_n_parent->_n_color = BLACK;
							ptr->_n_parent->_n_parent->_n_color = RED;
							__rotateRight(ptr->_n_parent->_n_parent);
						}
					} 
					else 	// getDirection(ptr->_n_parent) == RIGHT
					{
						node_pointer	uncle = ptr->_n_parent->_n_parent->_n_left;

						if (getColor(uncle) == RED) 
						{
							ptr->_n_parent->_n_color = BLACK;
							uncle->_n_color = BLACK;
							uncle->_n_parent->_n_color = RED;
							ptr = uncle->_n_parent;
						} 
						else 
						{
							if (getDirection(ptr) == LEFT) 
							{
								ptr = ptr->_n_parent;
								__rotateRight(ptr);
							}
							ptr->_n_parent->_n_color = BLACK;
							ptr->_n_parent->_n_parent->_n_color = RED;
							__rotateLeft(ptr->_n_parent->_n_parent);
						}
					}
				}
				getRoot()->_n_color = BLACK;
			}

			// delete
			void	__delete(node_pointer ptr) 
			{
				node_pointer	recolor_node;
				node_pointer	fixup_node = ptr;
				bool 			origin_n_color = getColor(ptr);

				if (ptr->_n_left == _n_nil) 
				{
					recolor_node = ptr->_n_right;
					__transplant(ptr, ptr->_n_right);
				} 
				else if (ptr->_n_right == _n_nil) 
				{
					recolor_node = ptr->_n_left;
					__transplant(ptr, ptr->_n_left);
				} 
				else 
				{
					fixup_node = getMinNode(ptr->_n_right, _n_nil);
					origin_n_color = getColor(fixup_node);
					recolor_node = fixup_node->_n_right;
					if (fixup_node->_n_parent == ptr)
						recolor_node->_n_parent = fixup_node;
					else 
					{
						__transplant(fixup_node, fixup_node->_n_right);
						fixup_node->_n_right = ptr->_n_right;
						fixup_node->_n_right->_n_parent = fixup_node;
					}
					__transplant(ptr, fixup_node);
					fixup_node->_n_left = ptr->_n_left;
					fixup_node->_n_left->_n_parent = fixup_node;
					fixup_node->_n_color = getColor(ptr);
				}
				if (origin_n_color)
					__deleteFix(recolor_node);
			}

			void 	__deleteFix(node_pointer ptr) 
			{
				while (ptr != getRoot() && getColor(ptr) == BLACK) 
				{
					if (getDirection(ptr) == LEFT) 
					{
						node_pointer	sib = ptr->_n_parent->_n_right;

						if (getColor(sib) == RED) 
						{
							sib->_n_color = BLACK;
							ptr->_n_parent->_n_color = RED;
							__rotateLeft(ptr->_n_parent);
							sib = ptr->_n_parent->_n_right;
						}
						if (getColor(sib->_n_left) == BLACK && getColor(sib->_n_right) == BLACK) 
						{
							sib->_n_color = RED;
							ptr = ptr->_n_parent;
						} 
						else if (getColor(sib->_n_right) == BLACK) 
						{
							sib->_n_left->_n_color = BLACK;
							sib->_n_color = RED;
							__rotateRight(sib);
							sib = ptr->_n_parent->_n_right;
						}
						if (getColor(sib->_n_right) == RED) 
						{
							sib->_n_color = getColor(ptr->_n_parent);
							ptr->_n_parent->_n_color = BLACK;
							sib->_n_right->_n_color = BLACK;
							__rotateLeft(ptr->_n_parent);
							ptr = getRoot();
						}
					} 
					else 	// getDirection(ptr) == RIGHT
					{
						node_pointer	sib = ptr->_n_parent->_n_left;

						if (getColor(sib) == RED) 
						{
							sib->_n_color = BLACK;
							ptr->_n_parent->_n_color = RED;
							__rotateRight(ptr->_n_parent);
							sib = ptr->_n_parent->_n_left;
						}
						if (getColor(sib->_n_right) == BLACK && getColor(sib->_n_left) == BLACK) 
						{
							sib->_n_color = RED;
							ptr = ptr->_n_parent;
						} 
						else if (getColor(sib->_n_left) == BLACK) 
						{
							sib->_n_right->_n_color = BLACK;
							sib->_n_color = RED;
							__rotateLeft(sib);
							sib = ptr->_n_parent->_n_left;
						}
						if (getColor(sib->_n_left) == RED) 
						{
							sib->_n_color = getColor(ptr->_n_parent);
							ptr->_n_parent->_n_color = BLACK;
							sib->_n_left->_n_color = BLACK;
							__rotateRight(ptr->_n_parent);
							ptr = getRoot();
						}
					}
				}
				ptr->_n_color = BLACK;
			}

			// transplant
			void 	__transplant(node_pointer former, node_pointer latter) 
			{
				if (former->_n_parent == _t_leaf)
					setRoot(latter);
				else if (getDirection(former) == LEFT)
					former->_n_parent->_n_left = latter;
				else
					former->_n_parent->_n_right = latter;
				latter->_n_parent = former->_n_parent;
			}

			// rotate
			void 	__rotateLeft(node_pointer ptr) 
			{
				node_pointer child = ptr->_n_right;

				ptr->_n_right = child->_n_left;
				if (ptr->_n_right != _n_nil)
					ptr->_n_right->_n_parent = ptr;

				node_pointer parent = ptr->_n_parent;
				
				child->_n_parent = parent;
				if (parent == _t_leaf)
					setRoot(child);
				else if (getDirection(ptr) == LEFT)
					parent->_n_left = child;
				else
					parent->_n_right = child;
				child->_n_left = ptr;
				ptr->_n_parent = child;
			}
			void 	__rotateRight(node_pointer ptr) 
			{
				node_pointer child = ptr->_n_left;
				
				ptr->_n_left = child->_n_right;
				if (ptr->_n_left != _n_nil)
					ptr->_n_left->_n_parent = ptr;

				node_pointer parent = ptr->_n_parent;
				
				child->_n_parent = parent;
				if (parent == _t_leaf)
					setRoot(child);
				else if (getDirection(ptr) == LEFT)
					parent->_n_left = child;
				else
					parent->_n_right = child;
				child->_n_right = ptr;
				ptr->_n_parent = child;
			}

			// find, lower_bound, upper_bound
			template <typename U>
			node_pointer	__find(const U& val) const 
			{
				node_pointer	ptr = getRoot();

				while (ptr != _n_nil) 
				{
					if (_t_comp(val, ptr->_n_val))
						ptr = ptr->_n_left;
					else if (_t_comp(ptr->_n_val, val))
						ptr = ptr->_n_right;
					else
						return ptr;
				}
				return _t_leaf;
			}
			node_pointer	__lower_bound(const key_type& key) const 
			{
				node_pointer	ptr = getRoot();
				node_pointer	tmp = _t_leaf;

				while (ptr != _n_nil) 
				{
					if (!_t_comp(ptr->_n_val, key))
					{
						tmp = ptr;
						ptr = ptr->_n_left;
					} 
					else
						ptr = ptr->_n_right;
				}
				return tmp;
			}
			node_pointer	__upper_bound(const key_type& key) const 
			{
				node_pointer	ptr = getRoot();
				node_pointer	tmp = _t_leaf;

				while (ptr != _n_nil)
				{
					if (_t_comp(key, ptr->_n_val)) 
					{
						tmp = ptr;
						ptr = ptr->_n_left;
					}
					else 
						ptr = ptr->_n_right;
				}
				return tmp;
			}
			
			template <typename U>
			ft::pair<iterator, iterator>	__equal(const U& val) 
			{
				node_pointer	ptr = getRoot();
				node_pointer	tmp = _t_leaf;

				while (ptr != _n_nil) 
				{
					if (_t_comp(val, ptr->_n_val)) 
					{
						tmp = ptr;
						ptr = ptr->_n_left;
					} 
					else if (_t_comp(ptr->_n_val, val))
						ptr = ptr->_n_right;
					else 
					{
						if (ptr->_n_right != _n_nil)
							tmp = getMinNode(ptr->_n_right, _n_nil);
						return ft::make_pair(iterator(ptr, _n_nil), iterator(tmp, _n_nil));
					}
				}
				return ft::make_pair(iterator(tmp, _n_nil), iterator(tmp, _n_nil));
			}

			template <typename U>
			ft::pair<const_iterator, const_iterator>	__equal(const U& val) const 
			{
				node_pointer	ptr = getRoot();
				node_pointer	tmp = _t_leaf;

				while (ptr != _n_nil) 
				{
					if (_t_comp(val, ptr->_n_val)) 
					{
						tmp = ptr;
						ptr = ptr->_n_left;
					} 
					else if (_t_comp(ptr->_n_val, val))
						ptr = ptr->_n_right;
					else 
					{
						if (ptr->_n_right != _n_nil)
							tmp = getMinNode(ptr->_n_right, _n_nil);
						return ft::make_pair(const_iterator(ptr, _n_nil), const_iterator(tmp, _n_nil));
					}
				}
				return ft::make_pair(const_iterator(tmp, _n_nil), const_iterator(tmp, _n_nil));
			}
	}; // end of class rbtree
}  // namespace ft

#endif