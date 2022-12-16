#include <vector>
#include <iostream>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#include "../vector.hpp"

int main()
{
    std::vector<std::string> v(20, "HELLO WORLD !");
    ft::vector<std::string> ft_v(20, "HELLO WORLD !");
    
    // std::vector<std::string>::iterator it;
    // ft::vector<std::string>::iterator ft_it;

    std::cout << " STD SIZE :: " << v.size() << " STD CAPA :: " << v.capacity() << std::endl;
    std::cout << "  FT SIZE :: " << ft_v.size() << "  FT CAPA :: " << ft_v.capacity() << std::endl << std::endl;
    v.insert(v.begin() + 2, 1, "hello");
    ft_v.insert(ft_v.begin() + 2, 1, "hello");

    // std::cout << "RETURN VAL IT STD :: " << *it << " STD SIZE :: " << v.size() << " STD CAPA :: " << v.capacity() << std::endl;
    // std::cout << "RETURN VAL IT STD :: " << *ft_it << "  FT SIZE :: " << ft_v.size() << "  FT CAPA :: " << ft_v.capacity() << std::endl << std::endl;


    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << "   V[" << i << "] :: " << v[i] << " STD SIZE :: " << v.size() << " STD CAPA :: " << v.capacity() << std::endl; 
        std::cout << "FT_V[" << i << "] :: " << ft_v[i] << "  FT SIZE :: " << ft_v.size() << "  FT CAPA :: " << ft_v.capacity() << std::endl << std::endl;
    }
}
