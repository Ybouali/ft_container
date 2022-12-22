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

    template <class Key, class T, class Alloc = std::allocator<ft::Node<Key, T> > >
    class Tree
    {
        public :
            Node<Key, T>    *root;
            Alloc           alloc;
        public :
            Tree (): root (nullptr) {}
            
            Tree (const Tree &other): root(other.root) {}
            ~Tree () {
                show_tree(root);
            }

            Node<Key, T> *init_node(bool color, const Key &_key, const T &value, Node<Key, T> *_parent)
            {
                Node<Key, T>    *new_node = alloc.allocate(1);
                new_node->color = color;
                new_node->left = nullptr;
                new_node->right = nullptr;
                new_node->parent = _parent;
                new_node->data = ft::pair<Key, T>(_key, value);
                return new_node;
            }

            void    insert_on_node(Node<Key, T> *node, const Key &_key, const T &_value)
            {
                if (node->data.first < _key)
                {
                    if (node->right)
                        insert_on_node(node->right, _key, _value);
                    else
                        node->right = init_node(false, _key, _value, node);
                }
                else if (node->data.first > _key)
                {
                    if (node->left)
                        insert_on_node(node->left, _key, _value);
                    else
                        node->left = init_node(false, _key, _value, node);
                }
            }

            void insert_red_black(const Key &_key, const T &_value)
            {
                // ? Need to check if the key is already exist 

                if (!root)
                    root = init_node(false, _key, _value, nullptr);
                else
                    insert_on_node(root, _key, _value);
            }

            void    show_tree_2D(Node<Key, T> *node, int space)
            {
                if (!node) return;

                space += COUNT;

                show_tree_2D(node->right, space);

                std::cout << std::endl;

                for (int i = COUNT; i < space; i++)
                    std::cout << " ";

                std::cout << node->data.first << std::endl;

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
            typedef typename Alloc::template rebind<ft::Node<Key, T> >::other                               allocator_type;
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
            void    insert(const Key& _key, const T& _value)
            {
                tree.insert_red_black(_key, _value);
            }
            
        
        public :
            key_type                                _key_map;
            mapped_type                             _mapped;
            key_compare                             _comp_key;
            allocator_type                          _alloc;
            ft::Tree<Key, T, allocator_type>        tree;

    };
}