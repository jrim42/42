#ifndef BST_HPP
# define BST_HPP

# define T_RED "\033[0;31m"
# define T_GRN "\033[0;32m"
# define T_YLW "\033[0;33m"
# define T_BLU "\033[0;36m"
# define T_GRY "\033[90m"
# define T_DFT "\033[0;37m"

# include <iostream>

namespace ft 
{
    template <typename T>
    struct Node
    {
        T       value;
        Node    *left = nullptr;
        Node    *right = nullptr;
    };

    template <typename T>
    class bst
    {
        private:
            Node<T>* root;
	        Node<T>* tail;

            void    inorder(Node<T> *cur)
            {
                if (cur != nullptr)
                {	
                    inorder(cur->left);
                    cout << cur->value << " ";
                    Inorder(cur->right);
                }
            }

            Node<T> *searchMax(Node<T> *node)
            {
                if (node == NULL)
                    return NULL;

                while (node->right != NULL)
                {
                    node = node->right;
                }
                return node;
            }

            Node<T> *removeSeq(Node<T> *node, T value)
            {
                if (node == nullptr) 
                    return node;
                else if (node->value >_vaule)
                    node->left = RemoveSeqence(node->left, _vaule);
                else if (node->value < _vaule)
                    node->right = RemoveSeqence(node->right, _vaule);
                else
                {
                    Node<T>* ptr = node;
                    if (node->right==nullptr && node->left==nullptr)
                    {
                        delete node;
                        node = nullptr;
                    }
                    else if (node->right == nullptr)
                    {
                        node = node->left;
                        delete ptr;
                    }
                    else if (node->left == nullptr)
                    {
                        node = node->right;
                        delete ptr;
                    }
                    else
                    {
                        ptr = SearchMaxNode(node->left);
                        node->value = ptr->value;
                        node->left = RemoveSeqence(node->left, ptr->value);
                    }
                }
                return node;
            }

        public:
            bst() : root(nullptr) {};
            ~bst() {};

            void addNode(T _value)
            {
                Node<T>* node = new Node<T>();
                Node<T>* tmpRoot = nullptr;

                node->value = _value;

                if (root == nullptr)
                    root = node;
                else
                {
                    Node<T>* ptr = root;

                    while (ptr != nullptr)
                    {
                        tmpRoot = ptr;
                        if (node->value < ptr->value)
                        {
                            ptr = ptr->left;
                        }
                        else
                        {
                            ptr = ptr->right;
                        }
                    }
                    if (node->value < tmpRoot->value )
                        tmpRoot->left = node;
                    else
                        tmpRoot->right = node;
                }
            }

            bool searchValue(T _value)
            {
                Node<T>* ptr = root;
                Node<T>* tmpRoot = nullptr;

                while (ptr!=nullptr)
                {
                    if (ptr->value == _value)
                        return true;
                    else if (ptr->value > _value)
                        ptr = ptr->left;
                    else
                        ptr = ptr->right;
                }
                return false;
            }

            void removeNode(T _value)
            {
                Node<T>* ptr = root;
                RemoveSeqence(ptr, _value);

            }

            void display()
            {
            	Inorder(root);
            }
    };
}

#endif