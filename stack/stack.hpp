#pragma once

#include "../vector/vector.hpp"

namespace ft
{
    template<class T, class Container = ft::vector<T > >
    class stack {

        public :
            typedef Container                                   container_type;
            typedef typename Container::value_type              value_type;
            typedef typename Container::size_type               size_type;
            typedef typename Container::reference               reference;
            typedef typename Container::const_reference         const_reference;

            explicit stack ( const Container& cont = Container() ): _c(cont) { }

            ~stack () { }

            bool empty() const { return _c.empty(); }

            size_type size() const { return _c.size(); }

            value_type& top() { return _c.back(); }

            const value_type& top() const { return _c.back(); }
        
            void push (const value_type& val) { _c.push_back(val); }

            void pop() { _c.pop_back(); }

            void swap (stack& x) { _c.swap(x); }

            bool operator== (const stack& other) { return _c == other._c; }

            bool operator!= (const stack& other) { return _c != other._c; }

            bool operator> (const stack& other) { return _c > other._c; }

            bool operator>= (const stack& other) { return _c >= other._c; }
            
            bool operator< (const stack& other) { return _c < other._c; }
            
            bool operator<= (const stack& other) { return _c <= other._c; }


        protected :
            Container  _c;
    };

    template <class T, class Container>
    void swap (stack<T,Container>& x, stack<T,Container>& y)
    {
        x.swap(y);
    }
}