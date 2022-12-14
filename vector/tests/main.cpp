#include <vector>

#include "../vector.hpp"

int main()
{
    ft::vector<long> v1(19, 100);
    std::vector<long> v2(19, 100);

    std::cout << " *v1.rbegin() - 10 :: " << *(v1.rbegin() + 10) << std::endl;
    std::cout << " *v2.rbegin() - 10 :: " << *(v2.rbegin() + 10) << std::endl;
    

}