#pragma once

#include "./iterator_traits.hpp"


namespace ft{

    template <class T>
    class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
        public :
            typedef typename iterator<std::random_access_iterator_tag, T>::value_type           value_type;
            typedef typename iterator<std::random_access_iterator_tag, T>::difference_type      difference_type;
            typedef typename iterator<std::random_access_iterator_tag, T>::pointer              pointer;
            typedef typename iterator<std::random_access_iterator_tag, T>::reference            reference;
            typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category    iterator_category;
            
            random_access_iterator(): ptr(0) { };
            
            random_access_iterator(pointer it) {
                this->ptr = it;
            };

            random_access_iterator(random_access_iterator const &  it) { 
                this->ptr = it.ptr;
            };

            operator random_access_iterator<const value_type>() const {
                return random_access_iterator<const value_type>(ptr);
            }
            
            ~random_access_iterator() { };

            pointer     base() const 
            {
                return (this->ptr);
            }

            reference operator*() { return *(this->ptr); }

            // const_reference operator*() const { return *(this->ptr); }

            pointer operator->() { return base(); }

            // const_pointer operator->() const { return base(); }
            
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
            
            random_access_iterator& operator++(void) {
                ++(this->ptr);
                return *this;
            }
            
            random_access_iterator operator++(int) {
                random_access_iterator tmp = *this;    
                ++(*this);
                return tmp;
            }

            random_access_iterator& operator--(void) { --(this->ptr); return *this; }
            
            random_access_iterator operator--(int) {
                random_access_iterator tmp = *this;
                --(*this);
                return tmp;
            }

            random_access_iterator operator+(difference_type const & n) const {
                random_access_iterator tmp = *this;
                return tmp += n;
            }

            random_access_iterator& operator+=(difference_type n) { 
                
                difference_type m = n;
                difference_type r = 0;
                
                if (m >= 0)
                    while (m--)
                        ++r;
                else
                    while (m++)
                        --r;
                this->ptr = this->ptr + r;
                return *(this); 
            }

            random_access_iterator& operator-=(difference_type n) {  return *this += -n; }
            
            random_access_iterator operator-(const difference_type&  n) const {
                random_access_iterator tmp = *this;
                tmp -= n;
                return (tmp);
            }
            
            template < class iter >
            difference_type operator-(const random_access_iterator < iter > & it) const { return (this->ptr - it.base()); }

            reference operator[](const difference_type n) const { return *(ptr + n); }

            friend random_access_iterator operator+(ptrdiff_t n, const random_access_iterator<T>& it) {
                random_access_iterator tmp = it;
                return tmp += n;
            }
        private :
            pointer     ptr;
    };
}