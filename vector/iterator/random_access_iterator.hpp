#include "./iterator.hpp"


namespace ft{

    template <class T>
    class random_access_iterator : public iterator<std::random_access_iterator_tag, T>
    {
        typedef typename iterator<std::random_access_iterator_tag, T>::value_type           value_type;
        typedef typename iterator<std::random_access_iterator_tag, T>::difference_type      difference_type;
        typedef typename iterator<std::random_access_iterator_tag, T>::pointer              pointer;
        typedef typename iterator<std::random_access_iterator_tag, T>::reference            reference;
        typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category    iterator_category;

        public :
            random_access_iterator() {
                this->ptr = NULL;
            };
            random_access_iterator(pointer it) {
                this->ptr = it->ptr;
            };
            random_access_iterator(const reference it) {
                *this = it;
            };
            reference operator= (const reference other)
            {
                this->ptr = other.ptr;
            }
            bool operator== (const reference other)
            {
                if (this->ptr == other.ptr)
                    return true;
                return false;
            }
            bool operator!= (const reference other)
            {
                return !(*this == other);
            }
            bool operator< (const reference other)
            {
                if (this->ptr < other.ptr)
                    return true;
                return false;
            }
            bool operator> (const reference other)
            {
                if (this->ptr > other.ptr)
                    return true;
                return false;
            }
            bool operator>= (const reference other)
            {
                if (*this == other || *this > other)
                    return true;
                return false;
            }
            bool operator<= (const reference other)
            {
                if (*this == other || *this < other)
                    return true;
                return false;
            }
            reference operator*()
            {
                return *this->ptr;
            }
            reference operator++(void)
            {
                ++(this->ptr);
                return *this;
            }
            reference operator++(int)
            {
                (this->ptr)++;
                return *this;
            }
            reference operator--(void)
            {
                --(this->ptr);
                return *this;
            }
            reference operator--(int)
            {
                (this->ptr)--;
                return *this;
            }
        public :
            pointer     ptr;
    };
}