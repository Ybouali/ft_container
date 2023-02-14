#include "../map.hpp"
#include <map>

template <class _T, class _U, class _I>
void    PRINT_EQ_RANGE(_T eq_f, _U eq_s, _I end_f)
{

    if (eq_f.first == end_f || eq_f.second == end_f)
    {
        std::cout << "THE EQUL RANGE RETURNED THE END :)" << std::endl;
        return;
    }

    while (eq_f.first != end_f && eq_f.second != end_f)
    {
        std::cout << "F FIRST FT  :: " << eq_f.first->first << " SECOND FT  " << eq_f.first->second << std::endl;
        std::cout << "S FIRST FT  :: " << eq_f.second->first << " SECOND FT  " << eq_f.second->second << std::endl << std::endl;

        std::cout << "F FIRST STD :: " << eq_s.first->first << " SECOND STD " << eq_s.first->second << std::endl;
        std::cout << "S FIRST STD :: " << eq_s.second->first << " SECOND STD " << eq_s.second->second << std::endl << std::endl;

        eq_f.first++;
        eq_f.second++;
        eq_s.first++;
        eq_s.second++;
    }
}


template <class _T, class _U>
void    PRINT_UPPER_LOWER(_T begin_f, _T end, _U begin_s)
{
    if (begin_f == end)
    {
        std::cout << "THE UPPER OR LOWER BOUND RETURNED THE END :)" << std::endl;
        return;
    }

    while (begin_f != end)
    {
        std::cout << "FIRST FT  :: " << begin_f->first << " SECOND FT  " << begin_f->second << std::endl;
        std::cout << "FIRST STD :: " << begin_s->first << " SECOND STD " << begin_s->second << std::endl << std::endl;
        begin_f++;
        begin_s++;
    }
    
}

template <class _T, class _U, class _Y>
void    CHECK_AND_PRINT(const ft::map<_T, _U, _Y>& map1, const std::map<_T, _U, _Y>& map2, int print, int leaks)
{
    if (map1.size() != map2.size())
    {
        std::cout << "Error: map1 and map2 must have the same size" << std::endl;
        return;
    }
    else
        std::cout << "The size of map1 is equal to the size of the map2" << std::endl;

    typename ft::map<_T, _U>::const_iterator it_ft = map1.begin();
    typename std::map<_T, _U>::const_iterator it_s = map2.begin();

    while (it_ft != map1.end())
    {
        if (it_ft->first != it_s->first || it_ft->second != it_s->second)
        {
            std::cout << "Error: map1 and map2 must have the same contents" << std::endl;
            return;
        }
        if (print)
        {
            std::cout << "FIRST FT  :: " << it_ft->first << " SECOND FT " << it_ft->second << std::endl;
            std::cout << "FIRST STD :: " << it_s->first << " SECOND STD " << it_s->second << std::endl;
        }
        it_ft++;
        it_s++;
    }
    std::cout << "the two maps are equals" << std::endl;
    if (leaks)
        system("leaks containers");
}

void    TEST_ASSIGNMENT_M(void)
{
    std::cout << "ASSIGNMENT TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];
    std::pair<int, std::string> arr_s[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
    {
        arr_f[i] = ft::make_pair(i, str[i]);
        arr_s[i] = std::make_pair(i, str[i]);
    }

    {
        ft::map<int, std::string>   map_ft;
        ft::map<int, std::string>   map_ft1;

        std::map<int, std::string>   map_s;
        std::map<int, std::string>   map_s1;

        std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;

        map_ft1 = map_ft;

        map_s1 = map_s;

        CHECK_AND_PRINT(map_ft1, map_s1, 0, 0);

        std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;

        map_ft = ft::map<int, std::string>(arr_f, arr_f + 64);

        map_s = std::map<int, std::string>(arr_s, arr_s + 64);

        CHECK_AND_PRINT(map_ft, map_s, 0, 0);

        std::cout << "||||||||||||||||||||||||||| TEST 3 |||||||||||||||||||||" << std::endl << std::endl;

        map_ft1 = map_ft;

        map_s1 = map_s;

        CHECK_AND_PRINT(map_ft1, map_s1, 0, 0);

        std::cout << "||||||||||||||||||||||||||| TEST 4 |||||||||||||||||||||" << std::endl << std::endl;

        map_ft = map_ft1;

        map_s = map_s1;

        CHECK_AND_PRINT(map_ft, map_s, 0, 0);
    }
    {
        ft::map<int, std::string>   map_f;
        std::map<int, std::string>   map_s;

        std::cout << "||||||||||||||||||||||||||| TEST 5 |||||||||||||||||||||" << std::endl << std::endl;

        map_f = ft::map<int, std::string>(arr_f, arr_f + 10);
        map_s = std::map<int, std::string>(arr_s, arr_s + 10);

        CHECK_AND_PRINT(map_f, map_s, 0, 0);
        
        std::cout << "||||||||||||||||||||||||||| TEST 6 |||||||||||||||||||||" << std::endl << std::endl;

        map_f = ft::map<int, std::string>(arr_f, arr_f + 5);
        map_s = std::map<int, std::string>(arr_s, arr_s + 5);

        CHECK_AND_PRINT(map_f, map_s, 0, 0);
    }
}

void    TEST_CLEAR_M(void)
{
    std::cout << "CLEAR TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];
    std::pair<int, std::string> arr_s[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
    {
        arr_f[i] = ft::make_pair(i, str[i]);
        arr_s[i] = std::make_pair(i, str[i]);
    }

    ft::map<int, std::string>   map_f;
    std::map<int, std::string>   map_s;

    std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;

    map_f.clear();
    map_s.clear();

    CHECK_AND_PRINT(map_f, map_s, 0, 0);

    std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;

    map_f.insert(arr_f, arr_f + 64);

    map_s.insert(arr_s, arr_s + 64);

    CHECK_AND_PRINT(map_f, map_s, 0, 0);

    std::cout << "||||||||||||||||||||||||||| TEST 3 |||||||||||||||||||||" << std::endl << std::endl;

    map_f.clear();

    map_s.clear();

    CHECK_AND_PRINT(map_f, map_s, 0, 0);
}

void    TEST_COMPARE(void)
{
    std::cout << "COMPARE TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];
    std::pair<int, std::string> arr_s[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
    {
        arr_f[i] = ft::make_pair(i, str[i]);
        arr_s[i] = std::make_pair(i, str[i]);
    }

    ft::map<int, std::string, std::greater<int> >   map_f(arr_f, arr_f + 64);
    std::map<int, std::string, std::greater<int> >   map_s(arr_s, arr_s + 64);

    std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;

    CHECK_AND_PRINT(map_f, map_s, 0, 0);
}

void    TEST_COMP_EQ(void)
{
    std::cout << "COMPARISONS EQ TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
        arr_f[i] = ft::make_pair(i, str[i]);

    {
        
        ft::map<int, std::string>   map_f;
        ft::map<int, std::string>   map_f1;

        std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;
        if (map_f1 == map_f)
            std::cout << "THE TOW MAPS ARE EQULS ." << std::endl;
    }
    {
        
        ft::map<int, std::string>   map_f(arr_f, arr_f + 20);
        ft::map<int, std::string>   map_f1(arr_f, arr_f + 20);

        std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;
        
        if (map_f1 == map_f)
            std::cout << "THE TOW MAPS ARE EQULS ." << std::endl;
    }
    {
        
        ft::map<int, std::string>   map_f(arr_f, arr_f + 20);
        ft::map<int, std::string>   map_f1(arr_f, arr_f + 20);

        std::cout << "||||||||||||||||||||||||||| TEST 3 |||||||||||||||||||||" << std::endl << std::endl;

        map_f1.insert(ft::make_pair(100, "test"));

        if (map_f1 == map_f)
            std::cout << "THE TOW MAPS ARE EQULS ." << std::endl;
        else
            std::cout << "THE TOW MAPS ARE NOT EQULS ." << std::endl;
    }
}

void    TEST_COMP_GE_M(void)
{
    std::cout << "COMPARISONS GE TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
        arr_f[i] = ft::make_pair(i, str[i]);

    {
        
        ft::map<int, std::string>   map_f;
        ft::map<int, std::string>   map_f1;

        std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;
        if (map_f1 > map_f)
            std::cout << "MAP_F1 GREATOR THAN MAP_F ." << std::endl;
        else
            std::cout << "MAP_F GREATOR THAN MAP_F1 ." << std::endl;
    }
    {
        
        ft::map<int, std::string>   map_f(arr_f, arr_f + 20);
        ft::map<int, std::string>   map_f1(arr_f, arr_f + 20);

        std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;
        
        if (map_f1 > map_f)
            std::cout << "MAP_F1 GREATOR THAN MAP_F ." << std::endl;
        else
            std::cout << "MAP_F GREATOR THAN MAP_F1 ." << std::endl;
    }
    {
        
        ft::map<int, std::string>   map_f(arr_f, arr_f + 20);
        ft::map<int, std::string>   map_f1(arr_f, arr_f + 20);

        std::cout << "||||||||||||||||||||||||||| TEST 3 |||||||||||||||||||||" << std::endl << std::endl;

        map_f1.insert(ft::make_pair(100, "test"));

        if (map_f1 > map_f)
            std::cout << "MAP_F1 GREATOR THAN MAP_F ." << std::endl;
        else
            std::cout << "MAP_F GREATOR THAN MAP_F1 ." << std::endl;
    }
}

void    TEST_COMP_GT_M(void)
{
    std::cout << "COMPARISONS GT TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
        arr_f[i] = ft::make_pair(i, str[i]);

    {
        
        ft::map<int, std::string>   map_f;
        ft::map<int, std::string>   map_f1;

        std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;
        if (map_f1 >= map_f)
            std::cout << "MAP_F1 GREATOR OR EQUL THAN MAP_F ." << std::endl;
        else
            std::cout << "MAP_F GREATOR OR EQUL THAN MAP_F1 ." << std::endl;
    }
    {
        
        ft::map<int, std::string>   map_f(arr_f, arr_f + 20);
        ft::map<int, std::string>   map_f1(arr_f, arr_f + 20);

        std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;
        
        if (map_f1 >= map_f)
            std::cout << "MAP_F1 GREATOR OR EQUL THAN MAP_F ." << std::endl;
        else
            std::cout << "MAP_F GREATOR OR EQUL THAN MAP_F1 ." << std::endl;
    }
    {
        
        ft::map<int, std::string>   map_f(arr_f, arr_f + 20);
        ft::map<int, std::string>   map_f1(arr_f, arr_f + 20);

        std::cout << "||||||||||||||||||||||||||| TEST 3 |||||||||||||||||||||" << std::endl << std::endl;

        map_f1.insert(ft::make_pair(100, "test"));

        if (map_f1 >= map_f)
            std::cout << "MAP_F1 GREATOR OR EQUL THAN MAP_F ." << std::endl;
        else
            std::cout << "MAP_F GREATOR OR EQUL THAN MAP_F1 ." << std::endl;
    }
}

void    TEST_COMP_LT_M(void)
{
    std::cout << "COMPARISONS LT TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
        arr_f[i] = ft::make_pair(i, str[i]);

    {
        
        ft::map<int, std::string>   map_f;
        ft::map<int, std::string>   map_f1;

        std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;
        if (map_f1 < map_f)
            std::cout << "MAP_F1 LESS THAN MAP_F ." << std::endl;
        else
            std::cout << "MAP_F LESS THAN MAP_F1 ." << std::endl;
    }
    {
        
        ft::map<int, std::string>   map_f(arr_f, arr_f + 20);
        ft::map<int, std::string>   map_f1(arr_f, arr_f + 20);

        std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;
        
        if (map_f1 < map_f)
            std::cout << "MAP_F1 LESS THAN MAP_F ." << std::endl;
        else
            std::cout << "MAP_F LESS THAN MAP_F1 ." << std::endl;
    }
    {
        
        ft::map<int, std::string>   map_f(arr_f, arr_f + 20);
        ft::map<int, std::string>   map_f1(arr_f, arr_f + 20);

        std::cout << "||||||||||||||||||||||||||| TEST 3 |||||||||||||||||||||" << std::endl << std::endl;

        map_f1.insert(ft::make_pair(100, "test"));

        if (map_f1 < map_f)
            std::cout << "MAP_F1 LESS THAN MAP_F ." << std::endl;
        else
            std::cout << "MAP_F LESS THAN MAP_F1 ." << std::endl;
    }
}

void    TEST_COMP_LE_M(void)
{
    std::cout << "COMPARISONS LE TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
        arr_f[i] = ft::make_pair(i, str[i]);

    {
        
        ft::map<int, std::string>   map_f;
        ft::map<int, std::string>   map_f1;

        std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;
        if (map_f1 <= map_f)
            std::cout << "MAP_F1 LESS OR EQUL THAN MAP_F ." << std::endl;
        else
            std::cout << "MAP_F LESS OR EQUL THAN MAP_F1 ." << std::endl;
    }
    {
        
        ft::map<int, std::string>   map_f(arr_f, arr_f + 20);
        ft::map<int, std::string>   map_f1(arr_f, arr_f + 20);

        std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;
        
        if (map_f1 <= map_f)
            std::cout << "MAP_F1 LESS OR EQUL THAN MAP_F ." << std::endl;
        else
            std::cout << "MAP_F LESS OR EQUL THAN MAP_F1 ." << std::endl;
    }
    {
        
        ft::map<int, std::string>   map_f(arr_f, arr_f + 20);
        ft::map<int, std::string>   map_f1(arr_f, arr_f + 20);

        std::cout << "||||||||||||||||||||||||||| TEST 3 |||||||||||||||||||||" << std::endl << std::endl;

        map_f1.insert(ft::make_pair(100, "test"));

        if (map_f1 <= map_f)
            std::cout << "MAP_F1 LESS OR EQUL THAN MAP_F ." << std::endl;
        else
            std::cout << "MAP_F LESS OR EQUL THAN MAP_F1 ." << std::endl;
    }
}

void    TEST_COMP_NE(void)
{
    std::cout << "COMPARISONS NE TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
        arr_f[i] = ft::make_pair(i, str[i]);

    {
        
        ft::map<int, std::string>   map_f;
        ft::map<int, std::string>   map_f1;

        std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;
        if (map_f1 != map_f)
            std::cout << "THE TOW MAPS ARE NOT EQULS ." << std::endl;
        else
            std::cout << "THE TOW MAPS ARE EQULS ." << std::endl;
    }
    {
        
        ft::map<int, std::string>   map_f(arr_f, arr_f + 20);
        ft::map<int, std::string>   map_f1(arr_f, arr_f + 20);

        std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;
        
        if (map_f1 != map_f)
            std::cout << "THE TOW MAPS ARE NOT EQULS ." << std::endl;
        else
            std::cout << "THE TOW MAPS ARE EQULS ." << std::endl;
    }
    {
        
        ft::map<int, std::string>   map_f(arr_f, arr_f + 20);
        ft::map<int, std::string>   map_f1(arr_f, arr_f + 20);

        std::cout << "||||||||||||||||||||||||||| TEST 3 |||||||||||||||||||||" << std::endl << std::endl;

        map_f1.insert(ft::make_pair(100, "test"));

        if (map_f1 != map_f)
            std::cout << "THE TOW MAPS ARE NOT EQULS ." << std::endl;
        else
            std::cout << "THE TOW MAPS ARE EQULS ." << std::endl;
    }
}

void    TEST_COUNT(void)
{
    std::cout << "COUNT TEST" << std::endl;
    
    ft::map<int, double>    map_f;
    std::map<int, double>    map_s;

    for (size_t i = 0; i < 5; i++)
    {
        map_f[i] = 101.10;
        map_s[i] = 101.10;
    }
    
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << "||||||||||||||||||||||||||| TEST " << i << " |||||||||||||||||||||" << std::endl << std::endl;
        std::cout << "COUNT TEST :FT : " << i << " RETURN COUNT > " << map_f.count(i) << std::endl;
        std::cout << "COUNT TEST :STD: " << i << " RETURN COUNT > " << map_s.count(i) << std::endl << std::endl;
    }
    
}

void    TEST_CTOR(void)
{
    std::cout << "TEST CTOR" << std::endl;
    {
        std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;
        ft::map<int, char>  map_f;
        std::map<int, char>  map_s;

        CHECK_AND_PRINT(map_f, map_s, 0, 0);
    }
    {
        std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;
        std::allocator<ft::pair<const int, char> > alloc;
        ft::map<int, char>  map_f(std::less<int>(), alloc);
        std::map<int, char>  map_s;

        CHECK_AND_PRINT(map_f, map_s, 0, 0);
    }
}

void    TEST_CTOR_RANGE_M(void)
{
    std::cout << "CTOR RANGE TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];
    std::pair<int, std::string> arr_s[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
    {
        arr_f[i] = ft::make_pair(i, str[i]);
        arr_s[i] = std::make_pair(i, str[i]);
    }
    {
        ft::map<int, std::string>   map_f(arr_f, arr_f + 20);
        ft::map<int, std::string>   map_f1(map_f.begin(), map_f.end());

        std::map<int, std::string>   map_s(arr_s, arr_s + 20);
        std::map<int, std::string>   map_s1(map_s.begin(), map_s.end());

        std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f, map_s, 0, 0);

        std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f1, map_s1, 0, 0);

    }
}

void    TEST_CTOR_COPY_M(void)
{
    std::cout << "CTOR COPY TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];
    std::pair<int, std::string> arr_s[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
    {
        arr_f[i] = ft::make_pair(i, str[i]);
        arr_s[i] = std::make_pair(i, str[i]);
    }
    {
        ft::map<int, std::string>   map_f(arr_f, arr_f + 20);
        ft::map<int, std::string>   map_f1(map_f);

        std::map<int, std::string>   map_s(arr_s, arr_s + 20);
        std::map<int, std::string>   map_s1(map_s);

        std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f, map_s, 0, 0);

        std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f1, map_s1, 0, 0);

    }
}

void    TEST_EMPTY_M(void)
{
    std::cout << "EMPTY TEST" << std::endl;

    ft::map<int, float>     map_f;
    std::map<int, float>     map_s;

    std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;

    std::cout << "EMPTY : FT  : " << (map_f.empty() ? "true" : "false") << std::endl;
    std::cout << "EMPTY : STD : " << (map_s.empty() ? "true" : "false") << std::endl;

    std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;

    map_f[10] = 10.10;
    map_s[10] = 10.10;

    std::cout << "EMPTY : FT  : " << (map_f.empty() ? "true" : "false") << std::endl;
    std::cout << "EMPTY : STD : " << (map_s.empty() ? "true" : "false") << std::endl;
    
}

void    TEST_UPPER_BOUND(void)
{
    std::cout << "TEST UPPER BOUND " << std::endl;

    ft::map<int, std::string>   map_f;
    std::map<int, std::string>   map_s;

    map_f.insert(ft::make_pair(34, "kljd9834iuhwet"));
    map_f.insert(ft::make_pair(3468, "dfghe45sywu4hsr"));
    map_f.insert(ft::make_pair(96533, "sdfghthrdfg5456ik"));
    map_f.insert(ft::make_pair(89548945894, "jtt5454wujtjse"));
    map_f.insert(ft::make_pair(7754322, "w4wt5u4wjhstrhj"));
    map_f.insert(ft::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
    map_f.insert(ft::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
    map_f.insert(ft::make_pair(4, "asdfhfjgh54w3ag"));
    map_f.insert(ft::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
    map_f.insert(ft::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
    map_f.insert(ft::make_pair(453834782, "juytje54yaerdrj"));
    map_f.insert(ft::make_pair(19458942, "j567uysdts56y6uj5r"));
    map_f.insert(ft::make_pair(3245689793, "jr67e5674574668679789ruyerdtadh"));

    map_s.insert(std::make_pair(34, "kljd9834iuhwet"));
    map_s.insert(std::make_pair(3468, "dfghe45sywu4hsr"));
    map_s.insert(std::make_pair(96533, "sdfghthrdfg5456ik"));
    map_s.insert(std::make_pair(89548945894, "jtt5454wujtjse"));
    map_s.insert(std::make_pair(7754322, "w4wt5u4wjhstrhj"));
    map_s.insert(std::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
    map_s.insert(std::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
    map_s.insert(std::make_pair(4, "asdfhfjgh54w3ag"));
    map_s.insert(std::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
    map_s.insert(std::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
    map_s.insert(std::make_pair(453834782, "juytje54yaerdrj"));
    map_s.insert(std::make_pair(19458942, "j567uysdts56y6uj5r"));
    map_s.insert(std::make_pair(3245689793, "jr67e5674574668679789ruyerdtadh"));
    {
        
        std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f, map_s, 0, 0);
        PRINT_UPPER_LOWER(map_f.upper_bound(-873487), map_f.end(), map_s.upper_bound(-873487));

        std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f, map_s, 0, 0);
        PRINT_UPPER_LOWER(map_f.upper_bound(2), map_f.end(), map_s.upper_bound(2));

        std::cout << "||||||||||||||||||||||||||| TEST 3 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f, map_s, 0, 0);
        PRINT_UPPER_LOWER(map_f.upper_bound(100000000), map_f.end(), map_s.upper_bound(100000000));

        std::cout << "||||||||||||||||||||||||||| TEST 4 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f, map_s, 0, 0);
        PRINT_UPPER_LOWER(map_f.upper_bound(1000000000), map_f.end(), map_s.upper_bound(1000000000));
    }
    {
        const ft::map<int, std::string>   map_f1(map_f);
        const std::map<int, std::string>   map_s1(map_s);

        std::cout << "||||||||||||||||||||||||||| TEST 5 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f1, map_s1, 0, 0);
        PRINT_UPPER_LOWER(map_f1.upper_bound(-873487), map_f1.end(), map_s1.upper_bound(-873487));

        std::cout << "||||||||||||||||||||||||||| TEST 6 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f1, map_s1, 0, 0);
        PRINT_UPPER_LOWER(map_f1.upper_bound(2), map_f1.end(), map_s1.upper_bound(2));

        std::cout << "||||||||||||||||||||||||||| TEST 7 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f1, map_s1, 0, 0);
        PRINT_UPPER_LOWER(map_f1.upper_bound(100000000), map_f1.end(), map_s1.upper_bound(100000000));

        std::cout << "||||||||||||||||||||||||||| TEST 8 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f1, map_s1, 0, 0);
        PRINT_UPPER_LOWER(map_f1.upper_bound(1000000000), map_f1.end(), map_s1.upper_bound(1000000000));
    }
}

void    TEST_LOWER_BOUND(void)
{
    std::cout << "TEST LOWER BOUND " << std::endl;
    ft::map<int, std::string>   map_f;
    std::map<int, std::string>   map_s;

    map_f.insert(ft::make_pair(34, "kljd9834iuhwet"));
    map_f.insert(ft::make_pair(3468, "dfghe45sywu4hsr"));
    map_f.insert(ft::make_pair(96533, "sdfghthrdfg5456ik"));
    map_f.insert(ft::make_pair(89548945894, "jtt5454wujtjse"));
    map_f.insert(ft::make_pair(7754322, "w4wt5u4wjhstrhj"));
    map_f.insert(ft::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
    map_f.insert(ft::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
    map_f.insert(ft::make_pair(4, "asdfhfjgh54w3ag"));
    map_f.insert(ft::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
    map_f.insert(ft::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
    map_f.insert(ft::make_pair(453834782, "juytje54yaerdrj"));
    map_f.insert(ft::make_pair(19458942, "j567uysdts56y6uj5r"));
    map_f.insert(ft::make_pair(3245689793, "jr67e5674574668679789ruyerdtadh"));

    map_s.insert(std::make_pair(34, "kljd9834iuhwet"));
    map_s.insert(std::make_pair(3468, "dfghe45sywu4hsr"));
    map_s.insert(std::make_pair(96533, "sdfghthrdfg5456ik"));
    map_s.insert(std::make_pair(89548945894, "jtt5454wujtjse"));
    map_s.insert(std::make_pair(7754322, "w4wt5u4wjhstrhj"));
    map_s.insert(std::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
    map_s.insert(std::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
    map_s.insert(std::make_pair(4, "asdfhfjgh54w3ag"));
    map_s.insert(std::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
    map_s.insert(std::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
    map_s.insert(std::make_pair(453834782, "juytje54yaerdrj"));
    map_s.insert(std::make_pair(19458942, "j567uysdts56y6uj5r"));
    map_s.insert(std::make_pair(3245689793, "jr67e5674574668679789ruyerdtadh"));
    {
        
        std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f, map_s, 0, 0);
        PRINT_UPPER_LOWER(map_f.lower_bound(-873487), map_f.end(), map_s.lower_bound(-873487));

        std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f, map_s, 0, 0);
        PRINT_UPPER_LOWER(map_f.lower_bound(2), map_f.end(), map_s.lower_bound(2));

        std::cout << "||||||||||||||||||||||||||| TEST 3 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f, map_s, 0, 0);
        PRINT_UPPER_LOWER(map_f.lower_bound(100000000), map_f.end(), map_s.lower_bound(100000000));

        std::cout << "||||||||||||||||||||||||||| TEST 4 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f, map_s, 0, 0);
        PRINT_UPPER_LOWER(map_f.lower_bound(1000000000), map_f.end(), map_s.lower_bound(1000000000));
    }
    {
        const ft::map<int, std::string>   map_f1(map_f);
        const std::map<int, std::string>   map_s1(map_s);

        std::cout << "||||||||||||||||||||||||||| TEST 5 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f1, map_s1, 0, 0);
        PRINT_UPPER_LOWER(map_f1.lower_bound(-873487), map_f1.end(), map_s1.lower_bound(-873487));

        std::cout << "||||||||||||||||||||||||||| TEST 6 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f1, map_s1, 0, 0);
        PRINT_UPPER_LOWER(map_f1.lower_bound(2), map_f1.end(), map_s1.lower_bound(2));

        std::cout << "||||||||||||||||||||||||||| TEST 7 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f1, map_s1, 0, 0);
        PRINT_UPPER_LOWER(map_f1.lower_bound(100000000), map_f1.end(), map_s1.lower_bound(100000000));

        std::cout << "||||||||||||||||||||||||||| TEST 8 |||||||||||||||||||||" << std::endl << std::endl;
        CHECK_AND_PRINT(map_f1, map_s1, 0, 0);
        PRINT_UPPER_LOWER(map_f1.lower_bound(1000000000), map_f1.end(), map_s1.lower_bound(1000000000));
    }
}

void    TEST_EQ_RANGE(void)
{
    std::cout << "TEST EQ RANGE " << std::endl;
    ft::map<int, std::string>   map_f;
    std::map<int, std::string>   map_s;

    map_f.insert(ft::make_pair(34, "kljd9834iuhwet"));
    map_f.insert(ft::make_pair(3468, "dfghe45sywu4hsr"));
    map_f.insert(ft::make_pair(96533, "sdfghthrdfg5456ik"));
    map_f.insert(ft::make_pair(89548945894, "jtt5454wujtjse"));
    map_f.insert(ft::make_pair(7754322, "w4wt5u4wjhstrhj"));
    map_f.insert(ft::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
    map_f.insert(ft::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
    map_f.insert(ft::make_pair(4, "asdfhfjgh54w3ag"));
    map_f.insert(ft::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
    map_f.insert(ft::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
    map_f.insert(ft::make_pair(453834782, "juytje54yaerdrj"));
    map_f.insert(ft::make_pair(19458942, "j567uysdts56y6uj5r"));
    map_f.insert(ft::make_pair(3245689793, "jr67e5674574668679789ruyerdtadh"));

    map_s.insert(std::make_pair(34, "kljd9834iuhwet"));
    map_s.insert(std::make_pair(3468, "dfghe45sywu4hsr"));
    map_s.insert(std::make_pair(96533, "sdfghthrdfg5456ik"));
    map_s.insert(std::make_pair(89548945894, "jtt5454wujtjse"));
    map_s.insert(std::make_pair(7754322, "w4wt5u4wjhstrhj"));
    map_s.insert(std::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
    map_s.insert(std::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
    map_s.insert(std::make_pair(4, "asdfhfjgh54w3ag"));
    map_s.insert(std::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
    map_s.insert(std::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
    map_s.insert(std::make_pair(453834782, "juytje54yaerdrj"));
    map_s.insert(std::make_pair(19458942, "j567uysdts56y6uj5r"));
    map_s.insert(std::make_pair(3245689793, "jr67e5674574668679789ruyerdtadh"));
    {
        std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;

        PRINT_EQ_RANGE(map_f.equal_range(2), map_s.equal_range(2), map_f.end());
        
        std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;

        PRINT_EQ_RANGE(map_f.equal_range(-873487), map_s.equal_range(-873487), map_f.end());

        std::cout << "||||||||||||||||||||||||||| TEST 3 |||||||||||||||||||||" << std::endl << std::endl;

        PRINT_EQ_RANGE(map_f.equal_range(1000000000), map_s.equal_range(1000000000), map_f.end());   
    }
    {
        const ft::map<int, std::string>   map_f1(map_f);
        const std::map<int, std::string>   map_s1(map_s);

        std::cout << "||||||||||||||||||||||||||| TEST 4 |||||||||||||||||||||" << std::endl << std::endl;

        PRINT_EQ_RANGE(map_f1.equal_range(2), map_s1.equal_range(2), map_f1.end());
        
        std::cout << "||||||||||||||||||||||||||| TEST 5 |||||||||||||||||||||" << std::endl << std::endl;

        PRINT_EQ_RANGE(map_f1.equal_range(-873487), map_s1.equal_range(-873487), map_f1.end());

        std::cout << "||||||||||||||||||||||||||| TEST 6 |||||||||||||||||||||" << std::endl << std::endl;

        PRINT_EQ_RANGE(map_f1.equal_range(1000000000), map_s1.equal_range(1000000000), map_f1.end());   
    }
}

void    TEST_ERASE_KEY(void)
{
    std::cout << "ERASE KEY TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];
    std::pair<int, std::string> arr_s[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
    {
        arr_f[i] = ft::make_pair(i, str[i]);
        arr_s[i] = std::make_pair(i, str[i]);
    }

    {
        ft::map<int, std::string>    map_f(arr_f, arr_f + 5);
        std::map<int, std::string>    map_s(arr_s, arr_s + 5);

        for (size_t i = 0; i < 10; i++)
        {
            std::cout << "||||||||||||||||||||||||||| TEST " << i << " |||||||||||||||||||||" << std::endl << std::endl;

            std::cout << "ERASE : FT : " << map_f.erase(i) << " : STD : " << map_s.erase(i) << std::endl;
        }
        
    }
}

void    TEST_ERASE_M(void)
{
    std::cout << "ERASE TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];
    std::pair<int, std::string> arr_s[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
    {
        arr_f[i] = ft::make_pair(i, str[i]);
        arr_s[i] = std::make_pair(i, str[i]);
    }

    ft::map<int, std::string>   map_f(arr_f, arr_f + 10);
    std::map<int, std::string>   map_s(arr_s, arr_s + 10);


    ft::map<int, std::string>::iterator it_f = map_f.begin();
    std::map<int, std::string>::iterator it_s = map_s.begin();
    
    std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;

    map_f.erase(it_f);
    map_s.erase(it_s);

    CHECK_AND_PRINT(map_f, map_s, 0, 0);

    std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;

    it_f = map_f.end();

    it_s = map_s.end();

    CHECK_AND_PRINT(map_f, map_s, 0, 0);

    std::cout << "||||||||||||||||||||||||||| TEST 3 |||||||||||||||||||||" << std::endl << std::endl;

    it_f = map_f.begin();

    it_s = map_s.begin();

    std::advance(it_f, 4);
    std::advance(it_s, 4);

    map_s.erase(it_s);
    map_f.erase(it_f);

    CHECK_AND_PRINT(map_f, map_s, 0, 0);
}

void    TEST_ERASE_RANGE_M(void)
{
    std::cout << "ERASE TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];
    std::pair<int, std::string> arr_s[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
    {
        arr_f[i] = ft::make_pair(i, str[i]);
        arr_s[i] = std::make_pair(i, str[i]);
    }

    {
        ft::map<char, char>     map_f;
        std::map<char, char>     map_s;

        std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;

        map_f.erase(map_f.begin(), map_f.end());
        map_s.erase(map_s.begin(), map_s.end());

        CHECK_AND_PRINT(map_f, map_s, 0, 0);

        std::cout << "||||||||||||||||||||||||||| TEST 2 |||||||||||||||||||||" << std::endl << std::endl;

        ft::map<int, std::string>     map_f1;
        std::map<int, std::string>     map_s1;

        map_f1.insert(arr_f, arr_f + 16);
        map_s1.insert(arr_s, arr_s + 16);

        map_f1.erase(map_f1.begin(), map_f1.end());
        map_s1.erase(map_s1.begin(), map_s1.end());

        CHECK_AND_PRINT(map_f1, map_s1, 0, 0);
    }
}

void    TEST_FIND(void)
{
    std::cout << "ERASE TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];
    std::pair<int, std::string> arr_s[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
    {
        arr_f[i] = ft::make_pair(i, str[i]);
        arr_s[i] = std::make_pair(i, str[i]);
    }

    ft::map<int, std::string>   map_f(arr_f, arr_f + 5);
    std::map<int, std::string>   map_s(arr_s, arr_s + 5);

    ft::map<int, std::string>::iterator it_f;
    std::map<int, std::string>::iterator it_s;
    for (size_t i = 0; i < 10; i++)
    {
        it_f = map_f.find(i);
        it_s = map_s.find(i);
        if (it_f == map_f.end())
            std::cout << "FT  key = " << i << " IS NOT FOUND" << std::endl;
        else
            std::cout << "FT  key = " << i << " FOUND" << std::endl;
        if (it_s == map_s.end())
            std::cout << "STD key = " << i << " IS NOT FOUND" << std::endl << std::endl;
        else
            std::cout << "STD key = " << i << " FOUND" << std::endl << std::endl;
    }
    
}

void    TEST_OPERATOR_INDEX(void)
{
    std::cout << "OPERATOR INDEX TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];
    std::pair<int, std::string> arr_s[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
    {
        arr_f[i] = ft::make_pair(i, str[i]);
        arr_s[i] = std::make_pair(i, str[i]);
    }

    ft::map<int, std::string>   map_f;
    std::map<int, std::string>   map_s;

    for (size_t i = 0; i < 10; i++)
    {
        map_f[i] = "HELLO ";
        map_s[i] = "HELLO ";
    }
    
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << "map_s[" << i << "] = " << map_s[i] << std::endl;
        std::cout << "map_f[" << i << "] = " << map_f[i] << std::endl << std::endl;
    }   
}

void    TEST_INSERT_M(void)
{
    std::cout << "INSERT TEST" << std::endl;
    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };

    {
        ft::map<int, std::string>   map_f;
        std::map<int, std::string>   map_s;

        typedef ft::pair<ft::map<int, std::string>::iterator, bool>   p_f;
        typedef std::pair<std::map<int, std::string>::iterator, bool>   p_s;

        p_f     pair_f;
        p_s     pair_s;

        for (size_t i = 0; i < 10; i++)
        {
            pair_s = map_s.insert(std::make_pair(i, str[i]));
            pair_f = map_f.insert(ft::make_pair(i, str[i]));

            std::cout << "STD THE KEY " << i << " IS " << (pair_s.second ? "INSERTED" : "NOT INSERTED")  << std::endl ;
            std::cout << "FT  THE KEY " << i << " IS " << (pair_f.second ? "INSERTED" : "NOT INSERTED")  << std::endl << std::endl;
        }

        for (size_t i = 0; i < 10; i++)
        {
            pair_s = map_s.insert(std::make_pair(i, str[i]));
            pair_f = map_f.insert(ft::make_pair(i, str[i]));

            std::cout << "STD THE KEY " << i << " IS " << (pair_s.second ? "INSERTED" : "IS NOT INSERTED")  << std::endl ;
            std::cout << "FT  THE KEY " << i << " IS " << (pair_f.second ? "INSERTED" : "IS NOT INSERTED")  << std::endl << std::endl;
        }
        
    }
}

void    TEST_INSERT_RANGE_M()
{
    std::cout << "INSERT RANGE TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];
    std::pair<int, std::string> arr_s[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
    {
        arr_f[i] = ft::make_pair(i, str[i]);
        arr_s[i] = std::make_pair(i, str[i]);
    }

    ft::map<int, std::string>   map_f;
    std::map<int, std::string>   map_s;

    ft::map<int, std::string>   map_f1;
    std::map<int, std::string>   map_s1;

    std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;
    
    map_f.insert(arr_f, arr_f + 20);
    map_s.insert(arr_s, arr_s + 20);


    CHECK_AND_PRINT(map_f, map_s, 0, 0);

    std::cout << "||||||||||||||||||||||||||| TEST 1 |||||||||||||||||||||" << std::endl << std::endl;

    map_f1.insert(map_f.begin(), map_f.end());

    map_s1.insert(map_s.begin(), map_s.end());
    
    CHECK_AND_PRINT(map_f, map_s, 0, 0);
    

}

void    TEST_ITERATOR_M(void)
{
    std::cout << "ITERATOR TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];
    std::pair<int, std::string> arr_s[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
    {
        arr_f[i] = ft::make_pair(i, str[i]);
        arr_s[i] = std::make_pair(i, str[i]);
    }

    ft::map<int, std::string> m(arr_f, arr_f + 20);

    ft::map<int, std::string>::iterator it = m.begin();
    ft::map<int, std::string>::iterator it2 = m.begin();
    ft::map<int, std::string>::const_iterator cit = m.begin();
    ft::map<int, std::string>::const_iterator cit2 = m.begin();

    it->second = "Hello";

    std::cout << m.begin()->first << std::endl;
    std::cout << (*it).first << std::endl;
    std::cout << (++it)->first << std::endl;
    std::cout << (it2++)->first << std::endl;
    std::cout << (*it++).first << std::endl;
    std::cout << (cit++)->first << std::endl;
    std::cout << (cit2++)->first << std::endl;
    std::cout << (++cit)->first << std::endl;
    std::cout << (++cit2)->first << std::endl;
    std::cout << it2->first << std::endl;
    std::cout << cit2->first << std::endl;
    std::cout << (it++)->first << std::endl;
    std::cout << (it++)->first << std::endl;
    std::cout << (it++)->first << std::endl;
    std::cout << (it2++)->first << std::endl;
    std::cout << (it2++)->first << std::endl;
    std::cout << (++it2)->first << std::endl;
    std::cout << (*cit).first << std::endl;
    std::cout << (*cit--).first << std::endl;
    std::cout << (*it--).first << std::endl;
    std::cout << (it--)->first << std::endl;
    std::cout << (--it)->first << std::endl;
    std::cout << (--cit2)->first << std::endl;
    std::cout << cit2->first << std::endl;
    std::cout << (*cit2).first << std::endl;
    std::cout << (*it2).first << std::endl;
    it = it2;
    std::cout << (*it).first << std::endl;
    std::cout << (*it2).first << std::endl;
    cit = cit2;
    std::cout << (*cit).first << std::endl;
    std::cout << (*cit2).first << std::endl;

}

void    TEST_RITERATOR_M(void)
{
    std::cout << "ITERATOR TEST" << std::endl;
    ft::pair<int, std::string> arr_f[64];
    std::pair<int, std::string> arr_s[64];

    std::string str[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };
    
    for (size_t i = 0; i < 64; i++)
    {
        arr_f[i] = ft::make_pair(i, str[i]);
        arr_s[i] = std::make_pair(i, str[i]);
    }

    ft::map<int, std::string> m(arr_f, arr_f + 30);

    ft::map<int, std::string>::reverse_iterator it = m.rbegin();
    ft::map<int, std::string>::reverse_iterator it2 = m.rbegin();
    ft::map<int, std::string>::const_reverse_iterator cit = m.rbegin();
    ft::map<int, std::string>::const_reverse_iterator cit2 = m.rbegin();

    for (ft::map<int, std::string>::reverse_iterator i = m.rbegin(); i != m.rend(); ++i)
        std::cout << i->first << std::endl;


    it->second = "Hello";

    std::cout << m.begin()->first << std::endl;
    std::cout << (*it).first << std::endl;
    std::cout << (++it)->first << std::endl;
    std::cout << (it2++)->first << std::endl;
    std::cout << (*it++).first << std::endl;
    std::cout << (cit++)->first << std::endl;
    std::cout << (cit2++)->first << std::endl;
    std::cout << (++cit)->first << std::endl;
    std::cout << (++cit2)->first << std::endl;
    std::cout << it2->first << std::endl;
    std::cout << cit2->first << std::endl;
    std::cout << (it++)->first << std::endl;
    std::cout << (it++)->first << std::endl;
    std::cout << (it++)->first << std::endl;
    std::cout << (it2++)->first << std::endl;
    std::cout << (it2++)->first << std::endl;
    std::cout << (++it2)->first << std::endl;
    std::cout << (*cit).first << std::endl;
    std::cout << (*cit--).first << std::endl;
    std::cout << (*it--).first << std::endl;
    std::cout << (it--)->first << std::endl;
    std::cout << (--it)->first << std::endl;
    std::cout << (--cit2)->first << std::endl;
    std::cout << cit2->first << std::endl;
    std::cout << (*cit2).first << std::endl;
    std::cout << (*it2).first << std::endl;
    it = it2;
    std::cout << (*it).first << std::endl;
    std::cout << (*it2).first << std::endl;
    cit = cit2;
    std::cout << (*cit).first << std::endl;
    std::cout << (*cit2).first << std::endl;
}
void     TEST_FOR_ROTATIONS()
{
    std::cout << "TEST FOR ROTATIONS" << std::endl;
    ft::map<char, int>   map;

    // goto next;
    {
        std::cout << std::endl << "TEST 1 [X, Y, Z] == ";
        map.insert(ft::make_pair('x', 10));
        map.insert(ft::make_pair('y', 10));
        map.insert(ft::make_pair('z', 10));
        map.clear();
    }
    // next: ;
    {
        std::cout << std::endl << "TEST 2 [Z, Y, X] == ";
        map.insert(ft::make_pair('z', 10));
        map.insert(ft::make_pair('y', 10));
        map.insert(ft::make_pair('x', 10));
        map.clear();
    }
    // next: ;
    {
        std::cout << std::endl << "TEST 3 [Z, X, Y] == ";
        map.insert(ft::make_pair('z', 10));
        map.insert(ft::make_pair('x', 10));
        map.insert(ft::make_pair('y', 10));
        map.clear();
    }
    // next: ;
    {
        std::cout << std::endl << "TEST 4 [X, Z, Y] == ";
        map.insert(ft::make_pair('x', 10));
        map.insert(ft::make_pair('z', 10));
        map.insert(ft::make_pair('y', 10));
    }
}

void    map_tests(void)
{
    std::cout << "LOADING MAP..." << std::endl;
    TEST_ASSIGNMENT_M();
    TEST_CLEAR_M();
    TEST_COMPARE();
    TEST_COMP_EQ();
    TEST_COMP_GE_M();
    TEST_COMP_GT_M();
    TEST_COMP_LT_M();
    TEST_COMP_LE_M();
    TEST_COMP_NE();
    TEST_COUNT();
    TEST_CTOR();
    TEST_CTOR_RANGE_M();
    TEST_CTOR_COPY_M();
    TEST_EMPTY_M();
    TEST_UPPER_BOUND();
    TEST_LOWER_BOUND();
    TEST_EQ_RANGE();
    TEST_ERASE_M();
    TEST_ERASE_KEY();
    TEST_ERASE_RANGE_M();
    TEST_FIND();
    TEST_OPERATOR_INDEX();
    TEST_INSERT_M();
    TEST_INSERT_RANGE_M();
    TEST_ITERATOR_M();
    TEST_RITERATOR_M();
    TEST_FOR_ROTATIONS();
}

