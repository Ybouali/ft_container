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
    std::vector<int> v;
    ft::vector<int> ft_v;

    // v.reserve(10);
    // ft_v.reserve(10);
    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
        ft_v.push_back(i);
    }

    std::vector<int>::iterator it;
    ft::vector<int>::iterator ft_it;


    // v.reserve(30);
    //  ft_v.reserve(30);
    std::cout << " STD SIZE :: " << v.size() << " STD CAPA :: " << v.capacity() << std::endl;
    std::cout << "  FT SIZE :: " << ft_v.size() << "  FT CAPA :: " << ft_v.capacity() << std::endl << std::endl;

    it = v.erase(v.begin() + 2);
    ft_it = ft_v.erase(ft_v.begin() + 2);

    std::cout << " RETURN STD :: " << *it << std::endl;
    std::cout << " RETURN  FT :: " << *ft_it << std::endl << std::endl;

    // v.insert(v.begin(), 100, "hello");
    // ft_v.insert(ft_v.begin(), 100, "hello");
    // v.insert(v.begin(), 0, "TEST :)");
    // ft_v.insert(ft_v.begin(), 0, "TEST :)");

    // std::cout << "RETURN VAL IT STD :: " << *it << " STD SIZE :: " << v.size() << " STD CAPA :: " << v.capacity() << std::endl;
    // std::cout << "RETURN VAL IT STD :: " << *ft_it << "  FT SIZE :: " << ft_v.size() << "  FT CAPA :: " << ft_v.capacity() << std::endl << std::endl;


    for (size_t i = 0; i < 8; i++)
    {
        std::cout << "   V[" << i << "] :: " << v[i] << " STD SIZE :: " << v.size() << " STD CAPA :: " << v.capacity() << std::endl; 
        std::cout << "FT_V[" << i << "] :: " << ft_v[i] << "  FT SIZE :: " << ft_v.size() << "  FT CAPA :: " << ft_v.capacity() << std::endl << std::endl;
    }

}
