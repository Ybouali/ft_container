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
            
            iterator find(const Key& _val)
            {
                node_pointer result = tree.search(_val);
                return result;
            }

            void    erase(const Key& _val) { tree.erase(_val); }
             
            void    insert(const value_type& val)
            {
                tree.insert(val);
            }

            // ! SIZE 
            size_type size() const { return tree.size(); }

            // ! EMPTY
            bool empty() const { return size() ? false : true; }
            
            // ! END
            iterator end() { return iterator(nullptr, tree.end()) ; }

            // ! BEGIN
            iterator begin()
            {
                return iterator(tree.begin(), nullptr);
            }

            // const_iterator begin() const
            // {
            //     return nullptr;
            // }

            // iterator end()
            // {
            //     return tree.get_super_root();
            // }
        private :
            key_type                                                                _key_map;
            mapped_type                                                             _mapped;
            key_compare                                                             _comp_key;
            allocator_type                                                          _alloc;
            allocator_type_pair                                                     _alloc_pair;
            tree_type                                                               tree;

    };
}