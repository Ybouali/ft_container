#include "../vector.hpp"
#include <vector>

int main()
{
    ft::vector<int> v;

    v.test_stock(9);
    
    ft::vector<int>::iterator   ptr;

    for (ptr = v.begin(); ptr < v.end(); ptr++)
        std::cout << *ptr << std::endl;
}