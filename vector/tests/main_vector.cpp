#include "../vector.hpp"
#include <vector>

int main()
{
    ft::vector<int>    v;
    ft::vector<int>    v2;
    
    for (int i = 0; i < 5; i++)
    {
        // std::cout << "STD:: SIZE = " << v.size() << " CAPACITY = " << v.capacity() << std::endl; 
        // std::cout << "STD:: SIZE = " << v1.size() << " CAPACITY = " << v1.capacity() << std::endl; 
        v.push_back(i);
        v2.push_back(i + 4);
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << " STD :: v[" << i << "] = " << v[i] << " CAPACITY : " << v.capacity() << " SIZE :: " << v.size() << std::endl;
        std::cout << " STD :: v2[" << i << "] = " << v2[i] << " CAPACITY : " << v2.capacity() << " SIZE :: " << v2.size() << std::endl << std::endl;
    }
    v2.swap (v);
    std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << " STD :: v[" << i << "] = " << v[i] << " CAPACITY : " << v.capacity() << " SIZE :: " << v.size() << std::endl;
        std::cout << " STD :: v2[" << i << "] = " << v2[i] << " CAPACITY : " << v2.capacity() << " SIZE :: " << v2.size() << std::endl << std::endl;
        // std::cout << " STD :: v2[" << i << "] = " << v2[i] << " CAPACITY : " << v2.capacity() << " SIZE :: " << v2.size() << std::endl;
        // std::cout << " FT :: v1[" << i << "] = " << v1[i] << " CAPACITY : " << v1.capacity() << " SIZE :: "<< v1.size() << std::endl << std::endl;
    }
}