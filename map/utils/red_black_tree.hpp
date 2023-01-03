#pragma once 
#include "../../vector/vector.hpp"

#define COUNT 10


namespace ft
{

    // ! false == RED && true == black
    template <class Key, class T > 
    class Node_red_black {
        public :
            bool                          color;
            Node_red_black                *left;
            Node_red_black                *right;
            Node_red_black                *parent;
            ft::pair<const Key, T>    *data;
            
            Node_red_black(): color(false), left(nullptr), right(nullptr), parent(nullptr), data() {}

            Node_red_black(const Node_red_black& other): color(other.color), left(other.left), right(other.right), parent(other.parent), data(other.data) {}

            Node_red_black(bool _color, Node_red_black *_left, Node_red_black *_right, Node_red_black *_parent, ft::pair<const Key, T>  *_data)
            : color(_color), left(_left), right(_right), parent(_parent), data(_data) {}

            ~Node_red_black() {}
    };

    template <
        class Key,
        class T,
        class Alloc = std::allocator<ft::Node_red_black<Key, T> >,
        class _comp = std::less<Key>,
        class Allocator_pair = std::allocator<ft::pair<const Key, T> >
    >
    class red_black_tree
    {
        private :
            ft::Node_red_black<Key, T>      *root;
            Alloc                           alloc;
            _comp                           Comp;
            Allocator_pair                  alloc_pair;
            ptrdiff_t                       _size;
        public :
            typedef ft::pair<const Key, T>   value_type;

            red_black_tree (): root (nullptr), _size(0) {}
            
            red_black_tree (const red_black_tree &other): root(other.root), alloc(other.alloc), Comp(other.Comp), alloc_pair(other.alloc_pair), _size(other._size) {}

            ~red_black_tree () {
                std::cout << "-------------------------------------------" << std::endl;
                show_tree(root);
                std::cout << "-------------------------------------------" << std::endl;
                destroy_tree(root);
            }

            ft::Node_red_black<Key, T> * search_red_black(Node_red_black<Key, T> *node, const Key& _val)
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

            Node_red_black<Key, T> *init_node(bool color, const value_type& _val, Node_red_black<Key, T> *_parent)
            {
                Node_red_black<Key, T>    *new_node = alloc.allocate(1);
                new_node->data = alloc_pair.allocate(1);
                alloc_pair.construct(new_node->data, _val);
                alloc.construct(new_node, Node_red_black<Key, T>(color, nullptr, nullptr, _parent, new_node->data));
                return new_node;
            }

            void    destroy_tree(ft::Node_red_black<Key, T>   *node)
            {
                if (!node)
                    return ;
                destroy_tree(node->left);
                destroy_tree(node->right);
                destroy_node(node);
            }

            ft::Node_red_black<Key, T>    *in_order_successor(ft::Node_red_black<Key, T> *_node)
            {
                if (!_node)
                    return nullptr;
                if (_node->right)
                    return get_min_subtree(_node->right);
                ft::Node_red_black<Key, T>    *node = _node;
                ft::Node_red_black<Key, T>    *parent = _node->parent;

                while (parent && node == parent->right) {
                    node = parent;
                    parent = parent->parent;
                }

                return parent;
            }

            ft::Node_red_black<Key, T>    *in_order_predecessor(ft::Node_red_black<Key, T> *_node)
            {
                if (!_node)
                    return nullptr;
                if (_node->left)
                    return get_max_subtree(_node->left);
                ft::Node_red_black<Key, T>    *node = _node;
                ft::Node_red_black<Key, T>    *parent = _node->parent;

                while (parent && node == parent->left) {
                    node = parent;
                    parent = parent->parent;
                }
                return parent;
            }

            ft::Node_red_black<Key, T>    *get_min_subtree(ft::Node_red_black<Key, T> *_node)
            {
                if (!_node)
                    return nullptr;
                while (_node->left)
                    _node = _node->left;
                return _node;
            }

            ft::Node_red_black<Key, T>    *min(void)
            {
                ft::Node_red_black<Key, T>    *_node = root;

                if (!_node)
                    return nullptr;
                while (_node->left)
                    _node = _node->left;
                return _node;
            }

            ft::Node_red_black<Key, T>    *get_max_subtree(ft::Node_red_black<Key, T> *_node)
            {
                if (!_node)
                    return nullptr;
                while (_node->right)
                    _node = _node->right;
                return _node;
            }

            ft::Node_red_black<Key, T>    *max(void)
            {
                ft::Node_red_black<Key, T>    *_node = root;

                if (!_node)
                    return nullptr;
                while (_node->right)
                    _node = _node->right;
                return _node;
            }

            void    recolor_red_black_for_delete(ft::Node_red_black<Key, T> *_node)
            {

                // // ! CASE 1 : IT IS JUST A RED NODE SO JUST DELETE THE NODE
                if (!_node->color)   
                    return ;

                // ! CASE 2 : REMOVING A DOUBLE BLACK FROM THE ROOT && RETURN
                if (_node == root)
                {
                    _node->color = true;
                    return ;
                }
                // if (_node && _node->color && \
                //     ((!_node->left && !_node->right) \
                //     || (((_node->left && _node->left->color) && (_node->right && _node->right->color))) \
                //     || (_node->left && _node->left->color && !_node->right) \
                //     || (_node->right && _node->right->color && !_node->left) ) )

                ft::Node_red_black<Key, T>    *uncle = (_node == _node->parent->left) ? _node->parent->right : _node->parent->left;
                if (uncle && uncle->color)
                {
                    if ((!uncle->right || uncle->right->color) && (!uncle->left || uncle->left->color))
                    {
                        uncle->color = false;
                        if (!_node->parent->color)
                        {
                            _node->parent->color = true;
                            return ;
                        }
                        else 
                            recolor_red_black_for_delete(_node->parent);
                    }
                    if (_node == _node->parent->left)
                    {
                        
                        if ((!uncle->right || uncle->right->color) && uncle->left && !uncle->left->color)
                        {
                            std::swap(uncle->color, uncle->left->color);
                            right_rotate(uncle);
                            uncle = _node->parent->right;   
                        }
                        if (uncle->right && !uncle->right->color)
                        {
                            std::swap(_node->parent->color, uncle->color);
                            uncle->right->color = true;
                            right_rotate(_node);
                        }
                    }
                    else 
                    {
                        if ((!uncle->left || uncle->left->color) && uncle->right && !uncle->right->color)
                        {
                            std::swap(uncle->color, uncle->right->color);
                            left_rotate(uncle->right);
                            uncle = _node->parent->left;
                        }
                        if (uncle->left && !uncle->left->color)
                        {
                            // ! CASE 6
                            std::swap(_node->parent->color, uncle->color);
                            uncle->left->color = true;
                            right_rotate(_node);
                        }
                    }
                }
                else if (uncle && !uncle->color)
                {
                    std::swap(uncle->color, _node->parent->color);
                    if (_node == _node->parent->left)
                        left_rotate(_node->parent->right);
                    else
                        right_rotate(_node->parent->left);
                    recolor_red_black_for_delete(_node);
                }
            }

            void    black_black(ft::Node_red_black<Key, T> *node)
            {
                if (node == root)
                    return ;
                if (node->parent && !node->parent->color)   
                {
                    ft::Node_red_black<Key, T>    *sibling = (node == node->parent->left) ? node->parent->right : node->parent->left;
                    if (ckeck_double_black(sibling))
                    {
                        // ! CASE 4
                        sibling->color = false;
                        node->parent->color = true;
                    }
                }
                else if (node->parent && node->parent->color)
                {
                    ft::Node_red_black<Key, T>    *sibling = (node == node->parent->left) ? node->parent->right : node->parent->left;
                    if (sibling && sibling->color && sibling->left && !sibling->left->color && sibling->right && sibling->right->color)
                    {

                    }
                }
            }

            bool ckeck_double_black(ft::Node_red_black<Key, T> *node)
            {
                if (node && node->color && \
                    ((!node->left && !node->right) \
                    || (((node->left && node->left->color) && (node->right && node->right->color))) \
                    || (node->left && node->left->color && !node->right) \
                    || (node->right && node->right->color && !node->left) ) )
                    return true;
                return false;
            }

            void    delete_one_red_black(ft::Node_red_black<Key, T> *node)
            {
                if (!node->left && !node->right)
                {
                    if (!node->parent)
                        root = nullptr;
                    else
                    {
                        if (node->parent->left == node)
                            node->parent->left = nullptr;
                        else
                            node->parent->right = nullptr;
                    }
                    destroy_node(node);
                    _size--;
                }
                else if (node->right) 
                {
                    ft::Node_red_black<Key, T>    *successor = in_order_successor(node);
                    alloc_pair.destroy(node->data);
                    alloc_pair.construct(node->data, *(successor->data));
                    delete_one_red_black(successor);
                }
                else
                {
                    ft::Node_red_black<Key, T>    *predecessor = in_order_predecessor(node);
                    alloc_pair.destroy(node->data);
                    alloc_pair.construct(node->data, *(predecessor->data));
                    delete_one_red_black(predecessor);
                }
            }

            // ! ERASE A NODE START
            bool    erase_red_black(const Key& _val)
            {
                ft::Node_red_black<Key, T>    *node = search_red_black(get_root(), _val);
                
                if (node)
                {
                    delete_one_red_black(node);
                    return true;
                }
                return false;
            }

            ft::Node_red_black<Key, T>    * get_root(void) const { return root; }
            
            void    destroy_node(ft::Node_red_black<Key, T> *node)
            {
                if (!node)
                    return ;
                alloc_pair.destroy(node->data);
                alloc_pair.deallocate(node->data, 1);
                alloc.destroy(node);
                alloc.deallocate(node, 1);
            }
            
            void    left_rotate(Node_red_black<Key, T> *node)
            {
                if (!node)  
                    return ;
                Node_red_black<Key, T>    *node_2 = (node && node->parent) ? node->parent : nullptr;
                Node_red_black<Key, T>    *node_3 = (node->parent && node->parent->parent) ? node->parent->parent : nullptr;
                
                if (!node_2 || !node_3)
                    return ;

                node_2->parent = node_3->parent;
                if (!node_2->parent)
                    root = node_2;
                {
                    if (node_3->parent && node_3->parent->left == node_3)
                        node_3->parent->left = node_2;
                    else if (node_3->parent && node_3->parent->right == node_3)
                        node_3->parent->right = node_2;
                }
                node_3->parent = node_2;
                
                
                node_3->right = node_2->left;
                node_2->left = node_3;
            }

            void    right_rotate(Node_red_black<Key, T> *node)
            {
                if (!node)
                    return ;
                Node_red_black<Key, T>    *node_2 = node->parent ? node->parent : nullptr;
                Node_red_black<Key, T>    *node_3 = (node->parent && node->parent->parent) ? node->parent->parent : nullptr; 

                if (!node_2 || !node_3)
                    return ;
                node_2->parent = node_3->parent;
                
                if (!node_2->parent)
                    root = node_2;
                else
                {
                    if (node_3->parent && node_3->parent->left == node_3)
                        node_3->parent->left = node_2;
                    else if (node_3->parent && node_3->parent->right == node_3)
                        node_3->parent->right = node_2;
                    node_3->parent = node_2;
                }
                
                node_3->left = node_2->right;
                node_2->right = node_3;
            }

            void    right_to_left_rotate(Node_red_black<Key, T> *node)
            {
                Node_red_black<Key, T>    *node_2 = node->parent;

                node_2->parent->left = node;
                node->parent = node_2->parent;
                node_2->parent = node;
                node_2->right = nullptr;
                node->left = node_2;
            }

            void    left_to_right_rotate(Node_red_black<Key, T> *node)
            {
                Node_red_black<Key, T>    *node_2 = node->parent;

                node_2->parent->right = node;
                node->parent = node_2->parent;
                node_2->parent = node;
                node_2->left = nullptr;
                node->right = node_2;
            }
            
            void    recolor_red_black(Node_red_black<Key, T> *_node)
            {
                
                Node_red_black<Key, T>    *tmp = _node;

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

            void    insert_on_node(Node_red_black<Key, T> *node, const value_type& _val)
            {
                if (Comp(node->data->first, _val.first))
                {
                    if (node->right)
                        insert_on_node(node->right, _val);
                    else
                    {
                        Node_red_black<Key, T>    *tmp = init_node(false, _val, node);
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
                        Node_red_black<Key, T>    *tmp = init_node(false, _val, node);
                        node->left = tmp;
                        recolor_red_black(tmp);
                        _size++;
                    }
                }
            }

            void insert_red_black(const value_type& _val)
            {
                if (!root)
                {
                    root = init_node(true, _val, nullptr);
                    _size++;
                }
                else
                    insert_on_node(root, _val);
            }

            void    show_tree_2D(Node_red_black<Key, T> *node, int space)
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

            void    show_tree(Node_red_black<Key, T> *node)
            {
                std::cout << "SHOW TREE THE SIZE OF THIS TREE IS :: " << _size << std::endl;
                show_tree_2D(node, 0);
            }
            
    };   
}