#include "../map.hpp"
#include <map>

int     main()
{
    
    // std::greater<int>
    ft::map<int, std::string >   map;

    // for (int i = -10; i <= 10; i++)
    //     map.insert(ft::make_pair(i, "TEST :)"));


    // map.insert(ft::make_pair(3, "TEST :)"));
    // map.insert(ft::make_pair(2, "TEST :)"));
    // map.insert(ft::make_pair(1, "TEST :)"));
    // map.insert(ft::make_pair(0, "TEST :)"));
    // map.insert(ft::make_pair(-1, "TEST :)"));
    // map.insert(ft::make_pair(-2, "TEST :)"));
    // map.insert(ft::make_pair(0, "TEST :)"));
    map.insert(ft::make_pair(200, "TEST :)"));
    map.insert(ft::make_pair(150, "TEST :)"));
    map.insert(ft::make_pair(250, "TEST :)"));
    map.insert(ft::make_pair(300, "TEST :)"));
    map.insert(ft::make_pair(225, "TEST :)"));
    map.insert(ft::make_pair(400, "TEST :)"));
    map.insert(ft::make_pair(500, "TEST :)"));
    map.insert(ft::make_pair(600, "TEST :)"));
    map.insert(ft::make_pair(650, "TEST :)"));
    map.insert(ft::make_pair(625, "TEST :)"));
    // map.find(225);
    // map.erase(150);

    ft::map<int, std::string>::iterator it_b = map.begin();
    ft::map<int, std::string>::iterator it_e = map.end();

    std::cout << "--0 // " << it_e->first << std::endl;
    --it_e;
    std::cout << "--1 // " << it_e->first << std::endl;
    --it_e;
    std::cout << "--2 // " << it_e->first << std::endl;
    --it_e;
    std::cout << "--3 // " << it_e->first << std::endl;
    --it_e;
    std::cout << "--4 // " << it_e->first << std::endl;
    --it_e;
    std::cout << "--5 // " << it_e->first << std::endl;
    --it_e;
    std::cout << "--6 // " << it_e->first << std::endl;
    --it_e;
    std::cout << "--7 // " << it_e->first << std::endl;
    --it_e;
    std::cout << "--8 // " << it_e->first << std::endl;
    --it_e;
    std::cout << "--9 // " << it_e->first << std::endl;
    // ++it_b;
    // std::cout << "10 // " << it_b->first << std::endl;

    
    // // std::cout << "TEST : " << it->first << std::endl;
    // // std::cout << "TEST : " << pair.first << std::endl;
    // // it = map.begin();
    // // it = map.end();
    // std::cout << it->first << std::endl;
}