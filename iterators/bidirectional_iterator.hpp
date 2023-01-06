#pragma once

#include "../vector/vector.hpp"

namespace ft {
    
    template <class T>
    class bidirectional_iterator 
    {
        public:
            typedef std::bidirectional_iterator_tag     iterator_category;
            typedef T                                   value_type;
            typedef ptrdiff_t                           difference_type;
            typedef size_t                              size_type;
            typedef T*                                  pointer;
            typedef T&                                  reference;
            
            bidirectional_iterator() : ptr() {}

            bidirectional_iterator(const bidirectional_iterator& other) : ptr(other.ptr) {}

            bidirectional_iterator& operator=(const bidirectional_iterator& other)
            {
                ptr = other.ptr;
                return *this;
            }

            bidirectional_iterator(pointer other) : ptr(other) {}

            ~bidirectional_iterator() {}
            
            reference   operator*() { return *(ptr); }

            pointer     operator->() { return ptr; }

            



        private :
            pointer ptr;
        
    };
}