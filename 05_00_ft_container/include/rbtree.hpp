#ifndef RBTREE_HPP
# define RBTREE_HPP

# define T_RED "\033[0;31m"
# define T_GRN "\033[0;32m"
# define T_YLW "\033[0;33m"
# define T_BLU "\033[0;36m"
# define T_GRY "\033[90m"
# define T_DFT "\033[0;37m"

# include <iostream>

namespace ft 
{
    enum Color
    {
        R,
        B
    };

    template <typename T>
    struct Node
    {
        T       key;
        Node    *left = nullptr;
        Node    *right = nullptr;
        Node    *parent = nullptr;
        Color   color = B;
    };
    // node 구조체 생성 후 색은 black으로 초기화, 모든 자식들은 nullptr로 초기화

    template <typename T>
    class rbtree
    {
        typedef Node<T> *NodePtr;

        private:    
            NodePtr root;  // root node는 항상  black
            NodePtr tail;  // 끝에 해당하는 노드로 항상 black

            // key 값이 있는지 검사하는 함수
            NodePtr isKey(T _key)
            {
                NodePtr ptr = root;
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
                NodePtr a = this->root;
                NodePtr b = nullptr;
                NodePtr c = new Node();

                c->key = _key;
                c->color = R;
                c->parent = nullptr;
                c->left = this->tail;
                c->right = this->tail;

                // BST의 일반 삽입 연산
                while (a != this->tail)
                {
                    b = a;
                    a = (a->key < _key) ? a->right : a->left;
                }
                c->parent = b;

                if (b == nullptr)
                    this->root = c;
                else if (c->key > b->key)
                    b->right = c;
                else
                    b->left = c;

                // c가 root node라면
                if (c->parent == nullptr)
                {
                    c->color = B;
                    return ;
                }
                // c의 부모노드가 root라면 fix up 필요없이 red로 붙여주면 된다.
                if (c->parent->parent != nullptr)
                    this->insertFix(c)
                return ;
            }

            // 삽입 후 규칙이 깨졌을 경우 재조정하는 함수
            void    insertFix(NodePtr n)
            {
                // root 노드가 아니고 부모노드의 색이 red라면
                while (n != this->root && n->parent->color == R)
                {
                    NodePtr gp = n->parent->parent;
                    NodePtr u = (n->parent == gp->left) ? gp->right : gp->left;
                    bool    side = (n->parent == gp->left) ? true : false; // 왼쪽이면 1, 오른쪽이면 0

                    // case 1
                    if (u && u->color == RED)
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
                this->root->color = B;
            }

            // 삭제 함수
            bool    remove(T _key)
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
                        removeFix(x);
                }
                return (true);
            }

            // 삭제 후 규칙이 깨졌을 경우 재조정하는 함수
            void    removeFix(NodePtr x)
            {
                NodePtr s;  // sibling node

                // root이러나 double Black이 깨질 때까지
                while (x != this->root && x->color == B)
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
                            s->color == RED;
                            x = x->parent;                            
                        }
                        else
                        {
                            // case 3
                            if (s->right->color = B)
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
                            x = root;
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
                            s->color == RED;
                            x = x->parent;                            
                        }
                        else
                        {
                            // case 3
                            if (s->left->color = B)
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
                            x = root;
                        }
                    }
                } 
                x->color = B;
                root->color = B;
            }

            // 삭제 시 이용, 삭제할 노드의 자식 노드를 부모노드에게 연결해주는 함수
            void    transplant(NodePtr n1, NodePtr n2)
            {
                if (n1->parent == nullptr)
                    root = v;
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
                    root = y;
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
                    root = x;
                else if (y == y->parent->left)
                    y->parent->left = x;
                else
                    y->parent->right = x;
                y->parent = x;
                x->right = y;
            }

            // print 함수
            void    display();

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
            rbtree()
            {
                this->tail = new Node();
                this->tail->color = B;
                this->tail->left = nullptr;
                this->tail->right = nullptr;
                this->tail->parent = nullptr;
                this->root = this->tail; 
            }

            rbtree(const rbtree& ref)
            {

            }

            rbtree& operator=(const rbtree& ref)
            {
                
            }

            ~rbtree() {};

            // min & max
            NodePtr getMin(NodePtr x)
            {
                while (x->left != this->tail)
                    x = x->left;
                return (x);
            }
            
            NodePtr getMax(NodePtr node)
            {
                while (x->right != this->tail)
                    x = x->right;
                return (x);
            }

    }; // end of class map
} // end of namespace ft

#endif