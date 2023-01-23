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
            // ! TYPEDEFS
            class value_compare;
            typedef Key                                                                                 key_type;
            typedef T                                                                                   mapped_type;
            typedef typename ft::pair<const key_type, mapped_type>                                      value_type;
            typedef Compare                                                                             key_compare;
            typedef Alloc                                                                               allocator_type;                    
            typedef ptrdiff_t                                                                           difference_type;
            typedef size_t                                                                              size_type;
            typedef typename allocator_type::reference                                                  reference;
            typedef typename allocator_type::const_reference                                            const_reference;
            typedef typename allocator_type::pointer                                                    pointer;
            typedef typename allocator_type::const_pointer                                              const_pointer;
            typedef typename ft::avl_tree<Key, T, key_compare, allocator_type>                          tree_type;
            typedef typename ft::bidirectional_iterator<value_type, ft::Node_avl<Key, T> >              iterator;
            typedef typename ft::bidirectional_iterator<const value_type, const ft::Node_avl<Key, T> >        const_iterator;
            typedef typename ft::reverse_iterator<iterator >                                            reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>                                       const_reverse_iterator;
        

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            : _key_map(), _mapped(), _comp_key(comp), _alloc_pair(alloc), _tree(), _value_comp() { }

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _key_map(), _mapped(), _comp_key(comp), _alloc_pair(alloc), _value_comp()
            {
                insert(first, last);
            }

            map (const map& x)
            {
                *this = x;
            }

            map& operator=(const map& other)
            {
                if (!empty())
                    clear();
                _key_map = other._key_map;
                _mapped = other._mapped;
                _comp_key = other._comp_key;
                _alloc_pair = other._alloc_pair;
                
                if (other.size())
                    insert(other.begin(), other.end());

                _value_comp = other._value_comp;
                return *this;
            }

            ~map() { }

            // ! GET ALLOCATOR
            allocator_type get_allocator() const { return _alloc_pair; }

            // ! KEY COMP
            key_compare key_comp() const { return (_comp_key); }

            // ! VALUE COMP
            value_compare  value_comp() const { return (_value_comp); }

            // ! ELEMENT ACCESS -------------------------------------------------------

            // ! AT
            mapped_type& at (const key_type& k)
            {
                iterator it = find(k);

                if (it == end())
                    throw std::out_of_range("OUT OF RANGE");
                return it->second;
            }
            
            // ! AT CONST
            const mapped_type& at (const key_type& k) const
            {
                const_iterator it = find(k);

                if (it == end())
                    throw std::out_of_range("OUT OF RANGE");
                return it->second;
            }

            // ! OPERATOR []
            mapped_type& operator[] (const key_type& _key) { return (insert(ft::make_pair(_key, mapped_type())).first)->second; }

            // ! ITERATORS -------------------------------------------------------
            
            // ! BEGIN
            iterator begin() { return iterator(_tree.begin(), _tree.end()); }

            // ! BEGIN CONST
            const_iterator begin() const { return const_iterator(_tree.begin(), _tree.end()); }

            // ! END
            iterator end() { return iterator(nullptr, _tree.end()); }

            // ! END CONST
            const_iterator end() const { return const_iterator(nullptr, _tree.end()) ; }

            // ! RBEGIN
            reverse_iterator rbegin() {
                reverse_iterator rit(end());
                return rit;
            }

            // ! RBEGIN CONST
            const_reverse_iterator rbegin() const {
                const_reverse_iterator rit(end());
                return rit;
            }

            // ! REND
            reverse_iterator rend() {
                
                reverse_iterator    rit(begin());
                return (rit);
            }

            // ! REND CONST
            const_reverse_iterator rend() const {
                const_reverse_iterator    rit(begin());
                return (rit);
            }


            // ! CAPACITY -------------------------------------------------------

            // ! EMPTY
            bool empty() const { return _tree.get_size() ? false : true; }

            // ! SIZE 
            size_type size() const { return _tree.get_size(); }
            
            // ! MAX SIZE
            size_type max_size() const { return _alloc_pair.max_size(); }

            // ! MODIFIERS -------------------------------------------------------

            // ! CLEAR
            void clear() { _tree.destroy_avl(); }

            // ! INSERT VALUE TYPE     
            ft::pair<iterator,bool> insert(const value_type& val)
            {
                node_pointer found = _tree.search(val.first);

                if (found)
                    return ft::make_pair(iterator(found), false);
                
                _tree.insert(val);
                
                return ft::make_pair(iterator(_tree.search(val.first)), true);
            }

            // ! INSERT POSITION 
            iterator insert(iterator pos, const value_type& _val)
            {
                (void)pos;
                _tree.insert(_val);
                return _tree.search(_val.first);
            }

            // ! INSERT RANGE OF VALUES
            template <typename iterator>
            void insert(iterator first, iterator last)
            {
                while (first != last)
                {
                    _tree.insert(*first);
                    first++;
                }
            }

            // ! ERASE POSITION OF VALUE
            void erase (iterator position) { _tree.erase(position->first); }

            // ! ERASE KEY TYPE
            size_type erase (const key_type& k)
            { 
                if (find(k) == end())
                    return 0;
                _tree.erase(k);
                return 1;
            }

            // ! ERASE RANGE ITERATOR TYPE
            void erase (iterator first, iterator last)
            {
                ft::vector<key_type> tmp;
				for (; first != last; first++)
						tmp.push_back(first->first);
				for (size_type i = 0; i < tmp.size(); i++)
					_tree.erase(tmp[i]);
            }

            // ! SWAP MAP
            void swap (map& x)
            {
                map tmp;

                std::swap(x._key_map, _key_map);
                std::swap(x._mapped, _mapped);
                std::swap(x._comp_key, _comp_key);
                std::swap(x._alloc_pair, _alloc_pair);
                x._tree.swap(_tree);
                std::swap(x._value_comp, _value_comp);
            }

            // ! COUNT 
            size_type count (const key_type& k) const
            {
                node_pointer node = _tree.search(k);
                return node ? 1 : 0;
            }
            // ! FIND WITHI KEY TYPE && RETURN ITERATOR TYPE
            iterator find(const Key& _val) { return _tree.search(_val); }

            // ! FIND WITHI KEY TYPE && RETURN CONST ITERATOR TYPE
            const_iterator find(const Key& _val) const { return _tree.search(_val); }

            // ! EQUAL RANGE && RETURN ITERATOR
            ft::pair<iterator, iterator> equal_range (const key_type& k) {
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            }

            // ! EQUAL RANGE && RETURN CONST ITERATOR TYPE
            ft::pair<const_iterator, const_iterator> equal_range (const key_type& k) const {
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            }
            
            // ! LOWER BOUND && RETURN NON CONST ITERATOR TYPE
            iterator lower_bound (const key_type& k) {
                iterator b = begin();
                iterator e = end();
                while (b != e) {
                    if (!_comp_key(b->first,k))
                        return b; 
                    b++;
                }
                return e;
            }
            
            // ! LOWER BOUND && RETURN CONST ITERATOR TYPE
            const_iterator lower_bound (const key_type& k) const {
                const_iterator b = begin();
                const_iterator e = end();
                while (b != e) {
                    if (!_comp_key(b->first,k))
                        return b; 
                    b++;
                }
                return e;
            }

            // ! UPPER BOUND && RETURN NON CONST ITERATOR TYPE
            iterator upper_bound (const key_type& k) {
                iterator b = begin();
                iterator e = end();
                while (b != e) {
                    if (_comp_key(k, b->first))
                        return b; 
                    b++;
                }
                return e;
            }

            // ! UPPER BOUND && RETURN CONST ITERATOR TYPE
            const_iterator upper_bound (const key_type& k) const {
                const_iterator b = begin();
                const_iterator e = end();
                while (b != e) {
                    if (_comp_key(k, b->first))
                        return b; 
                    b++;
                }
                return e;
            }

            // OPERATOR LOGICAL ------------------------------------------------

            template <class _Key, class _T, class _Compare, class _Alloc>
            friend bool operator== ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs );
            
            template <class _Key, class _T, class _Compare, class _Alloc>
            friend bool operator!= ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs );
            
            template <class _Key, class _T, class _Compare, class _Alloc>
            friend bool operator<  ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs );
            
            template <class _Key, class _T, class _Compare, class _Alloc>
            friend bool operator<= ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs );
            
            template <class _Key, class _T, class _Compare, class _Alloc>
            friend bool operator>  ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs );
            
            template <class _Key, class _T, class _Compare, class _Alloc> 
            friend bool operator>= ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs );
              
        private :
            key_type                                                                _key_map;
            mapped_type                                                             _mapped;
            key_compare                                                             _comp_key;
            allocator_type                                                          _alloc_pair;
            tree_type                                                               _tree;
            value_compare                                                           _value_comp;

    };

    template <class _Key, class _T, class _Compare, class _Alloc>
    bool operator== ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs )
    {
        if (lhs.size() == rhs.size())
            return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
        return false;        
    }
    
    template <class _Key, class _T, class _Compare, class _Alloc>
    bool operator!= ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs ) { return !(lhs == rhs); }
    
    template <class _Key, class _T, class _Compare, class _Alloc>
    bool operator<  ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs ) { return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }
    
    template <class _Key, class _T, class _Compare, class _Alloc>
    bool operator<= ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs ) { return ((lhs < rhs) || (lhs == rhs)); }
            
    template <class _Key, class _T, class _Compare, class _Alloc>
    bool operator>  ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs ) { return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()); }
    
    template <class _Key, class _T, class _Compare, class _Alloc>
    bool operator>= ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs ) { return ((lhs > rhs) || (lhs == rhs)); }


    // ----------------------------------------------------------------

	template <class _Key, class _T, class _Compare, class _Alloc>
	class map<_Key,_T,_Compare,_Alloc>::value_compare : public std::binary_function<value_type, value_type, bool>
	{
		friend class map<_Key,_T,_Compare,_Alloc>;
		protected:
			_Compare _comp;
		public:
			value_compare(const _Compare &c) : _comp(c) { }
			value_compare(){};
			bool operator()(const value_type &lhs, const value_type &rhs) const
			{
				return(_comp(lhs.first, rhs.first));
			}
	};

    // ----------------------------------------------------------------
    
    template <class _Key, class _T, class _Compare, class _Alloc>
    void swap (map<_Key,_T,_Compare,_Alloc>& x, map<_Key,_T,_Compare,_Alloc>& y)
    {
    	x.swap(y);
    }
}