namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector {
        private:
            T                       *arr;
            std::size_t             size_v;
            std::size_t             capacity_v;
            Alloc                   alloc;
        public:
            // explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
            // template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
            explicit vector (const Alloc& alloc = Alloc())
            {
                (void)alloc;
                this->arr = NULL;
                this->size_v = 0;
                this->capacity_v = 0;
            }
            vector (const vector& other)
            {
                *this = other;
            }
            vector& operator= (const vector& other)
            {
                if (this->size_v > 0)
                {
                    for (size_t i = 0; i < this->size_v; i++)
                    this->alloc.destroy(this->arr + i);
                    if (this->capacity_v > 0)
                        this->alloc.deallocate(this->arr, this->capacity_v);
                    this->arr = NULL;
                }
                this->arr = this->alloc.allocate(other->capacity_v);
                this->capacity_v = other->capacity_v;
                this->size_v = other->size_v;
                for (size_t i = 0; i < other->size_v; i++)
                    this->arr[i] = other->arr[i];
            }
            ~vector (void)
            {
                for (size_t i = 0; i < this->size_v; i++)
                    this->alloc.destroy(this->arr + i);
                if (this->capacity_v > 0)
                    this->alloc.deallocate(this->arr, this->capacity_v);
                this->arr = NULL;
            }
            // reference operator[] (size_t n);
            // const_reference operator[] (size_t n) const;
            std::size_t size(void)
            {
                return this->size_v;
            }
            std::size_t capacity(void)
            {
                return this->capacity_v;
            }
    };
}