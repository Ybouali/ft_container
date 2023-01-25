#include "../map.hpp"
#include <map>

int main()
{
    
    ft::map<int, int> data;
    
    for (std::size_t i = 0; i < 10000000; i++) {
        srand(time(NULL));
        data.insert(ft::make_pair(rand(), rand()));
    }

    std::cout << "DONE INSERTING DATA" << std::endl;

    ft::map<int, int>::iterator it = data.lower_bound(rand());
    // for (int i = 0; i < 10000000; ++i) {
    //     ft::map<int, int>::iterator it = data.lower_bound(rand());
    //         if (it != data.end()) {
    //         {
    //             std::cout << "  " << it->first << std::endl;
    //             it->second = 64;
    //         }
    // }

    // ft::map<int, int>   map;

    // ft::map<int, int>::iterator it = map.insert(ft::make_pair(0, 0)).first;
    // ++it;
    // if (it == map.end())
    //     std::cout << "here is nothing " << std::endl;
    // --it;
    // std::cout << it->first << std::endl;

    // // map.insert(ft::make_pair(10, 10));

    // // std::cout << "Loading map..." << std::endl;
}

