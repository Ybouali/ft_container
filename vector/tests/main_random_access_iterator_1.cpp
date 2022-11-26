
#include <iostream>
#include <vector>
#include <iterator>
#include <typeinfo>


#include "../iterator/random_access_iterator.hpp"
#include "../vector.hpp"

#define N 3

int main()
{
    ft::vector<int>    v;

    for (int i = 0; i < 3; i++)
        v.push_back(i * 11);

    ft::vector<int>::iterator it_b = v.begin();
    ft::vector<int>::const_iterator it_e = v.end();

    if (it_b >= it_e)
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "FALSE" << std::endl;
}