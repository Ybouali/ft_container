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
            typedef ft::Node_avl<Key, T> *                                          pointer;
            typedef ft::Node_avl<Key, T> &                                          reference;
            typedef typename Alloc::template rebind<ft::Node_avl<Key, T> >::other   allocator_type;
            typedef size_t                                                          size_type;

            avl_tree(): root(nullptr), alloc_pair(), comp(), alloc_node(), _size() {}
            
            avl_tree(const avl_tree& other): root(other.root), alloc_pair(other.aolloc_pair), comp(other._comp), alloc_node(other.alloc_node), _size(other._size) {} 
            
            ~avl_tree() {
                std::cout << "-------------------------------------------" << std::endl;
                std::cout << "SHOW TREE THE SIZE OF THIS TREE IS :: " << _size << std::endl;
                show_tree_2D(root, 0);
                std::cout << "-------------------------------------------" << std::endl;
                destroy_tree(root);
            } 

            void    show_tree_2D(pointer node, size_type space)
            {
                if (!node)
                    return ;
                
                space += COUNT;

                show_tree_2D(node->right, space);

                std::cout << std::endl;

                for (int i = COUNT; i < space; i++)
                    std::cout << " ";

                std::cout << "| " << node->data->first << " HEIGHT " << node->height << " |" << std::endl;
                
                show_tree_2D(node->left, space);
            }

            // // ! SHOW_TREE
            // void    show_tree(pointer node)
            // {
            //     std::cout << "SHOW TREE THE SIZE OF THIS TREE IS :: " << _size << std::endl;
            //     show_tree_2D(node, 0);
            // }

            // ! DESTROY NODE
            void    destroy_node(pointer node)
            {
                if (!node)
                    return ;
                alloc_pair.destroy(node->data);
                alloc_pair.deallocate(node->data, 1);
                alloc_node.destroy(node);
                alloc_node.deallocate(node, 1);
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

            // ! GET THE MAX OF TOW NUMBER
            int     max(int a, int b)
            {
                return (a > b) ? a : b;
            }

            // ! RIGHT ROTAION
            pointer     rightRotation(pointer _node)
            {
                pointer     _l_node = _node->left;
                pointer     _r_node = _l_node->right;

                _l_node->right = _node;
                _node->left    = _r_node;

                _node->height = max(height(_node->left), height(_node->right)) + 1;
                _l_node->height = max(height(_l_node->left), height(_l_node->right)) + 1;

                return _l_node;
            }

            // ! LEFT ROTATION
            pointer     leftRotation(pointer _node)
            {
                pointer     _r_node = _node->right;
                pointer     _l_node = _r_node->left;

                _r_node->left = _node;
                _node->right = _l_node;

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
                    return init_node(0, _val, _node);
                } 

                if (comp(_val.first, _node->data->first))
                    _node->left = insert_avl(_node->left, _val);
                else if (comp(_node->data->first, _val.first))
                    _node->right = insert_avl(_node->right, _val);
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
            void    insert(const value_type& _val)
            {
                root = insert_avl(root, _val);
            }

            // ! SEARCH WITH A ROOT
            pointer    search_avl(pointer node, const Key_type& _val)
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

            // ! SEARCH
            pointer     search(const Key_type& _val)
            {
                return search_avl(get_root(), _val);
            }

            // ! GET ROOT
            pointer     get_root() { return this->root; }

            pointer     min(void) 
            {
                pointer     _node = root;

                while(_node->left)
                    _node = _node->left;
                return _node;
            }
            
            pointer     min(pointer _root)
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
                        _size--;
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
            void    erase(const Key_type& _val)
            {
                root = erase_avl(get_root(), _val);
            }

        private :
            pointer                 root;
            allocator_type_pair     alloc_pair;
            Comp                    comp;
            allocator_type          alloc_node;
            size_type               _size;
        


    };

}