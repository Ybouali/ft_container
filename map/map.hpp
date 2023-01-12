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

            // ! ITERATORS -------------------------------------------------------
            
            // ! BEGIN
            iterator begin() { return iterator(tree->begin(), nullptr); }

            // ! BEGIN CONST
            const_iterator begin() const { return const_iterator(tree->begin(), nullptr); }

            // ! END
            iterator end() { return iterator(nullptr, tree->end()) ; }

            // ! END CONST
            const_iterator end() const { return const_iterator(nullptr, tree->end()) ; }


            // ! CAPACITY -------------------------------------------------------

            // ! EMPTY
            bool empty() const { return (bool)size(); }

            // ! SIZE 
            size_type size() const { return tree->get_size(); }
            
            // ! MAX SIZE
            size_type max_size() const { return _alloc.max_size(); }

            // ! MODIFIERS -------------------------------------------------------

            // ! CLEAR
            void clear() { tree->destroy_avl(); }

            // ! INSERT VALUE TYPE     
            ft::pair<iterator,bool> insert(const value_type& val)
            {
                node_pointer found = tree->search(val.first);

                if (found)
                    return ft::make_pair(iterator(found), false);
                
                tree->insert(val);
                
                return ft::make_pair(iterator(tree->search(val.first)), true);
            }

            // ! INSERT POSITION 
            iterator insert(iterator pos, const value_type& _val)
            {
                (void*)pos;
                tree->insert(_val);
                return tree->search(_val.first);
            }

            // ! INSERT RANGE OF VALUES
            template <typename iterator>
            void insert(iterator first, iterator last)
            {
                while (first != last)
                {
                    tree->insert(*first);
                    first++;
                }
            }

            // ! ERASE POSITION OF VALUE
            void erase (iterator position)
            {

                tree->erase((*position).first);
            }

            // ! ERASE KEY TYPE
            size_type erase (const key_type& k)
            {
                node_pointer    node = tree->search(k);
                if (!node)
                    return 0;
                tree->erase(k);
                return 1;
            }

            // ! ERASE RANGE ITERATOR TYPE
            void erase (iterator first, iterator last)
            {
                while (first != last)
                {
                    erase(first);
                    first++;
                }
            }

            // ! SWAP MAP
            void swap (map& x)
            {
                std::swap(x._key_map, _key_map);
                std::swap(x._mapped, _mapped);
                std::swap(x._comp_key, _comp_key);
                std::swap(x._alloc, _alloc);
                std::swap(x._alloc_pair, _alloc_pair);
                std::swap(x.tree, tree);
            }

            // ! COUNT 
            size_type count (const key_type& k) const
            {
                node_pointer node = tree->search(k);
                return node ? 1 : 0;
            }
            // ! FIND WITHI KEY TYPE && RETURN ITERATOR TYPE
            iterator find(const Key& _val) { return tree->search(_val); }

            // ! FIND WITHI KEY TYPE && RETURN CONST ITERATOR TYPE
            const_iterator find(const Key& _val) const { return tree->search(_val); }

            
            
            const_iterator lower_bound (const key_type& k) const
            {
                node_pointer    found = tree->search(k);

                if (found) return increment(found);

                return found;
            }


            

            


            

            
            
            

            
            

        private :
            key_type                                                                _key_map;
            mapped_type                                                             _mapped;
            key_compare                                                             _comp_key;
            allocator_type                                                          _alloc;
            allocator_type_pair                                                     _alloc_pair;
            tree_type*                                                               tree;

    };
}