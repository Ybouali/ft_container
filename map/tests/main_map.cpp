#include "../map.hpp"
#include <map>

int     main()
{
    // goto next;
    {
        std::cout << "STD MAIN :: " << std::endl;
        std::map<int, std::string >   map;


        map.insert(std::make_pair(200, "TEST :)"));
        map.insert(std::make_pair(150, "TEST :)"));
        map.insert(std::make_pair(100, "TEST :)"));
        map.insert(std::make_pair(250, "TEST :)"));
        map.insert(std::make_pair(300, "TEST :)"));
        map.insert(std::make_pair(225, "TEST :)"));
        map.insert(std::make_pair(400, "TEST :)"));
        map.insert(std::make_pair(500, "TEST :)"));
        map.insert(std::make_pair(600, "TEST :)"));
        map.insert(std::make_pair(650, "TEST :)"));

        std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator > te = map.equal_range(60);

        std::cout << "te : first : fisrt   : " << te.first->first << std::endl;
        std::cout << "te : first : second  : " << te.first->second << std::endl;
        std::cout << "te : second : fisrt  : " << te.second->first << std::endl;
        std::cout << "te : second : second : " << te.second->second << std::endl;

        // std::map<int, std::string>::iterator    it_u = map.upper_bound(10);
        // std::map<int, std::string>::iterator    it_l = map.lower_bound(10);

        // std::cout << "  UPPER BOUND :: " << it_u->first << " :: " << it_u->second << std::endl;
        // std::cout << "  LOWER BOUND :: " << it_l->first << " :: " << it_l->second << std::endl;

        // std::map<int, std::string>::iterator    itt = map.upper_bound(399);
        // std::cout << (*it).first << std::endl;
        // std::cout << (*itt).first << std::endl;
        // std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> test;

        // std::map<int, std::string>::iterator it_u = map.upper_bound(225);
        // std::map<int, std::string>::iterator it_l = map.lower_bound(225);

        
        // std::cout << it_l->first << " :: " << it_l->second << std::endl;
    }
// next:
    {
        std::cout << "FT MAIN :: " << std::endl;
        ft::map<int, std::string >   map;

        map.insert(ft::make_pair(200, "TEST :)"));
        map.insert(ft::make_pair(150, "TEST :)"));
        map.insert(ft::make_pair(250, "TEST :)"));
        map.insert(ft::make_pair(100, "TEST :)"));
        map.insert(ft::make_pair(300, "TEST :)"));
        map.insert(ft::make_pair(225, "TEST :)"));
        map.insert(ft::make_pair(400, "TEST :)"));
        map.insert(ft::make_pair(500, "TEST :)"));
        map.insert(ft::make_pair(600, "TEST :)"));
        map.insert(ft::make_pair(650, "TEST :)"));



        ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator > te = map.equal_range(60);

        std::cout << "te : first : fisrt   : " << te.first->first << std::endl;
        std::cout << "te : first : second  : " << te.first->second << std::endl;
        std::cout << "te : second : fisrt  : " << te.second->first << std::endl;
        std::cout << "te : second : second : " << te.second->second << std::endl;


        // // // ft::map<int, std::string>::iterator it_u = map.upper_bound(225);
        // ft::map<int, std::string>::iterator it_u = map.upper_bound(10);
        // ft::map<int, std::string>::iterator it_l = map.lower_bound(10);

        // // // std::cout << it_l->first << " :: " << it_l->second << std::endl;
        // if (it_l == map.end())
        //     it_l--;
        // if (it_u == map.end())
        //     it_l--;
        // std::cout << "  UPPER BOUND :: " << it_u->first << " :: " << it_u->second << std::endl;
        // std::cout << "  LOWER BOUND :: " << it_l->first << " :: " << it_l->second << std::endl;
        

        // // std::cout << it_e->first << " : >>>>>>>>>>> : " << it_e->second << std::endl;
        // it_e--;
        // std::cout << it_e->first << " : >>>>>>>>>>> : " << it_e->second << std::endl;
        
        // while (it_b != it_e)
        // {
        //     std::cout << it_b->first << " : >>>>>>>>>>> : " << it_b->second << std::endl;
        //     it_b++;
        // }


        // std::cout << it_b->first << " : >>>>>>>>>>> : " << it_b->second << std::endl;
        // it_b--;
        // std::cout << it_b->first << " : >>>>>>>>>>> : " << it_b->second << std::endl;

        // ft::pair<ft::map<int, std::string>::iterator, bool>  te = map.insert(ft::make_pair(650, "TEST :)"));

        


        // if (te.second)
        //     std::cout << "Testing " << std::endl;
        // std::cout << "te : FIRST : " << (*te.first).first << std::endl;
        // std::cout << "te : SECOND : " << (*te.first).second << std::endl;

        // if (te->second)
        //     std::cout << "it :: " << te->first << " :: " << (*te).second << std::endl;
    }
}