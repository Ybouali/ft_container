#include "../vector.hpp"
#include <vector>

#define S 6

int main()
{
    std::vector<int> vs;
    ft::vector<int> vf;

    for(int i=0; i < 4; i++)
    {
        vs.push_back(i + 11);
        vf.push_back(i + 11);
    }    

    std::cout << "------------------------------------------------------------------------------------" << std::endl;

    for (int i=0; i < 4; i++)
    {
        std::cout << "      VS[" << i << "] = " << vs[i] << " SIZE :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl;
        std::cout << "      VF[" << i << "] = " << vf[i] << " SIZE :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl << std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    // std::cout << " >>>>>>>>>>>>>> SIZE STD :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl << std::endl;
    // std::cout << " >>>>>>>>>>>>>> SIZE  FT :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl << std::endl;
    vs.insert(vs.begin() + 4, 5, 199);
    vf.insert(vf.begin() + 4, 5, 199);
    // std::cout << " >>>>>>>>>>>>>> SIZE STD :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl << std::endl;
    // std::cout << " >>>>>>>>>>>>>> SIZE  FT :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl << std::endl;
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    for (int i=0; i < (int)vs.size(); i++)
    {
        std::cout << "      VS[" << i << "] = " << vs[i] << " SIZE :: " << vs.size() << " CAPA :: " << vs.capacity() << std::endl;
        std::cout << "      VF[" << i << "] = " << vf[i] << " SIZE :: " << vf.size() << " CAPA :: " << vf.capacity() << std::endl << std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
}
