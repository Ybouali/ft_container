#include <sstream>

#include "../vector.hpp"

template <class _T>
void CHECK_FT_STD_VECTOR(const ft::vector<_T>& v_ft, const std::vector<_T>& v_s)
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
        std::cout << "v_ft[" << i << "] = " << v_ft[i] << std::endl;
        std::cout << " v_s[" << i << "] = " << v_s[i] << std::endl << std::endl;
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

int main()
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
    
}