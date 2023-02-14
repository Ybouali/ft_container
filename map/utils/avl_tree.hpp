#pragma once

#include "../../vector/vector.hpp"

#include "../../iterators/bidirectional_iterator.hpp"

#include "../utils/Node_avl.hpp"

#define COUNT 10

namespace ft {
    
    template <
        class Key,
        class T,
        class _comp,
        class Alloc
    >
    class avl_tree
    {
        public :
            typedef Alloc                                                           allocator_type_pair;
            typedef _comp                                                           Comp;
            typedef typename ft::pair<Key, T>                                       value_type;
            typedef ft::Node_avl<Key, T> *                                          pointer;
            typedef typename Alloc::template rebind<ft::Node_avl<Key, T> >::other   allocator_type;
            typedef size_t                                                          size_type;

            avl_tree(): root(NULL) , alloc_pair(), comp(), alloc_node(), _size(0) { }
            
            avl_tree(const avl_tree& other)
                : root(other.root), alloc_pair(other.alloc_pair), comp(other.comp), alloc_node(other.alloc_node), _size(other._size) {} 
            
            ~avl_tree() {
                // if (_size)
                // {
                //     std::cout << "-------------------------------------------" << std::endl;
                //     std::cout << "SHOW TREE THE SIZE OF THIS TREE IS :: " << _size << std::endl;
                //     show_tree_2D(root, 0);
                //     std::cout << "-------------------------------------------" << std::endl;
                // }
                if (_size)
                    destroy_avl();
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

                std::cout << "| " << node->data->first << " HEIGHT " << node->height << " |" << std::endl;

                show_tree_2D(node->left, space);
            }

            // ! GET SIZE
            size_type   get_size(void) const { return _size; }

            // ! DESTROY NODE
            void    destroy_node(pointer node)
            {
                if (!node)
                    return ;
                
                if (node->parent && node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent && node->parent->right == node)
                    node->parent->right = NULL;

                alloc_pair.destroy(node->data);
                alloc_pair.deallocate(node->data, 1);
                alloc_node.destroy(node);
                alloc_node.deallocate(node, 1);
                
                if (root == node)
                    root = NULL;
                _size--;
            }

            // ! SWAP
            void swap(avl_tree& x) {
                std::swap(x.root, root); 
                std::swap(x.alloc_pair, alloc_pair); 
                std::swap(x.comp, comp);
                std::swap(x.alloc_node, alloc_node);
                std::swap(x._size, _size);
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
            pointer init_node(const size_t& _height, const value_type& _val, pointer _parent)
            {
                pointer new_node = alloc_node.allocate(1);
                new_node->data = alloc_pair.allocate(1);
                alloc_pair.construct(new_node->data, _val);
                alloc_node.construct(new_node, ft::Node_avl<Key, T>(_height, NULL, NULL, _parent, new_node->data));
                return new_node;
            }

            // ! GET HIGHT
            size_type     height(pointer _node)
            {
                if (!_node)
                    return 0;
                return _node->height;
            }

            // ! GET THE MAX OF TOW NUMBERS
            size_type     max(size_type a, size_type b)
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
                pointer     _p_node = _node->parent;
                pointer     _r_node = _node->right;
                pointer     _l_node = _r_node->left;

                if (_l_node)
                    _l_node->parent = _node;
                _r_node->left = _node;
                _node->right = _l_node;
                _r_node->parent = _p_node;
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
                    return init_node(1, _val, NULL);
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
                
                if (balance > 1 && comp(_val.first, _node->left->data->first))
                {
                    // std::cout << "FROM TEST 2 LL"  << std::endl;
                    return rightRotation(_node);
                }

                if (balance > 1 && comp(_node->left->data->first, _val.first))
                {
                    // std::cout << "FROM TEST 3 LR"  << std::endl;
                    _node->left = leftRotation(_node->left);
                    return rightRotation(_node);
                }
                
                if (balance < -1 && comp(_node->right->data->first, _val.first))
                {
                    // std::cout << "FROM TEST 1 RR"  << std::endl;
                    return leftRotation(_node);
                }
                
                if (balance < -1 && comp(_val.first, _node->right->data->first))
                {
                    // std::cout << "FROM TEST 4 RL"  << std::endl;
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
            pointer    search_avl(pointer node, const Key& _val) const
            {
                if (!node)
                    return NULL;
                
                if (comp(node->data->first, _val))
                    return search_avl(node->right, _val);
                else if (comp(_val, node->data->first))
                    return search_avl(node->left, _val);
                else
                    return node;
                return NULL;
            }

            // ! END
            pointer    end() const
            {
                pointer node = get_root();

                if (!node) return NULL;

                while (node->right)
                    node = node->right;
                return node;
            }

            // ! BEGIN
            pointer    begin() const
            {
                pointer node = get_root();

                if (!node)
                    return NULL;

                while (node->left)
                    node = node->left;
                
                return node;
            }

            // ! SEARCH
            pointer     search(const Key& _val) const
            {
                return search_avl(get_root(), _val);
            }

            // ! GET ROOT
            pointer     get_root() const { return root; }
            
            // ! GET MIN OF SUBTREE
            pointer     min(pointer _root) const
            {
                while (_root->left)
                    _root = _root->left;
                return _root;
            }

            // ! ERASE AVL
            pointer    erase_avl(pointer   _root, const Key& _val)
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
                            _root = NULL;
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
            void    erase(const Key& _val) { root = erase_avl(root, _val); }

            pointer upper_bound(const Key& _val) const  {  
                pointer r = NULL;
                pointer node = get_root();
                while (node)
                {
                    if (comp(_val, node->data->first))
                    {
                        r = node;
                        node = node->left;
                    }
                    else
                        node = node->right;
                }
                return r;

            }

            pointer lower_bound(const Key& _val) const {
                pointer r = NULL;

                pointer node = get_root();

                while (node)
                {
                    if (!comp(node->data->first, _val))
                    {
                        r = node;
                        node = node->left;
                    }
                    else
                        node = node->right;
                }
                return r;
            }


        private :
            pointer                                         root;
            allocator_type_pair                             alloc_pair;
            Comp                                            comp;
            allocator_type                                  alloc_node;
            size_type                                       _size;
    };
} 