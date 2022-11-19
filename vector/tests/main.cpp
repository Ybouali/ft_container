
#include <iostream>
#include <vector>
#include <typeinfo>


#include "../iterator/random_access_iterator.hpp"
#include "../vector.hpp"

#define N 3

int main()
{
    {
        std::allocator<int> alloc;
        ft::random_access_iterator<int> it, it1;

        it.ptr = alloc.allocate(1);
        // it1 = it;

        *it.ptr = 2;

        std::cout << it.ptr << std::endl;
        it++;
        *it.ptr = 3;
        std::cout << it.ptr << std::endl;
        // for (int i = 0; i < 3; i++)
        // {
        //     *it.ptr = i;
        //     it++;
        // }
        // for (int i = 0; i < 3; i++)
        // {
        //     std::cout << it1.ptr[0] << std::endl;
        //     it1++;
        // }
        // for (int i = 0; i < 3; i++)
        // {
        //     std::cout << it1.ptr[0] << std::endl;
        //     it1--;
        // }
    }
    {
        // std::cout << "------------------------------ STD PUSH BACK ----------------" << std::endl;
        // // TESTS FOR MY VECTOR
        // std::vector<int> v;
        // for (int i = 1; i < N; i++)
        // {
        //     v.push_back(i);
        //     std::cout << "ARR[" << i - 1 << "] = " << v[i - 1] << " SIZE = " << v.size() << " CAPACITY = " << v.capacity() << std::endl;
        // }
        // the solution for this problem is iterator traits
        // ft::vector< int > v1 = v;
        // for (int i = 0; i < 3; i++)
        //     std::cout << "V [" << i << "] = " << v1[i] << std::endl;
        // std::cout << v1.size() << std::endl;
        // std::cout << v1.capacity() << std::endl;
    }
    {

        // TESTING COPY CONSTROCTOR

        // ft::vector<int> v1;

        // std::cout << "------------------------------ TEST COPY CONSTROCTOR ----------------" << std::endl;

        // v1.test_stock();
        // for (int i = 0; i < 6; i++)
        //     std::cout << v1[i] << std::endl;

        // std::cout << "---------------------------------------------------------------------" << std::endl;

        // ft::vector<int> v2;
        // v2 = v1;
        // v2 = v1;
        // v2 = v1;
        // v2 = v1;
        // for (int i = 0; i < 6; i++)
        //     std::cout << v2[i] << std::endl;
        // while (1);
    }
    {
        // std::cout << "------------------------------ FT PUSH BACK ----------------" << std::endl;

        // ft::vector<int> v;
        
        // for (int i = 1; i < N; i++)
        // {
        //     v.push_back(i);
        //     std::cout << "ARR[" << i - 1 << "] = " << v[i - 1] << " SIZE = " << v.size() << " CAPACITY = " << v.capacity() << std::endl;
        // }
    }
}