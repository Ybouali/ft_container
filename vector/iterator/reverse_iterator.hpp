#pragma once

#include "./iterator_traits.hpp"

namespace ft {
    template <class Iterator>
    class reverse_iterator : public iterator<
            typename iterator_traits<Iterator>::difference_type,
            typename iterator_traits<Iterator>::reference,
            typename iterator_traits<Iterator>::pointer,
            typename iterator_traits<Iterator>::value_type,
            typename iterator_traits<Iterator>::iterator_category
            >
    {
        protected :
            Iterator    curr;
        public :
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::reference reference;
            typedef typename iterator_traits<Iterator>::pointer pointer;

            reverse_iterator() { }
            explicit reverse_iterator(Iterator x): curr(x) { }

            template <class U>
            reverse_iterator(const reverse_iterator<U> & u) { this->curr =  u.curr; }

            Iterator base() const { return this->curr; }

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
                return (reverse_iterator(this->curr - n));
            }

            reverse_iterator operator+=(difference_type n)
            {
                this->curr -= n;
                return (*this);
            }

            reverse_iterator operator-(difference_type n) const
            {
                return (reverse_iterator(this->curr + n));
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
            
            friend bool operator==(const reverse_iterator<Iterator>& o1, const reverse_iterator<Iterator>& o2) { return (o1.curr == o2.curr); };

            friend bool operator>(const reverse_iterator<Iterator>& o1, const reverse_iterator<Iterator>& o2) { return (o1.curr > o2.curr); }
            
            friend bool operator!=(const reverse_iterator<Iterator>& o1, const reverse_iterator<Iterator>& o2) { return (o1.curr != o2.curr); }
            
            friend bool operator<(const reverse_iterator<Iterator>& o1, const reverse_iterator<Iterator>& o2) { return (o1.curr < o2.curr); }
            
            friend bool operator<=(const reverse_iterator<Iterator>& o1, const reverse_iterator<Iterator>& o2) { return (o1.curr <= o2.curr); }
            
            friend bool operator>=(const reverse_iterator<Iterator>& o1, const reverse_iterator<Iterator>& o2) { return (o1.curr >= o2.curr); }
            
            friend difference_type operator-(const reverse_iterator<Iterator>& o1, const reverse_iterator<Iterator>& o2) { return (o1.curr - o2.curr); }
            
            friend reverse_iterator<Iterator> operator+(reverse_iterator::difference_type n, const reverse_iterator<Iterator>& o2) { return (o2.curr - n); }
    };
    
}