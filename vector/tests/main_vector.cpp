// #include <vector>
// #include <iostream>
// #include <iterator>
// #include <ctime>
// #include <iomanip>
// #include <unistd.h>
// #include <signal.h>
// #include <sys/time.h>
// #include <map>
// #include <algorithm>
// #include <cmath>

// #include "../vector.hpp"

// // int main()
// // {
// //     std::vector<int> v;
// //     ft::vector<int> ft_v;

// //     // v.reserve(10);
// //     // ft_v.reserve(10);
// //     for (int i = 0; i < 5; i++)
// //     {
// //         v.push_back(i);
// //         ft_v.push_back(i);
// //     }

// //     std::vector<int>::iterator it;
// //     ft::vector<int>::iterator ft_it;


// //     // v.reserve(30);
// //     //  ft_v.reserve(30);
// //     std::cout << " STD SIZE :: " << v.size() << " STD CAPA :: " << v.capacity() << std::endl;
// //     std::cout << "  FT SIZE :: " << ft_v.size() << "  FT CAPA :: " << ft_v.capacity() << std::endl << std::endl;

// //     it = v.erase(v.begin() + 2);
// //     ft_it = ft_v.erase(ft_v.begin() + 2);

// //     std::cout << " RETURN STD :: " << *it << std::endl;
// //     std::cout << " RETURN  FT :: " << *ft_it << std::endl << std::endl;

// //     // v.insert(v.begin(), 100, "hello");
// //     // ft_v.insert(ft_v.begin(), 100, "hello");
// //     // v.insert(v.begin(), 0, "TEST :)");
// //     // ft_v.insert(ft_v.begin(), 0, "TEST :)");

// //     // std::cout << "RETURN VAL IT STD :: " << *it << " STD SIZE :: " << v.size() << " STD CAPA :: " << v.capacity() << std::endl;
// //     // std::cout << "RETURN VAL IT STD :: " << *ft_it << "  FT SIZE :: " << ft_v.size() << "  FT CAPA :: " << ft_v.capacity() << std::endl << std::endl;


// //     for (size_t i = 0; i < 8; i++)
// //     {
// //         std::cout << "   V[" << i << "] :: " << v[i] << " STD SIZE :: " << v.size() << " STD CAPA :: " << v.capacity() << std::endl; 
// //         std::cout << "FT_V[" << i << "] :: " << ft_v[i] << "  FT SIZE :: " << ft_v.size() << "  FT CAPA :: " << ft_v.capacity() << std::endl << std::endl;
// //     }


// #define TESTED_TYPE int

// int		main(void)
// {
	
// 	ft::vector<int>	v1(4);

// 	ft::vector<int>::iterator	it = v1.begin();
// 	std::for_each(it, v1.begin(), v1.end(), &(std::abs()));
	
// 	// ft::vector<int>::const_iterator	it1 = it;

// 	// std::cout << it1 - it << std::endl;

// 	return (0);
// }

// // }



// 30
// for_each example
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector
#include "../vector.hpp"

// void myfunction (int i) {  // function:
//   std::cout << ' ' << i;
// }

// struct myclass {           // function object type:
//   void operator() (int i) {std::cout << ' ' << i;}
// } myobject;

// int main () {
//   ft::vector<int> myvector;
//   std::iterator_traits<ft::vector<int>::iterator >::difference_type test;
//   myvector.push_back(10);
//   myvector.push_back(20);
//   myvector.push_back(30);

//   std::cout << "myvector contains:";
//   std::count (myvector.begin(), myvector.end(), 42);
//   std::cout << '\n';

//   // or:
//   std::cout << "myvector contains:";
//   std::for_each (myvector.rbegin(), myvector.rend(), myobject);
//   std::cout << '\n';

//   return 0;
// }

int main()
{
  ft::vector<int> myvector(10, 19);
  ft::vector<int>::iterator   n_it = myvector.begin(); 
  ft::vector<int>::const_iterator   c_it = myvector.begin(); 

  if (c_it == n_it)
    std::cout << "hello : " << std::endl;
}