#include <iostream>
#include <sstream>
#include "../utils.hpp"

void    TEST_IS_INTEGRAL(void)
{
    std::cout << "Testing is_integer " << std::endl << std::endl;

    std::cout << "FLOAT                   :: IS " << ((ft::is_integral<float>() == std::is_integral<float>()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "INT                     :: IS " << ((ft::is_integral<int>() == std::is_integral<int>()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "BOOL                    :: IS " << ((ft::is_integral<bool>() == std::is_integral<bool>()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "CHAR                    :: IS " << ((ft::is_integral<char>() == std::is_integral<char>()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "SIGNED CHAR             :: IS " << ((ft::is_integral<signed char>() == std::is_integral<signed char>()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "UNSIGNED CHAR           :: IS " << ((ft::is_integral<unsigned char>() == std::is_integral<unsigned char>()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "WCHAR_T                 :: IS " << ((ft::is_integral<wchar_t>() == std::is_integral<wchar_t>()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "CHAR16_T                :: IS " << ((ft::is_integral<char16_t>() == std::is_integral<char16_t>()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "SHORT                   :: IS " << ((ft::is_integral<short>() == std::is_integral<short>()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "UNSIGNED SHORT          :: IS " << ((ft::is_integral<unsigned short>() == std::is_integral<unsigned short>()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    
    std::cout << "UNSIGNED INT            :: IS " << ((ft::is_integral<unsigned int>() == std::is_integral<unsigned int>()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "LONG                    :: IS " << ((ft::is_integral<long>() == std::is_integral<long>()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "UNSIGNED LONG           :: IS " << ((ft::is_integral<unsigned long>() == std::is_integral<unsigned long>()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "LONG LONG               :: IS " << ((ft::is_integral<long long>() == std::is_integral<long long>()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "UNSIGNED LONG LONG      :: IS " << ((ft::is_integral<long long>() == std::is_integral<long long>()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "STD INTPT ITERATOR TYPE :: IS " << ((ft::is_integral<std::istreambuf_iterator<char> >() == std::is_integral<std::istreambuf_iterator<char> >()) ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
}

template <class T> typename ft::enable_if<std::is_signed<T>::value>::type
foo (T i)
{
    std::cout << "T is signed   :: " << i << std::endl;
}

template <class T> typename ft::enable_if<std::is_unsigned<T>::value>::type
foo (T i)
{
    std::cout << "T is unsigned :: " << i << std::endl;
}

void    TEST_ENABLE_IF()
{
    std::cout << "Testing enable_if " << std::endl << std::endl;
    int x = 5;
    unsigned int xx = 10101;
    foo(x);
    foo(xx);
}

void    TEST_EQUL()
{
    std::cout << "Testing equl " << std::endl << std::endl;
    std::string s = "approvjvorppa";

    if (ft::equal(s.begin(), s.begin() + (s.size() / 2), s.rbegin()))
        std::cout << "EQULS IS WORKING : " << s << std::endl;
}

#include "../../vector/vector.hpp"

void    TEST_ITERATOR_TRAITS()
{
    std::cout << "Testing ITERATOR TRAITS " << std::endl << std::endl;

    ft::vector<std::string> res;
    ft::vector<std::string> res1;

    res.push_back(typeid(std::vector<int>::iterator::iterator_category).name());
	res.push_back(typeid(std::vector<int>::iterator::value_type).name());
	res.push_back(typeid(std::vector<int>::iterator::difference_type).name());
	res.push_back(typeid(std::vector<int>::iterator::iterator_type).name());
	res.push_back(typeid(std::vector<int>::iterator::pointer).name());
	res.push_back(typeid(std::vector<int>::iterator::reference).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::iterator_category).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::value_type).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::difference_type).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::pointer).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::reference).name());

    res1.push_back(typeid(ft::vector<int>::iterator::iterator_category).name());
	res1.push_back(typeid(ft::vector<int>::iterator::value_type).name());
	res1.push_back(typeid(ft::vector<int>::iterator::difference_type).name());
	res1.push_back(typeid(ft::vector<int>::iterator::iterator_type).name());
	res1.push_back(typeid(ft::vector<int>::iterator::pointer).name());
	res1.push_back(typeid(ft::vector<int>::iterator::reference).name());
	res1.push_back(typeid(ft::vector<int>::reverse_iterator::iterator_category).name());
	res1.push_back(typeid(ft::vector<int>::reverse_iterator::value_type).name());
	res1.push_back(typeid(ft::vector<int>::reverse_iterator::difference_type).name());
	res1.push_back(typeid(ft::vector<int>::reverse_iterator::pointer).name());
	res1.push_back(typeid(ft::vector<int>::reverse_iterator::reference).name());

    if (res == res1)
        std::cout << "ITERATOR TRAITS IS WORKING" << std::endl;
}

void    TEST_LEXICOGRAPHICAL()
{
    std::cout << "Testing LEXICOGRAPHICAL " << std::endl << std::endl;
    ft::vector<int> result, result2;
	ft::vector<char> v1, v2;
	ft::vector<char> b1, b2;
	v1.assign(5000 * 10000, 'f');
	v1.push_back('e');
	v2.assign(5000 * 10000, 'f');
	v2.push_back('e');
	b1.assign(5000 * 10000, 'f');
	b1.push_back('e');
	b2.assign(5000 * 10000, 'f');
	b2.push_back('e');

    result.push_back(std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()));
    result2.push_back(ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()));

    if (result == result2)
         std::cout << "LEXICOGRAPHICAL IS WORKING" << std::endl;

}

void    utils_tests(void)
{
    std::cout << "UTILS LODING ..." << std::endl;
    TEST_IS_INTEGRAL();
    TEST_ENABLE_IF();
    TEST_EQUL();
    TEST_ITERATOR_TRAITS();
    TEST_LEXICOGRAPHICAL();
}