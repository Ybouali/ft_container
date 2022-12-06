#include "../vector.hpp"
// #include <iostream>
#include <vector>

int main()
{
    
    // int t[] = {1, 2, 3, 4, 5, 6, 7};
    // std::string t[] = {"1111", "2222", "3333", "4444", "5555", "6666", "7777"};

    std::vector<int> vs(1, 10);
    ft::vector<int> vf(1, 10);
    

    // for (int i = 0; i < 5; i++)
    // {
    //     s.push_back(i * 10);
    //     f.push_back(i * 10);
    // }


    // std::vector<int>    vs(s.begin(), s.end());
    // ft::vector<int>    vf(f.begin(), f.end());

    for (int i = 0; i < (int)vf.size(); i++)
    {
        std::cout << "      vs[" << i << "] = " << vs[i] << " CAPA :: " << vs.capacity() << " SIZE :: " << vs.size() << std::endl;
        std::cout << "      vf[" << i << "] = " << vf[i] << " CAPA :: " << vf.capacity() << " SIZE :: " << vf.size() << std::endl  << std::endl;
    }

}
