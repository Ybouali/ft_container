#include "./iterator.hpp"

namespace ft
{
    template <class Iterator>
    class iterator_traits
    {

    };
    
    template <class T>
    class iterator_traits<T*>
    {

    };
    
    template <class T>
    class iterator_traits<const T*>
    {

    };

}