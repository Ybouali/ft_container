#pragma once

#include "./utils/avl_tree.hpp"

namespace ft
{
    template <
        class Key,
        class T,
        class Compare = std::less<Key>,
        class Alloc = std::allocator<ft::pair<const Key, T> >
    >
    class map
    {
        private :
            typedef typename ft::Node_avl<Key, T>*                                                       node_pointer;

        public:
            // ? typedefs
            typedef Key                                                                                 key_type;
            typedef T                                                                                   mapped_type;
            typedef typename ft::pair<const key_type, mapped_type>                                      value_type;
            typedef Compare                                                                             key_compare;
            // ! value_compare 
            typedef Alloc                                                                               allocator_type_pair;
            typedef typename Alloc::template rebind<ft::Node_avl<Key, T> >::other                       allocator_type;                      
            typedef ptrdiff_t                                                                           difference_type;
            typedef size_t                                                                              size_type;
            typedef typename allocator_type::reference                                                  reference;
            typedef typename allocator_type::const_reference                                            const_reference;
            typedef typename allocator_type::pointer                                                    pointer;
            typedef typename allocator_type::const_pointer                                              const_pointer;
            typedef typename ft::avl_tree<Key, T, key_compare, allocator_type_pair>                     tree_type;
            typedef typename ft::bidirectional_iterator<value_type, ft::Node_avl<Key, T> >             iterator;
            typedef typename ft::bidirectional_iterator<const value_type, ft::Node_avl<Key, T> >       const_iterator;
            typedef typename ft::reverse_iterator<iterator >                                            reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator >                                      const_reverse_iterator;

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            : _key_map(), _mapped(), _comp_key(comp), _alloc(alloc), tree(nullptr)
            {
                if (!tree)
                    tree = new tree_type();
            }

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _key_map(), _mapped(), _comp_key(comp), _alloc(alloc)
            {
                if (tree)
                    delete tree;
                else 
                    tree = new tree_type();

                insert(first, last);
            }

            // map (const map& x)
            // {
            //     (void)x;
            // }

            ~map()
            {
                delete tree;
                tree = nullptr;
                // while (1);
            }

            // ! ELEMENT ACCESS -------------------------------------------------------

            // ! OPERATOR []
            mapped_type& operator[] (const key_type& _key)
            {
                node_pointer _node = tree->search(_key);

                if (!_node)
                    insert(ft::make_pair(_key, mapped_type()));
                _node = tree->search(_key);
                return _node->data->second;
            }
            
            iterator find(const Key& _val)
            {
                node_pointer result = tree->search(_val);
                return result;
            }

            // ! CLEAR
            void clear() { tree->destroy_avl(); }

            void    erase(const Key& _val) { tree->erase(_val); }

            // ! INSERT VALUE TYPE     
            value_type    insert(const value_type& val)
            {
                // std::cout << "insert inserted" << std::endl;
                node_pointer inserted = tree->insert(val);
                return *(inserted->data);
            }

            // ! INSERT POSITION 
            iterator insert(iterator pos, const value_type& _val)
            {
                (void*)pos;
                node_pointer inserted = tree->insert(_val);
                return *(inserted->data);
            }

            // ! INSERT RANGE OF VALUES
            template <typename InputIterator>
            void insert(InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    tree->insert(*first);
                    first++;
                }
            }


            // ! SIZE 
            size_type size() const { return tree->get_size(); }

            // ! EMPTY
            bool empty() const { return size() ? false : true; }
            
            // ! END
            iterator end() { return iterator(nullptr, tree->end()) ; }

            // ! END CONST
            const_iterator end() const { return const_iterator(nullptr, tree->end()) ; }

            // ! BEGIN
            iterator begin() { return iterator(tree->begin(), nullptr); }

            // ! BEGIN CONST
            const_iterator begin() const { return const_iterator(tree->begin(), nullptr); }
            

        private :
            key_type                                                                _key_map;
            mapped_type                                                             _mapped;
            key_compare                                                             _comp_key;
            allocator_type                                                          _alloc;
            allocator_type_pair                                                     _alloc_pair;
            tree_type*                                                               tree;

    };
}