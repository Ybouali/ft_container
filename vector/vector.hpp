#include <iostream>
#include "./iterator/random_access_iterator.hpp"
#include "./iterator/reverse_iterator.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector {
    
        public:
            typedef ft::random_access_iterator<T>           iterator;             
            typedef ft::random_access_iterator<const T>     const_iterator;
            typedef typename iterator::value_type           value_type;
            typedef Alloc                                   allocator_type;
            typedef typename iterator::reference            reference;
            typedef const reference                         const_reference;
            typedef typename iterator::pointer              pointer;
            typedef const pointer                           const_pointer;
            typedef ft::reverse_iterator<iterator>          reverse_iterator;
            typedef const reverse_iterator                  const_reverse_iterator;
            typedef typename iterator::difference_type      difference_type;
            typedef difference_type                         size_type;
            
            // explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
            
            // template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
            
            explicit vector (const Alloc& alloc = Alloc())
            {
                (void)alloc;
                this->arr = NULL;
                this->size_v = 0;
                this->capacity_v = 0;
            }
            void    test_stock(size_type n)
            {
                // FOR TESTING
                clear();
                this->arr = this->alloc.allocate(n);
                this->size_v = n;
                this->capacity_v = n;
                for (size_type o = 0; o < this->size_v; o++)
                    this->arr[o] = o;
            }
            
            vector (const vector& other) { *this = other; }

            vector& operator= (const vector& other)
            {
                if (this->size_v)
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

            // Capacity resize and reserve.
            size_type    size(void) const { return this->size_v;  }

            size_type    max_size(void) const { return this->alloc.max_size(); }
 
            size_type    capacity(void) const { return this->capacity_v; }

            bool         empty(void) const { return this->size_v == 0 ? true : false;  }
            
            // void         resize(size_type n, value_type val = value_type())
            // {
                // Need a clear method
            // }

            // void         reserve(size_type n)
            // {
                // Need a clear method
            // }

            // Modifiers assign , push_back, pop_back, insert, erase, swap
            void         clear() 
            {
                if (this->size_v)
                {
                    for (difference_type i = 0; i < this->size_v; i++)
                        this->alloc.destroy(this->arr + i);
                    if (this->capacity_v > 0)
                        this->alloc.deallocate(this->arr, this->capacity_v);
                    this->size_v = 0;
                    this->capacity_v = 0;
                    this->arr = NULL;
                }
            }

            // Iterator rbegin, rend

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
                const_iterator it;
                it = this->arr + this->size_v;
                return it;
            }

            // Element access [], at

            reference           at(size_type n) { return this->arr[n]; }

            const_reference     at(size_type n) const { return this->arr[n]; }

            // reference           front() { return this->arr; }
            
            // const_reference     front() const { return this->arr; }
            
            // reference           back() { return this->arr[this->size_v]; }
            
            // const_reference     back() const { return this->arr[this->size_v]; }

        private:
            pointer                     arr;
            size_type                   size_v;
            size_type                   capacity_v;
            allocator_type              alloc;
    };
}