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

void    TEST_ASSIGN(void) {
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

void    TEST_ASSIGNMENT(void) {
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
            
    ft::vector<long>::reference t = vector.back();

    std::cout << "BACK = " << t << std::endl;

    ft::vector<long>::const_reference c = vector.back();
    
    std::cout << "CONST BACK = " << c << std::endl;
}

int main()
{
    std::cout << "Loading vector ..." << std::endl;
    TEST_ASSIGN_RANGE();
    // TEST_ASSIGN();
    // TEST_ASSIGNMENT();
    // TEST_AT();
    // TEST_BACK();
    // TEST_CLEAR();
    // {
    //     std::cout << "CLEAR ..." << std::endl;

    //     std::string str[30] = {"test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test"};

    //     ft::vector<std::string>     v_ft(str, str + 30);
    //     std::vector<std::string>     v_s(str, str + 30);

    //     CHECK_FT_STD_VECTOR(v_ft, v_s);

    //     v_ft.clear();
    //     v_s.clear();

    //     CHECK_FT_STD_VECTOR(v_ft, v_s);


    // }

}