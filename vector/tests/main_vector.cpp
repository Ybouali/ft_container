#include "../vector.hpp"
#include <iostream>
#include <vector>

int main()
{
    // int t[] = {1, 2, 3, 4, 5, 6, 7};

    std::vector<double>    vs;
    ft::vector<double>    vf;

    for (int i = 0; i < 26; i++)
    {
        vs.push_back(45.0123);
        vf.push_back(45.0123);
    }
    
    for (int i = 0; i < (int)vf.size(); i++)
    {
        
        std::cout << "  STD   vs[" << i << "] = " << vs[i] << " C = " << vs.capacity() << " S = " << vs.size() << std::endl;
        std::cout << "  FT    vf[" << i << "] = " << vf[i] << " C = " << vf.capacity() << " S = " << vf.size() << std::endl << std::endl;
    }
    
}