#include "../map.hpp"
#include <map>



int     main()
{
    
    // , std::greater<int>
    ft::map<int, std::string >   map;

    map.insert(ft::make_pair(10, "TEST :)"));
    map.insert(ft::make_pair(18, "TEST :)"));
    map.insert(ft::make_pair(8, "TEST :)"));
    map.insert(ft::make_pair(9, "TEST :)"));
    map.insert(ft::make_pair(2, "TEST :)"));
    map.insert(ft::make_pair(20, "TEST :)"));
    map.insert(ft::make_pair(17, "TEST :)"));
    
    // std::map<int, std::string> std_map;

    // std_map.insert(std::make_pair(10, "TEST"));
}