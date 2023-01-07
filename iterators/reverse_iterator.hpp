#pragma once

#include "./iterator_traits.hpp"

namespace ft {
    template <class Iterator>
    class reverse_iterator
    {
        protected :
            Iterator    curr;
        public :
            typedef Iterator                                                    iterator_type;
            typedef typename iterator_traits<Iterator>::value_type              value_type;
            typedef typename iterator_traits<Iterator>::difference_type         difference_type;
            typedef typename iterator_traits<Iterator>::pointer                 pointer;
            typedef typename iterator_traits<Iterator>::reference               reference;
            typedef typename iterator_traits<Iterator>::iterator_category       iterator_category;

            reverse_iterator(): curr(NULL) { }

            explicit reverse_iterator(Iterator x) { curr = x; }

            template <class U>
            reverse_iterator(const reverse_iterator<U> & u) { this->curr =  u.base(); }

            Iterator base() const { return curr; }

            reference operator*() const {
                Iterator tmp = this->curr;
                return *--tmp;
            }

            pointer operator->() const { return &(operator*()); }

            reverse_iterator& operator++() {
                --this->curr;    
                return *this;
            }

            reverse_iterator operator++(int) {
                reverse_iterator tmp = *this;
                --this->curr;
                return tmp;
            }

            reverse_iterator operator--() {
                ++this->curr;
                return *this;
            }
            
            reverse_iterator operator--(int) {
                reverse_iterator tmp = *this;
                ++this->curr;
                return tmp;
            }

            reverse_iterator operator+(difference_type n) const
            {
                return (reverse_iterator(curr - n));
            }

            reverse_iterator operator+=(difference_type n)
            {
                this->curr -= n;
                return (*this);
            }

            reverse_iterator operator-(difference_type n) const
            {
                return (reverse_iterator(curr + n));
            }

            reverse_iterator operator-=(difference_type n)
            {
                this->curr += n;
                return (*this);
            }

            reference operator[](difference_type n) const
            {
                return (curr[-n-1]);
            }
            
            template <class U,class Y>
            friend bool operator==(const reverse_iterator<U>& o1, const reverse_iterator<Y>& o2);

            template <class U, class Y>
            friend bool operator>(const reverse_iterator<U>& o1, const reverse_iterator<Y>& o2);

            template <class U, class Y>
            friend bool operator!=(const reverse_iterator<U>& o1, const reverse_iterator<Y>& o2);

            template <class U, class Y>
            friend bool operator<(const reverse_iterator<U>& o1, const reverse_iterator<Y>& o2);

            template <class U, class Y>
            friend bool operator<=(const reverse_iterator<U>& o1, const reverse_iterator<Y>& o2);

            template <class U, class Y>
            friend bool operator>=(const reverse_iterator<U>& o1, const reverse_iterator<Y>& o2);
            
            operator reverse_iterator<const iterator_type>() const {
                return reverse_iterator<const iterator_type>(this->curr);
            }

    };

    template <class Iterator>        
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& o2) { return (reverse_iterator<Iterator>(o2.base() - n)); }

    template <class Iterator1, class Iterator2>
    ptrdiff_t operator-(const reverse_iterator<Iterator1>& o1, const reverse_iterator<Iterator2>& o2) { return (o2.base() - o1.base()); }

    
    template <class U, class Y>
    bool operator==(const reverse_iterator<U>& o1, const reverse_iterator<Y>& o2)  {return (o1.base() == o2.base()); }

    template <class U, class Y>
    bool operator!=(const reverse_iterator<U>& o1, const reverse_iterator<Y>& o2) { return !(o1.base() == o2.base()); }


    template <class U, class Y>
    bool operator<(const reverse_iterator<U>& o1, const reverse_iterator<Y>& o2) { return (o1.base() > o2.base()); }

    template <class U, class Y>
    bool operator<=(const reverse_iterator<U>& o1, const reverse_iterator<Y>& o2) { return (o1.base() >= o2.base()); }

    template <class U, class Y>
    bool operator>(const reverse_iterator<U>& o1, const reverse_iterator<Y>& o2)  { return (o1.base() < o2.base()); }

    template <class U, class Y>
    bool operator>=(const reverse_iterator<U>& o1, const reverse_iterator<Y>& o2) { return (o1.base() <= o2.base()); }
}