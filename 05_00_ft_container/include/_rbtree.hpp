#ifndef RBTREE_HPP
# define RBTREE_HPP

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

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
        Node    *parent = nullptr
        Color   color = B;
    };

    template <typename T>
    class rbtree
    {
        private:
            Node<T> *root;
            Node<T> *tail;

            Node<T> *isKey(T _val);
            void    insert(T _val);
            void    insertFix(Node<T> *node);
            bool    remove(T +val);
            void    removeFix(Node<T> *node);
            void    transplant(Node<T> *n1, Node<T> *n2);
            void    rotateLeft(Node<T> *node);
            void    rotateRight(Node<T> *node);

            void    display();

            void    inorder(Node<T> *node);
            void    preorder(Node<T> *node);
            void    postorder(Node<T> *node);

        public:
            rbtree();
            rbtree(const rbtree& ref);
            rbtree& operator=(const rbtree& ref)
            ~rbtree();

            Node<T> *getMin(Node<T> *node);
            Node<T> *getMax(Node<T> *node);



    }; // end of class map
} // end of namespace ft

#endif