#pragma once

namespace ft
{
    template <class Key, class T > 
    class Node_avl {
        public :
            int                         height;
            Node_avl                    *left;
            Node_avl                    *right;
            Node_avl                    *parent;
            ft::pair<const Key, T>      *data;
            
            Node_avl(): height(0), left(nullptr), right(nullptr), parent(nullptr), data() {}

            Node_avl(const Node_avl& other): height(other.height), left(other.left), right(other.right), parent(other.parent), data(other.data) {}

            Node_avl(int _height, Node_avl *_left, Node_avl *_right, Node_avl *_parent, ft::pair<const Key, T>  *_data)
            : height(_height), left(_left), right(_right), parent(_parent), data(_data) {}

            ~Node_avl() {}
            
    };
    
    template <class Key, class T>
    Node_avl<Key, T>    *get_next_min(Node_avl<Key, T> *_node)
    {
        while (_node && _node->left)
            _node = _node->left;
        return _node;
    }

    template <class Key, class T>
    Node_avl<Key, T>    *get_next_max(Node_avl<Key, T> *_node)
    {
        while (_node && _node->right)
            _node = _node->right;
        return _node;
    }

    template <class Key, class T>
    Node_avl<Key, T>    * decrement(Node_avl<Key, T> *r_node)
    {
        Node_avl<Key, T> *parent;
        
        if (r_node && r_node->left)
            r_node = get_next_max(r_node->left);
        else if (r_node)
        {
            parent = r_node->parent;
            while (parent && r_node == parent->left)
            {
                r_node = parent;
                parent = parent->parent;
            }
            r_node = parent;
        }
        return r_node;
    }

    template <class Key, class T>
    Node_avl<Key, T>    *increment(Node_avl<Key, T> *r_node)
    {
        Node_avl<Key, T> *parent;
        
        if (r_node && r_node->right)
            r_node = get_next_min(r_node->right);
        else if (r_node)
        {
            parent = r_node->parent;
            while (parent && r_node == parent->right)
            {
                r_node = parent;
                parent = parent->parent;
            }
            r_node = parent;
        }
        return r_node;
    }

}
