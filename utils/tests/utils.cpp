#include <iostream>
#include <sstream>
#include "../utils.hpp"

void    TEST_IS_INTEGRAL(void)
{
    std::cout << "Testing is_integer " << std::endl << std::endl;

    std::cout << "ft   FLOAT                         :: IS " << (ft::is_integral<float>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std  FLOAT                         :: IS " << (std::is_integral<float>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft  const FLOAT                    :: IS " << (ft::is_integral<const float>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std const FLOAT                    :: IS " << (std::is_integral<const float>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft   INT                           :: IS " << (ft::is_integral<int>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std  INT                           :: IS " << (std::is_integral<int>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft  const INT                      :: IS " << (ft::is_integral<const int>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std const INT                      :: IS " << (std::is_integral<const int>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft   CHAR                          :: IS " << (ft::is_integral<char>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std  CHAR                          :: IS " << (std::is_integral<char>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft  const CHAR                     :: IS " << (ft::is_integral<const char>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std const CHAR                     :: IS " << (std::is_integral<const char>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft   SIGNED CHAR                   :: IS " << (ft::is_integral<signed char>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std  SIGNED CHAR                   :: IS " << (std::is_integral<signed char>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft  const SIGNED CHAR              :: IS " << (ft::is_integral<const signed char>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std const SIGNED CHAR              :: IS " << (std::is_integral<const signed char>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft   WCHAR_T                       :: IS " << (ft::is_integral<wchar_t>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std  WCHAR_T                       :: IS " << (std::is_integral<wchar_t>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft  const WCHAR_T                  :: IS " << (ft::is_integral<const wchar_t>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std const WCHAR_T                  :: IS " << (std::is_integral<const wchar_t>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft   CHAR16_T                      :: IS " << (ft::is_integral<char16_t>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std  CHAR16_T                      :: IS " << (std::is_integral<char16_t>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft  const CHAR16_T                 :: IS " << (ft::is_integral<const char16_t>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std const CHAR16_T                 :: IS " << (std::is_integral<const char16_t>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft   SHORT                         :: IS " << (ft::is_integral<short>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std  SHORT                         :: IS " << (std::is_integral<short>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft  const SHORT                    :: IS " << (ft::is_integral<const short>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std const SHORT                    :: IS " << (std::is_integral<const short>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft   UNSIGNED SHORT                :: IS " << (ft::is_integral<unsigned short>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std  UNSIGNED SHORT                :: IS " << (std::is_integral<unsigned short>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft  const UNSIGNED SHORT           :: IS " << (ft::is_integral<const unsigned short>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std const UNSIGNED SHORT           :: IS " << (std::is_integral<const unsigned short>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft   UNSIGNED INT                  :: IS " << (ft::is_integral<unsigned int>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std  UNSIGNED INT                  :: IS " << (std::is_integral<unsigned int>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft  const UNSIGNED INT             :: IS " << (ft::is_integral<const unsigned int>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std const UNSIGNED INT             :: IS " << (std::is_integral<const unsigned int>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft   LONG                          :: IS " << (ft::is_integral<long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std  LONG                          :: IS " << (std::is_integral<long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft  const LONG                     :: IS " << (ft::is_integral<const long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std const LONG                     :: IS " << (std::is_integral<const long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft   UNSIGNED LONG                 :: IS " << (ft::is_integral<unsigned long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std  UNSIGNED LONG                 :: IS " << (std::is_integral<unsigned long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft  const UNSIGNED LONG            :: IS " << (ft::is_integral<const unsigned long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std const UNSIGNED LONG            :: IS " << (std::is_integral<const unsigned long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft   LONG LONG                     :: IS " << (ft::is_integral<long long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std  LONG LONG                     :: IS " << (std::is_integral<long long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft  const LONG LONG                :: IS " << (ft::is_integral<const long long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std const LONG LONG                :: IS " << (std::is_integral<const long long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft   UNSIGNED LONG LONG           :: IS " << (ft::is_integral<unsigned long long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std  UNSIGNED LONG LONG           :: IS " << (std::is_integral<unsigned long long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft  const UNSIGNED LONG LONG      :: IS " << (ft::is_integral<const unsigned long long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std const UNSIGNED LONG LONG      :: IS " << (std::is_integral<const unsigned long long>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft   INTPT ITERATOR TYPE          :: IS " << (ft::is_integral<std::istreambuf_iterator<char> >::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std  INTPT ITERATOR TYPE          :: IS " << (std::is_integral<std::istreambuf_iterator<char> >::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;

    std::cout << "ft  const INTPT ITERATOR TYPE     :: IS " << (ft::is_integral<const std::istreambuf_iterator<char> >::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std const INTPT ITERATOR TYPE     :: IS " << (std::is_integral<const std::istreambuf_iterator<char> >::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    
    std::cout << "ft   BOOL                         :: IS " << (ft::is_integral<bool>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
    std::cout << "std  BOOL                         :: IS " << (std::is_integral<bool>::value ? "INTEGRAL" : "NOT INTEGERL")  << std::endl << std::endl;
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