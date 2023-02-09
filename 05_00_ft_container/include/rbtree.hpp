#ifndef RBTREE_HPP
# define RBTREE_HPP

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

# include "./rbnode.hpp"

namespace ft 
{
    template <typename T, typename Key, typename Comp, typename Allocator>
    class rbtree
    {
		public: 
			typedef T       value_type;
			typedef Key     key_type;
			typedef Comp    compare_type;

			typedef treeNode<value_type>                    node_type;
			typedef treeNode<value_type>*                   NodePtr;
			typedef treeIter<value_type, node_type>         iterator;
			typedef treeIter<const value_type, node_type>   const_iterator;

			typedef Allocator                                                   allocator_type;
			typedef typename allocator_type::template rebind<node_type>::other  node_allocator;
			typedef std::allocator_traits<node_allocator>                       node_traits;

			typedef std::size_t         size_type;
			typedef std::ptrdiff_t      difference_type;

        private:    
			NodePtr			_begin;
			NodePtr			_end;
            NodePtr			_nil;
			compare_type	_comp;
			allocator_type	_alloc;
			size_type 		_size;

            // key 값이 있는지 검사하는 함수
            NodePtr isKey(T _key)
            {
                NodePtr ptr = _begin;
                NodePtr parent = NULL;

                while (ptr != NULL && ptr->key != _key)
                {
                    parent = ptr;
                    ptr = (parent->key > _key) ? parent->left : parent->right;
                }
                return (ptr);
            }

            // 삽입 함수
            void    insert(T _key)
            {
                NodePtr a = this->_begin;
                NodePtr b = 0;
                NodePtr c = new Node<T>();

                c->key = _key;
                c->color = R;
                c->parent = 0;
                c->left = this->tail;
                c->right = this->tail;

                // BST의 일반 삽입 연산
                while (a != this->tail)
                {
                    b = a;
                    a = (a->key < _key) ? a->right : a->left;
                }
                c->parent = b;

                if (b == 0)
                    this->_begin = c;
                else if (c->key > b->key)
                    b->right = c;
                else
                    b->left = c;

                // c가 _begin node라면
                if (c->parent == 0)
                {
                    c->color = B;
                    return ;
                }
                // c의 부모노드가 _begin라면 fix up 필요없이 red로 붙여주면 된다.
                if (c->parent->parent != 0)
                    this->insertFix(c);
                return ;
            }

            // 삽입 후 규칙이 깨졌을 경우 재조정하는 함수
            void    insertFix(NodePtr n)
            {
                // _begin 노드가 아니고 부모노드의 색이 red라면
                while (n != this->_begin && n->parent->color == R)
                {
                    NodePtr gp = n->parent->parent;
                    NodePtr u = (n->parent == gp->left) ? gp->right : gp->left;
                    bool    side = (n->parent == gp->left) ? true : false; // 왼쪽이면 1, 오른쪽이면 0

                    // case 1
                    if (u && u->color == R)
                    {
                        n->parent->color = B;
                        u->color = B;
                        gp->color = R;
                        n = gp;
                    }
                    // case 2
                    else
                    {
                        // side == true: n의 부모노드는 n의 조부모노드의 왼쪽 자식이다.
                        // side == false: n의 부모노드는 n의 조부모노드의 오른쪽 자식이다.
                        if (n == (side ? n->parent->right : n->parent->left))
                        {
                            n = n->parent;
                            side ? this->rotateLeft(n) : this->rotateRight(n);
                        }
                        n->parent->color = B;
                        gp->color = R;
                        side ? this->rotateRight(gp) : this->rotateLeft(gp);
                    }
                }
                this->_begin->color = B;
            }

            // 삭제 함수
            bool    erase(T _key)
            {
                NodePtr z = isKey(_key);
                
                if (!z)
                    return (false);
                else
                {
                    NodePtr x;
                    NodePtr y;
                    Color   originalColor = z->color;

                    // 자식이 없거나 1개인 경우 삭제할 노드 z가 Black이면 double Red이므로 fix
                    if (z->left == this->tail)
                    {
                        x = z->right;
                        transplant(z, z->right);
                    }
                    else if (z->right == this->tail)
                    {
                        x = z->left;
                        transplant(z, z->left);
                    }
                    else
                    {
                        y = getMin(z->right);
                        originalColor = y->color;
                        x = y->right;   // y의 왼쪽 자식은 없다.
                        if (y->parent == z) // z의 오른쪽 자식이 가장 작은 key
                            x->parent = y;  // x가 tail일 때, fix하게 될 때 사용
                        else
                        {
                            transplant(y, y->right);
                            y->right = z->right;
                            y->right->parent = y;
                        }
                        transplant(z, y);
                        y->left = z->left;
                        y->left->parent = y;
                        y->color = z->color;
                    }
                    delete z;
                    if (originalColor == B)
                        eraseFix(x);
                }
                return (true);
            }

            // 삭제 후 규칙이 깨졌을 경우 재조정하는 함수
            void    eraseFix(NodePtr x)
            {
                NodePtr s;  // sibling node

                // _begin이러나 double Black이 깨질 때까지
                while (x != this->_begin && x->color == B)
                {
                    if (x == x->parent->left)   // x가 p의 왼쪽 자식인 경우
                    {
                        s = x->parent->right;
                        // case 1
                        if (s->color == R)
                        {
                            s->color = B;
                            x->parent->color = R;
                            rotateLeft(x->parent);
                            s = x->parent->right;
                        }
                        // case 2
                        if (s->left->color == B && s->right->color == B)
                        {
                            s->color == R;
                            x = x->parent;                            
                        }
                        else
                        {
                            // case 3
                            if (s->right->color == B)
                            {
                                s->left->color = B;
                                s->color = R;
                                rotateRight(s);
                                s = x->parent->right;
                            }
                            // case 4
                            s->color = x->parent->color;
                            x->parent->color = B;
                            s->right->color = B;
                            rotateLeft(x->parent);
                            x = _begin;
                        }
                    }
                    else    // x가 p의 오른쪽 자식인 경우
                    {
                        s = x->parent->left;
                        // case 1
                        if (s->color == R)
                        {
                            s->color = B;
                            x->parent->color = R;
                            rotateRight(x->parent);
                            s = x->parent->right;
                        }
                        // case 2
                        if (s->left->color == B && s->right->color == B)
                        {
                            s->color == R;
                            x = x->parent;                            
                        }
                        else
                        {
                            // case 3
                            if (s->left->color == B)
                            {
                                s->right->color = B;
                                s->color = R;
                                rotateLeft(s);
                                s = x->parent->left;
                            }
                            // case 4
                            s->color = x->parent->color;
                            x->parent->color = B;
                            s->left->color = B;
                            rotateRight(x->parent);
                            x = _begin;
                        }
                    }
                } 
                x->color = B;
                _begin->color = B;
            }

            // 삭제 시 이용, 삭제할 노드의 자식 노드를 부모노드에게 연결해주는 함수
            void    transplant(NodePtr n1, NodePtr n2)
            {
                if (n1->parent == 0)
                    _begin = n2;
                else if (n1 == n1->parent->left)
                    n1->parent->left = n2;
                else
                    n1->parent->right = n2;
                n2->parent = n1->parent;
            }

            // node x를 기준으로 왼쪽으로 회전
            void    rotateLeft(NodePtr x)
            {
                NodePtr y;

                y = x->right;
                x->right = y->left;
                if (y->left != this->tail)
                    y->left->parent = x;
                y->parent = x->parent;
                if (!x->parent)
                    _begin = y;
                else if (x == x->parent->left)
                    x->parent->left = y;
                else
                    x->parent->right = y;
                x->parent = y;
                y->left = x;
            }

            // node x를 기준으로 오른쪽으로 회전
            void    rotateRight(NodePtr y)
            {
                NodePtr x;

                x = y->left;
                y->left = x->right;
                if (x->right != this->tail)
                {
                    x->right->parent = y;
                }
                x->parent = y->parent;
                if (!y->parent)
                    _begin = x;
                else if (y == y->parent->left)
                    y->parent->left = x;
                else
                    y->parent->right = x;
                y->parent = x;
                x->right = y;
            }

            // 순회 함수
            void    inorder(NodePtr target)
            {
                if (target == this->tail)
                    return ;
                inorder(target->left);
                inorder(target->right);
            }

            void    preorder(NodePtr target)
            {
                if (target == this->tail)
                    return ;
                preorder(target->left);
                preorder(target->right);
            }

            void    postorder(NodePtr target)
            {
                if (target == this->tail)
                    return ;
                postorder(target->left);
                postorder(target->right);
            }

        public:
            // constructor & destructor
            rbtree(const compare_type& comp, const allocator_type& alloc)
				: _comp(comp), _alloc(alloc), _size(size_type())
            {
                _nil = _alloc.allocate(1);
				_alloc.construcct(_nil, value_type());
				_nil->color = B;
				_nil->parent = _nil;
				_nil->left = _nil;
				_nil->right = _nil;
            }

            // rbtree(const rbtree& ref){}

            // rbtree& operator=(const rbtree& ref){}

            ~rbtree() {};

            // min & max
            NodePtr getMin(NodePtr x)
            {
                while (x->left != this->tail)
                    x = x->left;
                return (x);
            }
            
            NodePtr getMax(NodePtr x)
            {
                while (x->right != this->tail)
                    x = x->right;
                return (x);
            }

    }; // end of class map
} // end of namespace ft

#endif