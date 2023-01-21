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
}
