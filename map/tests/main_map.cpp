#include "../map.hpp"
#include <map>

int     main()
{
    ft::map<int, int> map;

    map.insert(ft::make_pair(10, 1001));
    map.insert(ft::make_pair(20, 1001));
    map.insert(ft::make_pair(30, 1001));
    map.insert(ft::make_pair(40, 1001));
    map.insert(ft::make_pair(50, 1001));
    map.insert(ft::make_pair(60, 1001));
    map.insert(ft::make_pair(70, 1001));

    ft::map<int, int>::iterator it = map.begin();

    std::cout << " AT " << map.at(20) << std::endl;
    // while (it != map.end())
    // {
    //     std::cout << " :: " << it->first << " :: " << it->second << std::endl;
    // }
}