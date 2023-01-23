#pragma once

#include "../utils/utils.hpp"
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector {
    
        public:
            typedef ft::random_access_iterator<T>                                   iterator;         
            typedef ft::random_access_iterator<const T>                             const_iterator;
            typedef T                                                               value_type;
            typedef Alloc                                                           allocator_type;
            typedef typename allocator_type::reference                              reference;
            typedef typename allocator_type::const_reference                        const_reference;
            typedef typename allocator_type::pointer                                pointer;
            typedef typename allocator_type::const_pointer                          const_pointer;
            typedef ft::reverse_iterator<ft::random_access_iterator<T> >            reverse_iterator;
            typedef ft::reverse_iterator<ft::random_access_iterator<const T> >      const_reverse_iterator;
            typedef ptrdiff_t                                                       difference_type;
            typedef size_t                                                          size_type;
            
            explicit vector (const Alloc& _alloc = Alloc()): arr(NULL),  size_v(0), capacity_v(0), alloc(_alloc) { }

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& _alloc = allocator_type()) : arr(0),  size_v(0), capacity_v(0), alloc(_alloc)
            {
                if (n)
                {
                    arr = alloc.allocate(n);
                    for (size_type i = 0; i < n; i++)
                        alloc.construct(arr + i, val);
                    size_v = n;
                    capacity_v = n;
                }
            }
            
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& _alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr) : arr(0),  size_v(0), capacity_v(0), alloc(_alloc) { assign(first, last); }
            
            vector (const vector& other): arr(NULL),  size_v(other.size()), capacity_v(other.capacity()), alloc(other.alloc)
            { 
                if (capacity_v)
                {
                    arr = alloc.allocate(capacity_v);
                    for (size_type i = 0; i < size_v; i++)
                        alloc.construct(arr + i, other[i]);
                }
            }

            vector& operator= (const vector& other)
            {
                clear();
                if (arr && capacity_v != other.capacity_v)
                    alloc.deallocate(arr, capacity_v);
                alloc =  other.alloc;
                if (capacity_v != other.capacity_v)
                    this->arr = this->alloc.allocate(other.capacity_v);
                this->capacity_v = other.capacity_v;
                this->size_v = other.size_v;
                for (size_type i = 0; i < other.size_v; i++)
                    alloc.construct(arr + i, *(other.arr + i));
                return *this;
            }
            
            ~vector (void) {
                clear();
                if (capacity_v)
                {
                    this->alloc.deallocate(arr, capacity_v);
                    this->capacity_v = 0;
                    size_v = 0;
                    this->arr = NULL;
                }
            }

            // * Capacity DONE
            size_type    size(void) const { return this->size_v;  }

            size_type    max_size(void) const { return alloc.max_size() > PTRDIFF_MAX ? PTRDIFF_MAX : alloc.max_size(); }
 
            size_type    capacity(void) const { return this->capacity_v; }

            bool         empty(void) const { return this->size_v == 0 ? true : false;  }
            
            void         resize(size_type n, value_type val = value_type())
            {
                if (this->size_v > n)   
                {
                    for (size_type o = n; o < this->size_v; o++)
                        this->alloc.destroy(this->arr + o);
                }
                if (this->size_v < n)
                {
                    reserve(n);
                    for (size_type i = size_v; i < n; i++)
                        alloc.construct(arr + i, val);
                }
                size_v = n;
            }

            void         reserve(size_type n)
            {
                if (n > this->capacity_v)
                {
                    pointer     tmp;
                    size_type   _old_size = this->size_v;
                    tmp = this->alloc.allocate(n);
                    for (size_type i = 0; i < this->size_v; i++)
                        alloc.construct(tmp + i, *(arr + i));
                    clear();
                    if (arr)
                        alloc.deallocate(arr, capacity_v);
                    
                    this->capacity_v = n;
                    this->size_v = _old_size;
                    this->arr = tmp;
                }
            }

            // Modifiers

            void         swap(vector& x)
            {
                pointer     tmp = this->arr;
                size_type   _capacity_tmp = this->capacity_v;
                size_type   _size_tmp = this->size_v;
                this->arr = x.arr;
                this->capacity_v = x.capacity_v;
                this->size_v = x.size_v;
                x.arr = tmp;
                x.size_v = _size_tmp;
                x.capacity_v = _capacity_tmp;
            }
            
            iterator erase (iterator position)
            {
                size_type   pos = position - begin();

                alloc.destroy(&arr[pos]);
                for (size_type i = pos; i < size_v - 1; i++)
                {
                    alloc.construct(arr + i, *(arr + i + 1));
                    alloc.destroy(&arr[i + 1]);
                }
                size_v--;
                return arr + pos;
            }

            iterator erase (iterator first, iterator last)
            {
                size_type _pos_f = first - begin();
                size_type _pos_e = last - begin();
                size_type dist = last - first;
                
                size_type _s_old = size_v;
                size_type _c_old = capacity_v;
                
                pointer _p = alloc.allocate(capacity_v);
                
                for (size_type i = 0; i < _pos_f; i++)
                    alloc.construct(_p + i, *(arr + i));
                
                for (size_type i = _pos_e; i < size_v; i++)
                    alloc.construct(_p + (i - dist), *(arr + i));
                clear();
                if (arr)
                    alloc.deallocate(arr, capacity_v);
                size_v = _s_old - dist;
                capacity_v = _c_old;
                arr = _p;
                return arr + _pos_f;
            }

            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
            {
                difference_type pos = size_v ? position - begin() : 0;

                vector<T> tmp(first, last);
                
                difference_type len = tmp.size();
            
                if (size_v + len > capacity_v)
                    (size_v + len) <= (capacity_v * 2) ? reserve(capacity_v * 2) : reserve(size_v + len);
                
                if (len)
                {
                    for (difference_type i = size_v - 1; i >= pos; i--)
                    {
                        alloc.construct(arr + (i + len), arr[i]);
                        alloc.destroy(&arr[i]);
                    }
                    size_v += len;
                    difference_type index = 0;
                    for(difference_type i = pos; len-- > 0 ; i++)
                        alloc.construct(arr + i, tmp.at(index++));
                }
            }

            void insert (iterator position, size_type n, const value_type& val)
            {
                difference_type pos = size_v ? position - begin() : 0;

                if (size_v + n > capacity_v)
                    (size_v + n) <= (capacity_v * 2) ? reserve(capacity_v * 2) : reserve(size_v + n);
                
                if (n)
                {
                    for (difference_type i = size_v - 1; i >= pos; i--)
                    {
                        alloc.construct(arr + (i + n), arr[i]);
                        alloc.destroy(&arr[i]);
                    }
                    size_v += n;
                    for (difference_type i = pos; n-- > 0; i++)
                        alloc.construct(arr + i, val);
                }
            }

            iterator insert (iterator position, const value_type& val)
            {
                difference_type pos  = position -  begin();
                
                if(capacity_v == size_v)
                {
                    if(!capacity_v)
                        reserve(1);
                    else 
                        reserve(capacity_v * 2);
                }

                for(difference_type i = size_v; i > pos; i--)
                {
                    alloc.construct(arr + i, *(arr + (i - 1)));
                    alloc.destroy(arr + (i - 1));
                }
                alloc.construct(arr + pos, val);
                size_v++;
                return(arr + pos);
            }

            void         pop_back()
            {
                if (this->size_v >= 0)
                    alloc.destroy(arr + --size_v);       
            }

            template <class InputIterator>
            void    assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
            {
                if (!std::is_same< typename iterator_traits<InputIterator>::iterator_category, std::input_iterator_tag>::value)
                {
                    size_type dist = std::distance(first, last);
                    if (dist > capacity_v)
                    {
                        clear();
                        arr = alloc.allocate(dist);
                        capacity_v = dist;
                    }
                    while(size_v < dist)
                        alloc.construct(arr + size_v++, *(first++));
                }
                else {
                    while(first != last)
                        push_back(*(first++));
                }
            }


            void         assign(size_type n, const value_type& val)
            {
                clear();
                if (n > capacity_v)
                {
                    if (capacity_v)
                        alloc.deallocate(arr, capacity_v);
                    arr = alloc.allocate(n);
                    capacity_v = n;
                }
                for (size_type i = 0; i < n; i++)
                    alloc.construct(arr + i, val);
                size_v = n ? n : size_v;
            }

            void         push_back(const value_type& val)
            {
                if (this->capacity_v == 0)
                {
                    this->capacity_v = 1;
                    this->size_v = 1;
                    this->arr = this->alloc.allocate(this->capacity_v);
                    alloc.construct(this->arr, val);
                }
                else
                {
                    if (this->size_v == this->capacity_v)
                    {
                        pointer             ptr;
                        difference_type     _old_c = this->capacity_v;
                        size_type           _old_s = this->size_v;

                        ptr = this->alloc.allocate(this->capacity_v * 2);
                        for (size_type o = 0; o < this->size_v; o++)
                            alloc.construct(ptr + o, arr[o]);
                        alloc.construct(ptr + _old_s, val);
                        clear();
                        if (arr)
                            alloc.deallocate(arr, capacity_v);
                        this->capacity_v = _old_c * 2;
                        this->arr = ptr;
                        this->size_v = ++_old_s;
                    }
                    else
                        alloc.construct(this->arr + this->size_v++, val);
                }
            }

            void         clear() 
            {
                if (size_v)
                {
                    for (size_type i = 0; i < this->size_v; i++)
                        this->alloc.destroy(arr + i);
                    this->size_v = 0;
                }
            }

            // Iterator DONE

            reverse_iterator    rbegin()
            {
                reverse_iterator    rit(this->arr + this->size_v);
                return (rit);
            }

            const_reverse_iterator    rbegin() const
            {
                const_reverse_iterator    rit(this->arr + this->size_v);
                return (rit);
            }

            reverse_iterator    rend()
            {
                reverse_iterator    rit(arr);
                return (rit);
            }

            const_reverse_iterator    rend() const
            {
                const_reverse_iterator    rit(arr);
                return (rit);
            }

            iterator      begin(void) 
            {
                iterator it(this->arr);
                return it;
            }

            const_iterator      begin(void) const
            {
                const_iterator it(this->arr);
                return it;
            }

            iterator      end(void) 
            {
                iterator it(this->arr + this->size_v);
                // it = ;
                return it;
            }

            const_iterator end(void) const
            {
                const_iterator it(this->arr + this->size_v);
                return it;
            }

            // Element access DONE

            reference           at(size_type n) {
                if (n < 0 || n >= size_v)
                    throw (std::out_of_range("OUT OF RANGE"));
                return *(arr + n);
            }

            const_reference     at(size_type n) const {
                if (n < 0 || n >= size_v)
                    throw (std::out_of_range("OUT OF RANGE"));
                return *(arr + n);
            }

            reference           operator[](size_type n) { return this->arr[n]; }

            const_reference     operator[](size_type n) const { return this->arr[n]; }

            reference           front() { return *this->arr; }
            
            const_reference     front() const { return *this->arr; }
            
            reference           back() { return at(size_v - 1); }
            
            const_reference     back() const { return at(size_v - 1); }

            // GET ALLOCATOR
            allocator_type get_allocator() const { return alloc; }
            
        private:
            pointer                     arr;
            size_type                   size_v;
            size_type                   capacity_v;
            allocator_type              alloc;
    };

    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size()) return false;

        for (typename ft::vector<T>::size_type i = 0; i < lhs.size(); i++)
            if (lhs[i] != rhs[i]) return false;
        return true;
    }
    
    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs == rhs); }
            
    template <class T, class Alloc>
    bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }
    
    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return lhs == rhs || lhs < rhs; }
    
    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return lhs == rhs || lhs > rhs; }

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }
}