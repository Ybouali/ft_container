#include "../utils/utils.hpp"

namespace ft
{
    template <class T1, class T2>
    class Node
    {
        private :
            Node                *left;
            Node                *right;
            bool                color;
            ft::pair<T1, T2>    data;
        public :
            Node(): left(nullptr), right(nullptr), color(false) {}
            Node(const Node& other): left(other.left), right(other.right), color(other.color), data(data) {}
            ~Node() {}
    };
      
    template <
        class Key,
        class T,
        class Compare = std::less<Key>,
        class Alloc = std::allocator<ft::pair<const Key,T> >
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
            typedef Alloc                                                                           allocator_type;
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

            bool empty () const { return true; }
        
        protected :
            key_type        _key_map;
            mapped_type     _mapped;
            key_compare     _comp_key;
            allocator_type  _alloc;

    };
}