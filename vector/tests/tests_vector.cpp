#include "../vector.hpp"

#include <sstream>

#include <list>

struct abc {
    int data[1024];
    long num;
};

template <class _T, class _U>
void CHECK_FT_STD_VECTOR(const _T& v_ft, const _U& v_s)
{
    std::cout << "| CHECK FT && STD VECTOR. CAPACITY && SIZE && CONTENT |" << std::endl << std::endl;
    
    // std::cout << "FT VECTOR SIZE " << v_ft.size() <<  " STD VECTOR SIZE = " << v_s.size() << std::endl;
    // std::cout << "FT VECTOR CAPACITY = " << v_ft.capacity() <<  " STD VECTOR CAPACITY = " << v_s.capacity() << std::endl;
    if (v_ft.size() == v_s.size())
        std::cout << "FT VECTOR SIZE == STD VECTOR SIZE " << std::endl;
    else
    {
        std::cout << "FT VECTOR SIZE != STD VECTOR SIZE " << std::endl;
        return ;
    }
    if (v_ft.capacity() == v_s.capacity())
        std::cout << "FT VECTOR CAPACITY == STD VECTOR CAPACITY " << std::endl;
    else
    {
        std::cout << "FT VECTOR CAPACITY != STD VECTOR CAPACITY " << std::endl;
        return ;
    }

    for (int i = 0; i < (int)v_s.size(); i++)
    {
        // std::cout << "v_ft[" << i << "] = " << v_ft[i] << std::endl;
        // std::cout << " v_s[" << i << "] = " << v_s[i] << std::endl << std::endl;
        if (v_s[i] != v_ft[i])
        {
            std::cout << "THE CONTENT OF THE VECTOR AT " << i << " IS NOT EQUALS ! " << std::endl;
            return ;
        }
    }
    std::cout << "THE CONTENT OF THE STD && FT VECTOR ARE EQUALS ! " << std::endl << std::endl;
}

void    TEST_ASSIGN_RANGE(void)
{
    std::cout << "ASSIGN_RANGE ..." << std::endl;

    std::string str[30] = { "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test" };
        
        {
            ft::vector<std::string> v_ft;
            std::vector<std::string> v_s;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;

            v_ft.assign(str, str + 15);

            v_s.assign(str, str + 15);
            
            CHECK_FT_STD_VECTOR(v_ft, v_s);       

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            v_ft.assign(str, str + 30);

            v_s.assign(str, str + 30);
            
            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;
            v_ft.assign(str, str);

            v_s.assign(str, str);

            CHECK_FT_STD_VECTOR(v_ft, v_s);
            // system("leaks vector.out");
        }
        {
            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 4" << std::endl << std::endl;
            ft::vector<std::string> v_ft(str, str + 15);

            std::vector<std::string> v_s(str, str + 15);

            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 6" << std::endl << std::endl;
            v_ft.push_back("HI AM HERE :)");
            v_s.push_back("HI AM HERE :)");

            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 7" << std::endl << std::endl;
            v_ft.assign(v_ft.begin(), v_ft.begin() + 10);

            v_s.assign(v_s.begin(), v_s.begin() + 10);

            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 8" << std::endl << std::endl;
            v_ft.assign(v_ft.begin(), v_ft.end());

            v_s.assign(v_s.begin(), v_s.end());

            CHECK_FT_STD_VECTOR(v_ft, v_s);
            // system("leaks vector.out");
        }
        {
            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 9" << std::endl << std::endl;


            std::istringstream str_s("1-2-3-4-5-6");
            std::istreambuf_iterator<char> it_s(str_s), end_s;

            std::istringstream str_f("1-2-3-4-5-6");
            std::istreambuf_iterator<char> it_f(str_f), end_f;

            ft::vector<char> v_ft;

            std::vector<char> v_s;

            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 10" << std::endl << std::endl;

            std::cout << "std::input_iterator_tag: " << std::endl;

            v_s.assign(it_s, end_s);

            v_ft.assign(it_f, end_f);

            CHECK_FT_STD_VECTOR(v_ft, v_s);
            system("leaks vector.out");
        }
        system("leaks vector.out");
}

void    TEST_ASSIGN(void)
{
        std::cout << "ASSIGN ..." << std::endl;
        {
            std::vector<char> v_s;
            ft::vector<char> v_ft;
            
            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
            v_s.assign(0, 'Y');

            v_ft.assign(0, 'Y');

            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            v_s.assign(60, 'Y');

            v_ft.assign(60, 'Y');

            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;

            v_s.assign(10, 'Y');

            v_ft.assign(10, 'Y');

            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 4" << std::endl << std::endl;

            v_s.assign(100, 'Y');

            v_ft.assign(100, 'Y');

            CHECK_FT_STD_VECTOR(v_ft, v_s);
        }
        {

            ft::vector<std::string> v_ft;
            std::vector<std::string> v_s;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 5" << std::endl << std::endl;

            v_s.assign(100, "");

            v_ft.assign(100, "");

            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 6" << std::endl << std::endl;

            v_s.assign(0, "hello world");

            v_ft.assign(0, "hello world");

            CHECK_FT_STD_VECTOR(v_ft, v_s);
        }
        system("leaks vector.out");
}

void    TEST_ASSIGNMENT(void)
{
    std::string str[30] = { "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test" };
        std::cout << "ASSIGNMENT ..." << std::endl;
        {
            ft::vector<std::string> v_ft;
            std::vector<std::string> v_s;

            ft::vector<std::string> v_ft_0;
            std::vector<std::string> v_s_0;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;

            v_s = v_s_0;
            v_ft = v_ft_0;

            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;

            v_s_0 = std::vector<std::string>(str, str + 15);
            v_ft_0 = ft::vector<std::string>(str, str + 15);

            CHECK_FT_STD_VECTOR(v_ft_0, v_s_0);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;
            
            v_s = v_s_0;
            v_ft = v_ft_0;

            CHECK_FT_STD_VECTOR(v_ft, v_s);
            system("leaks vector.out");
        }
}

void    TEST_AT(void)
{
        std::cout << "AT ..." << std::endl;

        std::string str[30] = {"test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test"};
            
            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
            try
            {
                
            ft::vector<std::string> vector(str, str + 30);

            // ! ERROR TEST
            ft::vector<std::string>::reference t = vector.at(-10);
            (void)t;
            }
            catch (const std::exception &e)
            {
            std::cerr << e.what() << '\n';
            }

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            try
            {
            ft::vector<std::string> vector(str, str + 30);

            // ! ERROR TEST
            ft::vector<std::string>::reference t = vector.at(30);
            (void)t;
            }
            catch (const std::exception &e)
            {
            std::cerr << e.what() << '\n';
            }

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;
            try
            {
            ft::vector<std::string> vector(str, str + 30);

            // ! VALID TEST REFERENCE
            ft::vector<std::string>::reference t = vector.at(20);
            std::cout << "AT 20 = " << t << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 4" << std::endl << std::endl;

            try
            {
            ft::vector<std::string> vector(str, str + 30);

                // ! VALID TEST const REFERENCE
                ft::vector<std::string>::const_reference t = vector.at(20);
                std::cout << "AT 20 = " << t << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
}

void    TEST_BACK(void)
{
     std::cout << "BACK ..." << std::endl;

    ft::vector<long> vector(10, 1010);
    
    std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
    ft::vector<long>::reference t = vector.back();

    std::cout << "BACK = " << t << std::endl;

    std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
    ft::vector<long>::const_reference c = vector.back();
    
    std::cout << "CONST BACK = " << c << std::endl;
}

void    TEST_CLEAR(void)
{
        std::cout << "CLEAR ..." << std::endl;

        std::string str[30] = {"test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test"};

        ft::vector<std::string>     v_ft(str, str + 30);
        std::vector<std::string>     v_s(str, str + 30);

        std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
        CHECK_FT_STD_VECTOR(v_ft, v_s);

        v_ft.clear();
        v_s.clear();

        std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
        CHECK_FT_STD_VECTOR(v_ft, v_s);

        v_ft.clear();
        v_s.clear();

        std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;
        CHECK_FT_STD_VECTOR(v_ft, v_s);
        system("leaks vector.out");

}

void    TEST_EQ(void)
{
        std::cout << "COMPARISONS EQ ..." << std::endl;
        {
            ft::vector<int> v_ft;
            ft::vector<int> v_ft_0;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
            if (v_ft == v_ft_0)
                std::cout << "YES V_FT == V_FT_0" << std::endl;
            else 
                std::cout << "NO V_FT != V_FT_0" << std::endl;

        }
        {
            ft::vector<long> v_ft(10, 111);
            ft::vector<long> v_ft_0;
            
            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            if (v_ft == v_ft_0)
                std::cout << "YES V_FT == V_FT_0" << std::endl;
            else 
                std::cout << "NO V_FT != V_FT_0" << std::endl;
        }
        {
            ft::vector<double> v_ft;
            ft::vector<double> v_ft_0(10, 111);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;
            if (v_ft == v_ft_0)
                std::cout << "YES V_FT == V_FT_0" << std::endl;
            else 
                std::cout << "NO V_FT != V_FT_0" << std::endl;
        }
        {
            ft::vector<std::string> v_ft(10, "test");
            ft::vector<std::string> v_ft_0(10, "test");

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 4" << std::endl << std::endl;
            if (v_ft == v_ft_0)
                std::cout << "YES V_FT == V_FT_0" << std::endl;
            else 
                std::cout << "NO V_FT != V_FT_0" << std::endl;
        }
        {
            ft::vector<std::string> v_ft(10);
            ft::vector<std::string> v_ft_0(10);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 5" << std::endl << std::endl;
            if (v_ft == v_ft_0)
                std::cout << "YES V_FT == V_FT_0" << std::endl;
            else 
                std::cout << "NO V_FT != V_FT_0" << std::endl;
        }       
}

void    TEST_GE(void)
{
        std::cout << "COMPARISONS GE ..." << std::endl;
        {
            ft::vector<long>    v_ft;
            ft::vector<long>    v_ft_0;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
            if (v_ft >= v_ft_0)
                std::cout << "GREATER THEN OR EQUQL ." << std::endl;
            else
                std::cout << "IS NOT GREATER THEN OR EQUQL ." << std::endl;
        }
        {
            ft::vector<int>    v_ft(3, 10);
            ft::vector<int>    v_ft_0;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            if (v_ft >= v_ft_0)
                std::cout << "GREATER THEN OR EQUQL ." << std::endl;
            else
                std::cout << "IS NOT GREATER THEN OR EQUQL ." << std::endl;
        }
        {
            ft::vector<std::string>    v_ft;
            ft::vector<std::string>    v_ft_0(3, "10");

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;
            if (v_ft >= v_ft_0)
                std::cout << "GREATER THEN OR EQUQL ." << std::endl;
            else
                std::cout << "IS NOT GREATER THEN OR EQUQL ." << std::endl;
        }
        {
            ft::vector<char>    v_ft(2, 'D');
            ft::vector<char>    v_ft_0(2, 'D');

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 4" << std::endl << std::endl;
            if (v_ft >= v_ft_0)
                std::cout << "GREATER THEN OR EQUQL ." << std::endl;
            else
                std::cout << "IS NOT GREATER THEN OR EQUQL ." << std::endl;
        }
        {
            ft::vector<float>    v_ft(2, 1010101);
            ft::vector<float>    v_ft_0(2, 1010101);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 5" << std::endl << std::endl;
            if (v_ft >= v_ft_0)
                std::cout << "GREATER THEN OR EQUQL ." << std::endl;
            else
                std::cout << "IS NOT GREATER THEN OR EQUQL ." << std::endl;
        }
    }

void    TEST_GT(void)
{
        std::cout << "COMPARISONS GT ..." << std::endl;
        {
            ft::vector<long>    v_ft;
            ft::vector<long>    v_ft_0;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
            if (v_ft > v_ft_0)
                std::cout << "GREATER THEN ." << std::endl;
            else
                std::cout << "IS NOT GREATER THEN ." << std::endl;
        }
        {
            ft::vector<int>    v_ft(3, 10);
            ft::vector<int>    v_ft_0;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            if (v_ft > v_ft_0)
                std::cout << "GREATER THEN ." << std::endl;
            else
                std::cout << "IS NOT GREATER THEN ." << std::endl;
        }
        {
            ft::vector<std::string>    v_ft;
            ft::vector<std::string>    v_ft_0(3, "10");

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;
            if (v_ft > v_ft_0)
                std::cout << "GREATER THEN ." << std::endl;
            else
                std::cout << "IS NOT GREATER THEN ." << std::endl;
        }
        {
            ft::vector<char>    v_ft(2, 'D');
            ft::vector<char>    v_ft_0(2, 'D');

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 4" << std::endl << std::endl;
            if (v_ft > v_ft_0)
                std::cout << "GREATER THEN ." << std::endl;
            else
                std::cout << "IS NOT GREATER THEN ." << std::endl;
        }
        {
            ft::vector<float>    v_ft(2, 1010101);
            ft::vector<float>    v_ft_0(2, 1010101);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 5" << std::endl << std::endl;
            if (v_ft > v_ft_0)
                std::cout << "GREATER THEN ." << std::endl;
            else
                std::cout << "IS NOT GREATER THEN ." << std::endl;
        }
    }

void    TEST_LE(void)
{
        std::cout << "COMPARISONS LE ..." << std::endl;
        {
            ft::vector<long>    v_ft;
            ft::vector<long>    v_ft_0;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
            if (v_ft <= v_ft_0)
                std::cout << "LESS THEN OR EQUAL ." << std::endl;
            else
                std::cout << "IS NOT LESS THEN OR EQUAL ." << std::endl;
        }
        {
            ft::vector<int>    v_ft(3, 10);
            ft::vector<int>    v_ft_0;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            if (v_ft <= v_ft_0)
                std::cout << "LESS THEN OR EQUAL ." << std::endl;
            else
                std::cout << "IS NOT LESS THEN OR EQUAL ." << std::endl;
        }
        {
            ft::vector<std::string>    v_ft;
            ft::vector<std::string>    v_ft_0(3, "10");

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;
            if (v_ft <= v_ft_0)
                std::cout << "LESS THEN OR EQUAL ." << std::endl;
            else
                std::cout << "IS NOT LESS THEN OR EQUAL ." << std::endl;
        }
        {
            ft::vector<char>    v_ft(2, 'D');
            ft::vector<char>    v_ft_0(2, 'D');

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 4" << std::endl << std::endl;
            if (v_ft <= v_ft_0)
                std::cout << "LESS THEN OR EQUAL ." << std::endl;
            else
                std::cout << "IS NOT LESS THEN OR EQUAL ." << std::endl;
        }
        {
            ft::vector<float>    v_ft(2, 1010101);
            ft::vector<float>    v_ft_0(2, 1010101);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 5" << std::endl << std::endl;
            if (v_ft <= v_ft_0)
                std::cout << "LESS THEN OR EQUAL ." << std::endl;
            else
                std::cout << "IS NOT LESS THEN OR EQUAL ." << std::endl;
        }
    }

void    TEST_LT(void)
{
        std::cout << "COMPARISONS LT ..." << std::endl;
        {
            ft::vector<long>    v_ft;
            ft::vector<long>    v_ft_0;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
            if (v_ft < v_ft_0)
                std::cout << "LESS THEN ." << std::endl;
            else
                std::cout << "IS NOT LESS THEN ." << std::endl;
        }
        {
            ft::vector<int>    v_ft(3, 10);
            ft::vector<int>    v_ft_0;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            if (v_ft < v_ft_0)
                std::cout << "LESS THEN ." << std::endl;
            else
                std::cout << "IS NOT LESS THEN ." << std::endl;
        }
        {
            ft::vector<std::string>    v_ft;
            ft::vector<std::string>    v_ft_0(3, "10");

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;
            if (v_ft < v_ft_0)
                std::cout << "LESS THEN ." << std::endl;
            else
                std::cout << "IS NOT LESS THEN ." << std::endl;
        }
        {
            ft::vector<char>    v_ft(2, 'D');
            ft::vector<char>    v_ft_0(2, 'D');

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 4" << std::endl << std::endl;
            if (v_ft < v_ft_0)
                std::cout << "LESS THEN ." << std::endl;
            else
                std::cout << "IS NOT LESS THEN ." << std::endl;
        }
        {
            ft::vector<float>    v_ft(2, 1010101);
            ft::vector<float>    v_ft_0(2, 1010101);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 5" << std::endl << std::endl;
            if (v_ft < v_ft_0)
                std::cout << "LESS THEN ." << std::endl;
            else
                std::cout << "IS NOT LESS THEN ." << std::endl;
        }
    }

void    TEST_NE(void)
{
        std::cout << "COMPARISONS NE ..." << std::endl;
        {
            ft::vector<long>    v_ft;
            ft::vector<long>    v_ft_0;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
            if (v_ft != v_ft_0)
                std::cout << "IS NOT EQUAL ." << std::endl;
            else
                std::cout << "EQUAL ." << std::endl;
        }
        {
            ft::vector<int>    v_ft(3, 10);
            ft::vector<int>    v_ft_0;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            if (v_ft != v_ft_0)
                std::cout << "IS NOT EQUAL ." << std::endl;
            else
                std::cout << "EQUAL ." << std::endl;
        }
        {
            ft::vector<std::string>    v_ft;
            ft::vector<std::string>    v_ft_0(3, "10");

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;
            if (v_ft != v_ft_0)
                std::cout << "IS NOT EQUAL ." << std::endl;
            else
                std::cout << "EQUAL ." << std::endl;
        }
        {
            ft::vector<char>    v_ft(2, 'D');
            ft::vector<char>    v_ft_0(2, 'D');

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 4" << std::endl << std::endl;
            if (v_ft != v_ft_0)
                std::cout << "IS NOT EQUAL ." << std::endl;
            else
                std::cout << "EQUAL ." << std::endl;
        }
        {
            ft::vector<float>    v_ft(2, 1010101);
            ft::vector<float>    v_ft_0(2, 1010101);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 5" << std::endl << std::endl;
            if (v_ft != v_ft_0)
                std::cout << "IS NOT EQUAL ." << std::endl;
            else
                std::cout << "EQUAL ." << std::endl;
        }
    }

void    TEST_CTOR_COPY(void)
{
        std::cout << "CTOR COPY ." << std::endl;
        std::string str[30] = { "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test" };
        {
            ft::vector<std::string> v_ft(str, str + 30);
            std::vector<std::string> v_s(str, str + 30);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
            CHECK_FT_STD_VECTOR(v_ft, v_s);

            ft::vector<std::string> v_ft_0(v_ft);
            std::vector<std::string> v_s_0(v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            CHECK_FT_STD_VECTOR(v_ft_0, v_s_0);

            if (&v_ft_0[0] == &v_ft[0])
                std::cout << "CTOR COPY DOSE NOT PROVIDE A DEEP COPY" << std::endl;

            system("leaks vector.out");
        }
    }

void    TEST_CTOR_RANGE(void)
{
        std::cout << "CTOR RANGE ..." << std::endl;
        std::string str[30] = { "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test" };
        {
            ft::vector<std::string> v_ft(str, str + 30);
            std::vector<std::string> v_s(str, str + 30);

             std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
            CHECK_FT_STD_VECTOR(v_ft, v_s);

            ft::vector<std::string> v_ft_0(v_ft.begin(), v_ft.end());
            std::vector<std::string> v_s_0(v_s.begin(), v_s.end());

             std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            CHECK_FT_STD_VECTOR(v_ft_0, v_s_0);            

            if (&v_ft_0[0] == &v_ft[0])
                std::cout << "CTOR COPY DOSE NOT PROVIDE A DEEP COPY" << std::endl;

        }
        {
            std::istringstream s_f("");
            std::istreambuf_iterator<char> it_f(s_f), e_f;

            std::istringstream s_s("");
            std::istreambuf_iterator<char> it_s(s_s), e_s;

            ft::vector<char>    v_ft(it_f, e_f);
            std::vector<char>    v_s(it_s, e_s);

             std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;
            CHECK_FT_STD_VECTOR(v_ft, v_s);
        }
        {
            std::istringstream s_f("HELLO WORLD !");
            std::istreambuf_iterator<char> it_f(s_f), e_f;

            std::istringstream s_s("");
            std::istreambuf_iterator<char> it_s(s_s), e_s;

            ft::vector<char>    v_ft(it_f, e_f);
            std::vector<char>    v_s(it_s, e_s);

             std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 4" << std::endl << std::endl;

            CHECK_FT_STD_VECTOR(v_ft, v_s);
        }
        system("leaks vector.out");
    }

void    TEST_CTOR_SIZE(void)
{
        std::cout << "CTOR SIZE ." << std::endl;
        {
            ft::vector<int> v_ft(64, 1);
            std::vector<int> v_s(64, 1);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
            CHECK_FT_STD_VECTOR(v_ft, v_s);
        }
        {
            ft::vector<long> v_ft(0, 1);
            std::vector<long> v_s(0, 1);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            CHECK_FT_STD_VECTOR(v_ft, v_s);
            
        }
        {
            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;
            try
            {
                ft::vector<float> v_ft(ft::vector<float>().max_size(), 1);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }
        system("leaks vector.out");
    }

void    TEST_EMPTY(void)
{
        std::cout << "EMPTY ..." << std::endl;
        {
            ft::vector<std::string> v_ft(0);
            std::vector<std::string> v_s(0);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;

            CHECK_FT_STD_VECTOR(v_ft, v_s);
            if (v_ft.empty() == v_s.empty())    
                std::cout << "YES FT empty == STD empty" << std::endl;
        }
        {
            ft::vector<std::string> v_ft;
            std::vector<std::string> v_s;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            CHECK_FT_STD_VECTOR(v_ft, v_s);
            if (v_ft.empty() == v_s.empty())    
                std::cout << "YES FT empty == STD empty" << std::endl;
        }
        {
            ft::vector<std::string> v_ft(10, "test");
            std::vector<std::string> v_s(10, "test");

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;
            CHECK_FT_STD_VECTOR(v_ft, v_s);
            if (v_ft.empty() == v_s.empty())    
                std::cout << "YES FT empty == STD empty" << std::endl;
        }
    }

void    TEST_ERASE_RANGE(void)
{
        std::cout << "ERASE RANGE" << std::endl;
        {
            ft::vector<int>     v_ft(20, 1010);
            std::vector<int>     v_s(20, 1010);

            v_ft.erase(v_ft.begin(), v_ft.end());
            v_s.erase(v_s.begin(), v_s.end());

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
            CHECK_FT_STD_VECTOR(v_ft, v_s);
            system("leaks vector.out");
        }
        {
            ft::vector<int>     v_ft(20, 1010);
            std::vector<int>     v_s(20, 1010);

            v_ft.erase(v_ft.end(), v_ft.end());
            v_s.erase(v_s.end(), v_s.end());

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            CHECK_FT_STD_VECTOR(v_ft, v_s);

            v_ft.erase(v_ft.begin(), v_ft.begin() + 3);
            v_s.erase(v_s.begin(), v_s.begin() + 3);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;
            CHECK_FT_STD_VECTOR(v_ft, v_s);
            system("leaks vector.out");
        }
    }

void    TEST_ERASE(void)
{
        std::cout << "ERASE POSITION ..." << std::endl;
        {
            ft::vector<int>     v_ft(20, 1010);
            std::vector<int>     v_s(20, 1010);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;

            ft::vector<int>::iterator f_it = v_ft.erase(v_ft.begin() + 3);
            std::vector<int>::iterator s_it = v_s.erase(v_s.begin() + 3);

            std::cout << "RETURN ERASE : FT: " << *f_it << std::endl;
            std::cout << "RETURN ERASE :STD: " << *s_it << std::endl;
            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;

            f_it = v_ft.erase(v_ft.end() - 3);
            s_it = v_s.erase(v_s.end() - 3);

            std::cout << "RETURN ERASE : FT: " << *f_it << std::endl;
            std::cout << "RETURN ERASE :STD: " << *s_it << std::endl;
            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;

            f_it = v_ft.erase(v_ft.begin());
            s_it = v_s.erase(v_s.begin());

            std::cout << "RETURN ERASE : FT: " << *f_it << std::endl;
            std::cout << "RETURN ERASE :STD: " << *s_it << std::endl;
            CHECK_FT_STD_VECTOR(v_ft, v_s);
        }
        {
            ft::vector<int>     v_ft(1, 1010);
            std::vector<int>     v_s(1, 1010);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;

            ft::vector<int>::iterator f_it = v_ft.erase(v_ft.begin());

            if (f_it == v_ft.end())
                std::cout << "RETURN ERASE IS END" << std::endl;

            CHECK_FT_STD_VECTOR(v_ft, v_s);
        }
    }

void    TEST_FRONT(void)
{
        std::cout << "FRONT ..." << std::endl;
        {
            ft::vector<int> v_ft(10, 1212);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
            std::cout << v_ft.front() << std::endl;

            if (&v_ft.front() != &v_ft[0])
                std::cout << "WRONG REFERENCE" << std::endl;
        }
        {
            ft::vector<std::string> v_ft(10, "1212");

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            std::cout << v_ft.front() << std::endl;

            if (&v_ft.front() != &v_ft[0])
                std::cout << "WRONG REFERENCE" << std::endl;
        }
        {
            const ft::vector<long> v(123, 543);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;
            std::cout << v.front() << std::endl;

            ft::vector<long>::const_reference b = v.front();
            if (&b != &v[0])
                std::cout << "WRONG REFERENCE" << std::endl;
        }

    }

void    TEST_INDEX_OPERATOR(void)
{
        std::cout << "TEST INDEX OPERATOR ..." << std::endl;
        std::string str[30] = { "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test" };
        {
            ft::vector<std::string>     v_ft(str, str + 15);
            std::vector<std::string>     v_s(str, str + 15);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
            ft::vector<std::string>::reference value_f = v_ft[10];
            std::vector<std::string>::reference value_s = v_s[10];

            value_f = "HELLO WORLD :)";
            value_s = "HELLO WORLD :)";
        
            CHECK_FT_STD_VECTOR(v_ft, v_s);
        }
        {
            const ft::vector<std::string>     v_ft(str, str + 15);
            const std::vector<std::string>     v_s(str, str + 15);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;
            ft::vector<std::string>::const_reference value_f = v_ft[10];
            std::vector<std::string>::const_reference value_s = v_s[10];

            std::cout << "  value_f :: " << value_f << std::endl;
            std::cout << "  value_s :: " << value_s << std::endl;
        
            CHECK_FT_STD_VECTOR(v_ft, v_s);
        }
    }

void    TEST_GET_ALLOCATOR(void)
{
        std::cout << " TEST_GET_ALLOCATOR" << std::endl;
        
        ft::vector<int> v;

        std::allocator<int> alloc = v.get_allocator();

        int *buff = alloc.allocate(2000 * 4);
        alloc.deallocate(buff, 2000 * 4);
}

void TEST_INSERT(void)
{
        std::cout << " TEST INSERT POSITION " << std::endl;   
        {
            {
                ft::vector<std::string> v_ft;
                std::vector<std::string> v_s;
                
                ft::vector<std::string>::iterator it_ft;
                std::vector<std::string>::iterator it_s;

                std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;


                it_ft = v_ft.insert(v_ft.end(), "hello world 1");
                it_s = v_s.insert(v_s.end(), "hello world 1");

                std::cout << "it_ft :: " << *it_ft << std::endl;
                std::cout << "it_s  :: " << *it_s << std::endl;

                CHECK_FT_STD_VECTOR(v_ft, v_s);

                std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;

                it_ft = v_ft.insert(v_ft.end(), "hello world 2");
                it_s = v_s.insert(v_s.end(), "hello world 2");

                std::cout << "it_ft :: " << *it_ft << std::endl;
                std::cout << "it_s  :: " << *it_s << std::endl;

                CHECK_FT_STD_VECTOR(v_ft, v_s);

                std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;

                it_ft = v_ft.insert(v_ft.begin() + 1, "hello world 3");
                it_s = v_s.insert(v_s.begin() + 1, "hello world 3");

                std::cout << "it_ft :: " << *it_ft << std::endl;
                std::cout << "it_s  :: " << *it_s << std::endl;

                CHECK_FT_STD_VECTOR(v_ft, v_s);

                std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 4" << std::endl << std::endl;

                it_ft = v_ft.insert(v_ft.begin() + 2, "hello world 4");
                it_s = v_s.insert(v_s.begin() + 2, "hello world 4");

                std::cout << "it_ft :: " << *it_ft << std::endl;
                std::cout << "it_s  :: " << *it_s << std::endl;

                CHECK_FT_STD_VECTOR(v_ft, v_s);

            }
            {
                ft::vector<int> v_ft;
                std::vector<int> v_s;

                ft::vector<int>::iterator it_ft;
                std::vector<int>::iterator it_s;

                std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 5" << std::endl << std::endl;

                it_ft = v_ft.insert(v_ft.begin(), 1000);
                it_s = v_s.insert(v_s.begin(), 1000);

                std::cout << "it_ft :: " << *it_ft << std::endl;
                std::cout << "it_s  :: " << *it_s << std::endl;

                CHECK_FT_STD_VECTOR(v_ft, v_s);

                std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 6" << std::endl << std::endl;

                it_ft = v_ft.insert(v_ft.end(), 20);
                it_s = v_s.insert(v_s.end(), 20);

                std::cout << "it_ft :: " << *it_ft << std::endl;
                std::cout << "it_s  :: " << *it_s << std::endl;

                CHECK_FT_STD_VECTOR(v_ft, v_s);
            }


        }

    }

void TEST_INSERT_SIZE(void)
{
        std::cout << "TEST INSERT SIZE" << std::endl;
        {
            ft::vector<int> v_ft;
            std::vector<int> v_s;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;

            v_ft.insert(v_ft.begin(), 0, 100);
            v_s.insert(v_s.begin(), 0, 100);

            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;

            v_ft.insert(v_ft.begin(), 12, 1010);
            v_s.insert(v_s.begin(), 12, 1010);

            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;

            v_ft.insert(v_ft.begin(), 12, -1010);
            v_s.insert(v_s.begin(), 12, -1010);

            CHECK_FT_STD_VECTOR(v_ft, v_s);
        }
    }

void    TEST_INSERT_RANGE(void)
{
        std::cout << "INSERT RANGE " << std::endl;
        std::string str[30] = { "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test" };
        {
            ft::vector<std::string> v_ft;
            std::vector<std::string> v_s;

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 1" << std::endl << std::endl;
            
            v_ft.insert(v_ft.begin(), v_ft.begin(), v_ft.begin());
            v_s.insert(v_s.begin(), v_s.begin(), v_s.begin());

            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 2" << std::endl << std::endl;

            v_ft.insert (v_ft.begin(), v_ft.begin(), v_ft.end());
            v_s.insert(v_s.begin(), v_s.begin(), v_s.end());

            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 3" << std::endl << std::endl;

            v_ft.insert (v_ft.begin(), str, str + 30);
            v_s.insert(v_s.begin(), str, str + 30);

            CHECK_FT_STD_VECTOR(v_ft, v_s);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 4" << std::endl << std::endl;

            v_ft.insert (v_ft.begin(), str + 5, str + 10);
            v_s.insert(v_s.begin(), str + 5, str + 10);

            CHECK_FT_STD_VECTOR(v_ft, v_s);
        }
        {
            std::list<int>  list_s(10, 1010);

            ft::vector<int> v_ft(5, 10);
            std::vector<int> v_s(5, 10);

            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 5" << std::endl << std::endl;

            v_ft.insert (v_ft.begin() + 2, list_s.begin(), list_s.end());
            v_s.insert (v_s.begin() + 2, list_s.begin(), list_s.end());

            CHECK_FT_STD_VECTOR(v_ft, v_s);
        }
        {
            std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST 6" << std::endl << std::endl;
            std::istringstream s_f("1_2_3_4");
            std::istreambuf_iterator<char> it_f(s_f);

            std::istringstream s_s("1_2_3_4");
            std::istreambuf_iterator<char> it_s(s_s), end;

            ft::vector<char>    v_ft(2, 'L');
            std::vector<char>    v_s(2, 'L');

            v_ft.insert(v_ft.begin(), it_f, end);

            v_s.insert(v_s.begin(), it_s, end);

            CHECK_FT_STD_VECTOR(v_ft, v_s);
        }
    }

void    TEST_ITERATOR(void)
{
        std::cout << "TEST ITERATOR " << std::endl;
        std::string str[30] = { "test 1", "test 2", "test 2", "test 4", "test 5", "test 6", "test 7", "test 8", "test 9", "test 10", "test 11", "test 12", "test 13", "test 14", "test 15", "test 16", "test 17", "test 18", "test 19", "test 20", "test 21", "test 22", "test 23", "test 24", "test 25", "test 26", "test 27", "test 28", "test 29", "test 30" };
        {
            ft::vector<int> v1;
            const ft::vector<int> v2;

            if (v1.begin() != v1.end())
                std::cerr << "ITERATOR ERROR :) " << std::endl;
            else
                std::cout << "NON CONST VECTOR v1.begin() != v1.end() " << std::endl;

            if (v2.begin() != v2.end())
                std::cerr << "ITERATOR ERROR :) " << std::endl;
            else
                std::cout << "CONST VECTOR v2.begin() != v2.end() " << std::endl;
        }
        {
            ft::vector<std::string>     v(str, str + 30);

            ft::vector<std::string>::iterator it1 = v.begin();
            ft::vector<std::string>::iterator it2 = it1;

            std::cout << " :it1: = " << *it1 << std::endl;
            std::cout << " :it2: = " << *it2 << std::endl;

            it1 = v.begin() + 9;
            std::cout << " it1 = v.begin() + 9 " << std::endl;
            std::cout << " :it1: = " << *it1 << std::endl;

            it1 = v.end() - 1;
            std::cout << " it1 = v.end() - 1 " << std::endl;
            std::cout << " :it1: = " << *it1 << std::endl;

            it2 = it1;
            std::cout << " it2 = it1 " << std::endl;
            std::cout << " :it2: = " << *it2 << std::endl;

            *it1 = -1;
        }
        {
            ft::vector<std::string>     v(str, str + 30);

            ft::vector<std::string>::iterator it = v.begin();

            ft::vector<std::string>::const_iterator cit = v.begin() + 2;

            std::cout << "it = " << *it << std::endl;
            std::cout << "cit = " << *cit << std::endl;

            std::cout << "CLEAR THE BEGIN OF ITERATOR" << std::endl;
            it->clear();
            std::cout << " *it = " << *it << std::endl;
            std::cout << "cit->c_str() = " << cit->c_str() << std::endl;

            for (ft::vector<std::string>::iterator i = v.begin(); i != v.end(); i++)
                std::cout << " i :: " << *i << " || ";
            std::cout << std::endl;
            
            int i = 0;
            while (i < 7)
                ++it, i++;
            it++;
            ++cit;
            cit++;

            std::cout << " it = " << *it << std::endl;
            std::cout << " it++ = " << *it++ << std::endl;
            std::cout << " it = " << *it << std::endl;

            std::cout << " cit = " << *cit << std::endl;
            std::cout << " cit++ = " << *cit++ << std::endl;
            std::cout << " cit = " << *cit << std::endl;


            i = 0;
            while (i < 7)
                --it, i++;
            it--;
            --cit;
            cit--;

            std::cout << " it = " << *it << std::endl;
            std::cout << " it-- = " << *it-- << std::endl;
            std::cout << " it = " << *it << std::endl;

            std::cout << " cit = " << *cit << std::endl;
            std::cout << " cit-- = " << *cit-- << std::endl;
            std::cout << " cit = " << *cit << std::endl;
        }
        {
            ft::vector<std::string> v(str, str + 30);

            std::cout << "v.begin() + 4 = " << *(v.begin() + 4) << std::endl;
            std::cout << "v.begin() - 4 = " << *(v.end() - 4) << std::endl;

            std::cout << "v.end() - v.begin() :: " << v.end() - v.begin() << std::endl;
        }
    }

void    TEST_ITERATOR_COMPARISONS(void)
{
        std::string str[30] = { "test 1", "test 2", "test 2", "test 4", "test 5", "test 6", "test 7", "test 8", "test 9", "test 10", "test 11", "test 12", "test 13", "test 14", "test 15", "test 16", "test 17", "test 18", "test 19", "test 20", "test 21", "test 22", "test 23", "test 24", "test 25", "test 26", "test 27", "test 28", "test 29", "test 30" };
        ft::vector<std::string> v(str, str + 30);

        ft::vector<std::string>::iterator it = v.begin();
        ft::vector<std::string>::iterator it2 = v.begin();

        ft::vector<std::string>::const_iterator cit = v.begin();
        ft::vector<std::string>::const_iterator cit2 = v.begin();

        if (it == v.begin())
            std::cout << "Equal iterators" << std::endl;

        if (cit == v.begin())
            std::cout << "Equal const iterators" << std::endl;
        
        if (cit == it)
            std::cout << "Equal const iterators." << std::endl;

        ++it;
        cit += 6;

        if (it != v.end())
            std::cout << "Not Equal iterators" << std::endl;
        
        if (cit != v.end())
            std::cout << "Not Equal const iterators" << std::endl;
        
        if (cit != it)
        std::cout << "Not Equal const iterators." << std::endl;

        if (it < it + 1)
            std::cout << "Less than" << std::endl;
            
        if (it + 1 < it)
            std::cout << "Less than." << std::endl;
        
        if (it < it)
            std::cout << "Less than.." << std::endl;
        
        if (cit < cit + 1) 
            std::cout << "Less than..." << std::endl;
        
        if (cit + 1 < cit)
            std::cout << "Less than...." << std::endl;
        
        if (cit < cit)
            std::cout << "Less than...." << std::endl;
        
        if (it2 < cit2 + 1)
            std::cout << "Less than....." << std::endl;
        
        if (it2 < cit2)
            std::cout << "Less than......" << std::endl;

        if (it <= it + 1)
            std::cout << "Less than or equal" << std::endl;
        
        if (it + 1 <= it)
            std::cout << "Less than or equal." << std::endl;

        if (it <= it)
            std::cout << "Less than or equal.." << std::endl;
        if (cit <= cit + 1)
            std::cout << "Less than or equal..." << std::endl;
        
        if (cit + 1 <= cit)
            std::cout << "Less than or equal...." << std::endl;
        
        if (cit <= cit)
            std::cout << "Less than or equal....." << std::endl;
        
        if (it2 <= cit2 + 1)
            std::cout << "Less than or equal......" << std::endl;
        
        if (it2 <= cit2)
            std::cout << "Less than or equal......." << std::endl;
        
        if (it > it + 1)
            std::cout << "Greater than" << std::endl;
        
        if (it + 1 > it)
            std::cout << "Greater than." << std::endl;
        
        if (it > it)
            std::cout << "Greater than.." << std::endl;
        
        if (cit > cit + 1)
            std::cout << "Greater than..." << std::endl;
        
        if (cit + 1 > cit)
            std::cout << "Greater than...." << std::endl;
        
        if (cit > cit)
            std::cout << "Greater than...." << std::endl;
        
        if (it2 + 1 > cit2)
            std::cout << "Greater than....." << std::endl;
        
        if (it2 > cit2)
            std::cout << "Greater than......" << std::endl;
        

        if (it >= it + 1)
            std::cout << "Greater than or equal" << std::endl;
        
        if (it + 1 >= it)
            std::cout << "Greater than or equal." << std::endl;
        
        if (it >= it)
            std::cout << "Greater than or equal.." << std::endl;
        
        if (cit >= cit + 1)
            std::cout << "Greater than or equal..." << std::endl;
        
        if (cit + 1 >= cit)
            std::cout << "Greater than or equal...." << std::endl;
        
        if (cit >= cit)
            std::cout << "Greater than or equal....." << std::endl;
        
        if (it2 >= cit2 + 1)
            std::cout << "Greater than or equal......" << std::endl;
        
        if (it2 + 1 >= cit2)
            std::cout << "Greater than or equal......." << std::endl;
        
        if (it2 >= cit2)
            std::cout << "Greater than or equal........" << std::endl;
    }

void    TEST_MAX_SIZE(void)
{
        
        std::cout << " FT  " << "Unsigned Char max size:" << ft::vector<unsigned char>().max_size() << std::endl;
        std::cout << " STD " << "Unsigned Char max size:" << std::vector<unsigned char>().max_size() << std::endl;
        std::cout << " FT  " << "Char max size:" << ft::vector<char>().max_size() << std::endl;
        std::cout << " STD " << "Char max size:" << std::vector<char>().max_size() << std::endl;
        std::cout << " FT  " << "Int max size:" << ft::vector<int>().max_size() << std::endl;
        std::cout << " STD " << "Int max size:" << std::vector<int>().max_size() << std::endl;
        std::cout << " FT  " << "Long max size:" << ft::vector<long>().max_size() << std::endl;
        std::cout << " STD " << "Long max size:" << std::vector<long>().max_size() << std::endl;
        std::cout << " FT  " << "Short max size:" << ft::vector<short>().max_size() << std::endl;
        std::cout << " STD " << "Short max size:" << std::vector<short>().max_size() << std::endl;
        std::cout << " FT  " << "abc struct max size:" << ft::vector<abc>().max_size() << std::endl;
        std::cout << " STD " << "abc struct max size:" << ft::vector<abc>().max_size() << std::endl;
        std::cout << " FT  " << "Float max size:" << ft::vector<float>().max_size() << std::endl;
        std::cout << " STD " << "Float max size:" << std::vector<float>().max_size() << std::endl;
    }

void    TEST_POP_BACK(void)
{
        std::cout << "TEST POP BACK" << std::endl;
        std::string str[30] = { "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test" };

        ft::vector<std::string> v_ft(str, str + 30);
        std::vector<std::string> v_s(str, str + 30);

        v_ft.pop_back();
        v_s.pop_back();

        CHECK_FT_STD_VECTOR(v_ft, v_s);

        for (size_t i = 0; i < 20; i++)
            v_ft.pop_back(), v_s.pop_back();
        
        CHECK_FT_STD_VECTOR(v_ft, v_s);
    }

void    TEST_PUSH_BACK(void)
{
    ft::vector<double> v_ft;
    std::vector<double> v_s;

    for (size_t i = 0; i < 20; i++)
    {
        v_ft.push_back(1.0);
        v_s.push_back(1.0);

        CHECK_FT_STD_VECTOR(v_ft, v_s);
    }

    v_ft.push_back(6.0);
    v_s.push_back(6.0);

    CHECK_FT_STD_VECTOR(v_ft, v_s);
    
}

void    TEST_RESERVE(void)
{
    ft::vector<int> v_ft;
    std::vector<int> v_s;

    int n = 0;

    srand(time(NULL));
    for (size_t i = 0; i < 10; i++)
    {
        n = rand() % 2;
        v_ft.reserve(n);
        v_s.reserve(n);

        CHECK_FT_STD_VECTOR(v_ft, v_s);
    }
}

void    TEST_RESIZE(void)
{
    ft::vector<int> v_ft;
    std::vector<int> v_s;

    int n = 0;

    srand(time(NULL));
    for (size_t i = 0; i < 10; i++)
    {
        n = rand() % 2;
        v_ft.resize(n, 1010);
        v_s.resize(n, 1010);

        CHECK_FT_STD_VECTOR(v_ft, v_s);
    }
    
}

void    TEST_RITERATOR(void)
{
    std::string str[30] = { "test 1", "test 2", "test 2", "test 4", "test 5", "test 6", "test 7", "test 8", "test 9", "test 10", "test 11", "test 12", "test 13", "test 14", "test 15", "test 16", "test 17", "test 18", "test 19", "test 20", "test 21", "test 22", "test 23", "test 24", "test 25", "test 26", "test 27", "test 28", "test 29", "test 30" };

    {
        ft::vector<int> v1;
        const ft::vector<int> v2;

        if (v1.rbegin() != v1.rend())
            std::cout << "Iterator error" << std::endl;

        ft::vector<int>::const_reverse_iterator it = v2.rbegin();
        if (it != v2.rend())
            std::cout << "Iterator error" << std::endl;
    }

    {
        ft::vector<std::string> v(str, str + 30);

        ft::vector<std::string>::reverse_iterator it1 = v.rbegin();
        ft::vector<std::string>::reverse_iterator it2 = it1;

        std::cout << "It1:" <<  *it1 << std::endl;
        std::cout << "It2:" <<  *it2 << std::endl;

        it1 = v.rbegin() + 9;

        std::cout << "It1:" <<  *it1 << std::endl;

        it1 = v.rend() - 1;

        std::cout << "It1:" <<  *it1 << std::endl;

        it2 = it1;

        std::cout << "It2:" <<  *it2 << std::endl;

        *it1 = -1;

    }

    {
        ft::vector<std::string> v(str, str + 30);

        ft::vector<std::string>::reverse_iterator it = v.rbegin();
        ft::vector<std::string>::const_reverse_iterator cit = v.rbegin() + 34;

        std::cout << "It:" << *it << std::endl;
        std::cout << "Cit:" <<  *cit << std::endl;

        it->clear();
        std::cout << "Cstr:  " << cit->c_str() << std::endl;


        ++it;
        ++it;
        ++it;
        ++it;
        ++it;
        ++it;
        ++it;
        ++it;
        ++it;
        ++it;
        ++it;
        it++;
        ++cit;
        cit++;

        std::cout << "It: " << *it << std::endl;
        std::cout << "It: " << *it++ << std::endl;
        std::cout << "It: " << *it << std::endl;

        std::cout << "Cit:" <<  *cit << std::endl;
        std::cout << "Cit:" <<  *cit++ << std::endl;
        std::cout << "Cit:" <<  *cit << std::endl;

        --it;
        it--;
        it--;
        --cit;
        --cit;
        cit--;

        std::cout << "It: " << *it << std::endl;
        std::cout << "It: " << *it-- << std::endl;
        std::cout << "It: " << *it << std::endl;

        std::cout << "Cit:" <<  *cit << std::endl;
        std::cout << "Cit:" <<  *cit-- << std::endl;
        std::cout << "Cit:" <<  *cit << std::endl;

        std::cout << "It: " << *(it + 6) << std::endl;
        std::cout << "It: " << *(42 + it) << std::endl;
        std::cout << "It: " << *(42 + it - 3) << std::endl;
        std::cout << "It: " << *(v.rend() - 6) << std::endl;
        std::cout << "Cit:" <<  *(cit - 6) << std::endl;
        std::cout << "Cit:" <<  *(cit + 7) << std::endl;
        std::cout << "Size: " << v.rend() - v.rbegin() << std::endl;

        it = v.rbegin() + 25;
        cit = v.rbegin() + 25;

        std::cout << "It: " << *it << std::endl;
        std::cout << "Cit:" <<  *cit << std::endl;

        it += 12;
        cit += 12;

        std::cout << "It: " << *it << std::endl;
        std::cout << "Cit:" <<  *cit << std::endl;

        it += 0;
        cit += 0;

        std::cout << "It: " << *it << std::endl;
        std::cout << "Cit:" <<  *cit << std::endl;

        it += 4;
        cit += 4;

        std::cout << "It: " << *it << std::endl;
        std::cout << "Cit:" <<  *cit << std::endl;

        it -= 0;
        cit -= 0;

        std::cout << "It: " << *it << std::endl;
        std::cout << "Cit:" <<  *cit << std::endl;

        it -= 22;
        cit -= 22;

        std::cout << "It: " << *it << std::endl;
        std::cout << "Cit:" <<  *cit << std::endl;
        std::cout << "It +  << 0:" << it[10] << std::endl;
        std::cout << "Cit + << 10:" << cit[10] << std::endl;
    }
}

void    TEST_RITERATOR_COMPARISONS(void)
{
    std::string str[30] = { "test 1", "test 2", "test 2", "test 4", "test 5", "test 6", "test 7", "test 8", "test 9", "test 10", "test 11", "test 12", "test 13", "test 14", "test 15", "test 16", "test 17", "test 18", "test 19", "test 20", "test 21", "test 22", "test 23", "test 24", "test 25", "test 26", "test 27", "test 28", "test 29", "test 30" };

        ft::vector<std::string> v(str, str + 30);

        ft::vector<std::string>::reverse_iterator it = v.rbegin();
        ft::vector<std::string>::reverse_iterator it2 = v.rbegin();
        ft::vector<std::string>::const_reverse_iterator cit = v.rbegin();
        ft::vector<std::string>::const_reverse_iterator cit2 = v.rbegin();

        if (it == v.rbegin())
            std::cout << "Equal iterators" << std::endl;
        
        if (cit == v.rbegin())
            std::cout << "Equal const iterators" << std::endl;
        
        if (cit == it)
            std::cout << "Equal const iterators." << std::endl;
        

        ++it;
        cit += 6;

        if (it != v.rend())
            std::cout << "Not Equal iterators" << std::endl;
        
        if (cit != v.rend())
            std::cout << "Not Equal const iterators" << std::endl;
        
        if (cit != it)
            std::cout << "Not Equal const iterators." << std::endl;
        

        if (it < it + 1)
            std::cout << "Less than" << std::endl;
        
        if (it + 1 < it)
            std::cout << "Less than." << std::endl;
        
        if (it < it)
            std::cout << "Less than.." << std::endl;
        
        if (cit < cit + 1)
            std::cout << "Less than..." << std::endl;
        
        if (cit + 1 < cit)
            std::cout << "Less than...." << std::endl;
        
        if (cit < cit)
            std::cout << "Less than...." << std::endl;
        
        if (it2 < cit2 + 1)
            std::cout << "Less than....." << std::endl;
        
        if (it2 < cit2)
            std::cout << "Less than......" << std::endl;
        

        if (it <= it + 1)
            std::cout << "Less than or equal" << std::endl;
        
        if (it + 1 <= it)
            std::cout << "Less than or equal." << std::endl;
        
        if (it <= it)
            std::cout << "Less than or equal.." << std::endl;
        
        if (cit <= cit + 1)
            std::cout << "Less than or equal..." << std::endl;
        
        if (cit + 1 <= cit)
            std::cout << "Less than or equal...." << std::endl;
        
        if (cit <= cit)
            std::cout << "Less than or equal....." << std::endl;
        
        if (it2 <= cit2 + 1)
            std::cout << "Less than or equal......" << std::endl;
        
        if (it2 <= cit2)
            std::cout << "Less than or equal......." << std::endl;
        

        if (it > it + 1)
            std::cout << "Greater than" << std::endl;
        
        if (it + 1 > it)
            std::cout << "Greater than." << std::endl;
        
        if (it > it)
            std::cout << "Greater than.." << std::endl;
        
        if (cit > cit + 1)
            std::cout << "Greater than..." << std::endl;
        
        if (cit + 1 > cit)
            std::cout << "Greater than...." << std::endl;
        
        if (cit > cit)
            std::cout << "Greater than...." << std::endl;
        
        if (it2 + 1 > cit2)
            std::cout << "Greater than....." << std::endl;
        
        if (it2 > cit2)
            std::cout << "Greater than......" << std::endl;
        

        if (it >= it + 1)
            std::cout << "Greater than or equal" << std::endl;
        
        if (it + 1 >= it)
            std::cout << "Greater than or equal." << std::endl;
        
        if (it >= it)
            std::cout << "Greater than or equal.." << std::endl;
        
        if (cit >= cit + 1)
            std::cout << "Greater than or equal..." << std::endl;
        
        if (cit + 1 >= cit)
            std::cout << "Greater than or equal...." << std::endl;
        
        if (cit >= cit)
            std::cout << "Greater than or equal....." << std::endl;
        
        if (it2 >= cit2 + 1)
            std::cout << "Greater than or equal......" << std::endl;
        
        if (it2 + 1 >= cit2)
            std::cout << "Greater than or equal......." << std::endl;
        
        if (it2 >= cit2)
            std::cout << "Greater than or equal........" << std::endl;
        
}

void    TEST_SWAP(void)
{
    std::string str[30] = { "test 1", "test 2", "test 2", "test 4", "test 5", "test 6", "test 7", "test 8", "test 9", "test 10", "test 11", "test 12", "test 13", "test 14", "test 15", "test 16", "test 17", "test 18", "test 19", "test 20", "test 21", "test 22", "test 23", "test 24", "test 25", "test 26", "test 27", "test 28", "test 29", "test 30" };

    ft::vector<std::string> v_ft(str, str + 15);
    ft::vector<std::string> v_ft1(str + 15, str + 30);

    std::vector<std::string> v_s(str, str + 15);
    std::vector<std::string> v_s1(str + 15, str + 30);

    v_ft.swap(v_ft1);
    v_s.swap(v_s1);

    CHECK_FT_STD_VECTOR(v_ft, v_s);
    CHECK_FT_STD_VECTOR(v_ft1, v_s1);

    ft::swap(v_ft, v_ft1);
    std::swap(v_s, v_s1);

    CHECK_FT_STD_VECTOR(v_ft, v_s);
    CHECK_FT_STD_VECTOR(v_ft1, v_s1);
}

void vector_tests(void)
{
    std::cout << "Loading vector ..." << std::endl;
    // TEST_ASSIGN_RANGE();
    // TEST_ASSIGN();
    // TEST_ASSIGNMENT();
    // TEST_AT();
    // TEST_BACK();
    // TEST_CLEAR();
    // TEST_EQ();
    // TEST_GE();
    // TEST_GT();
    // TEST_LE();
    // TEST_LT();
    // TEST_NE();
    // TEST_CTOR_COPY();
    // TEST_CTOR_RANGE();
    // TEST_CTOR_SIZE();
    // TEST_EMPTY();
    // TEST_ERASE_RANGE();
    // TEST_ERASE();
    // TEST_FRONT();
    // TEST_INDEX_OPERATOR();
    // TEST_GET_ALLOCATOR();
    // TEST_INSERT();
    // TEST_INSERT_SIZE();
    // TEST_INSERT_RANGE();
    // TEST_ITERATOR();
    // TEST_ITERATOR_COMPARISONS();
    // TEST_MAX_SIZE();
    // TEST_POP_BACK();
    // TEST_PUSH_BACK();
    // TEST_RESERVE();
    // TEST_RESIZE();
    // TEST_RITERATOR();
    // TEST_RITERATOR_COMPARISONS();
    // TEST_SWAP();
}