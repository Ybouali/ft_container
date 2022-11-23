#pragma once

#include "./iterator_traits.hpp"


namespace ft{

    template <class T>
    class random_access_iterator : public iterator<std::random_access_iterator_tag, T>
    {
        public :
            typedef typename iterator<std::random_access_iterator_tag, T>::value_type           value_type;
            typedef typename iterator<std::random_access_iterator_tag, T>::difference_type      difference_type;
            typedef typename iterator<std::random_access_iterator_tag, T>::pointer              pointer;
            typedef typename iterator<std::random_access_iterator_tag, T>::reference            reference;
            typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category    iterator_category;
            random_access_iterator(): ptr(NULL) { };
            random_access_iterator(pointer it) { this->ptr = it; };
            random_access_iterator(const reference it) { *this = it; };
            ~random_access_iterator() { };

            reference operator= (const reference other) { this->ptr = other.ptr; }

            bool operator== (const random_access_iterator& other) const
            {
                if (this->ptr == other.ptr)
                    return true;
                return false;
            }
            bool operator!= (const random_access_iterator& other) const
            {
                return !(*this == other);
            }
            bool operator< (const random_access_iterator& other) const
            {
                if (this->ptr < other.ptr)
                    return true;
                return false;
            }
            bool operator> (const random_access_iterator& other) const
            {
                if (this->ptr > other.ptr)
                    return true;
                return false;
            }
            bool operator>= (const random_access_iterator& other) const
            {
                if (*this == other || *this > other)
                    return true;
                return false;
            }
            bool operator<= (const random_access_iterator& other) const
            {
                if (*this == other || *this < other)
                    return true;
                return false;
            }
            
            reference operator*() const { return *(this->ptr); }
            
            random_access_iterator& operator++(void) { ++(this->ptr); return *this; }
            
            random_access_iterator& operator++(int) { (this->ptr)++; return *this; }

            random_access_iterator operator+(difference_type const & n) const { return (this->ptr + n); }

            random_access_iterator& operator+=(difference_type n) { 
                this->ptr = this->ptr + n;
                return *(this); 
            }
            random_access_iterator& operator-=(difference_type n) { 
                this->ptr = this->ptr - n;
                return *(this); 
            }
            
            random_access_iterator operator-(const difference_type&  n) const { return (this->ptr - n); }
            
            difference_type operator-(const random_access_iterator& it) const { return (this->ptr - it.ptr); }

            reference operator[](const difference_type n) const { return (this->ptr[n]); }

            random_access_iterator& operator--(void) { --(this->ptr); return *this; }
            
            random_access_iterator& operator--(int) { (this->ptr)--; return *this; }

            friend random_access_iterator operator+(ptrdiff_t n, const random_access_iterator<T>& it) { return it + n; }
        private :
            pointer     ptr;
    };
}