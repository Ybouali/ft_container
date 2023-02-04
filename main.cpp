// #include "headers.hpp"

#include "vector.hpp"
#include "map.hpp"

#include <iostream>

// int ac, char **av
int main()
{
    // if (ac != 2)
    // {
    //     std::cout << "PLEASE: ENTER IN THE TERMINAL ./containers and the name of the container :) " << std::endl;
    //     return 1;
    // }
    // if ((std::string)av[1] == "vector")
    //     vector_tests();
    // else if ((std::string)av[1] == "stack")
    //     stack_tests();
    // else if ((std::string)av[1] == "map")
    //     map_tests();

    ft::vector<ft::pair<int, int> > data;

    for (std::size_t i = 0; i < 2500000; ++i) {
        data.push_back(ft::make_pair(rand(), rand()));
    }

    

    for (int i = 0; i < 1; ++i) {
        
        ft::map<int, int> m(data.begin(), data.begin() + 2500000);
        
        // m.clear();
    }
}