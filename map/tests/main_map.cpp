#include "../map.hpp"
#include <map>

int     main()
{
    
    // std::greater<int>
    ft::map<int, std::string >   map;

    // for (int i = -10; i <= 10; i++)
    //     map.insert(ft::make_pair(i, "TEST :)"));


    map.insert(ft::make_pair(200, "TEST :)"));
    map.insert(ft::make_pair(150, "TEST :)"));
    map.insert(ft::make_pair(250, "TEST :)"));
    map.insert(ft::make_pair(300, "TEST :)"));
    // map.insert(ft::make_pair(225, "TEST :)"));
    map.insert(ft::make_pair(400, "TEST :)"));
    map.insert(ft::make_pair(500, "TEST :)"));
    map.insert(ft::make_pair(600, "TEST :)"));
    map.insert(ft::make_pair(650, "TEST :)"));
    map.insert(ft::make_pair(625, "TEST :)"));
    // map.find(225);
    map.erase(200);

       
}