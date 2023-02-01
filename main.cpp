#include "headers.hpp"

#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "PLEASE: ENTER IN THE TERMINAL ./containers and the name of the container :) " << std::endl;
        return 1;
    }
    if ((std::string)av[1] == "vector")
        vector_tests();
    // else if ((std::string)av[1] == "stack")
        // stack_tests();
    // else if ((std::string)av[1] == "map")
        // map_tests();
}