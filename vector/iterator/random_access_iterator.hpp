#pragma once

#include "./iterator_traits.hpp"


namespace ft{

    template <class T>
    class random_access_iterator
    {
        public :
            typedef typename iterator_traits<T*>::value_type           value_type;
            typedef typename iterator_traits<T*>::difference_type      difference_type;
            typedef typename iterator_traits<T*>::pointer              pointer;
            typedef typename iterator_traits<T*>::reference            reference;
            typedef typename iterator_traits<T*>::iterator_category    iterator_category;
            
            random_access_iterator(): ptr(0) { };
            
            random_access_iterator(pointer it) { 
                this->ptr = it;
            };

            random_access_iterator(random_access_iterator const &  it) { 
                this->ptr = it.ptr;
            };
            
            ~random_access_iterator() { };

            operator random_access_iterator<const value_type>() const {
                return random_access_iterator<const value_type>(ptr);
            }

            pointer     base() const 
            {
                return (this->ptr);
            }
            
            friend bool operator== (const random_access_iterator<T>& other, const random_access_iterator<T>& other1)
            {
                return (other.ptr == other1.ptr);
            }

            friend bool operator!= (const random_access_iterator<T>& other, const random_access_iterator<T>& other1)
            {
                return (other.ptr != other1.ptr);
            }

            friend bool operator< (const random_access_iterator<T>& other, const random_access_iterator<T>& other1)
            {
                return (other.ptr < other1.ptr);
            }
            
            friend bool operator> (const random_access_iterator<T>& other, const random_access_iterator<T>& other1)
            {
                return (other.ptr > other1.ptr);
            }
            friend bool operator>= (const random_access_iterator<T>& other, const random_access_iterator<T>& other1)
            {
                return (other.ptr >= other1.ptr);
            }
            friend bool operator<= (const random_access_iterator<T>& other, const random_access_iterator<T>& other1)
            {
                return (other.ptr <= other1.ptr);
            }
            
            reference operator*() const { return *(this->ptr); }
            
            random_access_iterator& operator++(void) { ++(this->ptr); return *this; }
            
            // it shoud be return the class type not a reference on the class
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