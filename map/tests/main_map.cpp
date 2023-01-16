#include "../map.hpp"
#include <map>

int     main()
{
    ft::map<int, int> map;
    ft::map<int, int> map1;

    map.insert(ft::make_pair(10, 1001));
    map.insert(ft::make_pair(20, 1001));
    map.insert(ft::make_pair(30, 1001));
    map.insert(ft::make_pair(40, 1001));
    map.insert(ft::make_pair(50, 1001));
    map.insert(ft::make_pair(60, 1001));
    map.insert(ft::make_pair(70, 1001));

    map1 = map;
}