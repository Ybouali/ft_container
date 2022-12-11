#include "../vector.hpp"
#include <vector>

#define S 6

int main()
{
    // ft::vector<int> vf;
    int p[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64};
    std::vector<int> vs(p + 10 , p + 20);
    ft::vector<int> vf(p + 10, p + 20);

    // for(int i=0; i < 10; i++)
    // {
    //     vs.push_back(i);
    //     vf.push_back(i);
    // } 

    for (int i=0; i < (int)vs.size(); i++)
    {
        std::cout << "      VF[" << i << "] = " << vf[i] << " SIZE :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl;
        std::cout << "      VS[" << i << "] = " << vs[i] << " SIZE :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    std::vector<int>::iterator its = vs.erase(vs.begin() + 1);
    ft::vector<int>::iterator itf = vf.erase(vf.begin() + 1);
    for (int i=1; i < 4; i++)
    {
        its = vs.erase(vs.begin() + i);
        itf = vf.erase(vf.begin() + i);or
    }

    std::cout << " STD *it :: " << *its << " SIZE :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl;
    std::cout << "  FT *it :: " << *itf << " SIZE :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl << std::endl;

    for (int i = 0; i < (int)vs.size(); i++)
    {
        std::cout << "      VS[" << i << "] = " << vs[i] << " SIZE :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl;
        std::cout << "      VF[" << i << "] = " << vf[i] << " SIZE :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl << std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    // for (int i=0; i < 10; i++)
    // {
    //     std::cout << "      VF[" << i << "] = " << vf[i] << " SIZE :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl;
    //     std::cout << "      VS[" << i << "] = " << vs[i] << " SIZE :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl << std::endl;
    // }
    // while (1);
}
