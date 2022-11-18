#include "./iterator/iterator.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector {
    
        public:
            // TODO: TYPES ON STD VECTOR ??
            // typedef T                   value_type;
            typedef Alloc               allocator_type;
            typedef T&                  reference;
            typedef const T &           const_reference;
            // typedef T*                  pointer;
            // typedef const T*            const_pointer;
            // typedef iterator
            // typedef const_iterator
            // typedef reverse_iterator
            // typedef const_reverse_iterator
            // typedef  difference_type
            typedef unsigned int        size_type;
            // explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
            // template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
            // TODO: DEFAULT CONSTROCTOR
            explicit vector (const Alloc& alloc = Alloc())
            {
                (void)alloc;
                this->arr = NULL;
                this->size_v = 0;
                this->capacity_v = 0;
            }
            void    test_stock(void)
            {
                // FOR TESTING
                this->arr = this->alloc.allocate(4);
                this->size_v = 4;
                this->capacity_v = 4;
                for (size_t o = 0; o < this->size_v; o++)
                    this->arr[o] = o;
            }
            // TODO: DEFAULT COPY CONSTROCTOR
            vector (const vector& other)
            {
                *this = other;
            }
            // TODO: OPERATOR =
            vector& operator= (const vector& other)
            {
                if (this->size_v > 0)
                {
                    for (size_t i = 0; i < this->capacity_v; i++)
                        this->alloc.destroy(this->arr + i);
                    this->alloc.deallocate(this->arr, this->capacity_v);
                    this->capacity_v = 0;
                    this->size_v = 0;
                    this->arr = NULL;
                }
                this->arr = this->alloc.allocate(other.capacity_v);
                this->capacity_v = other.capacity_v;
                this->size_v = other.size_v;
                for (size_t i = 0; i < other.size_v; i++)
                    this->arr[i] = other.arr[i];
                return *this;
            }
            // TODO: DEFAULT DESTROCTOR
            ~vector (void)
            {
                for (size_t i = 0; i < this->size_v; i++)
                    this->alloc.destroy(this->arr + i);
                if (this->capacity_v > 0)
                    this->alloc.deallocate(this->arr, this->capacity_v);
                this->arr = NULL;
            }

            // TODO: OPERATOR []
            reference operator[] (size_t n)
            {
                return this->arr[n];
            }
            // TODO: CONST OPERATOR []
            const_reference operator[] (size_t n) const
            {
                return this->arr[n];
            }
            // TODO: ----------> SIZE
            size_type    size(void)
            {
                return this->size_v;
            }
            // TODO: ----------> CAPACITY
            size_type    capacity(void)
            {
                return this->capacity_v;
            }
            // TODO: ----------> PUSH_BACK
            void    push_back(const size_type & val)
            {
                if (this->capacity_v == 0)
                {
                    this->capacity_v = 1;
                    this->arr = this->alloc.allocate(this->capacity_v);
                    this->arr[0] = val;
                    this->size_v = 1;
                }
                else if (this->capacity_v == 1)
                {
                    
                    this->capacity_v = 2;
                    this->size_v = 2;
                    this->arr[this->size_v - 1] = val;
                }
                else
                {
                    // std::cout << val << std::endl;
                }
            }
        private:
            T                           *arr;
            size_type                   size_v;
            size_type                   capacity_v;
            allocator_type              alloc;
    };

    
}