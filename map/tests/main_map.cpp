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
    // map.insert(ft::make_pair(300, "TEST :)"));
    // map.insert(ft::make_pair(225, "TEST :)"));
    // map.insert(ft::make_pair(400, "TEST :)"));
    // map.insert(ft::make_pair(500, "TEST :)"));
    // map.insert(ft::make_pair(600, "TEST :)"));
    // map.insert(ft::make_pair(650, "TEST :)"));
    // map.insert(ft::make_pair(625, "TEST :)"));

    ft::map<int, std::string>::iterator it_b = map.begin();
    // ft::map<int, std::string>::iterator it_e = map.end();
    ft::map<int, std::string>::iterator it_e = map.end();
    // map.erase(250);

    it_e--;
    // std::cout << it_e->first << std::endl;
    // if (it_b < it_e)
    //     std::cout << "hello world!" << std::endl;
    // if (*it_b < *it_e)
    //     std::cout << "hello world!" << std::endl;
    






    // ft::map<int, std::string>::iterator it_t;

    // std::cout << ((*++it_b)).first << std::endl;
    // std::cout << it_e->first << std::endl;
    // it_e++;
    // std::cout << it_e->first << std::endl;
    // std::cout << "it_b // " << (*it_b).first << ": :" << it_b->first << std::endl;
    // ++it_b;
    // std::cout << "++it_b // " << (*it_b).first << ": :" << it_b->first << std::endl;
    // it_b++;
    // std::cout << "it_b++ // " << (*it_b).first << ": :" << it_b->first << std::endl;
    // ++it_b;
    // std::cout << "++it_b // " << (*it_b).first << ": :" << it_b->first << std::endl;
}