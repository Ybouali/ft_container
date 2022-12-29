#pragma once 
#include "../../vector/vector.hpp"

#define COUNT 10


namespace ft
{

    // ! false == RED && true == black
    template <class Key, class T > 
    class Node {
        public :
            bool                color;
            Node                *left;
            Node                *right;
            Node                      *parent;
            ft::pair<const Key, T>    *data;
            
            Node(): color(false), left(nullptr), right(nullptr), parent(nullptr), data() {}

            Node(const Node& other): color(other.color), left(other.left), right(other.right), parent(other.parent), data(other.data) {}

            Node(bool _color, Node *_left, Node *_right, Node *_parent, ft::pair<const Key, T>  *_data)
            : color(_color), left(_left), right(_right), parent(_parent), data(_data) {}

            ~Node() {}
    };

    template <
        class Key,
        class T,
        class Alloc = std::allocator<ft::Node<Key, T> >,
        class _comp = std::less<Key>,
        class Allocator_pair = std::allocator<ft::pair<const Key, T> >
    >
    class Tree
    {
        private :
            ft::Node<Key, T>    *root;
            Alloc               alloc;
            _comp               Comp;
            Allocator_pair      alloc_pair;
            ptrdiff_t           _size;
        public :
            typedef ft::pair<const Key, T>   value_type;

            Tree (): root (nullptr), _size(0) {}
            
            Tree (const Tree &other): root(other.root), alloc(other.alloc), Comp(other.Comp), alloc_pair(other.alloc_pair), _size(other._size) {}

            ~Tree () {
                std::cout << "-------------------------------------------" << std::endl;
                show_tree(root);
                std::cout << "-------------------------------------------" << std::endl;
                destroy_tree(root);
            }

            ft::Node<Key, T> * search_red_black(Node<Key, T> *node, const Key& _val)
            {
                if (!node)
                    return nullptr;
                
                if (Comp(node->data->first, _val))
                    return search_red_black(node->right, _val);
                else if (Comp(_val, node->data->first))
                    return search_red_black(node->left, _val);
                else
                    return node;
                return nullptr;
            }

            Node<Key, T> *init_node(bool color, const value_type& _val, Node<Key, T> *_parent)
            {
                Node<Key, T>    *new_node = alloc.allocate(1);
                new_node->data = alloc_pair.allocate(1);
                alloc_pair.construct(new_node->data, _val);
                alloc.construct(new_node, Node<Key, T>(color, nullptr, nullptr, _parent, new_node->data));
                return new_node;
            }

            void    destroy_tree(ft::Node<Key, T>   *node)
            {
                if (!node)
                    return ;
                destroy_tree(node->left);
                destroy_tree(node->right);
                destroy_node(node);
            }

            ft::Node<Key, T>    *in_order_successor(ft::Node<Key, T> *_node)
            {
                if (!_node)
                    return nullptr;
                if (!_node->right)
                    return get_min_subtree(_node->right);
                ft::Node<Key, T>    *node = _node;
                ft::Node<Key, T>    *parent = _node->parent;

                while (parent && node = parent->right) {
                    node = parent;
                    parent = parent->parent;
                }

                return parent;
            }

            ft::Node<Key, T>    *in_order_predecessor(ft::Node<Key, T> *_node)
            {
                if (!_node)
                    return nullptr;
                if (!_node->left)
                    return get_max_subtree(_node->left);
                ft::Node<Key, T>    *node = _node;
                ft::Node<Key, T>    *parent = _node->parent;

                while (parent && node = parent->left) {
                    node = parent;
                    parent = parent->parent;
                }
                return parent;
            }

            ft::Node<Key, T>    *get_min_subtree(ft::Node<Key, T> *_node)
            {
                if (!_node)
                    return nullptr;
                while (_node->left)
                    _node = _node->left;
                return _node;
            }

            ft::Node<Key, T>    *min(void)
            {
                ft::Node<Key, T>    *_node = root;

                if (!_node)
                    return nullptr;
                while (_node->left)
                    _node = _node->left;
                return _node;
            }

            ft::Node<Key, T>    *get_max_subtree(ft::Node<Key, T> *_node)
            {
                if (!_node)
                    return nullptr;
                while (_node->right)
                    _node = _node->right;
                return _node;
            }

            ft::Node<Key, T>    *max(void)
            {
                ft::Node<Key, T>    *_node = root;

                if (!_node)
                    return nullptr;
                while (_node->right)
                    _node = _node->right;
                return _node;
            }

            void    delete_one_red_black(ft::Node<Key, T> *_node, const Key& _val)
            {
                ft::Node<Key, T>    *node = search_red_black(_node, _val);
                
            }

            ft::Node<Key, T>    * get_root(void) const { return root; }


            void    destroy_node(ft::Node<Key, T> *node)
            {
                if (!node)
                    return ;
                alloc_pair.destroy(node->data);
                alloc_pair.deallocate(node->data, 1);
                alloc.destroy(node);
                alloc.deallocate(node, 1);
            }


            
            void    left_rotate(Node<Key, T> *node)
            {
                Node<Key, T>    *node_2 = node->parent;
                Node<Key, T>    *node_3 = node->parent->parent;
                
                node_2->parent = node_3->parent;
                if (node_3->parent && node_3->parent->left == node_3)
                    node_3->parent->left = node_2;
                else if (node_3->parent && node_3->parent->right == node_3)
                    node_3->parent->right = node_2;
                node_3->parent = node_2;
                
                if (!node_2->parent)
                    root = node_2;
                
                node_3->right = node_2->left;
                node_2->left = node_3;
            }

            void    right_rotate(Node<Key, T> *node)
            {
                Node<Key, T>    *node_2 = node->parent;
                Node<Key, T>    *node_3 = node->parent->parent;


                node_2->parent = node_3->parent;
                
                if (node_3->parent && node_3->parent->left == node_3)
                    node_3->parent->left = node_2;
                else if (node_3->parent && node_3->parent->right == node_3)
                    node_3->parent->right = node_2;
                node_3->parent = node_2;
                
                if (!node_2->parent)
                    root = node_2;
                
                node_3->left = node_2->right;
                node_2->right = node_3;
            }

            void    right_to_left_rotate(Node<Key, T> *node)
            {
                Node<Key, T>    *node_2 = node->parent;

                node_2->parent->left = node;
                node->parent = node_2->parent;
                node_2->parent = node;
                node_2->right = nullptr;
                node->left = node_2;
            }

            void    left_to_right_rotate(Node<Key, T> *node)
            {
                Node<Key, T>    *node_2 = node->parent;

                node_2->parent->right = node;
                node->parent = node_2->parent;
                node_2->parent = node;
                node_2->left = nullptr;
                node->right = node_2;
            }

            void    insert_on_node(Node<Key, T> *node, const value_type& _val)
            {
                if (Comp(node->data->first, _val.first))
                {
                    if (node->right)
                        insert_on_node(node->right, _val);
                    else
                    {
                        Node<Key, T>    *tmp = init_node(false, _val, node);
                        node->right = tmp;
                        recolor_red_black(tmp);
                        _size++;
                    }
                }
                else if (Comp(_val.first, node->data->first))
                {
                    if (node->left)
                        insert_on_node(node->left, _val);
                    else
                    {
                        Node<Key, T>    *tmp = init_node(false, _val, node);
                        node->left = tmp;
                        recolor_red_black(tmp);
                        _size++;
                    }
                }
            }
            
            void    recolor_red_black(Node<Key, T> *_node)
            {
                
                Node<Key, T>    *tmp = _node;

                if (!_node || !_node->parent || _node->parent->color)
                    return ;
                
                if (!_node->parent->color)
                {
                    if (!_node->parent->parent->right || _node->parent->parent->right->color)
                    {
                        if (_node->parent->right == _node)
                        {
                            right_to_left_rotate(tmp);
                            right_rotate(tmp->left);
                            tmp->color = true;
                            tmp->left->color = false;
                            tmp->right->color = false;
                        }
                        else
                        {
                            right_rotate(tmp);
                            tmp->parent->color = true;
                            tmp->parent->right->color = false;
                        }
                        
                    }
                    else if (!_node->parent->parent->left || _node->parent->parent->left->color)
                    {
                        if (_node->parent->left == _node)
                        {
                            left_to_right_rotate(tmp);
                            left_rotate(tmp->right);
                            tmp->color = true;
                            tmp->left->color = false;
                            tmp->right->color = false;
                        }
                        else
                        {
                            left_rotate(tmp);
                            tmp->parent->color = true;
                            tmp->parent->left->color = false;
                        }
                        
                    }
                    else if (_node->parent->parent->left != _node->parent)
                    {
                        _node->parent->color = true;
                        _node->parent->parent->left->color = true;
                        if (_node->parent->parent->parent)
                        {
                            _node->parent->parent->color = false;
                            recolor_red_black(tmp->parent->parent);
                        }
                    }
                    else if (_node->parent->parent->right != _node->parent)
                    {
                       
                        _node->parent->color = true;
                        _node->parent->parent->right->color = true;
                        if (_node->parent->parent->parent)
                        {
                            _node->parent->parent->color = false;
                            
                            recolor_red_black(tmp->parent->parent);
                        }
                    }

                }
            }

            void insert_red_black(const value_type& _val)
            {
                if (!root)
                    root = init_node(true, _val, nullptr);
                else
                    insert_on_node(root, _val);
            }

            void    show_tree_2D(Node<Key, T> *node, int space)
            {
                if (!node)
                    return ;
                
                space += COUNT;

                show_tree_2D(node->right, space);

                std::cout << std::endl;

                for (int i = COUNT; i < space; i++)
                    std::cout << " ";

                std::cout << "| " << node->data->first;
                node->color ? std::cout << " BLACK |" << std::endl : std::cout << " RED |" << std::endl;
                
                show_tree_2D(node->left, space);
            }

            void    show_tree(Node<Key, T> *node)
            {
                std::cout << "SHOW TREE THE SIZE OF THIS TREE IS :: " << _size << std::endl;
                show_tree_2D(node, 0);
            }
            
    };   
}