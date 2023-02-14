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
    struct rbnode
    { 
        typedef T           value_type;
        typedef bool        Color;
        typedef rbnode<T> 	NodePtr;

        value_type  val;
        Color   	color;
        NodePtr		left;
        NodePtr		right;
        NodePtr		parent;
    
		// OCCF
		rbnode(void)
			: val(value_type()), color(B), left(NULL), right(NULL), parent(NULL) {}
		rbnode(const value_type& _val)
			: val(_val), color(B), left(NULL), right(NULL), parent(NULL) {}
		rbnode(const rbnode& ref)
			: val(ref.val), color(ref.color), left(ref.left), right(ref.right), parent(ref.parent) {}
		~rbnode(void) {}

		rbnode&	operator=(const rbnode& ref)
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

		static NodePtr	getNodeMin(NodePtr x)
		{
			while (x->left != 0)
				x = x->left;
			return x;
		}
		static NodePtr	getNodeMax(NodePtr x)
		{
			while (x->right != 0)
				x = x->right;
			return x;
		}
	}; // end of rbnode struct
    // node 구조체 생성 후 색은 black으로 초기화, 모든 자식들은 0로 초기화
}

#endif