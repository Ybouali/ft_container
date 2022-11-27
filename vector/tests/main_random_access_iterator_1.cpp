
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

    ft::vector<int>::const_reverse_iterator     it_b;
    ft::vector<int>::reverse_iterator           it_e;

    it_e = v.rbegin();
    it_b = v.rend();

    std::cout << "-------------------------------------------------------" << std::endl;
    if (it_e == it_b)
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "FALSE" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    if (it_e > it_b)
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "FALSE" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    if (it_e != it_b)
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "FALSE" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    if (it_e < it_b)
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "FALSE" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    if (it_e <= it_b)
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "FALSE" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    if (it_e >= it_b)
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "FALSE" << std::endl;
}