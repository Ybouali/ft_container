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

            bidirectional_iterator() : _node_curr(), ptr() {}

            bidirectional_iterator(const bidirectional_iterator& other) : _node_curr(other._node_curr), ptr(other.ptr) {}

            bidirectional_iterator& operator=(const bidirectional_iterator& other)
            {
                this->_node_curr = other._node_curr;
                this->ptr = other.ptr;
                return *this;
            }

            bidirectional_iterator(node_type_p __root)
            {
                _node_curr = __root;
                ptr = _node_curr->data;
            }

            ~bidirectional_iterator() {}
            
            reference   operator*() { return *(this->_node_curr->data); }

            pointer     operator->() { return this->_node_curr->data; }

            bidirectional_iterator& operator++(void)
            {
                _node_curr = increment(_node_curr);
                return (*this);
            }

            bidirectional_iterator& operator--(void)
            {
                _node_curr = decrement(_node_curr);
                return (*this);
            }

        private :
            node_type_p     _node_curr;
            pointer         ptr;
        
    };
}