#pragma once

#include "../../vector/vector.hpp"

#include "../../iterators/bidirectional_iterator.hpp"

#include "../utils/Node_avl.hpp"

#define COUNT 10

namespace ft {
    
    template <
        class Key,
        class T,
        class _comp = std::less<Key>,
        class Alloc = std::allocator<ft::pair<Key, T> >
    >
    class avl_tree
    {
        public :
            typedef Alloc                                                           allocator_type_pair;
            typedef _comp                                                           Comp;
            typedef Key                                                             Key_type;
            typedef T                                                               mapped_type;
            typedef typename ft::pair<Key_type, mapped_type>                        value_type;
            typedef typename ft::Node_avl<Key_type, mapped_type>                    _Node_type;
            typedef ft::Node_avl<Key, T> *                                          pointer;
            typedef const ft::Node_avl<Key, T> *                                    const_pointer;
            typedef ft::Node_avl<Key, T> &                                          reference;
            typedef typename Alloc::template rebind<ft::Node_avl<Key, T> >::other   allocator_type;
            typedef size_t                                                          size_type;

            avl_tree(): root(nullptr) , alloc_pair(), comp(), alloc_node(), _size(0) { }
            
            avl_tree(const avl_tree& other): root(other.root), alloc_pair(other.alloc_pair), comp(other.comp), alloc_node(other.alloc_node), _size(other._size) {} 
            
            ~avl_tree() {
                // if (_size)
                // {
                //     std::cout << "-------------------------------------------" << std::endl;
                //     std::cout << "SHOW TREE THE SIZE OF THIS TREE IS :: " << _size << std::endl;
                //     // show_tree_2D(root, 0);
                //     std::cout << "-------------------------------------------" << std::endl;
                // }
                if (_size)
                {
                    destroy_avl();
                    // deallocate_tree(root);
                }
            } 

            void    show_tree_2D(pointer node, size_type space)
            {
                if (!node)
                    return ;
                
                space += COUNT;

                show_tree_2D(node->right, space);

                std::cout << std::endl;

                for (size_type i = COUNT; i < space; i++)
                    std::cout << " ";

                // " HEIGHT " << node->height << " add :: " << node->parent <<
                std::cout << "| " << node->data->first << " |" << std::endl;

                show_tree_2D(node->left, space);
            }

            // ! GET SIZE
            size_type   get_size(void) const { return _size; }
            
            // ! GET MIN SUBTREE
            pointer     get_min_subtree(pointer _node)
            {
                if (!_node)
                    return nullptr;
                while (_node->left)
                    _node = _node->left;
                return _node;
            }

            // ! IN ORDER SUCCESSOR
            pointer in_order_successor(pointer _node)
            {
                if (!_node)
                    return nullptr;
                if (_node->right)
                    return get_min_subtree(_node->right);
                pointer node = _node;
                pointer parent = _node->parent;

                while (parent && node == parent->right) {
                    node = parent;
                    parent = parent->parent;
                }

                return parent;
            }

            // ! GET MAX SUBTREE
            pointer     get_max_subtree(pointer _node)
            {
                if (!_node)
                    return nullptr;
                while (_node->right)
                    _node = _node->right;
                return _node;
            }

            // ! DESTROY NODE
            void    destroy_node(pointer node)
            {
                if (!node)
                    return ;
                
                if (node->parent && node->parent->left == node)
                    node->parent->left = nullptr;
                else if (node->parent && node->parent->right == node)
                    node->parent->right = nullptr;

                alloc_pair.destroy(node->data);
                alloc_pair.deallocate(node->data, 1);
                alloc_node.destroy(node);
                alloc_node.deallocate(node, 1);
                
                if (root == node)
                    root = nullptr;
                else
                    node = nullptr;
                _size--;
            }

            // ! DESTROY TREE
            void    destroy_tree(pointer node)
            {
                if (!node)
                    return ;
                destroy_tree(node->left);
                destroy_tree(node->right);
                destroy_node(node);
            }

            // ! DESTROY ALL aka CLEAR THE MAP
            void destroy_avl(void)
            {
                if (_size)
                    destroy_tree(root);
            }

            // ! INIT NODE
            pointer init_node(const int& _height, const value_type& _val, pointer _parent)
            {
                pointer new_node = alloc_node.allocate(1);
                new_node->data = alloc_pair.allocate(1);
                alloc_pair.construct(new_node->data, _val);
                alloc_node.construct(new_node, ft::Node_avl<Key, T>(_height, nullptr, nullptr, _parent, new_node->data));
                return new_node;
            }

            // ! GET HIGHT
            int     height(pointer _node)
            {
                if (!_node)
                    return 0;
                return _node->height;
            }

            // ! GET THE MAX OF TOW NUMBERS
            int     max(int a, int b)
            {
                return (a > b) ? a : b;
            }

            // ! RIGHT ROTAION
            pointer     rightRotation(pointer _node)
            {
                pointer     _p_node = _node->parent;
                pointer     _l_node = _node->left;
                pointer     _r_node = _l_node->right;
                
                if (_r_node)
                    _r_node->parent = _node;
                _l_node->right = _node;
                _node->left    = _r_node;
                _l_node->parent = _p_node;
                _node->parent = _l_node;

                _node->height = max(height(_node->left), height(_node->right)) + 1;
                _l_node->height = max(height(_l_node->left), height(_l_node->right)) + 1;

                return _l_node;
            }

            // ! LEFT ROTATION
            pointer     leftRotation(pointer _node)
            {
                pointer     _r_node = _node->right;
                pointer     _l_node = _r_node->left;

                if (_l_node)
                    _l_node->parent = _node;
                _r_node->left = _node;
                _node->right = _l_node;
                _r_node->parent = _node->parent;
                _node->parent = _r_node;

                _node->height = max(height(_node->left), height(_node->right)) + 1;
                _r_node->height = max(height(_r_node->left), height(_r_node->right)) + 1;

                return _r_node;
            }

            // ! GET BALANCE
            int     get_Balance(pointer _node)
            {
                if (!_node)
                    return 0;
                return height(_node->left) - height(_node->right);
            }

            // ! INSERT NODE
            pointer     insert_avl(pointer _node, const value_type& _val)
            {
                if (!_node)
                {
                    _size++;
                    return init_node(1, _val, nullptr);
                } 

                if (comp(_val.first, _node->data->first))
                {
                    _node->left = insert_avl(_node->left, _val);
                    _node->left->parent = _node;
                }
                else if (comp(_node->data->first, _val.first))
                {
                    _node->right = insert_avl(_node->right, _val);
                    _node->right->parent = _node;
                }
                else
                    return _node;

                _node->height = 1 + max(height(_node->left), height(_node->right));

                int balance = get_Balance(_node);
                
                if (balance > 1 && comp(_val.first, _node->data->first))
                    return rightRotation(_node);
                
                if (balance < -1 && comp(_node->data->first, _val.first))
                    return leftRotation(_node);
                
                if (balance > 1 && comp(_node->left->data->first, _val.first))
                {
                    _node->left = leftRotation(_node->left);
                    return rightRotation(_node);
                }

                if (balance < -1 && comp(_node->right->data->first, _val.first))
                {
                    _node->right = rightRotation(_node->right);
                    return leftRotation(_node);
                }

                return _node;
            }
            
            // ! INSERT
            pointer    insert(const value_type& _val)
            {
                root = insert_avl(root, _val);

                return root;
            }

            // ! SEARCH WITH A ROOT
            pointer    search_avl(pointer node, const Key_type& _val) const
            {
                if (!node)
                    return nullptr;
                
                if (comp(node->data->first, _val))
                    return search_avl(node->right, _val);
                else if (comp(_val, node->data->first))
                    return search_avl(node->left, _val);
                else
                    return node;
                return nullptr;
            }

            // ! END
            pointer    end() const
            {
                pointer node = get_root();

                if (!node) return nullptr;

                while (node->right)
                    node = node->right;
                return node;
            }

            // ! BEGIN
            pointer    begin() const
            {
                pointer node = get_root();

                if (!node)
                    return nullptr;

                while (node->left)
                    node = node->left;
                
                return node;
            }

            // ! SEARCH
            pointer     search(const Key_type& _val) const
            {
                return search_avl(get_root(), _val);
            }

            // ! GET ROOT
            pointer     get_root() const { return root; }

            // ! GET MIN 
            pointer     min(void) const
            {
                pointer     _node = root;

                while(_node->left)
                    _node = _node->left;
                return _node;
            }
            
            pointer     min(pointer _root) const
            {
                while (_root->left)
                    _root = _root->left;
                return _root;
            }

            // ! ERASE AVL
            pointer    erase_avl(pointer   _root, const Key_type& _val)
            {
                if (!_root)
                    return _root;
                if (comp(_val, _root->data->first))
                    _root->left = erase_avl(_root->left, _val);
                else if (comp(_root->data->first, _val))
                    _root->right = erase_avl(_root->right, _val);
                else
                {
                    if (!_root->left || !_root->right)
                    {
                        pointer     temp = _root->left ? _root->left : _root->right;
                        
                        if (!temp)
                        {
                            temp = _root;
                            _root = nullptr;
                        }
                        else
                        {
                            alloc_pair.destroy(_root->data);
                            alloc_pair.construct(_root->data, *(temp->data));
                            _root->left = temp->left;
                            _root->right = temp->right;
                        }
                            
                        destroy_node(temp);
                    }
                    else
                    {
                        pointer     temp = min(_root->right);

                        alloc_pair.destroy(_root->data);
                        alloc_pair.construct(_root->data, *(temp->data));

                        _root->right = erase_avl(_root->right, temp->data->first);
                    }
                }
                if (!_root)
                    return _root;
                _root->height = 1 + max(height(_root->left), height(_root->right));

                int balance = get_Balance(_root);
                
                if (balance > 1 && get_Balance(_root->left) >= 0)
                    return rightRotation(_root);
                
                if (balance > 1 && get_Balance(_root->left) < 0)
                {
                    _root->left = leftRotation(_root->left);
                    return rightRotation(_root);
                }

                if (balance < -1 && get_Balance(_root->right) <= 0)
                    return leftRotation(_root);
                
                if (balance < -1 && get_Balance(_root->right) > 0)
                {
                    _root->right = rightRotation(_root->right);
                    return leftRotation(_root);
                }

                return _root;
            }

            // ! ERASE
            size_type    erase(const value_type& _val)
            {
                if (!search(_val.first))
                    return 0;
                root = erase_avl(root, _val.first);
                return 1;
            }

            // ! _LOWER BOUND
            pointer upper_bound(const Key_type & _k) const
            {
                pointer node_h = get_root();
                pointer node_r;
                
                while (node_h)
                {
                    if (comp(_k, node_h->data->first))
                    {
                        node_r = node_h;
                        node_h = node_h->left;
                    }
                    else
                        node_h = node_h->right;
                }
                return node_r;
            }

            // ! _LOWER BOUND
            pointer lower_bound(const Key_type & _k) const
            {
                pointer node_h = get_root();
                pointer node_r;
                
                while (node_h)
                {
                    if (!comp(node_h->data->first, _k))
                    {
                        node_r = node_h;
                        node_h = node_h->left;
                    }
                    else
                        node_h = node_h->right;
                }
                return node_r;
            }

        private :
            _Node_type*                                     root;
            allocator_type_pair                             alloc_pair;
            Comp                                            comp;
            allocator_type                                  alloc_node;
            size_type                                       _size;
    };
} 