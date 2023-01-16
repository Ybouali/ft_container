#include "../map.hpp"
#include <map>

int     main()
{
    ft::map<int, std::string> map;
    // ft::map<int, std::string> map1;

    // map.insert(ft::make_pair(10, 1001));
    // map.insert(ft::make_pair(20, 1001));
    // map.insert(ft::make_pair(30, 1001));
    // map.insert(ft::make_pair(40, 1001));
    // map.insert(ft::make_pair(50, 1001));
    // map.insert(ft::make_pair(60, 1001));
    // map.insert(ft::make_pair(70, 1001));

    map.insert(ft::make_pair(23, "23n"));
    map.insert(ft::make_pair(25, "asdasdfsdfsafdsf"));
    map.insert(ft::make_pair(1, "asdssdfdfdffffff"));
    map.insert(ft::make_pair(2, "dsfdffffdfdfdsdfdffa"));
    map.insert(ft::make_pair(3, "sssdfs"));
    map.insert(ft::make_pair(75, "dfse"));
    map.insert(ft::make_pair(30, "sefsadfasdfasdfsadfasdfsf"));
    map.insert(ft::make_pair(-22, "dfhkihgbnfbcx5reterjhd"));
    map.insert(ft::make_pair(-23, "sdffgdfgrefet34thfgheewt"));
    map.insert(ft::make_pair(0, "98y4rtuohwidsjusdossefsse"));
    
    // if ()

    std::cout << "OK :: " << map.erase(75) << std::endl;

    ft::map<int, std::string>::iterator it = map.begin();
    
    while (it != map.end())
    {

        std::cout << "map :: " << it->first << " " << it->second << std::endl;
        // std::cout << "map1 :: " << it1->first << " " << it1->second << std::endl;
        it++;
        // it1++;
    }
}