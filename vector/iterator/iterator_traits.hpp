#include "./iterator.hpp"

namespace ft
{
    // class iterator_traits : pulic 

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