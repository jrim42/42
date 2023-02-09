#ifndef RBNODE_HPP
# define RBNODE_HPP

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
# include "./iterator_traits.hpp"
# include "./type_traits.hpp"

namespace ft
{
    template <typename T>
    struct treeNode
    { 
        typedef T           value_type;
        typedef bool        Color;
        // typedef treeNode<T> Node;

        value_type  val;
        Color   	color;
        treeNode    *left;
        treeNode    *right;
        treeNode    *parent;
    
		// OCCF
		treeNode(void)
			: val(value_type()), color(B), left(NULL), right(NULL), parent(NULL) {}
		treeNode(const value_type& _val)
			: val(_val), color(B), left(NULL), right(NULL), parent(NULL) {}
		treeNode(const treeNode& ref)
			: val(ref.val), color(ref.color), left(ref.left), right(ref.right), parent(ref.parent) {}
		~treeNode(void) {}

		treeNode&	operator=(const treeNode& ref)
		{
			if (this != &ref)
			{
				val = ref.val;
				color = ref.color;
				right = ref.right;
				left = ref.left;
				parent = ref.parent;
			}
			return *this;
		}
	}; // end of treeNode
    // node 구조체 생성 후 색은 black으로 초기화, 모든 자식들은 0로 초기화

    template <typename U, typename V>
    class treeIter
    {
		public:
			typedef U 				value_type;
			typedef V* 				iterator_type;
			typedef value_type* 	pointer;
			typedef value_type& 	reference;

			typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename ft::iterator_traits<iterator_type>::value_type 		node_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer 			node_ptr;
			typedef typename ft::iterator_traits<iterator_type>::reference 			node_reference;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category 	iterator_category;
		
		private:
			node_ptr	_cur;
			node_ptr	_nil;

		public:
			// OCCF
			treeIter(void)
				: _cur(0), _nil(0) {}
			treeIter(node_ptr _cur, node_ptr _nil)
				: _cur(_cur), _nil(_nil) {}
			treeIter(const treeIter& ref)
				: _cur(ref._cur), _nil(ref._nil) {}
			~treeIter(void) {}

			treeIter& operator=(const treeIter& ref)
			{
				if (this != &ref)
				{
					_cur = ref._cur;
					_nil = ref._nil;
				}
				return *this;
			}

			// access
			node_ptr	base(void) const 		{ return _cur; }
			pointer 	operator->(void) const	{ return &_cur->val; }
			reference 	operator*(void) const	{ return _cur->val; }

            // 아직 안 함 // increment & decrement
            treeIter&   operator++(void) 
            {
                
            }
            treeIter&   operator--(void) 
            {

            }
            treeIter    operator++(int) 
            {

            }
            treeIter    operator--(int) 
            {

            }

    }; // end of treeIter
}

#endif