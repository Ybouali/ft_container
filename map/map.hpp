#include "../vector/vector.hpp"

#define COUNT 10

namespace ft
{

    // ! false == RED && true == black
    template <class Key, class T > 
    struct Node {
        Node                *left;
        Node                *right;
        Node                *parent;
        bool                color;
        ft::pair<Key, T>    data;
    };

    template <
        class Key,
        class T,
        class Alloc = std::allocator<ft::Node<Key, T> >,
        class _comp = std::less<Key>
    >
    class Tree
    {
        private :
            Node<Key, T>    *root;
            Alloc           alloc;
            _comp           Comp;
        public :
            typedef ft::pair<const Key, T>   value_type;

            Tree (): root (nullptr) {}
            
            Tree (const Tree &other): root(other.root) {}
            ~Tree () {
                std::cout << "-------------------------------------------" << std::endl;
                show_tree(root);
            }

            Node<Key, T> *init_node(bool color, const value_type& _val, Node<Key, T> *_parent)
            {
                Node<Key, T>    *new_node = alloc.allocate(1);
                new_node->color = color;
                new_node->left = nullptr;
                new_node->right = nullptr;
                new_node->parent = _parent ? _parent : nullptr;
                new_node->data = _val;
                return new_node;
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
                if (Comp(node->data.first, _val.first))
                {
                    if (node->right)
                        insert_on_node(node->right, _val);
                    else
                    {
                        Node<Key, T>    *tmp = init_node(false, _val, node);
                        node->right = tmp;
                        // if (node->right->data.first == 16)
                        // {
                        //     Node<Key, T> *tmp = node->right;
                        //     show_tree(root);
                        //     right_to_left_rotate(tmp);
                        //     show_tree(root);

                        //     right_rotate(tmp->left);
                        // }
                        recolor_red_black(tmp);
                    }
                }
                else if (Comp(_val.first, node->data.first))
                {
                    if (node->left)
                        insert_on_node(node->left, _val);
                    else
                    {
                        Node<Key, T>    *tmp = init_node(false, _val, node);
                        node->left = tmp;
                        // if (node->left->data.first == 17)
                        // {
                        //     Node<Key, T>    *tmp = node->left;
                        //     show_tree(root);
                        //     left_to_right_rotate(tmp);
                        //     show_tree(root);
                        //     left_rotate(tmp->right);
                        // }
                        recolor_red_black(tmp);
                    }
                }
            }

            // ! recolor_red_black Not done yet 
            void    recolor_red_black(Node<Key, T> *_node)
            {
                
                Node<Key, T>    *tmp = _node;

                if (!_node || !_node->parent || _node->parent->color)
                    return ;
                // if (_node->data.first == 25 && _node->right && _node->right->right)
                // {
                //     std::cout << "yes" << std::endl;
                //     return ;
                // }
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

                std::cout << "| " << node->data.first;
                node->color ? std::cout << " BLACK |" << std::endl : std::cout << " RED |" << std::endl;
                
                show_tree_2D(node->left, space);
            }

            void    show_tree(Node<Key, T> *node)
            {
                std::cout << "Show Tree well be called :)" << std::endl;
                show_tree_2D(node, 0);
            }
            
    };
      
    template <
        class Key,
        class T,
        class Compare = std::less<Key>,
        class Alloc = std::allocator<ft::pair<const Key, T> >
    >
    class map
    {
        public:
            // ? typedefs
            typedef Key                                                                             key_type;
            typedef T                                                                               mapped_type;
            typedef ft::pair<const key_type, mapped_type>                                           value_type;
            typedef Compare                                                                         key_compare;
            // ! value_compare 
            typedef typename Alloc::template rebind<ft::Node<Key, T> >::other                       allocator_type;
            // typedef std::allocator<ft::Node<Key, T> >                                               allocator_type_n;                      
            typedef ptrdiff_t                                                                       difference_type;
            typedef size_t                                                                          size_type;
            typedef typename allocator_type::reference                                              reference;
            typedef typename allocator_type::const_reference                                        const_reference;
            typedef typename allocator_type::pointer                                                pointer;
            typedef typename allocator_type::const_pointer                                          const_pointer;
            // typedef typename bidirectional_iterator<value_type>::iterator                        iterator;
            // typedef typename bidirectional_iterator<value_type>::const_iterator                  const_iterator;
            // typedef typename ft::reverse_iterator<ft::bidirectional_iterator<value_type> >       reverse_iterator;
            // typedef typename ft::reverse_iterator<ft::bidirectional_iterator<const value_type> > const_reverse_iterator;

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _key_map(), _mapped(), _comp_key(comp), _alloc(alloc) {}

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _key_map(), _mapped(), _comp_key(comp), _alloc(alloc)
            {
                (void*) first;
                (void*) last;
            }

            map (const map& x)
            {
                (void*)x;
            }

            ~map()
            {
                
            }

            // bool empty () const { return true; }
            // ! See the cplusplus before implementation of any method 
            void    insert(const value_type& val)
            {
                // std::cout << val.first << std::endl;
                tree.insert_red_black(val);
                // tree.root->data.first = 100;
            }
            
        
        private :
            key_type                                        _key_map;
            mapped_type                                     _mapped;
            key_compare                                     _comp_key;
            allocator_type                                  _alloc;
            ft::Tree<Key, T, allocator_type, key_compare>   tree;

    };
}