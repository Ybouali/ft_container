#include "../map.hpp"

int main()
{
    ft::map<int, int>   map;

    map.insert(ft::make_pair(10, 10));

    std::cout << "Loading map..." << std::endl;
}

