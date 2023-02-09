#pragma once

#include "./pair.hpp"

#include <iostream>

namespace ft {

    template <class InputIterator1, class InputIterator2>
    bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
    while (first1!=last1) {
        if (!(*first1 == *first2))
        return false;
        ++first1; ++first2;
    }
    return true;
    }    

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        while (first1!=last1)
        {
            if (first2==last2 || *first2<*first1) return false;
            else if (*first1<*first2) return true;
            ++first1; ++first2;
        }
        return (first2!=last2);
    }

    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
    {
        while (first1!=last1)
        {
            if (first2==last2 || comp(*first2, *first1)) return false;
            else if (comp(*first1, *first2)) return true;
            ++first1; ++first2;
        }
        return (first2!=last2);
    }

    template <class U>
    struct is_same{ static const bool value = false; };

    template<>
    struct is_same<std::input_iterator_tag> { static const bool value = true; };

    template<bool Cond, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T> { typedef T type; };

    template <typename T>
    struct is_integral : public std::false_type
    {
        static const bool value = false;
    };

    template <typename _T>
    struct is_integral<const _T> : public is_integral<_T> { };

    template <>
    struct is_integral<int> : public std::true_type { };

    template <>
    struct is_integral<char> : public std::true_type{ };
    
    template <>
    struct is_integral<char16_t> : public std::true_type{ };

    template <>
    struct is_integral<char32_t> : public std::true_type{ };

    template <>
    struct is_integral<wchar_t> : public std::true_type{ };

    template <>
    struct is_integral<signed char> : public std::true_type{ };

    template <>
    struct is_integral<short int> : public std::true_type{ };

    template <>
    struct is_integral<long int> : public std::true_type{ };

    template <>
    struct is_integral<long long int> : public std::true_type{ };

    template <>
    struct is_integral<unsigned char> : public std::true_type{ };

    template <>
    struct is_integral<unsigned short int> : public std::true_type{ };

    template <>
    struct is_integral<unsigned int> : public std::true_type{ };

    template <>
    struct is_integral<unsigned long int> : public std::true_type{ };

    template <>
    struct is_integral<unsigned long long int> : public std::true_type{ };

    template <>
    struct is_integral<bool> : public std::true_type{ };
}