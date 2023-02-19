#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <algorithm>
# include <limits>
# include <memory>
# include "./iterator_traits.hpp"
# include "./pair.hpp"
# include "./type_traits.hpp"

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

		rbnode*		_parent;
		rbnode*		_left;
		rbnode*		_right;
		value_type	_val;
		Color		_color;

		// constructor & destructor
		rbnode(void)
			: _parent(NULL), _left(NULL), _right(NULL), 
			  _val(value_type()), _color(BLACK) {}
		rbnode(const value_type& val)
			: _parent(NULL), _left(NULL), _right(NULL), 
			  _val(val), _color(BLACK) {}
		rbnode(const rbnode& ref)
			: _parent(ref._parent), _left(ref._left), _right(ref._right),
			  _val(ref._val), _color(ref._color) {}
		~rbnode(void) {}

		rbnode& operator=(const rbnode& ref) 
		{
			if (this != &ref) 
			{
				_parent = ref._parent;
				_left = ref._left;
				_right = ref._right;
				_val = ref._val;
				_color = ref._color;
			}
			return *this;
		}
	};

	template <class NodePtr>
	bool	getDirection(const NodePtr& ptr)
	{
		if (ptr == ptr->_parent->_left)
			return LEFT;
		else
			return RIGHT;
	}

	template <class NodePtr>
	bool	getColor(const NodePtr& ptr) 
	{
		if (ptr->_color == BLACK)
			return BLACK;
		else
			return RED;
	}

	template <class NodePtr>
	NodePtr getMinNode(NodePtr ptr, NodePtr nil) 
	{
		while (ptr->_left != nil) 
			ptr = ptr->_left;
		return ptr;
	}

	template <class NodePtr>
	NodePtr getMaxNode(NodePtr ptr, NodePtr nil) 
	{
		while (ptr->_right != nil) 
			ptr = ptr->_right;
		return ptr;
	}

	template <class NodePtr>
	NodePtr getNextNode(NodePtr ptr, NodePtr nil) 
	{
		if (ptr->_right != nil) 
			return getMinNode(ptr->_right, nil);
		while (getDirection(ptr) == RIGHT) 
			ptr = ptr->_parent;
		return ptr->_parent;
	}

	template <class NodePtr>
	NodePtr getPrevNode(NodePtr ptr, NodePtr nil) 
	{
		if (ptr->_left != nil) 
			return getMaxNode(ptr->_left, nil);
		while (getDirection(ptr) == LEFT) 
			ptr = ptr->_parent;
		return ptr->_parent;
	}

	template <typename U, typename V, class Comp>
	bool isEqual(const U& u, const V& v, Comp comp) 
	{
		return !comp(u, v) && !comp(v, u);
	}

	//============================ rbiter ============================//
	template <typename U, typename V>
	class rbiter 
	{
		public:
			typedef U 				value_type;
			typedef value_type*		pointer;
			typedef value_type&		reference;
			typedef V* 				iterator_type;

			typedef typename ft::iterator_traits<iterator_type>::difference_type 	difference_type;
			typedef typename ft::iterator_traits<iterator_type>::value_type 		node_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer 			node_pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference 			node_reference;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category 	iterator_category;

		private:
			node_pointer _cur;
			node_pointer _nil;

		public:
			// constructor & destructor
			rbiter(void) 
				: _cur(NULL), _nil(NULL) {}
			rbiter(node_pointer cur, node_pointer nil)
				: _cur(cur), _nil(nil) {}
			rbiter(const rbiter& i)
				: _cur(i._cur), _nil(i._nil) {}
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
			node_pointer	base(void) const 		{ return _cur; }
			pointer 		operator->(void) const 	{ return &_cur->_val; }
			reference 		operator*(void) const 	{ return _cur->_val; }

			// increment & decrement
			rbiter& operator++(void) 
			{
				_cur = getNextNode(_cur, _nil);
				return *this;
			}
			rbiter& operator--(void) 
			{
				_cur = getPrevNode(_cur, _nil);
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
			bool	operator==(const rbiter<T, node_type>& ite) const 
			{
				return _cur == ite.base();
			}
			template <typename T>
			bool	operator!=(const rbiter<T, node_type>& ite) const 
			{
				return !(*this == ite);
			}

			// utils
			operator	rbiter<const value_type, node_type>(void) const 
			{
				return rbiter<const value_type, node_type>(_cur, _nil);
			}
			friend bool	operator==(const rbiter& x, const rbiter& y)	{ return x._cur == y._cur;}
			friend bool	operator!=(const rbiter& x, const rbiter& y)	{ return !(x == y);}
	};

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
			node_pointer 	_begin;
			node_pointer 	_end;
			node_pointer	_nil;
			compare_type 	_comp;
			node_allocator 	_alloc;
			size_type 		_size;

		public:
			// constructor & destructor
			rbtree(const compare_type& comp, const allocator_type& alloc)
				: _comp(comp), _alloc(alloc), _size(size_type()) 
			{
				_nil = _alloc.allocate(1);
				_alloc.construct(_nil, value_type());
				_nil->_color = BLACK;
				_nil->_parent = _nil;
				_nil->_left = _nil;
				_nil->_right = _nil;
				_end = constructNode(value_type());
				_end->_color = BLACK;
				_begin = _end;
			}
			rbtree(const rbtree& ref)
				: _comp(ref._comp), _alloc(ref._alloc), _size(size_type()) 
			{
				_nil = _alloc.allocate(1);
				_alloc.construct(_nil, value_type());
				_nil->_color = BLACK;
				_nil->_parent = _nil;
				_nil->_left = _nil;
				_nil->_right = _nil;
				_end = constructNode(value_type());
				_end->_color = BLACK;
				_begin = _end;
				insert(ref.begin(), ref.end());
			}
			~rbtree(void) 
			{
				destructAll(_end);
				destructNode(_nil);
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
			iterator		begin(void) 		{ return iterator(_begin, _nil); }
			iterator 		end(void) 			{ return iterator(_end, _nil); }
			const_iterator 	begin(void) const 	{ return const_iterator(_begin, _nil); }
			const_iterator 	end(void) const 	{ return const_iterator(_end, _nil); }

			// size, max_size, empty
			size_type	size(void) const 		{ return _size; }
			size_type 	max_size(void) const 	{ return size_type(-1); }
			bool 		empty(void) const 		{ return _size == 0; }

			// modifiers: insert, erase
			ft::pair<iterator, bool>	insert(const value_type& val) 
			{
				node_pointer ptr = findParent(val);
				if (ptr != _end && isEqual(ptr->_val, val, _comp))
					return ft::make_pair(iterator(ptr, _nil), RED);
				return ft::make_pair(iterator(__insert(val, ptr), _nil), BLACK);
			}
			iterator	insert(iterator pos, const value_type& val) 
			{
				node_pointer ptr = findParent(val, pos.base());
				if (ptr != _end && isEqual(ptr->_val, val, _comp))
					return iterator(ptr, _nil);
				return iterator(__insert(val, ptr), _nil);
			}
			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last) 
			{
				for ( ; first != last ; first++)
					insert(*first);
			}
			
			iterator	erase(iterator pos) 
			{
				if (_size == 0)
					return iterator(_nil, _nil);
				iterator tmp(pos);
				++tmp;
				if (pos == begin())
					_begin = tmp.base();
				--_size;
				__remove(pos.base());
				destructNode(pos.base());
				return tmp;
			}
			template <typename U>
			size_type	erase(const U& val) 
			{
				iterator i(__find(val), _nil);
				if (i == end())
					return 0;
				if (i == begin()) 
				{
					iterator tmp(i);
					++tmp;
					_begin = tmp.base();
				}
				--_size;
				__remove(i.base());
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
				std::swap(_nil, t._nil);
				std::swap(_begin, t._begin);
				std::swap(_end, t._end);
				std::swap(_comp, t._comp);
				std::swap(_alloc, t._alloc);
				std::swap(_size, t._size);
			}
			void	clear(void) 
			{
				rbtree	tmp(_comp, _alloc);
				swap(tmp);
			}

			iterator 		find(const key_type& key) 				{ return iterator(__find(key), _nil); }
			const_iterator 	find(const key_type& key) const 		{ return const_iterator(__find(key), _nil); }
			iterator 		lower_bound(const key_type& key) 		{ return iterator(__lower_bound(key), _nil); }
			const_iterator 	lower_bound(const key_type& key) const 	{ return const_iterator(__lower_bound(key), _nil); }
			iterator 		upper_bound(const key_type& key) 		{ return iterator(__upper_bound(key), _nil); }
			const_iterator 	upper_bound(const key_type& key) const	{ return const_iterator(__upper_bound(key), _nil); }
			
			ft::pair<iterator, iterator> 				equal_range(const key_type& key) 		{ return __equal(key); }
			ft::pair<const_iterator, const_iterator>	equal_range(const key_type& key) const	{ return __equal(key); }

			// allocator
			allocator_type	get_allocator(void) const	{ return _alloc; }

		private:
			// root
			node_pointer	getRoot(void) const 
			{
				return _end->_left;
			}
			void	setRoot(const node_pointer ptr) 
			{
				ptr->_parent = _end;
				_end->_left = ptr;
			}

			// node constructor & destructor
			node_pointer 	constructNode(const value_type& val) 
			{
				node_pointer ptr = _alloc.allocate(1);
				_alloc.construct(ptr, val);
				ptr->_parent = _nil;
				ptr->_left = _nil;
				ptr->_right = _nil;
				ptr->_color = RED;
				return ptr;
			}
			void 	destructNode(node_pointer ptr) 
			{
				_alloc.destroy(ptr);
				_alloc.deallocate(ptr, 1);
			}
			void	destructAll(node_pointer ptr) 
			{
				if (ptr == _nil) {
				return;
				}
				destructAll(ptr->_left);
				destructAll(ptr->_right);
				destructNode(ptr);
			}

			node_pointer 	findParent(const value_type& val, node_pointer pos = NULL) 
			{
				if (pos && pos != _end) 
				{
					if (_comp(val, pos->_val) && pos->_left == _nil) 
					{
						iterator prev = iterator(pos, _nil);
						if (prev == begin() || _comp(*--prev, val))
							return pos;
					} 
					else if (pos->_right == _nil) 
					{
						iterator next = iterator(pos, _nil);
						if (next == end() || _comp(val, *++next))
							return pos;
					}
				}
				node_pointer	cur = getRoot();
				node_pointer	tmp = _end;
				for ( ; cur != _nil ; ) 
				{
					tmp = cur;
					if (_comp(val, cur->_val))
						cur = cur->_left;
					else if (_comp(cur->_val, val))
						cur = cur->_right;
					else
						return cur;
				}
				return tmp;
			}
			
			// insert
			node_pointer	__insert(const value_type& val, node_pointer parent) 
			{
				node_pointer	ptr = constructNode(val);
				if (parent == _end)
					setRoot(ptr);
				else if (_comp(val, parent->_val))
					parent->_left = ptr;
				else
					parent->_right = ptr;
				ptr->_parent = parent;
				__insertFix(ptr);

				if (_begin == _end || _comp(ptr->_val, _begin->_val))
					_begin = ptr;
				_size++;
				return ptr;
			}
			
			void	__insertFix(node_pointer ptr) 
			{
				while (getColor(ptr->_parent) == RED) 
				{
					if (getDirection(ptr->_parent) == LEFT) 
					{
						node_pointer	uncle = ptr->_parent->_parent->_right;
						__insertFix_uncle_right(ptr, uncle);
					} 
					else 
					{
						node_pointer	uncle = ptr->_parent->_parent->_left;
						__insertFix_uncle_left(ptr, uncle);
					}
				}
				getRoot()->_color = BLACK;
			}

			void	__insertFix_uncle_right(node_pointer ptr, node_pointer uncle) 
			{
				if (getColor(uncle) == RED) 
				{
					ptr->_parent->_color = BLACK;
					uncle->_color = BLACK;
					uncle->_parent->_color = RED;
					ptr = uncle->_parent;
				} 
				else 
				{
					if (getDirection(ptr) == RIGHT) 
					{
						ptr = ptr->_parent;
						__rotateLeft(ptr);
					}
					ptr->_parent->_color = BLACK;
					ptr->_parent->_parent->_color = RED;
					__rotateRight(ptr->_parent->_parent);
				}
			}

			void	__insertFix_uncle_left(node_pointer ptr, node_pointer uncle) 
			{
				if (getColor(uncle) == RED) 
				{
					ptr->_parent->_color = BLACK;
					uncle->_color = BLACK;
					uncle->_parent->_color = RED;
					ptr = uncle->_parent;
				} 
				else 
				{
					if (getDirection(ptr) == LEFT) 
					{
						ptr = ptr->_parent;
						__rotateRight(ptr);
					}
					ptr->_parent->_color = BLACK;
					ptr->_parent->_parent->_color = RED;
					__rotateLeft(ptr->_parent->_parent);
				}
			}

			// remove
			void	__remove(node_pointer ptr) 
			{
				node_pointer	recolor_node;
				node_pointer	fixup_node = ptr;
				bool 			origin_color = getColor(ptr);

				if (ptr->_left == _nil) 
				{
					recolor_node = ptr->_right;
					__transplant(ptr, ptr->_right);
				} 
				else if (ptr->_right == _nil) 
				{
					recolor_node = ptr->_left;
					__transplant(ptr, ptr->_left);
				} 
				else 
				{
					fixup_node = getMinNode(ptr->_right, _nil);
					origin_color = getColor(fixup_node);
					recolor_node = fixup_node->_right;
					if (fixup_node->_parent == ptr)
						recolor_node->_parent = fixup_node;
					else 
					{
						__transplant(fixup_node, fixup_node->_right);
						fixup_node->_right = ptr->_right;
						fixup_node->_right->_parent = fixup_node;
					}
					__transplant(ptr, fixup_node);
					fixup_node->_left = ptr->_left;
					fixup_node->_left->_parent = fixup_node;
					fixup_node->_color = getColor(ptr);
				}
				if (origin_color)
					__removeFix(recolor_node);
			}

			void 	__removeFix(node_pointer ptr) 
			{
				while (ptr != getRoot() && getColor(ptr) == BLACK) 
				{
					if (getDirection(ptr) == LEFT) 
					{
						node_pointer	sib = ptr->_parent->_right;
						ptr = __removeFix_sib_right(ptr, sib);
					} 
					else 
					{
						node_pointer	sib = ptr->_parent->_left;
						ptr = __removeFix_sib_left(ptr, sib);
					}
				}
				ptr->_color = BLACK;
			}

			node_pointer	__removeFix_sib_right(node_pointer ptr, node_pointer sib)
			{
				if (getColor(sib) == RED) 
				{
					sib->_color = BLACK;
					ptr->_parent->_color = RED;
					__rotateLeft(ptr->_parent);
					sib = ptr->_parent->_right;
				}
				if (getColor(sib->_left) == BLACK && getColor(sib->_right) == BLACK) 
				{
					sib->_color = RED;
					ptr = ptr->_parent;
				} 
				else if (getColor(sib->_right) == BLACK) 
				{
					sib->_left->_color = BLACK;
					sib->_color = RED;
					__rotateRight(sib);
					sib = ptr->_parent->_right;
				}
				if (getColor(sib->_right) == RED) 
				{
					sib->_color = getColor(ptr->_parent);
					ptr->_parent->_color = BLACK;
					sib->_right->_color = BLACK;
					__rotateLeft(ptr->_parent);
					ptr = getRoot();
				}
				return ptr;
			}

			node_pointer 	__removeFix_sib_left(node_pointer ptr, node_pointer sib)
			{
				if (getColor(sib) == RED) 
				{
					sib->_color = BLACK;
					ptr->_parent->_color = RED;
					__rotateRight(ptr->_parent);
					sib = ptr->_parent->_left;
				}
				if (getColor(sib->_right) == BLACK && getColor(sib->_left) == BLACK) 
				{
					sib->_color = RED;
					ptr = ptr->_parent;
				} 
				else if (getColor(sib->_left) == BLACK) 
				{
					sib->_right->_color = BLACK;
					sib->_color = RED;
					__rotateLeft(sib);
					sib = ptr->_parent->_left;
				}
				if (getColor(sib->_left) == RED) 
				{
					sib->_color = getColor(ptr->_parent);
					ptr->_parent->_color = BLACK;
					sib->_left->_color = BLACK;
					__rotateRight(ptr->_parent);
					ptr = getRoot();
				}
				return ptr;
			}

			// transplant
			void 	__transplant(node_pointer former, node_pointer latter) 
			{
				if (former->_parent == _end)
					setRoot(latter);
				else if (getDirection(former) == LEFT)
					former->_parent->_left = latter;
				else
					former->_parent->_right = latter;
				latter->_parent = former->_parent;
			}

			// rotate
			void 	__rotateLeft(node_pointer ptr) 
			{
				node_pointer child = ptr->_right;

				ptr->_right = child->_left;
				if (ptr->_right != _nil)
					ptr->_right->_parent = ptr;
				node_pointer parent = ptr->_parent;
				child->_parent = parent;
				if (parent == _end)
					setRoot(child);
				else if (getDirection(ptr) == LEFT)
					parent->_left = child;
				else
					parent->_right = child;
				child->_left = ptr;
				ptr->_parent = child;
			}
			void 	__rotateRight(node_pointer ptr) 
			{
				node_pointer child = ptr->_left;
				
				ptr->_left = child->_right;
				if (ptr->_left != _nil)
					ptr->_left->_parent = ptr;
				node_pointer parent = ptr->_parent;
				child->_parent = parent;
				if (parent == _end)
					setRoot(child);
				else if (getDirection(ptr) == LEFT)
					parent->_left = child;
				else
					parent->_right = child;
				child->_right = ptr;
				ptr->_parent = child;
			}

			// find: find, lower_bound, upper_bound
			template <typename U>
			node_pointer	__find(const U& val) const 
			{
				node_pointer	ptr = getRoot();

				while (ptr != _nil) 
				{
					if (_comp(val, ptr->_val))
						ptr = ptr->_left;
					else if (_comp(ptr->_val, val))
						ptr = ptr->_right;
					else
						return ptr;
				}
				return _end;
			}
			node_pointer	__lower_bound(const key_type& key) const 
			{
				node_pointer	ptr = getRoot();
				node_pointer	tmp = _end;

				while (ptr != _nil) {
				if (!_comp(ptr->_val, key)) {
					tmp = ptr;
					ptr = ptr->_left;
				} else {
					ptr = ptr->_right;
				}
				}
				return tmp;
			}
			node_pointer	__upper_bound(const key_type& key) const 
			{
				node_pointer	ptr = getRoot();
				node_pointer	tmp = _end;

				while (ptr != _nil)
				{
					if (_comp(key, ptr->_val)) 
					{
						tmp = ptr;
						ptr = ptr->_left;
					}
					else 
						ptr = ptr->_right;
				}
				return tmp;
			}
			
			template <typename U>
			ft::pair<iterator, iterator>	__equal(const U& val) 
			{
				node_pointer	ptr = getRoot();
				node_pointer	tmp = _end;

				while (ptr != _nil) 
				{
					if (_comp(val, ptr->_val)) 
					{
						tmp = ptr;
						ptr = ptr->_left;
					} 
					else if (_comp(ptr->_val, val))
						ptr = ptr->_right;
					else 
					{
						if (ptr->_right != _nil)
							tmp = getMinNode(ptr->_right, _nil);
						return ft::make_pair(iterator(ptr, _nil), iterator(tmp, _nil));
					}
				}
				return ft::make_pair(iterator(tmp, _nil), iterator(tmp, _nil));
			}
			template <typename U>
			ft::pair<const_iterator, const_iterator>	__equal(const U& val) const 
			{
				node_pointer	ptr = getRoot();
				node_pointer	tmp = _end;

				while (ptr != _nil) 
				{
					if (_comp(val, ptr->_val)) 
					{
						tmp = ptr;
						ptr = ptr->_left;
					} 
					else if (_comp(ptr->_val, val))
						ptr = ptr->_right;
					else 
					{
						if (ptr->_right != _nil)
							tmp = getMinNode(ptr->_right, _nil);
						return ft::make_pair(const_iterator(ptr, _nil), const_iterator(tmp, _nil));
					}
				}
				return ft::make_pair(const_iterator(tmp, _nil), const_iterator(tmp, _nil));
			}
	};
}  // namespace ft

#endif