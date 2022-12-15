#include <vector>

#include "../vector.hpp"

int main()
{
    std::vector<int> v(3, 4);
    std::vector<int>::iterator it;
    std::vector<int>::iterator it1;
    it = v.begin();
    it1 = v.begin() + 1;

    ft::vector<int> vf(3, 4);
    ft::vector<int>::iterator my_it;
    ft::vector<int>::iterator my_it1;
    my_it = vf.begin();
    my_it1 = vf.begin() + 1;
    
    if ((it < it1) == (my_it < my_it1))
        std::cout << "FT /// YES it > it1 " << std::endl;
    

}