#include "../map.hpp"
#include <map>

int     main()
{
    
    // std::greater<int>
    ft::map<int, std::string >   map;

    // for (int i = -10; i <= 10; i++)
    //     map.insert(ft::make_pair(i, "TEST :)"));


    map.insert(ft::make_pair(100, "TEST :)"));
    map.insert(ft::make_pair(99, "TEST :)"));
    map.insert(ft::make_pair(200, "TEST :)"));
    map.insert(ft::make_pair(150, "TEST :)"));
    map.insert(ft::make_pair(300, "TEST :)"));
    map.insert(ft::make_pair(125, "TEST :)"));
    map.insert(ft::make_pair(130, "TEST :)"));
    map.insert(ft::make_pair(225, "TEST :)"));
    map.insert(ft::make_pair(43, "TEST :)"));
    map.insert(ft::make_pair(49, "TEST :)"));
    // map.insert(ft::make_pair(31, "TEST :)"));
    // map.insert(ft::make_pair(60, "TEST :)"));
    // ft::Node<int, std::string>    result;

    map.erase(130);
    map.erase(125);
    map.erase(100);

    // system("leaks a.out");

    // std::cout << "------------------------> " << result.data->first << std::endl;
    // map.insert(ft::make_pair(18, "TEST :)"));
    // map.insert(ft::make_pair(7, "TEST :)"));
    // map.insert(ft::make_pair(15, "TEST :)"));
    // map.insert(ft::make_pair(16, "TEST :)"));
    // map.insert(ft::make_pair(30, "TEST :)"));
    // map.insert(ft::make_pair(25, "TEST :)"));
    // map.insert(ft::make_pair(40, "TEST :)"));
    // map.insert(ft::make_pair(60, "TEST :)"));
    // map.insert(ft::make_pair(2, "TEST :)"));
    // map.insert(ft::make_pair(1, "TEST :)"));
    // map.insert(ft::make_pair(70, "TEST :)"));
    

    // map.insert(ft::make_pair(10, "TEST :)"));
    // map.insert(ft::make_pair(19, "TEST :)"));
    // map.insert(ft::make_pair(8, "TEST :)"));
    // map.insert(ft::make_pair(20, "TEST :)"));
    // map.insert(ft::make_pair(9, "TEST :)"));
    // map.insert(ft::make_pair(18, "TEST :)"));
    
}