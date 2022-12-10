#include "../vector.hpp"
#include <vector>

#define S 6

int main()
{
    // ft::vector<int> vf;
    // int p[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    std::vector<int> vs;
    ft::vector<int> vf;

    for(int i=0; i < 10; i++)
    {
        vs.push_back(i);
        vf.push_back(i);
    } 

    // for (int i=0; i < (int)vs.size(); i++)
    // {
    //     std::cout << "      VF[" << i << "] = " << vf[i] << " SIZE :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl;
    //     std::cout << "      VS[" << i << "] = " << vs[i] << " SIZE :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl << std::endl;
    // }

    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    std::vector<int>::iterator its = vs.erase(vs.begin(), vs.begin() + 6);
    ft::vector<int>::iterator itf = vf.erase(vf.begin(), vf.begin() + 6);

    std::cout << " STD *it :: " << *its << " SIZE :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl;
    std::cout << "  FT *it :: " << *itf << " SIZE :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl;

    // for (int i=0; i < (int)vs.size(); i++)
    // {
    //     std::cout << "      VS[" << i << "] = " << vs[i] << " SIZE :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl << std::endl;
    //     std::cout << "      VF[" << i << "] = " << vf[i] << " SIZE :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl;
    // }
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    // for (int i=0; i < (int)vs.size(); i++)
    // {
    //     std::cout << "      VF[" << i << "] = " << vf[i] << " SIZE :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl;
    //     std::cout << "      VS[" << i << "] = " << vs[i] << " SIZE :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl << std::endl;
    // }
    // while (1);
}
