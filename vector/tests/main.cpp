
#include <iostream>
#include <vector>
#include <typeinfo>


#include "../vector.hpp"

int main()
{
    // TESTS FOR MY VECTOR
    // std::vector<int> v;
    // for (int i = 0; i < 3; i++)
    //     v.push_back(i);
    // for (int i = 0; i < 3; i++)
    //     std::cout << "V [" << i << "] = " << v[i] << std::endl;
    // the solution for this problem is iterator traits
    // ft::vector< int > v1 = v;
    // for (int i = 0; i < 3; i++)
    //     std::cout << "V [" << i << "] = " << v1[i] << std::endl;
    // std::cout << v1.size() << std::endl;
    // std::cout << v1.capacity() << std::endl;
    
    {

        // TESTING COPY CONSTROCTOR

        ft::vector<int> v1;

        std::cout << "------------------------------ TEST COPY CONSTROCTOR ----------------" << std::endl;

        v1.test_stock();
        for (int i = 0; i < 6; i++)
            std::cout << v1[i] << std::endl;

        std::cout << "---------------------------------------------------------------------" << std::endl;

        ft::vector<int> v2;
        v2 = v1;
        v2 = v1;
        v2 = v1;
        v2 = v1;
        for (int i = 0; i < 6; i++)
            std::cout << v2[i] << std::endl;
        while (1);
    }
}