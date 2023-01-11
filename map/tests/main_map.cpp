#include "../map.hpp"
#include <map>

int     main()
{
    goto next;
    {
        std::cout << "STD MAIN :: " << std::endl;
        std::map<int, std::string >   map;


        map.insert(std::make_pair(200, "TEST :)"));
        map.insert(std::make_pair(150, "TEST :)"));
        map.insert(std::make_pair(250, "TEST :)"));
        map.insert(std::make_pair(300, "TEST :)"));
        map.insert(std::make_pair(225, "TEST :)"));
        map.insert(std::make_pair(400, "TEST :)"));
        map.insert(std::make_pair(500, "TEST :)"));
        map.insert(std::make_pair(600, "TEST :)"));
        map.insert(std::make_pair(650, "TEST :)"));


        
        std::map<int, std::string>::iterator it_b = map.begin();
        std::map<int, std::string>::iterator it_e = map.end();

        map.clear();

        while (it_b != it_e) 
        {
            std::cout << it_b->first << " : : " << it_b->second << std::endl;
            it_b++;
        }
    }
next:
    {
        std::cout << "FT MAIN :: " << std::endl;
        ft::map<int, std::string >   map;

        map[10] = "test 11";
        map[1] = "test 11";
        map[12] = "test 11";
        // map.insert(ft::make_pair(200, "TEST :)"));
        // map.insert(ft::make_pair(150, "TEST :)"));
        // map.insert(ft::make_pair(250, "TEST :)"));
        // map.insert(ft::make_pair(300, "TEST :)"));
        // map.insert(ft::make_pair(225, "TEST :)"));
        // map.insert(ft::make_pair(400, "TEST :)"));
        // map.insert(ft::make_pair(500, "TEST :)"));
        // map.insert(ft::make_pair(600, "TEST :)"));
        // map.insert(ft::make_pair(650, "TEST :)"));

        map.clear();

        map[20] = "test 11";
        map[1] = "test 11";
        map[120] = "test 11";

        ft::map<int, std::string>::iterator it_b = map.begin();
        // // std::cout << "Testing map" << std::endl;
        ft::map<int, std::string>::iterator it_e = map.end();

        // // map.clear();

        while (it_b != it_e) 
        {
            std::cout << it_b->first << " : : " << it_b->second << std::endl;
            it_b++;
        }
    }
}