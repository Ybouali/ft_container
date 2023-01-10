#pragma once

#include "../vector/vector.hpp"
#include "../map/utils/Node_avl.hpp"

namespace ft {
    
    template <class P, class T>
    class bidirectional_iterator 
    {
        private :
            typedef T*                                   node_type_p;
        public:
            typedef std::bidirectional_iterator_tag     iterator_category;
            typedef P                                   value_type;
            typedef ptrdiff_t                           difference_type;
            typedef size_t                              size_type;
            typedef P*                                  pointer;
            typedef P&                                  reference;

            bidirectional_iterator() : _node_curr(), _end() {}

            bidirectional_iterator(const bidirectional_iterator& other) : _node_curr(other._node_curr), _end(other._end) {}

            bidirectional_iterator& operator=(const bidirectional_iterator& other)
            {
                this->_node_curr = other._node_curr;
                this->_end = other._end;
                return *this;
            }

            bidirectional_iterator(node_type_p node, node_type_p last)
            {
                _node_curr = node;
                _end = last;
            }

            bidirectional_iterator(node_type_p node)
            {
                _node_curr = node;
                _end = nullptr;
            }

            ~bidirectional_iterator() {}
            
            reference   operator*() { return *(this->_node_curr->data); }

            pointer     operator->() { return this->_node_curr->data; }

            bidirectional_iterator& operator++(void)
            {
                _node_curr = increment(_node_curr);
                return (*this);
            }

            bidirectional_iterator operator++(int)
            {
                node_type_p node = _node_curr;
                _node_curr = increment(_node_curr);
                return (node);
            }

            bidirectional_iterator& operator--(void)
            {
                if (!_node_curr)
                    _node_curr = _end;
                else
                    _node_curr = decrement(_node_curr);
                return (*this);
            }

            bidirectional_iterator operator--(int)
            {
                node_type_p r_node;
                r_node = _node_curr;

                if (!_node_curr)
                    _node_curr = _end;
                else 
                    _node_curr = decrement(_node_curr);
                
                return (r_node);
            }

            bool    operator==(const bidirectional_iterator& other) const { return _node_curr == other._node_curr; }

            bool    operator!=(const bidirectional_iterator& other) const { return _node_curr != other._node_curr; }

            bool    operator>(const bidirectional_iterator& other) const { return _node_curr > other._node_curr; }

            bool    operator>=(const bidirectional_iterator& other) const { return _node_curr >= other._node_curr; }

            bool    operator<(const bidirectional_iterator& other) const { return _node_curr < other._node_curr; }

            bool    operator<=(const bidirectional_iterator& other) const { return _node_curr <= other._node_curr; }

            template <class p, class t>
            friend bool operator==(const bidirectional_iterator<p, t>& r, const bidirectional_iterator<p, t>& h);

            template <class p, class t>
            friend bool operator!=(const bidirectional_iterator<p, t>& r, const bidirectional_iterator<p, t>& h);

            template <class p, class t>
            friend bool operator<(const bidirectional_iterator<p, t>& r, const bidirectional_iterator<p, t>& h);
            
            template <class p, class t>
            friend bool operator<=(const bidirectional_iterator<p, t>& r, const bidirectional_iterator<p, t>& h);

            template <class p, class t>
            friend bool operator>(const bidirectional_iterator<p, t>& r, const bidirectional_iterator<p, t>& h);

            template <class p, class t>
            friend bool operator>=(const bidirectional_iterator<p, t>& r, const bidirectional_iterator<p, t>& h);
            
        private :
            node_type_p     _node_curr;
            node_type_p     _end;
    };
 
    template <class p, class t>
    bool operator==(const bidirectional_iterator<p, t>& r, const bidirectional_iterator<p, t>& h) { return *r == *h; }

    template <class p, class t>
    bool operator!=(const bidirectional_iterator<p, t>& r, const bidirectional_iterator<p, t>& h) { return *r != *h; }

    template <class p, class t>
    bool operator<(const bidirectional_iterator<p, t>& r, const bidirectional_iterator<p, t>& h) { return *r < *h; }

    template <class p, class t>
    bool operator<=(const bidirectional_iterator<p, t>& r, const bidirectional_iterator<p, t>& h) { return *r <= *h; }

    template <class p, class t>
    bool operator>(const bidirectional_iterator<p, t>& r, const bidirectional_iterator<p, t>& h) { return *r > *h; }

    template <class p, class t>
    bool operator>=(const bidirectional_iterator<p, t>& r, const bidirectional_iterator<p, t>& h) { return *r >= *h; }
}