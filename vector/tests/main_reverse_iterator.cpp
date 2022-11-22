
#include <iostream>

#include "../iterator/reverse_iterator.hpp"
#include "../iterator/random_access_iterator.hpp"

#define N 3

int main()
{
    // std::cout << "--------- TEST REVERSE ITERATOR ---------------------" << std::endl << std::endl;

    // std::allocator<int> alloc;
    ft::random_access_iterator<int> it;

    // it = alloc.allocate(3);
    // for (int i = 0; i < 3; i++)
    // {
    //     *it = i;
    //     it++;
    // }

    ft::reverse_iterator<ft::random_access_iterator<int> > rit;

}