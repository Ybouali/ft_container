#include "../vector.hpp"
#include <vector>

#define S 6

int main()
{
    // ft::vector<int> vf;
    int p[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    std::vector<int> vs;
    ft::vector<int> vf;

    
    for(int i=0; i < 2; i++)
    {
        vs.push_back(99);
        vf.push_back(99);
    } 

    for (int i=0; i < (int)vs.size(); i++)
    {
        std::cout << "      VF[" << i << "] = " << vf[i] << " SIZE :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl;
        std::cout << "      VS[" << i << "] = " << vs[i] << " SIZE :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl << std::endl;
    }
    vs.assign(p, p + 9);
    vf.assign(p, p + 9);

    std::cout << "------------------------------------------------------------------------------------" << std::endl;

    std::cout << " STD SIZE :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl;
    std::cout << "  FT SIZE :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl;

    for (int i=0; i < (int)vs.size(); i++)
    {
        std::cout << "      VF[" << i << "] = " << vf[i] << " SIZE :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl;
        std::cout << "      VS[" << i << "] = " << vs[i] << " SIZE :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl << std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    // for (int i=0; i < (int)vs.size(); i++)
    // {
    //     std::cout << "      VF[" << i << "] = " << vf[i] << " SIZE :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl;
    //     std::cout << "      VS[" << i << "] = " << vs[i] << " SIZE :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl << std::endl;
    // }
    while (1);
}
