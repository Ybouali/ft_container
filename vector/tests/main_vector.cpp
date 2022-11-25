#include "../vector.hpp"
#include <vector>

int main()
{
    std::vector<int>    v;
    ft::vector<int>     v1;
    
    for (int i = 0; i < 5; i++)
    {
        // std::cout << "STD:: SIZE = " << v.size() << " CAPACITY = " << v.capacity() << std::endl; 
        // std::cout << "STD:: SIZE = " << v1.size() << " CAPACITY = " << v1.capacity() << std::endl; 
        v.push_back(i);
        v1.push_back(i);
    }


    for (int i = 0; i < 5; i++)
    {
        std::cout << "STD :: v[" << i << "] = " << v[i] << std::endl;
        std::cout << " FT :: v1[" << i << "] = " << v1[i] << std::endl;
    }
    std::cout << "--------------------------------------------------------------" << std::endl;
    v.assign(19, 89);
    v1.assign(19, 89);
    for (int i = 0; i < 10; i++)
    {
        std::cout << " STD :: v[" << i << "] = " << v[i] << " CAPACITY : " << v.capacity() << " SIZE :: " << v.size() << std::endl;
        std::cout << " FT :: v1[" << i << "] = " << v1[i] << " CAPACITY : " << v1.capacity() << " SIZE :: "<< v1.size() << std::endl;
    }

    // while (1);
}