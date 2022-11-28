#include <iostream>
#include <signal.h>
#include "./iterator/random_access_iterator.hpp"
#include "./iterator/reverse_iterator.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector {
    
        public:
            typedef ft::random_access_iterator<T>                                   iterator;         
            typedef ft::random_access_iterator<const T>                             const_iterator;
            typedef T                                                               value_type;
            typedef Alloc                                                           allocator_type;
            typedef T&                                                              reference;
            typedef const T&                                                        const_reference;
            typedef T*                                                              pointer;
            typedef const T*                                                        const_pointer;
            typedef ft::reverse_iterator<ft::random_access_iterator<T> >            reverse_iterator;
            typedef ft::reverse_iterator<ft::random_access_iterator<const T> >      const_reverse_iterator;
            typedef ptrdiff_t                                                       difference_type;
            typedef difference_type                                                 size_type;
            
            // explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
            
            // template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
            
            explicit vector (const Alloc& alloc = Alloc())
            {
                (void)alloc;
                this->arr = NULL;
                this->size_v = 0;
                this->capacity_v = 0;
            }
            
            vector (const vector& other) { *this = other; }

            vector& operator= (const vector& other)
            {
                clear();
                this->arr = this->alloc.allocate(other.capacity_v);
                this->capacity_v = other.capacity_v;
                this->size_v = other.size_v;
                for (size_t i = 0; i < other.size_v; i++)
                    this->arr[i] = other.arr[i];
                return *this;
            }
            
            ~vector (void) {
                clear();
            }

            // Capacity DONE
            size_type    size(void) const { return this->size_v;  }

            size_type    max_size(void) const { return this->alloc.max_size(); }
 
            size_type    capacity(void) const { return this->capacity_v; }

            bool         empty(void) const { return this->size_v == 0 ? true : false;  }
            
            void         resize(size_type n, value_type val = value_type())
            {
                if (this->size_v > n)   
                {
                    for (int o = n; o < this->size_v; o++)
                        this->alloc.destroy(this->arr + o);
                    this->size_v = n;
                }
                if (this->size_v < n)
                {
                    pointer     tmp;

                    tmp = this->alloc.allocate(n);
                    for (size_type i = 0; i < this->size_v; i++)
                        tmp[i] = this->arr[i];
                    if (val)
                    {
                        for (size_type i = size_v; i < n; i++)
                            tmp[i] = val;
                    }
                    clear();
                    this->capacity_v = n;
                    this->size_v = n;
                    this->arr = tmp;
                }
            }

            void         reserve(size_type n)
            {
                if (n > this->capacity_v)
                {
                    pointer     tmp;
                    size_type   _old_size = this->size_v;
                    tmp = this->allo.allocate(n);
                    for (size_type i = 0; i < this->size_v; i++)
                        tmp[i] = this->arr[i];
                    clear();
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
            // TODO: ERASE :)
            // iterator erase (iterator position);
            // iterator erase (iterator first, iterator last);
            // TODO: INSERT :)
            // void insert (iterator position, size_type n, const value_type& val);
            // void insert (iterator position, InputIterator first, InputIterator last);
            iterator insert (iterator position, const value_type& val)
            {
                pointer _p = position.base();
                size_type _tmp = 0;
                if (this->size_v <= this->capacity_v)
                {
                    size_type _capa = this->size_v == this->capacity_v ? this->capacity_v * 2 : this->capacity_v;
                    if (_capa == 0)
                        _capa = 1;
                    pointer _ptr = this->alloc.allocate(_capa);
                    size_type j = 0;
                    if (this->size_v)
                    {
                        for (size_type i = 0; i < this->size_v; i++)
                        {
                            if (_p == this->arr + i)
                            {
                                _tmp = j;
                                _ptr[j++] = val;
                            }
                            _ptr[j++] = this->arr[i];
                        }
                    }
                    else
                        _ptr[0] = val;
                    clear();
                    this->size_v = j ? j : 1;
                    this->capacity_v = _capa;
                    this->arr = _ptr;
                }
                return (iterator(this->arr + _tmp));
            }
            void         pop_back()
            {
                if (this->size_v >= 0)
                    this->alloc.destroy(this->arr + this->size_v--);
            }

            // void         assign(InputIterator first, InputIterator last);
            void         assign(size_type n, const value_type& val)
            {
                if (this->size_v >= n)
                {
                    for (size_type i = 0; i < n; i++)
                        this->arr[i] = val;
                    this->size_v = n;
                }
                else
                {
                    clear();
                    for (size_type i = 0; i < n; i++)
                        push_back(val);
                }
            }

            void         push_back(const value_type& val)
            {
                if (this->capacity_v == 0)
                {
                    this->capacity_v = 1;
                    this->size_v = 1;
                    this->arr = this->alloc.allocate(this->capacity_v);
                    this->arr[0] = val;
                }
                else if (this->capacity_v == 1)
                {
                    value_type  tmp;
                    tmp = at(0);
                    clear();
                    this->capacity_v = 2;
                    this->size_v = 2;
                    this->arr = this->alloc.allocate(this->capacity_v);
                    this->arr[0] = tmp;
                    this->arr[1] = val;
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
                            ptr[o] = at(o);
                        clear();
                        this->capacity_v = _old_c * 2;
                        this->arr = ptr;
                        this->arr[_old_s] = val;
                        this->size_v = ++_old_s;
                    }
                    else
                        this->arr[this->size_v++] = val;
                }
            }

            void         clear() 
            {
                if (this->capacity_v)
                {
                    for (difference_type i = 0; i < this->capacity_v; i++)
                        this->alloc.destroy(this->arr + i);
                    if (this->arr)
                        this->alloc.deallocate(this->arr, this->capacity_v);
                    this->size_v = 0;
                    this->capacity_v = 0;
                    this->arr = NULL;
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
                reverse_iterator    rit(this->arr);
                return (rit);
            }

            const_reverse_iterator    rend() const
            {
                const_reverse_iterator    rit(this->arr);
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
                iterator it;
                it = this->arr + this->size_v;
                return it;
            }

            const_iterator end(void) const
            {
                const_iterator it(this->arr + this->size_v);
                return it;
            }

            // Element access DONE

            reference           at(size_type n) { return this->arr[n]; }

            const_reference     at(size_type n) const { return this->arr[n]; }

            reference           operator[](size_type n) { return this->arr[n]; }

            const_reference     operator[](size_type n) const { return this->arr[n]; }

            reference           front() { return *this->arr; }
            
            const_reference     front() const { return *this->arr; }
            
            reference           back() { return *(this->arr + this->size_v - 1); }
            
            const_reference     back() const { return *(this->arr + this->size_v - 1); }

        private:
            pointer                     arr;
            size_type                   size_v;
            size_type                   capacity_v;
            allocator_type              alloc;
    };
}